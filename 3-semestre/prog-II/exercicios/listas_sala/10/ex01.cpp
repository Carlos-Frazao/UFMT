#include <iostream>
#include <string>

// Classe Base Veiculo
class Veiculo {
public:
    // Atributo público do tipo texto
    std::string marca; 

    // Função virtual emitirSom()
    // A palavra-chave 'virtual' permite que classes filhas reescrevam essa função.
    virtual void emitirSom() const {
        std::cout << "Ruído genérico do motor: Vrum vrum...\n";
    }

    // Evitar vazamentos de memória.
    virtual ~Veiculo() = default; 
};

// Classe Derivada Carro
class Carro : public Veiculo {
public:
    // Atributo inteiro específico
    int numeroPortas; 
    void emitirSom() const override {
        std::cout << "Som de buzina automotiva: Biii biii!\n";
    }
};

// Testando as classes
int main() {
    std::cout << "--- Testando a Classe Base (Veiculo) ---\n";
    Veiculo meuVeiculo;
    meuVeiculo.marca = "Generica"; // Acessando atributo público
    std::cout << "Marca: " << meuVeiculo.marca << "\n";
    meuVeiculo.emitirSom(); // Chama a implementação original

    std::cout << "\n--- Testando a Classe Derivada (Carro) ---\n";
    Carro meuCarro;
    meuCarro.marca = "Fiat";       // Atributo herdado de Veiculo
    meuCarro.numeroPortas = 4;     // Atributo específico de Carro
    
    std::cout << "Marca: " << meuCarro.marca << "\n";
    std::cout << "Portas: " << meuCarro.numeroPortas << "\n";
    meuCarro.emitirSom(); // Chama a implementação sobrescrita (override)

    return 0;
}