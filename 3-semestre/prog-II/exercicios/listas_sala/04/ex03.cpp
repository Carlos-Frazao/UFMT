#include <iostream>

using namespace std;

inline double conversor(double x) {
    double taxa = 5.05;
    
    return x * taxa;
}

int main() {
    // Declarar variáveis 
    float dolares;

    // Entrada de dados 
    cout << "Informe a quantidade em dolares, a ser convertida: ";
    cin >> dolares;

    // Saída de dados
    cout << "A quantia convertida em reais e: R$ " << conversor(dolares) << endl;
    return 0;
}

/*Escreva um programa que solicite ao usuário digitar uma quantida em dólares que 
você deseja que seja conver da para reais. Seu programa deve  implementar uma 
função inline. Após a entrada da quantida em dólares, o programa calcula e retorna 
a quantia convertida em reais.*/