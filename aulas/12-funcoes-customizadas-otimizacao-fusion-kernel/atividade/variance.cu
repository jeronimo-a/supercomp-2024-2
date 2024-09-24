#include <cmath>
#include <chrono>
#include <iostream>
#include <thrust/host_vector.h>
#include <thrust/device_vector.h>
#include <thrust/transform_reduce.h>

struct variance_op
{
    float mean;
    variance_op(float mean_) : mean(mean_) {}  // Construtor que armazena a média

    __host__ __device__
    float operator()(const float& x) const {
        float diff = x - mean;  // Diferença em relação à média
        return diff * diff;  // Elevar ao quadrado a diferença
    }
};

float calculate_variance(const thrust::device_vector<float>& d_vec, float mean) {
    return thrust::transform_reduce(d_vec.begin(), d_vec.end(), variance_op(mean), 0.0f, thrust::plus<float>()) / d_vec.size();
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
    float v_mean = thrust::reduce(v.begin(), v.end(), 0.0f, thrust::plus<float>() / v.size());
    float v_variance = calculate_variance(v, v_mean);

    // termina a marcação do tempo
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration = end - start;

    // imprime os resultados
    std::cout << "Tamanho do vetor:   " << v_host.size() << std::endl;
    std::cout << "Variância do vetor: " << v_variance << std::endl;
    std::cout << "Tempo de execução:  " << duration.count() << " s" << std::endl;

    return 0;
}