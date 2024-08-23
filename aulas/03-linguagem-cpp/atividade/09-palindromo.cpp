#include <iostream>

int main() {

    // definição das variáveis
    std::string x;
    bool p = true;

    // coleta da entrada do usuário
    std::cout << "Insira uma palavra: ";
    std::cin >> x;

    // verifica se é palíndromo
    int n = x.size();
    int m = n / 2 + n % 2;
    for (int i = 0; i < n; i++) {
        p = p and (x[i] == x[n - 1 - i]);
    }

    // apresenta se é palíndromo ou não
    std::cout << "A palavra " << x << " ";
    if (!p) { std::cout << "não "; }
    std::cout << "é um palíndromo." << std::endl;

    return 0;
}