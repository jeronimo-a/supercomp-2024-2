#include <iostream>
#include <vector>

class Vector {
    public:
        void inserir(int index, int valor);
        void remover(int index);

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
    std::cout << vec.get(2) << std::endl;

    return 0;
}