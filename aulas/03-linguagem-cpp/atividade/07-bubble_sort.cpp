#include <iostream>
#include <vector>

#define SIZE 10

void swap(std::vector<int>& v, int m, int n) {
    // troca os valores de v[m] e v[n]
    v[m] += v[n];
    v[n] = v[m] - v[n];
    v[m] -= v[n];
}

void bubble_sort(std::vector<int>& v) {
    // aplica o bubble sort no vetor

    int n = v.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) { swap(v, j, j + 1); }
        }
    }

}

int main() {

    // definição das variáveis
    std::vector<int> v(SIZE);
    int sum = 0;

    // coleta da entrada do usuário
    std::cout << "Insira " << SIZE << " números: ";
    for (int i = 0; i < SIZE; i++) {
        std::cin >> v[i];
    }

    // ordena o vetor por bubble sort
    bubble_sort(v);

    // apresenta o resultado
    std::cout << "Em ordem: ";
    for (int i = 0; i < SIZE; i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}