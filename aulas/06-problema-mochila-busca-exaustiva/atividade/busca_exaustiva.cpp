#include <iostream>
#include <vector>
#include <cmath>

void incrementa_vetor_binario(std::vector<int> &vetor);
void soma_vetor_binario(std::vector<int> &vetor_a, std::vector<int> vetor_b, int tamanho, int vaium);

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

    // define o vetor que representa a mochila, mochila[i] == 0 => item 1 não está na mochila
    std::vector<int> mochila(quantidade_itens, 0);

    // variável de valor máximo encontrado
    int valor_maximo = 0;
    std::vector<int> mochila_maxima(quantidade_itens, 0);

    // loop que encontra o valor máximo
    for (int i = 0; i < pow(2, quantidade_itens) - 1; i++) {
        incrementa_vetor_binario(mochila);
        for (int i = 0; i < quantidade_itens; i++) {
            std::cout << mochila[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

void incrementa_vetor_binario(std::vector<int> &vetor) {

    // copia o vetor
    int tamanho = vetor.size();
    std::vector<int> vetor_copia(tamanho);
    std::copy(vetor.begin(), vetor.end(), vetor_copia.begin());

    // cria o vetor unitário
    std::vector<int> vetor_1(tamanho, 0);
    vetor_1[tamanho - 1] = 1;

    soma_vetor_binario(vetor_copia, vetor_1, tamanho, 0);

    std::copy(vetor_copia.begin(), vetor_copia.end(), vetor.begin());
}

void soma_vetor_binario(std::vector<int> &vetor_a, std::vector<int> vetor_b, int tamanho, int vaium) {
    
    // base
    if (tamanho == 0) { return; }

    // passo
    int a = vetor_a[tamanho - 1];
    int b = vetor_b[tamanho - 1];
    int vaium_prox = a + b + vaium >= 2;
    vetor_a[tamanho - 1] = (a + b + vaium) % 2 == 1;

    soma_vetor_binario(vetor_a, vetor_b, tamanho - 1, vaium_prox);
}