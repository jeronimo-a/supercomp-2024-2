#include <iostream>
#include <vector>
#include <random>

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

    // imprime os resultados
    std::cout << "Mochila aleatória por chance de inclusão: ";
    for (int i = 0; i < quantidade_itens; i++) {
        std::cout << mochila[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Valor: " << valor << std::endl;
    std::cout << "Peso: " << peso << "/" << capacidade_mochila << std::endl <<std::endl;

    // forçando o preenchimento completo
    for (int i = 0; i < quantidade_itens; i++) {
        if (mochila[i]) { continue; }
        if (itens[i][1] + peso > capacidade_mochila) { continue; }
        peso += itens[i][1];
        valor += itens[i][2];
        mochila[i] = 1;
    }

    // imprime os resultados
    std::cout << "Mochila com preenchimento completo forçado: ";
    for (int i = 0; i < quantidade_itens; i++) {
        std::cout << mochila[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Valor: " << valor << std::endl;
    std::cout << "Peso: " << peso << "/" << capacidade_mochila << std::endl <<std::endl;

    // substituição
    for (int i = 0; i < quantidade_itens; i++) {
        if (mochila[i]) { continue; }
        for (int j = 0; j < quantidade_itens; j++) {
            if (i == j) { continue; }
            if (!mochila[j]) { continue; }
            if (itens[j][2] >= itens[i][2]) { continue; }
            if (peso - itens[j][1] + itens[i][1] <= capacidade_mochila) {
                std::cout << i << " sub " << j << std::endl;
                mochila[j] = 0;
                mochila[i] = 1;
                peso -= itens[j][1];
                peso += itens[i][1];
                valor -= itens[j][2];
                valor += itens[i][2];
                break;
            }
        }
    }

    // imprime os resultados
    std::cout << "Mochila com preenchimento completo forçado e substituição: ";
    for (int i = 0; i < quantidade_itens; i++) {
        std::cout << mochila[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Valor: " << valor << std::endl;
    std::cout << "Peso: " << peso << "/" << capacidade_mochila << std::endl <<std::endl;

    return 0;
}