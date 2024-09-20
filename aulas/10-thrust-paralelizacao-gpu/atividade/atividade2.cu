#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <thrust/extrema.h>
#include <iostream>
#include <sstream>
#include <string>
#include <chrono>

int main() {

    // variáveis e vetores necessários para a leitura dos preços
    int prices_amount = 3520;
    auto read_start = std::chrono::steady_clock::now();
    thrust::host_vector<double> host_apple;
    thrust::host_vector<double> host_micro;
    std::string line;

    // lê os preços e os armazena no vetor da CPU
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

    // transfere os dados para a GPU
    thrust::device_vector<double> dev_apple(host_apple);
    thrust::device_vector<double> dev_micro(host_micro);

    // calcula a diferenças ponto a ponto dos preços de cada ação
    thrust::device_vector<double> diffs(dev_micro.size());
    thrust::transform(dev_apple.begin(), dev_apple.end(), dev_micro.begin(), diffs.begin(), thrust::minus<double>());

    // calcula a média das diferenças
    double avg_diff = thrust::reduce(diffs.begin(), diffs.end(), 0.0, thrust::plus<double>());
    avg_diff = avg_diff / (double) diffs.size();
    std::cout << "Média das diferenças: " << avg_diff << std::endl;

    return 0;
}