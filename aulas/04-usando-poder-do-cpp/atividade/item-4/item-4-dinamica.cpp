#include <iostream>

class Vector {
    public:

        Vector(int tamanho) {
            capacidade = tamanho;
            dados = new int[capacidade];
        }

        ~Vector() {
            delete[] dados;
        }

        void inicializa(int valor) {
            for (int i = 0; i < capacidade; i++) {
                dados[i] = valor;
            }
        }

        int get(int index) const {
            if (index >= capacidade) {
                throw std::out_of_range("Índice grande demais");
            }
            return dados[index];
        }

        void set(int index, int valor) {
            if (index >= capacidade) {
                throw std::out_of_range("Índice grande demais");
            }
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
            for (int i = 0; i < capacidade; i++) {
                std::cout << dados[i] << " ";
            }
            std::cout << std::endl;
        }

        void multiplicar_por_escalar(int escalar) {
            for (int i = 0; i < capacidade; i++) {
                dados[i] *= escalar;
            }
        }

        int soma() {
            int s = 0;
            for (int i = 0; i < capacidade; i++) {
                s += dados[i];
            }
            return s;
        }

        int max() {
            int m = dados[0];
            for (int i = 1; i < capacidade; i++) {
                if (dados[i] > m) { m = dados[i]; }
            }
            return m;
        }

        int min() {
            int m = dados[0];
            for (int i = 1; i < capacidade; i++) {
                if (dados[i] < m) { m = dados[i]; }
            }
            return m;
        }

        double media() {
            int s = soma();
            return (double) s / (double) capacidade;
        }

    private:
        int* dados;
        int tam;
        int capacidade;
        void redimensiona(int novaCapacidade) {
            
            int* novosDados = new int(novaCapacidade);
            int copiarN = std::min(capacidade, novaCapacidade);
            for (int i = 0; i < novaCapacidade; i++) {
                novosDados[i] = dados[i];
            }

            capacidade = novaCapacidade;
            dados = novosDados;
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
    std::cout << vec.soma() << " ";
    std::cout << vec.max() << " ";
    std::cout << vec.min() << " ";
    std::cout << vec.media() << std::endl;

    return 0;
}