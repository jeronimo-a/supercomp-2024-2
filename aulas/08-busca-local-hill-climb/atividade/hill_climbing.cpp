#include <iostream>
#include <vector>
#include <random>

int calcula_valor(std::vector<int> mochila, std::vector<std::vector<int>> itens);
int calcula_peso(std::vector<int> mochila, std::vector<std::vector<int>> itens);

int main() {

    // cria o gerados de números aleatórios
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0.0, 1.0);

    // faz a leitura do tamanho da quantidade de itens e capacidade da mochila
    int quantidade_itens, capacidade_mochila;
    std::cin >> quantidade_itens >> capacidade_mochila;

    // define a matriz que contém todos os itens, itens[n] = [id, peso, valor]
    std::vector<std::vector<int>> itens(quantidade_itens, std::vector<int>(3));

    // faz a leitura dos valores e pesos de cada item
    for (int i = 0; i < quantidade_itens; i++) {
        itens[i][0] = i;
        std::cin >> itens[i][1] >> itens[i][2];
    }

    // percorre cada item, com 50% de chance de incluir cada um, se ele couber
    int peso = 0;
    int valor = 0;
    std::vector<int> mochila(quantidade_itens, 0);
    for (int i = 0; i < quantidade_itens; i++) {
        double random = distribution(generator);
        if (random <= 0.5) { continue; }
        if (peso + itens[i][1] > capacidade_mochila) { continue; }
        peso += itens[i][1];
        valor += itens[i][2];
        mochila[i] = 1;
    }

    // loop de hill climbing
    while (true) {

        int valor_maximo = calcula_valor(mochila, itens);
        std::vector<int> mochila_maxima;
        int alterou = 0;

        for (int i = 0; i < quantidade_itens; i++) {
            if (mochila[i]) { continue; }
            std::vector<int> nova_mochila(mochila);
            nova_mochila[i] = 1;
            if (calcula_peso(nova_mochila, itens) > capacidade_mochila) { continue; }
            int novo_valor = calcula_valor(nova_mochila, itens);
            if (novo_valor > valor_maximo) {
                valor_maximo = novo_valor;
                mochila_maxima = nova_mochila;
                alterou = 1;
            }
        }

        if (!alterou) { break; }

        mochila = mochila_maxima;
        valor = valor_maximo;
    }

    // imprime os resultados
    std::cout << "Mochila: ";
    for (int i = 0; i < quantidade_itens; i++) {
        std::cout << mochila[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Valor: " << valor << std::endl;
    std::cout << "Peso: " << peso << std::endl;

    return 0;
}

int calcula_valor(std::vector<int> mochila, std::vector<std::vector<int>> itens) {

    int resultado = 0;

    for (int i = 0; i < itens.size(); i++) {
        resultado += itens[i][2];
    }

    return resultado;
}

int calcula_peso(std::vector<int> mochila, std::vector<std::vector<int>> itens) {

    int resultado = 0;

    for (int i = 0; i < itens.size(); i++) {
        resultado += itens[i][1];
    }

    return resultado;
}