#include <iostream>
#include <vector>

int main() {

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

    return 0;
}