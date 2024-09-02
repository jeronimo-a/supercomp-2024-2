#include <iostream>
#include <vector>
#include <random>
#include <chrono>

int main() {

    // cria o gerados de números aleatórios
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0.0, 1.0);

    // faz a leitura do tamanho da quantidade de itens e capacidade da mochila
    int quantidade_itens, capacidade_mochila;
    std::cin >> quantidade_itens >> capacidade_mochila;

    // define a matriz que contém todos os itens, itens[n] = [id, peso, valor]
    std::vector<std::vector<int>> itens(quantidade_itens, std::vector<int>(3));

    // faz a leitura dos valores e pesos de cada item
    for (int i = 0; i < quantidade_itens; i++) {
        itens[i][0] = i;
        std::cin >> itens[i][1] >> itens[i][2];
    }

    // marca o tempo de início
    auto start = std::chrono::high_resolution_clock::now();

    // percorre cada item, com 50% de chance de incluir cada um, se ele couber
    int peso_atual = 0;
    int valor_atual = 0;
    std::vector<int> mochila(quantidade_itens, 0);
    for (int i = 0; i < quantidade_itens; i++) {
        double random = distribution(generator);
        if (random <= 0.5) { continue; }
        if (peso_atual + itens[i][1] > capacidade_mochila) { continue; }
        peso_atual += itens[i][1];
        valor_atual += itens[i][2];
        mochila[i] = 1;
    }

    // marca o tempo de término e imprime o tempo de execução
    auto end = std::chrono::high_resolution_clock::now();\
    std::chrono::duration<double> duration = end - start;
    std::cout << "Tempo de execução: " << duration.count() << " segundos" << std::endl << std::endl;

    // imprime os resultados
    std::cout << "Mochila: ";
    for (int i = 0; i < quantidade_itens; i++) {
        std::cout << mochila[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Valor: " << valor_atual << std::endl;
    std::cout << "Peso: " << peso_atual << std::endl;

    return 0;
}