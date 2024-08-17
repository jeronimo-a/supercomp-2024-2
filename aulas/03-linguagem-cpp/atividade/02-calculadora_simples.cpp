#include <iostream>

int main() {

    // definição das variáveis
    int x, y;
    std::string op;

    // coleta das entradas
    std::cout << "Insira dois números: ";
    std::cin >> x >> y;
    std::cout << "Insira uma operação (soma, sub, mult, div): ";
    std::cin >> op;

    // cálculo e apresentação do resultado
    std::cout << "Resultado: ";
    if (op == "soma")       { std::cout << x + y; }
    else if (op == "sub")   { std::cout << x - y; }
    else if (op == "mult")  { std::cout << x * y; }
    else if (op == "div")   { std::cout << x / y; }
    std::cout << std::endl;

    return 0;
}