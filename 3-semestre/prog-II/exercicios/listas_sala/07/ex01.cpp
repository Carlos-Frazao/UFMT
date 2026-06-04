#include <iostream>
#include <string>

using namespace std;

class Gato {
private:
    string nome;
    int idade;
    double peso;

public:
    // Construtor
    Gato(string n, int i, double p) {
        nome = n;
        idade = i;
        // Usa o setter dentro do construtor para aproveitar a validação logo na criação
        setPeso(p); 
    }

    // Setter para o peso com regra de validação
    void setPeso(double p) {
        if (p > 0) {
            peso = p;
        } else {
            cout << "Erro: O peso deve ser maior que zero! Valor ignorado." << endl;
        }
    }

    // Getters auxiliares para testar a classe
    string getNome() { return nome; }
    double getPeso() { return peso; }
};

int main() {
    // Testando a criação e a validação
    Gato meuGato("Frajola", 3, 4.5);
    cout << "Gato: " << meuGato.getNome() << " | Peso: " << meuGato.getPeso() << "kg" << endl;

    cout << "\nTentando alterar para um peso invalido (-2.0):" << endl;
    meuGato.setPeso(-2.0); // Vai disparar a mensagem de erro
    
    cout << "Peso apos tentativa: " << meuGato.getPeso() << "kg" << endl;

    return 0;
}