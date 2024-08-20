#include <iostream>   // Inclui a biblioteca padrão de entrada e saída, usada para operações como std::cout.
#include <fstream>    // Inclui a biblioteca para manipulação de arquivos, usada para ler e escrever arquivos.
#include <vector>     // Inclui a biblioteca de vetores, usada para armazenar e manipular listas de números.

// Declaração de funções:

// Função que lê números de um arquivo e os armazena em um vetor.
int lerArquivo(const std::string& nomeArquivo, std::vector<int>& numeros);

// Função que dobra os valores de um vetor de números, passando o vetor original por referência.
int dobrarValoresReferencia(const std::vector<int>& numerosOriginais, std::vector<int>& numerosDobrados);

// Função que dobra os valores de um vetor de números, passando o vetor original por ponteiro.
int dobrarValoresPonteiro(const std::vector<int>* numerosOriginais, std::vector<int>* numerosDobrados);

// Função que escreve os números de um vetor em um arquivo.
int escreverArquivo(const std::string& nomeArquivo, const std::vector<int>& numeros);

// Implementação das funções...

int main() {
    
    // Declaração dos vetores de entrada e de saída e da variável de erro
    std::vector<int> numeros, numerosDobrados;
    int erro;

    // Chama a função para ler os números do arquivo "entrada.txt" e armazena-os no vetor 'numeros'.
    erro = lerArquivo("entrada.txt", numeros);
    if (erro) {
        std::cerr << "Não foi possível ler o arquivo \"entrada.txt\".";
        return 1;
    }

    // Chama a função que dobra os valores do vetor 'numeros' usando passagem por referência e armazena o resultado no vetor 'numerosDobrados'.
    erro = dobrarValoresReferencia(numeros, numerosDobrados);
    if (erro) {
        std::cerr << "Erro ao dobrar os valores por referência.";
        return 1;
    }

    // Chama a função que escreve os números do vetor 'numerosDobrados' no arquivo "saida_referencia.txt".
    erro = escreverArquivo("saida_referencia.txt", numerosDobrados);
    if (erro) {
        std::cerr << "Não foi possível escrever no arquivo \"saida_referencia.txt\".";
        return 1;
    }

    // Chama a função que dobra os valores do vetor 'numeros' usando passagem por ponteiro e armazena o resultado no vetor 'numerosDobrados'.
    erro = dobrarValoresPonteiro(&numeros, &numerosDobrados);
    if (erro) {
        std::cerr << "Erro ao dobrar os valores por ponteiro.";
        return 1;
    }

    // Chama a função que escreve os números do vetor 'numerosDobrados' no arquivo "saida_ponteiro.txt".
    erro = escreverArquivo("saida_ponteiro.txt", numerosDobrados);
    if (erro) {
        std::cerr << "Não foi possível escrever no arquivo \"saida_ponteiro.txt\".";
        return 1;
    }

    // Retorna 0, indicando que o programa terminou com sucesso.
    return 0;
}

int lerArquivo(const std::string& nomeArquivo, std::vector<int>& numeros) {
    return 0;
}


int dobrarValoresReferencia(const std::vector<int>& numerosOriginais, std::vector<int>& numerosDobrados) {
    return 0;
}

int dobrarValoresPonteiro(const std::vector<int>* numerosOriginais, std::vector<int>* numerosDobrados) {
    return 0;
}

int escreverArquivo(const std::string& nomeArquivo, const std::vector<int>& numeros) {
    return 0;
}