#include <iostream>
#include <string>

using namespace std;

class ContaBancaria {
private:
    string numeroConta;
    double saldo;

public:
    // Construtor
    ContaBancaria(string numConta) {
        numeroConta = numConta;
        saldo = 0.0; // Saldo iniciado em 0
    }

    // Getter para o saldo
    double getSaldo() {
        return saldo;
    }

    // Método para depositar
    void depositar(double valor) {
        if (valor > 0) {
            saldo += valor;
            cout << "Deposito de R$" << valor << " realizado." << endl;
        } else {
            cout << "Erro: O valor de deposito deve ser positivo." << endl;
        }
    }

    // Método para sacar
    void sacar(double valor) {
        if (valor > 0 && valor <= saldo) {
            saldo -= valor;
            cout << "Saque de R$" << valor << " realizado." << endl;
        } else {
            cout << "Erro: Saque invalido ou saldo insuficiente." << endl;
        }
    }
};

int main() {
    ContaBancaria conta("12345-6");
    
    cout << "Saldo inicial: R$" << conta.getSaldo() << endl;

    conta.depositar(150.50);
    cout << "Saldo atual: R$" << conta.getSaldo() << endl;

    conta.sacar(50.00);
    cout << "Saldo atual: R$" << conta.getSaldo() << endl;

    // Tentativa de sacar mais do que tem
    conta.sacar(200.00); 

    return 0;
}