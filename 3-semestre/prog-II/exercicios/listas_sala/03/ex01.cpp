#include <iostream>

using namespace std;

int main() {
    int idade, opcao;

    cout << "Sistema de validação com regras encadeadas." << endl;
    cout << "Qual sua idade? ";
    cin >> idade;

    if (idade < 16) {
        cout << "Acesso negado.";
    } else if (idade >= 16 && idade < 17) {
        cout << "Acesso permitido com restrições.";
    } else if (idade >= 18) {
        cout << "Acesso com níveis.:";
        cout << "Escolha um nível de acesso: ";
        cout << "1. Básico, 2. Intermediário e 3. total.";
        cin >> opcao;
        switch (opcao) {
            case 1:
                cout << "Acesso ao nível básico.";
                break;
            case 2:
                cout << "Acesso ao nível intermediário.";
                break;
            case 3:
                cout << "Acesso total.";
                break;
            default:
                cout << "Opção inválida.";
        }
    } else {
        cout << "Acesso negado.";
    }

    return 0;
}