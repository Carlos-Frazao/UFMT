#include <iostream>
#include <string>
#include <iomanip> // Para formatar o preço

class Produto {
protected:
    std::string nome;
    double preco;

public:
    Produto(std::string n, double p) : nome(n), preco(p) {}

    void exibirDetalhes() {
        std::cout << "Produto: " << nome << " | Preco: R$ " << std::fixed << std::setprecision(2) << preco;
    }
};

class Livro : public Produto {
private:
    std::string autor;

public:
    // Construtor chamando o construtor da classe base
    Livro(std::string n, double p, std::string a) : Produto(n, p), autor(a) {}

    void exibirDetalhes() {
        Produto::exibirDetalhes(); // Reutiliza o código da mãe
        std::cout << "\n Autor: " << autor << std::endl;
    }
};

class Eletronico : public Produto {
private:
    std::string marca;

public:
    Eletronico(std::string n, double p, std::string m) : Produto(n, p), marca(m) {}

    void exibirDetalhes() {
        Produto::exibirDetalhes(); // Reutiliza o código da mãe
        std::cout << "\n Marca: " << marca << std::endl;
    }
};

// Código principal 
int main() {
    std::cout << "--- Cadastro de Produtos ---\n";

    // Produto Generico (Teste da base)
    Produto p1("Suporte para Notebook", 50.00);
    p1.exibirDetalhes ();
    std::cout << "\n";
    
    // Livro (Herda de Produto)
    Livro l1("O Senhor dos Aneis", 120.00 , "J.R.R. Tolkien");
    l1.exibirDetalhes ();
    std::cout << "\n";
    
    // Eletronico (Herda de Produto)
    Eletronico e1("Fone Bluetooth", 200.00 , "JBL");
    e1.exibirDetalhes ();
    return 0;
}

/*Requisitos das Classes
    1. Classe Base Produto:
        •Atributos protected: nome, pre ̧co.
        •M ́etodo: exibirDetalhes() (Mostra nome e pre ̧co).
    2. Classe Livro (Herda de Produto):
        •Atributo espec ́ıfico: autor.
        •Construtor: Deve chamar o construtor de Produto.
        •M ́etodo: exibirDetalhes() deve mostrar dados do pai + o autor.
    3. Classe Eletronico (Herda de Produto):
        •Atributo espec ́ıfico: marca.
        •M ́etodo: exibirDetalhes() deve mostrar dados do pai + a marca.
    Saida Esperada:
    Produto: Suporte para Notebook | Preco: R$ 50.00
    Produto: O Senhor dos Aneis | Preco: R$ 120.00
    Autor: J.R.R. Tolkien
    Produto: Fone Bluetooth | Preco: R$ 200.00
    Marca: JBL
*/