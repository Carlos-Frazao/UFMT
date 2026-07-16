#include <iostream>
#include <string>
#include <iomanip>

class ContaBancaria {
private:
    std::string numeroConta;
    double saldo;
    std::string titular;

public:
    // Construtor 1 (Com saldo inicial)
    ContaBancaria(const std::string& conta, double saldoInicial, const std::string& nomeTitular) :
        numeroConta(conta), saldo(saldoInicial), titular(nomeTitular) {}

    // Construtor 2 (Sem saldo, inicializa com 0.0)
    ContaBancaria(const std::string& conta, const std::string& nomeTitular) :
        numeroConta(conta), saldo(0.0), titular(nomeTitular) {}

    // Métodos Get 
    std::string getNumeroConta() const { return numeroConta; }
    double getSaldo() const { return saldo; }
    std::string getTitular() const { return titular; }

    // Métodos Set (apenas Titular pode ser alterado por set, conta e saldo não via set) 
    void setTitular(const std::string& novoTitular) { titular = novoTitular; }

    // Métodos de Operação 
    void depositar(double valor) {
        if (valor > 0) {
            saldo += valor;
        }
    }

    double sacar(double valor) {
        if (valor > 0 && saldo >= valor) {
            saldo -= valor;
            return valor;
        }
        return 0.0; // Indica falha no saque
    }

    // Mostrar Dados 
    void mostrarDados() const {
        std::cout << "Conta: " << numeroConta
                  << ", Titular: " << titular
                  << ", Saldo: " << std::fixed << std::setprecision(2) << saldo
                  << std::endl;
    }
};

int main() {
    ContaBancaria c1("12345 -6", 1000.0 , "Joao Silva");
    c1.mostrarDados (); // Conta: 12345-6, Titular: Joao Silva , Saldo: 1000

    c1.depositar (500.0);
    auto valor = c1.sacar (300.0);
    if (valor > 0)
        std::cout << "Saque de R$"<< valor << " efetuado com sucesso"<<std
            ::endl;
    else
        std::cout << "Saldo insuficiente" << std::endl;

    c1.mostrarDados (); // Conta: 12345-6, Titular: Joao Silva , Saldo: 1200

    ContaBancaria c2("789-0", "Pedro Martins");
    c2.mostrarDados (); // Conta: 789-0, Titular: Pedro Martins , Saldo: 0
    auto valor2 = c2.sacar (100.0);
    //Idem ao feito na tentativa anterior
    if (valor2 > 0) {
        std::cout << "Saque de R$" << std::fixed << std::setprecision(2) << valor2 << " efetuado com sucesso" << std::endl;
    } else {
        std::cout << "Saldo insuficiente" << std::endl; // Saída esperada aqui
    }

    return 0;
}
