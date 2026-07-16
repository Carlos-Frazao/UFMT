#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "Livro.h"
#include "Membro.h"

#include <string>
#include <vector>

class Biblioteca {
private:
    std::vector<Livro> livros;
    std::vector<Membro> membros;

public:
    void carregarLivros(const std::string& nomeArquivo);
    void carregarMembros(const std::string& nomeArquivo);

    bool registrarLivro(const Livro& livro);
    bool registrarMembro(const Membro& membro);

    void gravarLivros(const std::string& nomeArquivo) const;
    void gravarMembros(const std::string& nomeArquivo) const;

    void listarLivros() const;
    void listarMembros() const;

    bool emprestarLivro(const std::string& isbn, int idMembro);
    bool devolverLivro(const std::string& isbn, int idMembro);
};

#endif

