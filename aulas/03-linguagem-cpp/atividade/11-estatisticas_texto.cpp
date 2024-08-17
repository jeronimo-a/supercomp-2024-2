#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

/*
Lê um arquivo de texto e calcula as seguintes estatísticas
- Número de palavras
- Número de linhas
- Número médio de palavras por linha
- Palavra mais frequente

E as escreve em um novo arquivo de texto
*/

int main() {

    // variável do nome do arquivo de entrada
    std::string filename;

    // coleta o nome do arquivo de texto
    std::cout << "Insira o nome do arquivo de texto: ";
    std::cin >> filename;

    // abre o arquivo de entrada
    std::ifstream fileread(filename);
    if (!fileread) {
        std::cerr << "Não foi possível abrir o arquivo " << filename << std::endl;
        return 1;
    }

    // variáveis das estatísticas
    int total_words = 0;
    int total_lines = 0;
    double words_per_line_average = 0;
    std::string most_frequent_word;

    // dicionário de contagem de quantidade de occorências das palavras
    std::map<std::string, int> word_count_dict;

    // variável da linha atual
    std::string current_line;

    // percorre o arquivo linha por linha
    while (std::getline(fileread, current_line)) {

        total_lines++;  // incrementa o número total de linhas
        
        // variáveis de separação da linha em palavras
        std::string current_word;
        std::istringstream current_line_stream(current_line);

        // percorre palavra por palavra da linha
        while (current_line_stream >> current_word) {
            
            total_words++;  // incrementa o número total de palavras

            // cria a chave da palavra no dicionário de contagem se não existir ainda
            if (word_count_dict.find(current_word) == word_count_dict.end()) {
                word_count_dict[current_word] = 0;
            }

            // incrementa a contagem da palavra
            word_count_dict[current_word]++;
        }
    }

    // fecha o arquivo de entrada
    fileread.close();

    // verifica qual a palavra mais frequente
    int highest_frequency = 0;
    for (auto i = word_count_dict.begin(); i != word_count_dict.end(); i++) {
        if (i->second > highest_frequency) {
            most_frequent_word = i->first;
            highest_frequency = i->second;
        }
    }

    // calcula a quantidade média de palavras por linha
    words_per_line_average = (double) total_words / (double) total_lines;

    // cria o arquivo de saída
    std::ofstream filewrite(filename + ".stats");
    if (!filewrite) {
        std::cerr << "Não foi possível criar o arquivo de saída " << filename + ".stat" << std::endl;
        return 1;
    }

    // imprime as estatísticas no arquivo de saída
    filewrite << "Número total de palavras: " << total_words << std::endl;
    filewrite << "Número total de linhas: " << total_lines << std::endl;
    filewrite << "Número médio de palavras por linha: " << words_per_line_average << std::endl;
    filewrite << "Palavra mais frequente: " << most_frequent_word << std::endl;    

    return 0;
}