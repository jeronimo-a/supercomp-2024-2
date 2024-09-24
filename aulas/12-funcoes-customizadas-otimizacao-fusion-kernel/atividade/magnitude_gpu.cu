#include <cmath>
#include <chrono>
#include <iostream>
#include <thrust/host_vector.h>
#include <thrust/device_vector.h>
#include <thrust/transform_reduce.h>

struct square {
    __host__ __device__
    float operator()(const float& x) const {
        return x * x;
    }
};

float magnitude(thrust::device_vector<float>& v) {
    float sum_of_squares = thrust::transform_reduce(v.begin(), v.end(), square(), 0.0f, thrust::plus<float>());
    return std::sqrt(sum_of_squares);
}

int main() {

    // lê o tamanho do arquivo de entrada
    int size;
    std::cin >> size;

    // lê o arquivo de entrada
    thrust::host_vector<float> v_host(size);
    for (int i = 0; i < size; i++) {
        std::cin >> v_host[i];
    }

    // copia os valores para a GPU
    thrust::device_vector<float> v(v_host);

    // inicia a marcação do tempo
    auto start = std::chrono::steady_clock::now();

    // realiza a operação
    float v_norm = magnitude(v);

    // termina a marcação do tempo
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration = end - start;

    // imprime os resultados
    std::cout << "Tamanho do vetor:  " << v_host.size() << std::endl;
    std::cout << "Norma do vetor:    " << v_norm << std::endl;
    std::cout << "Tempo de execução: " << duration.count() << " s" << std::endl;

    return 0;
}