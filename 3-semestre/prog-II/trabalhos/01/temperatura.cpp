#include <iostream>

using namespace std;

// Função para pegar a temperatura
int temp_7_Dias() {
    int vet [7]; // Jogando 7 valores em um vetor

    for (int i=0; i<7; i++) {
        cout << "Digite a temperatura do dia " << i+1 << ": ";
        cin >> vet[i];
    }
    // Rastrear as sequências
        int sequencia_atual = 0; 
        int maior_sequencia = 0;
        
        /* media graus maior que 25
        for (int i = 0; i < 7; i++) {
            if (vet[i] > 25) {
                sequencia_atual++;
            }
        */

        for (int i = 1; i < 7; i++) {
        if (vet[i] > vet[i-1] & vet[i] > 25){
            // A temperatura subiu em relação a ontem! Aumenta a sequência atual.
            sequencia_atual++;
        } else {
            // A temperatura caiu ou se manteve igual. A sequência quebrou.
            // Antes de zerar, verificamos se essa sequência que acabou era a maior de todas:
            if (sequencia_atual > maior_sequencia) {
                maior_sequencia = sequencia_atual;
            }
            // Reseta a sequência atual para começar a contar de novo a partir do dia atual
            sequencia_atual = 0;
        }
}
    if (sequencia_atual > maior_sequencia) {
        maior_sequencia = sequencia_atual;
    }

    return maior_sequencia;
}

// Função pincípal
int main() {
    int resultado = temp_7_Dias();

    cout << "A maior sequência de dias com temperatura acima de 25 subindo é: " << resultado << endl;

    return 0;
}

/* Trabalho 01 - Temperatura

Leia as temperaturas de 7 dias em um vetor. Use estruturas de controle para identificar a 
maior sequência de dias em que a temperatura subiu constantemente.  

*/