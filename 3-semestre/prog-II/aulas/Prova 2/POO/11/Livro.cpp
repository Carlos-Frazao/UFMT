#include "Livro.h"

#include <iostream>

Livro::Livro() : isbn(""), titulo(""), disponivel(true) {}

Livro::Livro(const std::string& isbn, const std::string& titulo, bool disponivel)
    : isbn(isbn), titulo(titulo), disponivel(disponivel) {}

std::string Livro::getISBN() const {
    return isbn;
}

std::string Livro::getTitulo() const {
    return titulo;
}

bool Livro::isDisponivel() const {
    return disponivel;
}

void Livro::emprestar() {
    disponivel = false;
}

void Livro::devolver() {
    disponivel = true;
}

void Livro::exibirDados() const {
    std::cout << "ISBN: " << isbn
              << " | Titulo: " << titulo
              << " | Status: " << getStatusTexto()
              << '\n';
}

std::string Livro::getStatusTexto() const {
    return disponivel ? "Disponivel" : "Emprestado";
}

