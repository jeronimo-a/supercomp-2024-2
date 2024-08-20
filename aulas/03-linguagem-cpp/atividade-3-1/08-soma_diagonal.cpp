#include <iostream>
#include <vector>

#define SIZE 3

int main() {

    // definição da matriz e da variável da soma
    std::vector<std::vector<int>> matrix(SIZE, std::vector<int>(SIZE));
    int sum = 0;

    // coleta da entrada do usuário
    for (int i = 0; i < SIZE; i++) {
        std::cout << "Insira " << SIZE << " números na " << i + 1 << "a linha: ";
        for (int j = 0; j < SIZE; j++) {
            std::cin >> matrix[i][j];
        }
    }

    // calcula a soma da diagonal principal
    for (int i = 0; i < SIZE; i++) {
        sum += matrix[i][i];
    }

    // apresenta o resultado
    std::cout << "Soma da diagonal principal: " << sum << std::endl;

    return 0;
}