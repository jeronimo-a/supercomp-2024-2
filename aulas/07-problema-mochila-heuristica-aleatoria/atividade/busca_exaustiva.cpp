#include <iostream>
#include <vector>
#include <chrono>
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

    // imprime a quantidade de itens
    std::cout << "Quantidade de itens: " << quantidade_itens << std::endl;

    // define o vetor que representa a mochila, mochila[i] == 0 => item 1 não está na mochila
    std::vector<int> mochila(quantidade_itens, 0);

    // variável de valor máximo encontrado e a respectiva mochila
    int valor_maximo = 0;
    int peso_mochila_maxima = 0;
    std::vector<int> mochila_maxima(quantidade_itens, 0);

    // marca o tempo de início
    auto start = std::chrono::high_resolution_clock::now();

    // loop que encontra o valor máximo
    for (int i = 0; i < pow(2, quantidade_itens) - 1; i++) {

        // incrementa o vetor da mochila como se fosse um binário
        incrementa_vetor_binario(mochila);

        // define as variáveis do peso e do valor atual
        int valor_atual = 0;
        int peso_atual = 0;

        // loop de incrementação do peso e do valor
        for (int j = 0; j < quantidade_itens; j++) {

            // se o item não tiver na mochila, pula
            if (!mochila[j]) { continue; }

            // incrementa o valor
            peso_atual += itens[j][1];

            // verifica se o item cabe na mochila, caso couber, soma ao valor do peso e continua
            if (peso_atual > capacidade_mochila) { break; }
            valor_atual += itens[j][2];
        }

        // se for o caso, atualiza o valor e os itens da mochila mais valiosa
        if (valor_atual > valor_maximo && peso_atual <= capacidade_mochila) {
            valor_maximo = valor_atual;
            peso_mochila_maxima = peso_atual;
            std::copy(mochila.begin(), mochila.end(), mochila_maxima.begin());
        }
    }

    // marca o tempo de término e imprime o tempo de execução
    auto end = std::chrono::high_resolution_clock::now();\
    std::chrono::duration<double> duration = end - start;
    std::cout << "Tempo de execução: " << duration.count() << " segundos" << std::endl << std::endl;

    // imprime os resultados
    std::cout << "Mochila: ";
    for (int i = 0; i < quantidade_itens; i++) {
        std::cout << mochila_maxima[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Valor: " << valor_maximo << std::endl;
    std::cout << "Peso: " << peso_mochila_maxima << std::endl;

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

    // soma o vetor unitário ao vetor atual
    soma_vetor_binario(vetor_copia, vetor_1, tamanho, 0);

    std::copy(vetor_copia.begin(), vetor_copia.end(), vetor.begin());
}

void soma_vetor_binario(std::vector<int> &vetor_a, std::vector<int> vetor_b, int tamanho, int vaium) {
    // soma o vetor_b ao vetor_a (ALTERA O VETOR A)
    
    // base
    if (tamanho == 0) { return; }

    // passo
    int a = vetor_a[tamanho - 1];
    int b = vetor_b[tamanho - 1];
    int vaium_prox = a + b + vaium >= 2;
    vetor_a[tamanho - 1] = (a + b + vaium) % 2 == 1;

    soma_vetor_binario(vetor_a, vetor_b, tamanho - 1, vaium_prox);
}