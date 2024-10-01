#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <chrono>
#include <cmath>

void incrementa_vetor_binario(std::vector<int> &vetor);
void soma_vetor_binario(std::vector<int> &vetor_a, std::vector<int> vetor_b, int tamanho, int vaium);

int main() {

    // coleta a soma desejada e a quantidade de números
    int soma_desejada;
    int quantidade_numeros;
    std::cin >> quantidade_numeros;
    std::cin >> soma_desejada;

    // coleta os números e associa um ID a cada um
    std::vector<std::vector<int>> numeros(quantidade_numeros, std::vector<int>(2));
    for (int i = 0; i < quantidade_numeros; i++) {
        numeros[i][0] = i;
        std::cin >> numeros[i][1];
    }

    // registra o momento de início da execução
    auto inicio = std::chrono::high_resolution_clock::now();

    // vetor da solução atual
    std::vector<int> solucao_atual(quantidade_numeros, 0);

    // loop de teste
    bool achou = false;
    while (true) {

        // verifica a solução atual
        int soma = 0;
        for (int i = 0; i < quantidade_numeros; i++) {
            if (solucao_atual[i] == 0) { continue; }
            soma += numeros[i][1];
            if (soma == soma_desejada) {
                achou = true;
                break;
            }
            if (soma > soma_desejada) {
                break;
            }
        }

        // verifica se percorreu todas as combinações oou se achou uma solução
        int teste = std::accumulate(solucao_atual.begin(), solucao_atual.end(), 0);
        if (teste == quantidade_numeros || achou) { break; }

        incrementa_vetor_binario(solucao_atual);
    }

    // registra o tempo de finalização
    auto fim = std::chrono::high_resolution_clock::now();

    // imprime a solução, se houver
    std::cout << "Quantidade de números: " << quantidade_numeros << std::endl;
    if (achou) {
        std::cout << "Solução encontrada: ";
        for (int i = 0; i < quantidade_numeros; i++) {
            if (solucao_atual[i]) {
                std::cout << i << "(" << numeros[i][1] << ") ";
            }
        }
        std::cout << std::endl;
    } else {
        std::cout << "Nenhuma solução encontrada" << std::endl;
    }

    // imprime o tempo de execução
    std::chrono::duration<double> duracao = fim - inicio;
    std::cout << "Tempo de execução: " << duracao.count() << " segundos" << std::endl << std::endl;

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