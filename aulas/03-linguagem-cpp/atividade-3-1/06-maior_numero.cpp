#include <iostream>
#include <vector>

#define SIZE 5

int main() {

    // definição das variáveis
    std::vector<int> v(SIZE);
    int max = 0;

    // coleta da entrada do usuário
    std::cout << "Insira " << SIZE << " números: ";
    for (int i = 0; i < SIZE; i++) {
        std::cin >> v[i];
    }

    // encontra o valor máximo
    max = v[0];
    for (int i = 1; i < SIZE; i++) {
        if (v[i] > max) { max = v[i]; }
    }

    // apresenta o resultado
    std::cout << "Valor máximo: " << max << std::endl;

    return 0;
}