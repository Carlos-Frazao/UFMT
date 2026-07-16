#include <iostream>

using namespace  std;

int main() {
    int n, soma = 0;

    cout << "Informe um número: ";
    cin >> n;

    if (n < 0) {
        cout << "Informe um valor positivo!\n";
        return 1;
    }

    int numero = n;

    while (numero > 0) {
        soma += numero % 10;
        numero /=10;
    }

    cout << "A soma dos dígitos de " << n << " é: " << soma << "\n";
    
    return 0;
}