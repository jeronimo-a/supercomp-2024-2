#include <iostream>
#include <vector>

#define SIZE 5

int main() {

    // definição das variáveis
    std::vector<int> v(SIZE);
    int sum = 0;

    // coleta da entrada do usuário
    std::cout << "Insira " << SIZE << " números: ";
    for (int i = 0; i < SIZE; i++) {
        std::cin >> v[i];
    }

    // calcula a soma
    for (int i = 0; i < SIZE; i++) {
        sum += v[i];
    }

    // apresenta o resultado
    std::cout << "Soma: " << sum << std::endl;

    return 0;
}