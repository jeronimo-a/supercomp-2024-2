#include <iostream>   // Inclui a biblioteca padrão de entrada e saída, usada para operações como std::cout.
#include <chrono>     // Inclui a biblioteca para medição de tempo, usada para medir a performance do código.
#include <vector>

int main() {

    // Marca o tempo de início
    auto start = std::chrono::high_resolution_clock::now();
    
    // Cria a matriz usando vector
    int N = 30000;
    std::vector<std::vector<int>> matriz(N, std::vector<int>(N, 1));

    // Soma todos os elementos da matriz
    int soma = 0;
    for (auto& linha : matriz) {
        for (int valor : linha) {
            soma += valor;
        }
    }

    // Marca o tempo de término e calcula o tempo total
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Tempo total de execução da alocação dinâmica: " << duration.count() << std::endl;

    return 0;  // Retorna 0, indicando que o programa terminou com sucesso.
}