#include <iostream>

int main() {

    // definição das variáveis
    std::string x;

    // coleta da entrada do usuário
    std::cout << "Insira uma frase: ";
    std::getline(std::cin, x);

    // retorna o tamanho da string
    std::cout << x.size() << std::endl;

    return 0;
}