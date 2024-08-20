#include <iostream>
#include <vector>

class Vector {
    public:
        int get(int index) const;
        void set(int index, int valor);
        void inserir(int index, int valor);
        void remover(int index);

        Vector(int tamanho) {
            capacidade = tamanho;
        }

        void inicializa(int valor) {
            dados = std::vector<int>(capacidade, valor);
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
        void redimensiona(int novaCapacidade);
};

// Implementação das funções...

int main() {
    Vector vec(5);
    vec.inicializa(0);
    vec.imprime();

    return 0;
}