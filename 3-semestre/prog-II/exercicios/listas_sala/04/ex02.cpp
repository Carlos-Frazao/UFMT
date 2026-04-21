#include <iostream>

using namespace std;

// Função soma
int soma(int a, int b) {
    return a+b;
}

int main() {
    // Declarar variáveis 
    int num1, num2;

    // Entrada de dados
    cout << "Infome um valor: ";
    cin >> num1;
    cout << "Informe outro valor: ";
    cin >> num2;
    
    // Saída de dados
    cout << "A soma de " << num1 << " e " <<num2<< " e igual a " <<soma(num1, num2);


    return 0;
}

/*Escreva um programa que solicite ao usuário digitar dois valores inteiros e, em 
seguida, o programa principal chama uma função, denominada soma, passando 
os parâmetros que o usuário digitou.*/