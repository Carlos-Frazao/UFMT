#include <iostream>
#include <string>

class Livro {
private:
    std::string titulo;
    std::string autor;
    int anoPublicacao;
    int numPaginas;

public:
    // Construtor 
    Livro(const std::string& titulo, const std::string& autor, int ano, int paginas) :
        titulo(titulo), autor(autor), anoPublicacao(ano), numPaginas(paginas) {}

    // Métodos Get 
    std::string getTitulo() const { return titulo; }
    std::string getAutor() const { return autor; }
    int getAnoPublicacao() const { return anoPublicacao; }
    int getNumPaginas() const { return numPaginas; }

    // Métodos Set 
    void setTitulo(const std::string& novoTitulo) { titulo = novoTitulo; }
    void setAutor(const std::string& novoAutor) { autor = novoAutor; }
    void setAnoPublicacao(int novoAno) { anoPublicacao = novoAno; }
    void setNumPaginas(int novasPaginas) {
        if (novasPaginas > 0) {
            numPaginas = novasPaginas; // [cite: 40]
        }
    }

    // Mostrar Dados 
    void mostrarDados() const {
        std::cout << "Titulo: " << titulo
                  << ", Autor: " << autor
                  << ", Ano: " << anoPublicacao
                  << ", Paginas: " << numPaginas << std::endl;
    }
};

int main() {
    Livro l1("1984", "George Orwell", 1949, 328);
    l1.mostrarDados (); // Titulo: 1984, Autor: George Orwell , Ano: 1949, Paginas: 328
    Livro l2("Fogo Morto", "Graciliano Ramos", 1933, 229);
    l2.mostrarDados (); // Titulo: Fogo Morto , Autor: Graciliano Ramos , Ano: 1933, Paginas: 229
    l2.setNumPaginas (299);
    l2.mostrarDados (); // Titulo: Fogo Morto , Autor: Graciliano Ramos , Ano: 1933, Paginas: 299
    return 0;
}
