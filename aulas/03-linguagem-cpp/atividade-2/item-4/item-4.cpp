#include <iostream>
#include <vector>

class Vector {
    public:

        Vector(int tamanho) {
            capacidade = tamanho;
        }

        void inicializa(int valor) {
            dados = std::vector<int>(capacidade, valor);
        }

        int get(int index) const {
            return dados[index];
        }

        void set(int index, int valor) {
            dados[index] = valor;
        }

        void inserir(int index, int valor) {
            redimensiona(capacidade + 1);
            for (int i = capacidade - 1; i > index; i--) {
                dados[i] = dados[i - 1];
            }
            dados[index] = valor;
        }

        void remover(int index) {
            for (int i = index; i < capacidade - 1; i++) {
                dados[i] = dados[i + 1];
            }
            redimensiona(capacidade - 1);
        }

        void imprime() const {
            for (int valor : dados) {
                std::cout << valor << " ";
            }
            std::cout << std::endl;
        }

    private:
        std::vector<int> dados;
        int tam;
        int capacidade;
        void redimensiona(int novaCapacidade) {
            capacidade = novaCapacidade;
            dados.resize(capacidade);
        }
};

// Implementação das funções...

int main() {
    Vector vec(5);
    vec.inicializa(3);
    vec.set(4, 10);
    vec.set(2, 666);
    vec.imprime();
    vec.inserir(3, 7878);
    vec.imprime();
    vec.remover(2);
    vec.imprime();
    std::cout << vec.get(2) << std::endl;

    return 0;
}