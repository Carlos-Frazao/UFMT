#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Informe um número inteiro positivo: ";
    cin >> n;

    // Verificando se é positivo
    if (n > 0) {
        cout << "C";
    } else {
        cout << "Informe um número inteiro!\n";
        return 1;
    }
    return 0;
}