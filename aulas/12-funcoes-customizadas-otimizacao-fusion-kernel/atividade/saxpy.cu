#include <iostream>
#include <thrust/host_vector.h>
#include <thrust/device_vector.h>

struct saxpy {
    int a;
    saxpy(int a_): a(a_) {};

    __host__ __device__
    double operator()(const int& x, const int& y) const {
        return a* x + y;
    }
};

int main() {

    // define os vetore de entrada
    thrust::host_vector<int> a_host = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    thrust::host_vector<int> b_host = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};

    // manda os vetores de entrada para a GPU
    thrust::device_vector<int> a(a_host);
    thrust::device_vector<int> b(b_host);

    // define o vetor de saída
    thrust::device_vector<int> c(a.size());

    // aplica a operação saxpy
    thrust::transform(a.begin(), a.end(), b.begin(), c.begin(), saxpy(5));

    // copia o resultado para a CPU
    thrust::host_vector<int> c_host(c);

    // mostra o resultado
    std::cout << "Entrada A: ";
    for (int i = 0; i < a_host.size(); i++) {
        std::cout << a_host[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Entrada B: ";
    for (int i = 0; i < b_host.size(); i++) {
        std::cout << b_host[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Saída:     ";
    for (int i = 0; i < c_host.size(); i++) {
        std::cout << c_host[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}