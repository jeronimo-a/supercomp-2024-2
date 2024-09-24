#include <cmath>
#include <chrono>
#include <vector>
#include <iostream>

int main() {

    // lê o tamanho do arquivo de entrada
    int size;
    std::cin >> size;

    // lê o arquivo de entrada
    std::vector<float> v_host(size);
    for (int i = 0; i < size; i++) {
        std::cin >> v_host[i];
    }

    // inicia a marcação do tempo
    auto start = std::chrono::steady_clock::now();

    // realiza a operação
    float v2_sum = 0.0;
    for (int i = 0; i < v_host.size(); i++) {
        v2_sum += v_host[i] * v_host[i];
    }
    float v_norm = std::sqrt(v2_sum);

    // termina a marcação do tempo
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration = end - start;

    // imprime os resultados
    std::cout << "Tamanho do vetor:  " << v_host.size() << std::endl;
    std::cout << "Norma do vetor:    " << v_norm << std::endl;
    std::cout << "Tempo de execução: " << duration.count() << " s" << std::endl;

    return 0;
}