#include <iostream>
#include <string>
#include <iomanip> // Biblioteca para formatar a saída

using namespace std;

int main() {
    string nome;
    float salario;

    cout << "Informe seu nome:";
    getline(cin, nome);
    cout << "Informe seu salário:";
    cin >> salario;
    cout << fixed << setprecision(2);

    cout << "Seu nome é, " << nome << "e seu salário é de " << salario;

    return 0;
}