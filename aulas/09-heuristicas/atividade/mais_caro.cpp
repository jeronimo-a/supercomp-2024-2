#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    // lê a quantidade de itens e capacidade da mochila
    int quantidade_itens;
    int capacidade_mochila;
    cin >> quantidade_itens >> capacidade_mochila;

    // lê os pesos e valores de cada item
    vector<vector<int>> itens(quantidade_itens, vector<int>(3, 0));
    for (int i = 0; i < quantidade_itens; i++) {
        itens[i][0] = i;
        cin >> itens[i][1] >> itens[i][2];
    }

    // ordena os itens conforme o valor
    sort(itens.begin(), itens.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] > b[2];
    });

    // percorre todos os itens ordenados pelo valor e inclui na mochila se couber
    int peso = 0;
    int valor = 0;
    vector<int> mochila(quantidade_itens, 0);
    for (int i = 0; i < quantidade_itens; i++) {
        if (peso + itens[i][1] <= capacidade_mochila) {
            peso += itens[i][1];
            valor += itens[i][2];
            mochila[itens[i][0]] = 1;
        }
    }

    // imprime os resultados
    cout << "Solução: ";
    for (int i = 0; i < quantidade_itens; i++) {
        cout << mochila[i] << " ";
    }
    cout << endl << "Valor:   " << valor << endl;
    cout << "Peso:    " << peso << "/" << capacidade_mochila << endl;

    return 0;
}