#include <algorithm>
#include <iostream>
#include <vector>
#include <random>
#include <chrono>

int main() {

    // faz a leitura do tamanho da quantidade de itens e capacidade da mochila
    int quantidade_itens, capacidade_mochila;
    std::cin >> quantidade_itens >> capacidade_mochila;

    // define a matriz que contém todos os itens, itens[n] = [id, peso, valor]
    std::vector<std::vector<int>> itens(quantidade_itens, std::vector<int>(3));

    // faz a leitura dos valores e pesos de cada item e mostra cada um com o seu respectivo ID
    std::cout << std::endl << "ITENS" << std::endl;
    std::cout << "ID PESO VALOR" << std::endl;
    for (int i = 0; i < quantidade_itens; i++) {
        itens[i][0] = i;
        std::cin >> itens[i][1] >> itens[i][2];
        std::cout << itens[i][0] << " ";
        std::cout << itens[i][1] << " ";
        std::cout << itens[i][2] << std::endl;
    }
    std::cout << std::endl;

    // marca o tempo de início
    auto start = std::chrono::high_resolution_clock::now();

    // embaralha o vetor dos itens e define o vetor da mochila
    std::shuffle(itens.begin(), itens.end(), std::default_random_engine{});
    std::vector<int> mochila;

    // enche a mochila até não caber mais nada ou acabarem os itens
    int peso_atual = 0;
    int valor_atual = 0;
    int quantidade_itens_mochila = 0;
    for (int i = 0; i < quantidade_itens; i++) {
        if (peso_atual + itens[i][1] <= capacidade_mochila) {
            mochila.push_back(itens[i][0]);
            peso_atual += itens[i][1];
            valor_atual += itens[i][2];
            quantidade_itens_mochila++;
        }
    }

    // marca o tempo de término e imprime o tempo de execução
    auto end = std::chrono::high_resolution_clock::now();\
    std::chrono::duration<double> duration = end - start;
    std::cout << "Tempo de execução: " << duration.count() << " segundos" << std::endl << std::endl;

    // imprime os resultados
    std::cout << "Mochila: ";
    for (int i = 0; i < quantidade_itens_mochila; i++) {
        std::cout << mochila[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Valor: " << valor_atual << std::endl;
    std::cout << "Peso: " << peso_atual << std::endl;

    return 0;
}