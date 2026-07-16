#include <iostream>
#include <string>
#include <iomanip> // Para formatar o preço

class Produto {
private:
    std::string nome;
    double preco;
    int quantidade;

public:
    // Construtor 
    Produto(const std::string& nome, double preco, int quantidade) :
        nome(nome), preco(preco), quantidade(quantidade) {}

    // Métodos Get 
    std::string getNome() const { return nome; }
    double getPreco() const { return preco; }
    int getQuantidade() const { return quantidade; }

    // Métodos Set 
    void setNome(const std::string& novoNome) { nome = novoNome; }
    void setPreco(double novoPreco) {
        if (novoPreco >= 0) {
            preco = novoPreco;
        }
    }
    void setQuantidade(int novaQuantidade) {
        if (novaQuantidade >= 0) {
            quantidade = novaQuantidade;
        }
    }

    // Gerenciamento de Estoque 
    void adicionarEstoque(int valor) {
        if (valor > 0) {
            quantidade += valor;
        }
    }

    void removerEstoque(int valor) {
        if (valor > 0 && quantidade >= valor) {
            quantidade -= valor;
        }
    }

    // Mostrar Dados 
    void mostrarDados() const {
        std::cout << "Nome: " << nome
                  << ", Preco: " << std::fixed << std::setprecision(2) << preco
                  << ", Quantidade: " << quantidade << std::endl;
    }
};

int main() {
    Produto p1("Notebook", 2500.0 , 10);
    p1.mostrarDados (); // Nome: Notebook , Preco: 2500, Quantidade: 10
    p1.adicionarEstoque (5);
    p1.removerEstoque (3);
    p1.mostrarDados (); // Nome: Notebook , Preco: 2500, Quantidade: 12
return 0;
}
