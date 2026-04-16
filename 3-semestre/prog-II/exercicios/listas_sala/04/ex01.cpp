#include <iostream>

using namespace std;

int main() {
    // Declaração de variáveis para armazenar dia, mês e ano
    int dia;
    int mes;
    int ano;
    
    // Entrada de dados
    cout << "Dia: ";
    cin >> dia;
    cout << "Mês: ";
    cin >> mes;
    cout << "Ano: ";
    cin >> ano;

    // saída de dados 
    cout << dia << "/" << mes << "/" << ano << endl; 

    return 0;
}

//Escreva um programa que solicite do usuário dia, mês e ano atual e, em seguida, 
//o programa exibe a data informada.