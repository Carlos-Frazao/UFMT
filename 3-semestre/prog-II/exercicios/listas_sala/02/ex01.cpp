#include <iostream>
#include <string>

using namespace std;

int main() {
    string nome;
    int idade;

    cout << "Informe seu nome completo: ";
    getline(cin, nome);
    cout << "Informe sua idade: ";
    cin >> idade;

    cout << "Nome: " << nome << endl;
    cout << "Idade: " << idade << endl;

    return 0;
}