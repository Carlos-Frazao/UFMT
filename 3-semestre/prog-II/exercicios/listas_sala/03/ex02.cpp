#include <iostream>

using namespace std;

int main() {
    int saldo = 1000;
    int opcao;

    cout << "Menu:" << endl;
    cout << "1. Ver Saldo" << endl;
    cout << "2. Depositar" << endl;
    cout << "3. Sacar" << endl;
    cout << "4. Sair" << endl;

    cin >> opcao;

    switch (opcao) {
        case 1:
            cout << "Saldo atual: " << saldo << endl;
            break;
        case 2: {
            int deposito;
            cout << "Digite o valor a depositar: ";
            cin >> deposito;
            saldo += deposito;
            cout << "Novo saldo: " << saldo << endl;
            break;
        }
        case 3: {
            int saque;
            cout << "Digite o valor a sacar: ";
            cin >> saque;
            if (saque > saldo) {
                cout << "Saldo insuficiente!" << endl;
            } else {
                saldo -= saque;
                cout << "Novo saldo: " << saldo << endl;
            }
            break;
        }
        case 4:
            cout << "Saindo..." << endl;
            break;
        default:
            cout << "Opção inválida!" << endl;
    }

    return 0;
}