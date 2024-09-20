#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <thrust/extrema.h>
#include <iostream>
#include <chrono>

int main() {

    // EXERCÍCIO 1: leitura e transferência dos dados para a GPU    --- --- --- --- --- --- --- --- --- 1

    // 1.1: leitura dos preços da ação do google    --- --- --- --- --- --- --- --- --- --- --- 1.1

    // define as variáveis necessárias para a leitura e cronometragem e o vetor da CPU
    int prices_amount = 2048;
    auto read_start = std::chrono::steady_clock::now();
    thrust::host_vector<double> host(prices_amount, 0);

    // lê os preços e os armazena no vetor da CPU
    for (int i = 0; i < prices_amount; i++) {
        std::cin >> host[i];
    }

    // marca o fim da medição de tempo e imprime a variação
    auto read_end = std::chrono::steady_clock::now();
    std::chrono::duration<double> read_diff = read_end - read_start;
    std::cout << "Tempo de LEITURA: " << read_diff.count() << " segundos" << std::endl;

    // 1.2: transferência dos dados para a GPU  --- --- --- --- --- --- --- --- --- --- --- --- 1.2

    // marca o momento de início, copia tudo e marca o momento de finalização
    auto copy_start = std::chrono::steady_clock::now();
    thrust::device_vector<double> dev(host);
    auto copy_end = std::chrono::steady_clock::now();

    // calcula o tempo de cópia e imprime
    std::chrono::duration<double> copy_diff = copy_end - copy_start;
    std::cout << "Tempo de CÓPIA: " << copy_diff.count() << " segundos" << std::endl;

    // 1.3: tempo de execução do primeiro exercício --- --- --- --- --- --- --- --- --- --- --- 1.3
    std::cout << "Tempo de LEITURA e CÓPIA: " << read_diff.count() + copy_diff.count() << " segundos" << std::endl;

    // EXERCÍCIO 2: cálculo das médias e extremos   --- --- --- --- --- --- --- --- --- --- --- --- --- 2

    // 2.1: cálculo do preço médio da ação nos útlimos 10 anos  --- --- --- --- --- --- --- --- 2.1
    int average_price = thrust::reduce(dev.end() - 2610, dev.end(), 0.0, thrust::plus<double>());
    average_price = average_price / 2610.0;
    std::cout << "Preço médio da ação nos últimos 10 anos: " << average_price << std::endl;

    // 2.2: cálculo do preço médio da ação no último ano    --- --- --- --- --- --- --- --- --- 2.2
    average_price = thrust::reduce(dev.end() - 261, dev.end(), 0.0, thrust::plus<double>());
    average_price = average_price / 261.0;
    std::cout << "Preço médio da ação no último ano: " << average_price << std::endl;

    // 2.3: encontra o valor máximo ao longo de todo o período e do último ano  --- --- --- --- 2.3
    auto max_all_iter = thrust::max_element(dev.begin(), dev.end());
    auto max_year_iter = thrust::max_element(dev.end() - 261, dev.end());
    int max_all = *max_all_iter;
    int max_year = *max_year_iter;
    std::cout << "Valor máximo no período completo: " << max_all << std::endl;
    std::cout << "Valor máximo no último ano: " << max_year << std::endl;

    return 0;
}