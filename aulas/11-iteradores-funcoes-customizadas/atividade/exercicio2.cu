#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <iostream>

struct difference_functor {
    __host__ __device__
    double operator()(const double& a, const double& b) const {
        return b - a;
    }
};

int main() {
    
    // variáveis e vetores necessários para a leitura dos preços da ação do google
    int prices_amount = 2160;
    thrust::host_vector<double> host_stocks(prices_amount, 0);

    // loop de coleta dos preços
    for (int i = 0; i < prices_amount; i++) {
        std::cin >> host[i];
    }

    // copia o vetor para a GPU
    thrust::device_vector<double> stocks(host_stocks);

    // calcula as diferenças de preço entre cada dia
    thrust::device_vector<double> ganho_diario(prices_amount - 1, 0);
    thrust::transform(stocks.begin(), stocks.end() - 1, ganho_diario.begin(), difference_functor());

    // cria um novo vetor somente com os valores positivos de ganho diario
    thrust::device_vector<double> ganho_diario_positivo(prices_amount - 1, 0);
    auto end = thrust::copy_if(danho_diario.begin(), ganho_diario.end(), ganho_diario_positivo.begin(), thrust::placeholders::_1 > 0);
    ganho_diario_positivo.resize(end - ganho_diario_positivo.begin());

    // calcula a média deste novo vetor
    int contagem = ganho_diario_positivo.size();
    double media_positiva = thrust::reduce(ganho_diario_positivo.begin(), ganho_diario_positivo.end(), 0.0, thrust::plus<double>());
    media_positiva = (contagem > 0) ? media_positiva / contagem : 0.0;

    std::cout << "Média dos ganhos diários positivos: " << std::endl;

    return 0;
}
