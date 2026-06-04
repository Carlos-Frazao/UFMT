/* Escreva um programa que crie um array de double e dque permita entrar com até 
100 valores. Entretanto, quando seu programa ler os dados digitados pelo usuário, 
ele deve usar a instrução:
a. cin >> *(a + j); // usando *(a+j) para armazenar em a[j]
b. e, quando acumular os valores lidos, seu programa deve usar: 
c. soma += *(aPtr + j); // usando *aPtr para acessar a[j] Por fim, seu programa 
deve exibir a soma e a média dos valores digitados. */

#include <iostream>

using namespace std;

int main() {
    int n;
    double a[100];      // Cria um array de double para até 100 valores
    double *aPtr = a;   // Inicializa o ponteiro aPtr apontando para o array 'a'
    double soma = 0.0;

    cout << "Quantos valores voce deseja inserir (maximo 100)? ";
    cin >> n;

    // Validação de segurança para garantir que não ultrapasse o tamanho do array
    if (n <= 0 || n > 100) {
        cout << "Quantidade invalida. O programa sera encerrado." << endl;
        return 1;
    }

    cout << "Digite os " << n << " valores:" << endl;
    
    // a. Lendo os dados com *(a + j)
    for (int j = 0; j < n; j++) {
        cin >> *(a + j); 
    }

    // c. Acumulando os valores com *(aPtr + j)
    for (int j = 0; j < n; j++) {
        soma += *(aPtr + j);
    }

    // Calculando a média
    double media = soma / n;

    // Exibindo a soma e a média
    cout << "\n--- Resultados ---" << endl;
    cout << "Soma: " << soma << endl;
    cout << "Media: " << media << endl;

    return 0;
}