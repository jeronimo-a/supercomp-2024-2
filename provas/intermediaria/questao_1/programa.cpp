#include <algorithm>
#include <iostream>
#include <vector>

bool criterio(const std::vector<int>& a, const std::vector<int>& b);            // função que define o critério de ordenação
bool solucao(const std::vector<std::vector<int>>& numeros, int soma_desejada);  // função que monta uma solução e a testa

int main() {

    // coleta a soma desejada e a quantidade de números
    int soma_desejada;
    int quantidade_numeros;
    std::cin >> quantidade_numeros;
    std::cin >> soma_desejada;

    // coleta os números e associa um ID a cada um
    std::vector<std::vector<int>> numeros(quantidade_numeros, std::vector<int>(2));
    for (int i = 0; i < quantidade_numeros; i++) {
        numeros[i][0] = i;
        std::cin >> numeros[i][1];
    }

    // ordena os números por ordem decrescente
    std::sort(numeros.begin(), numeros.end(), criterio);

    // verifica se a heurística gerou uma solução adequada
    bool resultado = solucao(numeros, soma_desejada);

    // imprime o resultado
    std::cout << resultado << std::endl;

    return 0;
}

// função que define o critério de ordenação dos números
bool criterio(const std::vector<int>& a, const std::vector<int>& b) {
    return a[1] > b[1];
}

// função que monta uma solução e a testa
bool solucao(const std::vector<std::vector<int>>& numeros, int soma_desejada) {

    // variável de acumulação da soma e matriz da solução
    int soma = 0;
    std::vector<std::vector<int>> solucao;

    // loop de inclusão dos valores na soma
    for (int i = 0; i < numeros.size(); i++) {
        if (soma + numeros[i][1] <= soma_desejada) {
            soma += numeros[i][1];
            solucao.push_back(numeros[i]);
        }
        if (soma == soma_desejada) {
            return true;
        }
    }

    return false;
}