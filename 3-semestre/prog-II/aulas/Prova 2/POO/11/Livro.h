#ifndef LIVRO_H
#define LIVRO_H

#include <string>

class Livro {
private:
    std::string isbn;
    std::string titulo;
    bool disponivel;

public:
    Livro();
    Livro(const std::string& isbn, const std::string& titulo, bool disponivel = true);

    std::string getISBN() const;
    std::string getTitulo() const;
    bool isDisponivel() const;

    void emprestar();
    void devolver();
    void exibirDados() const;

    std::string getStatusTexto() const;
};

#endif

