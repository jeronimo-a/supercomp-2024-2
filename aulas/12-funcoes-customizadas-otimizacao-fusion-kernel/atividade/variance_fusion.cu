#include <thrust/host_vector.h>
#include <thrust/device_vector.h>
#include <thrust/transform_reduce.h>
#include <thrust/functional.h>
#include <iostream>
#include <cmath>

// Estrutura para acumular a soma e a soma dos quadrados
struct stats {
    float sum;
    float sum_of_squares;

    __host__ __device__
    stats(float s = 0.0f, float sq = 0.0f) : sum(s), sum_of_squares(sq) {}

    // Operador de redução para combinar duas estruturas stats
    __host__ __device__
    stats operator+(const stats& other) const {
        return stats(sum + other.sum, sum_of_squares + other.sum_of_squares);
    }
};

// Functor para calcular tanto a soma quanto a soma dos quadrados de cada valor
struct compute_stats {
    __host__ __device__
    stats operator()(const float& x) const {
        return stats(x, x * x);
    }
};

// Função que calcula a média e a variância usando Fusion Kernel
void compute_mean_variance(const thrust::device_vector<float>& v, float& mean, float& variance) {
    int n = v.size();

    // Usa transform_reduce para calcular a soma e a soma dos quadrados em uma única passada
    stats result = thrust::transform_reduce(v.begin(), v.end(), compute_stats(), stats(), thrust::plus<stats>());

    // Calcula a média
    mean = result.sum / n;

    // Calcula a variância
    variance = (result.sum_of_squares / n) - (mean * mean);
}

int main() {
    // Tamanho do vetor
    int size;
    std::cin >> size;

    // Vetor de entrada
    thrust::host_vector<float> h_vec(size);
    for (int i = 0; i < size; ++i) {
        std::cin >> h_vec[i];
    }

    // Copiar para o device
    thrust::device_vector<float> d_vec = h_vec;

    // Calcular média e variância usando Fusion Kernel
    float mean = 0.0f, variance = 0.0f;
    compute_mean_variance(d_vec, mean, variance);

    // Exibir os resultados
    std::cout << "Média: " << mean << std::endl;
    std::cout << "Variância: " << variance << std::endl;

    return 0;
}
