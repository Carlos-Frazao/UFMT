#include "Membro.h"

#include <algorithm>
#include <iostream>

Membro::Membro() : id(0), nome("") {}

Membro::Membro(int id, const std::string& nome) : id(id), nome(nome) {}

int Membro::getID() const {
    return id;
}

std::string Membro::getNome() const {
    return nome;
}

std::vector<std::string> Membro::getLivrosEmprestados() const {
    return livrosEmprestados;
}

void Membro::adicionarLivro(const std::string& isbn) {
    if (!possuiLivro(isbn)) {
        livrosEmprestados.push_back(isbn);
    }
}

bool Membro::removerLivro(const std::string& isbn) {
    const auto it = std::find(livrosEmprestados.begin(), livrosEmprestados.end(), isbn);
    if (it == livrosEmprestados.end()) {
        return false;
    }

    livrosEmprestados.erase(it);
    return true;
}

bool Membro::possuiLivro(const std::string& isbn) const {
    return std::find(livrosEmprestados.begin(), livrosEmprestados.end(), isbn) != livrosEmprestados.end();
}

void Membro::exibirDados() const {
    std::cout << "ID: " << id << " | Nome: " << nome << " | Livros: ";

    if (livrosEmprestados.empty()) {
        std::cout << "nenhum";
    } else {
        for (size_t i = 0; i < livrosEmprestados.size(); ++i) {
            if (i > 0) {
                std::cout << ", ";
            }
            std::cout << livrosEmprestados[i];
        }
    }

    std::cout << '\n';
}

