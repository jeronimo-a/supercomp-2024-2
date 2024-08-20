#include <iostream>

int main() {

    // definição das variáveis
    int x;

    // coleta da entrada do usuário
    std::cout << "Insira um número: ";
    std::cin >> x;

    // verifica se é par ou ímpar e apresenta o resultado
    std::cout << "Resultado: ";
    if (x % 2 == 1) { std::cout << "ímpar"; }
    else            { std::cout << "par"; }
    std::cout << std::endl;

    return 0;
}