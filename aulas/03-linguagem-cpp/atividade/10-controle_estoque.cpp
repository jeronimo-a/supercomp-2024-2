#include <iostream>
#include <vector>

int main() {

    // definição dos vetores e variáveis
    int n_products = 0;
    std::vector<std::string> name(0);
    std::vector<int> ammount(0);
    std::vector<double> value(0);

    // definição das variáveis
    std::string command;
    int product_id;

    // variável de lixo
    std::string trash;

    // loop do programa
    while (true) {

        // solicitação de comando
        std::cout << "Insira um comando (sair, adicionar, atualizar, limpar, info): ";
        std::cin >> command;
        std::getline(std::cin, trash);

        // lida com o comando de saída
        if (command == "sair") { break; }
        
        // lida com o comando de acição
        if (command == "adicionar") {

            // aumenta os vetores
            n_products++;
            name.push_back("");
            ammount.push_back(NULL);
            value.push_back(NULL);
            
            // solicita o nome do item
            std::cout << "Insira o nome do produto: ";
            std::getline(std::cin, name[n_products - 1]);

            // apresenta o ID do item
            std::cout << "ID do item: " << n_products - 1 << std::endl;

            // reinicia o loop
            continue;
        }

        // lida com o comando de atualização
        if (command == "atualizar") {
            
            // solicita o ID do item
            std::cout << "Insira o ID do produto: ";
            std::cin >> product_id;
            std::getline(std::cin, trash);


            // verifica se o produto existe
            if (product_id >= n_products) {
                std::cout << "ID inválido" << std::endl;
                continue;
            }

            // solicita o item a atualizar
            std::cout << "Insira o item a atualizar (nome, quantidade, valor): ";
            std::cin >> command;
            std::getline(std::cin, trash);

            // atualiza o nome do produto
            if (command == "nome") {
                std::cout << "Insira o novo nome do produto: ";
                std::getline(std::cin, name[product_id]);
            }

            // atualiza a quantidade do produto
            else if (command == "quantidade") {
                std::cout << "Insira a nova quantidade do produto: ";
                std::cin >> ammount[product_id];
                std::getline(std::cin, trash);
            }

            // atualiza o valor do produto
            else if (command == "valor") {
                std::cout << "Insira o novo valor do produto: ";
                std::cin >> value[product_id];
                std::getline(std::cin, trash);
            }

            // lida com comandos inválidos
            else { std::cout << "Comando inválido" << std::endl; }

            // reinicia o loop
            continue;
        }

        // lida com o comando de limpar produto
        if (command == "limpar") {
            
            // solicita o ID do item
            std::cout << "Insira o ID do produto: ";
            std::cin >> product_id;
            std::getline(std::cin, trash);

            // verifica se o produto existe
            if (product_id >= n_products) {
                std::cout << "ID inválido" << std::endl;
                continue;
            }

            // limpa o produto (deleta a quantidade e o valor)
            ammount[product_id] = NULL;
            value[product_id] = NULL;

            // indica que o produto foi limpo
            std::cout << "Produto " << product_id << ": " << name[product_id];
            std::cout << " foi limpo." << std::endl;

            // reinicia o loop
            continue;
        }

        // lida com o comando de informações sobre produto
        if (command == "info") {
            
            // solicita o ID do item
            std::cout << "Insira o ID do produto: ";
            std::cin >> product_id;
            std::getline(std::cin, trash);

            // verifica se o produto existe
            if (product_id >= n_products) {
                std::cout << "ID inválido" << std::endl;
                continue;
            }

            // mostra as informações do produto
            std::cout << "Nome do produto: " << name[product_id] << std::endl;
            std::cout << "Quantidade: " << ammount[product_id] << std::endl;
            std::cout << "Valor: " << value[product_id] << std::endl;

            // reinicia o loop
            continue;
        }

        // lida com comandos inválidos
        std::cout << "Comando inválido" << std::endl;
    }

    return 0;
}