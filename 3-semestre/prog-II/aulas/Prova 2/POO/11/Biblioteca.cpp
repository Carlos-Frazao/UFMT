#include "Biblioteca.h"

#include <fstream>
#include <iostream>
#include <sstream>

namespace {
std::vector<std::string> splitTokens(const std::string& linha) {
    std::vector<std::string> tokens;
    std::istringstream iss(linha);
    std::string token;
    while (iss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

std::vector<std::string> splitBySemicolon(const std::string& linha) {
    std::vector<std::string> partes;
    std::stringstream ss(linha);
    std::string item;
    while (std::getline(ss, item, ';')) {
        partes.push_back(item);
    }
    return partes;
}

std::string trim(const std::string& valor) {
    const std::string espacos = " \t\r\n";
    const size_t inicio = valor.find_first_not_of(espacos);
    if (inicio == std::string::npos) {
        return "";
    }
    const size_t fim = valor.find_last_not_of(espacos);
    return valor.substr(inicio, fim - inicio + 1);
}
}

void Biblioteca::carregarLivros(const std::string& nomeArquivo) {
    livros.clear();

    std::ifstream entrada(nomeArquivo);
    if (!entrada.is_open()) {
        return;
    }

    std::string linha;
    while (std::getline(entrada, linha)) {
        if (linha.empty()) {
            continue;
        }

        std::vector<std::string> campos = splitBySemicolon(linha);
        if (campos.size() >= 3) {
            const std::string isbn = trim(campos[0]);
            const std::string titulo = trim(campos[1]);
            const std::string status = trim(campos[2]);
            const bool disponivel = (status == "Disponivel");
            livros.emplace_back(isbn, titulo, disponivel);
            continue;
        }

        const std::vector<std::string> tokens = splitTokens(linha);
        if (tokens.size() >= 3) {
            const std::string isbn = tokens.front();
            const std::string status = tokens.back();

            std::string titulo;
            for (size_t i = 1; i + 1 < tokens.size(); ++i) {
                if (!titulo.empty()) {
                    titulo += ' ';
                }
                titulo += tokens[i];
            }

            const bool disponivel = (status == "Disponivel");
            livros.emplace_back(isbn, titulo, disponivel);
        }
    }
}

void Biblioteca::carregarMembros(const std::string& nomeArquivo) {
    membros.clear();

    std::ifstream entrada(nomeArquivo);
    if (!entrada.is_open()) {
        return;
    }

    std::string linha;
    while (std::getline(entrada, linha)) {
        if (linha.empty()) {
            continue;
        }

        std::vector<std::string> campos = splitBySemicolon(linha);
        if (campos.size() >= 2) {
            int id = 0;
            try {
                id = std::stoi(trim(campos[0]));
            } catch (...) {
                continue;
            }

            Membro membro(id, trim(campos[1]));
            for (size_t i = 2; i < campos.size(); ++i) {
                const std::string isbn = trim(campos[i]);
                if (!isbn.empty()) {
                    membro.adicionarLivro(isbn);
                }
            }

            membros.push_back(membro);
            continue;
        }

        const std::vector<std::string> tokens = splitTokens(linha);
        if (tokens.size() >= 2) {
            int id = 0;
            try {
                id = std::stoi(tokens[0]);
            } catch (...) {
                continue;
            }

            Membro membro(id, tokens[1]);
            for (size_t i = 2; i < tokens.size(); ++i) {
                membro.adicionarLivro(tokens[i]);
            }

            membros.push_back(membro);
        }
    }
}

bool Biblioteca::registrarLivro(const Livro& livro) {
    for (const auto& existente : livros) {
        if (existente.getISBN() == livro.getISBN()) {
            return false;
        }
    }

    livros.push_back(livro);
    return true;
}

bool Biblioteca::registrarMembro(const Membro& membro) {
    for (const auto& existente : membros) {
        if (existente.getID() == membro.getID()) {
            return false;
        }
    }

    membros.push_back(membro);
    return true;
}

void Biblioteca::gravarLivros(const std::string& nomeArquivo) const {
    std::ofstream saida(nomeArquivo);
    if (!saida.is_open()) {
        return;
    }

    for (const auto& livro : livros) {
        saida << livro.getISBN() << ';'
              << livro.getTitulo() << ';'
              << livro.getStatusTexto() << '\n';
    }
}

void Biblioteca::gravarMembros(const std::string& nomeArquivo) const {
    std::ofstream saida(nomeArquivo);
    if (!saida.is_open()) {
        return;
    }

    for (const auto& membro : membros) {
        saida << membro.getID() << ';' << membro.getNome();
        const auto livrosMembro = membro.getLivrosEmprestados();
        for (const auto& isbn : livrosMembro) {
            saida << ';' << isbn;
        }
        saida << '\n';
    }
}

void Biblioteca::listarLivros() const {
    if (livros.empty()) {
        std::cout << "Nenhum livro cadastrado.\n";
        return;
    }

    for (const auto& livro : livros) {
        livro.exibirDados();
    }
}

void Biblioteca::listarMembros() const {
    if (membros.empty()) {
        std::cout << "Nenhum membro cadastrado.\n";
        return;
    }

    for (const auto& membro : membros) {
        membro.exibirDados();
    }
}

bool Biblioteca::emprestarLivro(const std::string& isbn, int idMembro) {
    Livro* livroEncontrado = nullptr;
    for (auto& livro : livros) {
        if (livro.getISBN() == isbn) {
            livroEncontrado = &livro;
            break;
        }
    }

    if (livroEncontrado == nullptr) {
        std::cout << "Livro nao encontrado.\n";
        return false;
    }

    if (!livroEncontrado->isDisponivel()) {
        std::cout << "Livro indisponivel para emprestimo.\n";
        return false;
    }

    Membro* membroEncontrado = nullptr;
    for (auto& membro : membros) {
        if (membro.getID() == idMembro) {
            membroEncontrado = &membro;
            break;
        }
    }

    if (membroEncontrado == nullptr) {
        std::cout << "Membro nao encontrado.\n";
        return false;
    }

    livroEncontrado->emprestar();
    membroEncontrado->adicionarLivro(isbn);
    std::cout << "Emprestimo realizado com sucesso.\n";
    return true;
}

bool Biblioteca::devolverLivro(const std::string& isbn, int idMembro) {
    Membro* membroEncontrado = nullptr;
    for (auto& membro : membros) {
        if (membro.getID() == idMembro) {
            membroEncontrado = &membro;
            break;
        }
    }

    if (membroEncontrado == nullptr) {
        std::cout << "Membro nao encontrado.\n";
        return false;
    }

    if (!membroEncontrado->possuiLivro(isbn)) {
        std::cout << "Membro nao possui esse livro.\n";
        return false;
    }

    Livro* livroEncontrado = nullptr;
    for (auto& livro : livros) {
        if (livro.getISBN() == isbn) {
            livroEncontrado = &livro;
            break;
        }
    }

    if (livroEncontrado == nullptr) {
        std::cout << "Livro nao encontrado.\n";
        return false;
    }

    membroEncontrado->removerLivro(isbn);
    livroEncontrado->devolver();
    std::cout << "Devolucao realizada com sucesso.\n";
    return true;
}

