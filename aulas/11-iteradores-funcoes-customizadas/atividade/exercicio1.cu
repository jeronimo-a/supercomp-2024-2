#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <iostream>
#include <sstream>
#include <string>
#include <chrono>
#include <thrust/transform.h>
#include <thrust/reduce.h>
#include <thrust/functional.h>

struct relative_difference_functor {
    __host__ __device__
    double operator()(const double& a, const double& b) const {
        return b / a - 1;
    }
};

struct squared_difference_functor {
    double mean;
    squared_difference_functor(double m) : mean(m) {}
    __host__ __device__
    double operator()(const double& x) const {
        return (x - mean) * (x - mean);
    }
};

int main() {
    // Variables and vectors necessary for reading prices
    auto read_start = std::chrono::steady_clock::now();
    thrust::host_vector<double> host_apple;
    thrust::host_vector<double> host_micro;
    std::string line;

    // Read prices and store them in CPU vector
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        std::string apple_str, micro_str;
        if (std::getline(ss, apple_str, ',') && std::getline(ss, micro_str)) {
            double apple = std::stod(apple_str);
            double micro = std::stod(micro_str);
            host_apple.push_back(apple);
            host_micro.push_back(micro);
        }
    }

    // Transfer data to GPU
    thrust::device_vector<double> dev_apple(host_apple);
    thrust::device_vector<double> dev_micro(host_micro);

    // Calculate returns for each stock
    thrust::device_vector<double> dev_apple_returns(dev_apple.size() - 1);
    thrust::device_vector<double> dev_micro_returns(dev_micro.size() - 1);
    thrust::transform(dev_apple.begin(), dev_apple.end() - 1, dev_apple.begin() + 1, dev_apple_returns.begin(), relative_difference_functor());
    thrust::transform(dev_micro.begin(), dev_micro.end() - 1, dev_micro.begin() + 1, dev_micro_returns.begin(), relative_difference_functor());

    // Calculate the average return for each stock
    double expected_return_apple = thrust::reduce(dev_apple_returns.begin(), dev_apple_returns.end(), 0.0, thrust::plus<double>()) / dev_apple_returns.size();
    double expected_return_micro = thrust::reduce(dev_micro_returns.begin(), dev_micro_returns.end(), 0.0, thrust::plus<double>()) / dev_micro_returns.size();

    // Calculate variance for each stock
    thrust::device_vector<double> dev_apple_squared_diff(dev_apple_returns.size());
    thrust::device_vector<double> dev_micro_squared_diff(dev_micro_returns.size());
    thrust::transform(dev_apple_returns.begin(), dev_apple_returns.end(), dev_apple_squared_diff.begin(), squared_difference_functor(expected_return_apple));
    thrust::transform(dev_micro_returns.begin(), dev_micro_returns.end(), dev_micro_squared_diff.begin(), squared_difference_functor(expected_return_micro));

    double return_variance_apple = thrust::reduce(dev_apple_squared_diff.begin(), dev_apple_squared_diff.end(), 0.0, thrust::plus<double>()) / dev_apple_squared_diff.size();
    double return_variance_micro = thrust::reduce(dev_micro_squared_diff.begin(), dev_micro_squared_diff.end(), 0.0, thrust::plus<double>()) / dev_micro_squared_diff.size();

    std::cout << expected_return_apple << " " << expected_return_micro << std::endl;
    std::cout << return_variance_apple << " " << return_variance_micro << std::endl;

    return 0;
}
