#include <iostream>

using namespace std;

// Número perfeito
int main() {
    int numero;
    
    cout << "Digite um número: ";
    cin >> numero;

    int soma = 0;
    for (int i = 1; i < numero; i++) {
        if (numero % i == 0) {
            soma += i;
        }
    }

    if (soma == numero) {
        cout << numero << " é um número perfeito." << endl;
    } else {
        cout << numero << " não é um número perfeito." << endl;
    }

    return 0;
}
