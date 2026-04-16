#include <iostream>

using namespace std;

// Função para pegar a temperatura
int temp_7_Dias() {
    int vet [7];

    for (int i=0; i<7; i++) {
        cout << "Digite a temperatura do dia " << i+1 << ": ";
        cin >> vet[i];

        // Fazendo a verificação da maior sequência 
            if (vet[i] > vet[i-1]) {
                cout << "A temperatura subiu no dia " << i+1 << endl;
            } else {
                cout << "A temperatura não subiu no dia " << i+1 << endl;
            }       
    }

    return 0;
}

// Função pincípal
int main() {
    temp_7_Dias();
    cout << "A maior sequência de dias com temperatura subindo é: ";

    return 0;
}

/* Trabalho 01 - Temperatura

Leia as temperaturas de 7 dias em um vetor. Use estruturas de controle para identificar a 
maior sequência de dias em que a temperatura subiu constantemente.  

*/