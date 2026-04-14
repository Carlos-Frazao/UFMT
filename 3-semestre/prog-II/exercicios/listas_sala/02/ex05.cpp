#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    string nome;
    int idade;
    float n1, n2, n3, media;

    cout << "Informe o nome completo do aluno: ";
    getline(cin, nome);

    cout << "Informe a idade: ";
    cin >> idade;

    // Você pode ler as três notas na mesma linha usando múltiplos >>
    cout << "Informe as tres notas (separadas por espaco ou Enter): ";
    cin >> n1 >> n2 >> n3;

    // Calculando a média
    media = (n1 + n2 + n3) / 3.0;

    // Exibindo tudo de forma estruturada
    cout << "\n--- Boletim Escolar ---\n";
    
    // Configura 2 casas decimais para as notas e a média
    cout << fixed << setprecision(2); 
    
    cout << "Aluno: " << nome << "\n";
    cout << "Idade: " << idade << " anos\n";
    cout << "Notas: " << n1 << " | " << n2 << " | " << n3 << "\n";
    cout << "Media: " << media << "\n";
    cout << "-----------------------\n";

    return 0;
}