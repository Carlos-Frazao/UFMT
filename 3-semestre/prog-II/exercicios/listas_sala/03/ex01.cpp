#include <iostream>

using namespace std;

int main() {
    int idade;

    cout << "Sistema de validação com regras encadeadas." << endl;
    cout << "Qual sua idade? ";
    cin >> idade;

    if (idade < 16) {
        cout << "Acesso negado.";
    }

    return 0;
}