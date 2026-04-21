#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Declarar variáveis 
    const int ANO = 2;
    const int TRIMESTRE = 4;

    double despesas[ANO][TRIMESTRE];
    double totalGeral = 0;
    
    // Entrada de dados 
    for (int i = 0; i < ANO; i++) {
        for (int j = 0; j < TRIMESTRE; j++) {
            cout << "Informe a despesa do Ano " << i + 1 << ", Trimestre " << j + 1 << ": ";
            cin >> despesas[i][j];
            totalGeral += despesas[i][j]; // Já vai somando o total
        }
    }

    // Saída de dados
    cout << "\nTABELA DE DESPESAS\n";
    cout << "Ano\tTri 1\tTri 2\tTri 3\tTri 4\n"; // Cabeçalho

    for (int i = 0; i < ANO; i++) {
        cout << i + 1 << "\t"; // Número do ano
        for (int j = 0; j < TRIMESTRE; j++) {
            cout << fixed << setprecision(2) << despesas[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nValor total de despesas nos dois anos: R$ " << totalGeral << endl;
    return 0;
}

/*Elabore um programa que cria um array bidimensional com valores do tipo 
double. Chame esse array de despesas[ANO][TRIMESTRE]. Adicionalmente, você 
deve definir ANO=2 e TRIMESTRE=4. Em seguida, deve criar um laço que solicite ao 
usuário digitar os valores de despesas para cada um dos semestres nos dois 
anos. Ao final, o programa exibirá uma tabela que mostra os valores das despesas 
de cada ano, sendo listadas por trimestre, além do valor total de despesas nos 
dois anos*/