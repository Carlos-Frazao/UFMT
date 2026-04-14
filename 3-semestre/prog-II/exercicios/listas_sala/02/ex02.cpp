#include <iostream>
#include <string>

using namespace std;

int main() {
    int idade;
    float altura;
    string nome;

    cout << "Informe seu nome completo: ";
    getline(cin, nome);
    cout << "Informe sua idade:  ";
    cin >> idade;
    cout << "Informe seu peso:";
    cin >> altura;



    cout << "Seu nome: " << nome << endl;
    cout << "Sua idade: " << idade << endl;
    cout << "Sua altura:" << altura << endl;
    return 0;
}