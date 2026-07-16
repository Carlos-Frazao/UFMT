#ifndef MEMBRO_H
#define MEMBRO_H

#include <string>
#include <vector>

class Membro {
private:
    int id;
    std::string nome;
    std::vector<std::string> livrosEmprestados;

public:
    Membro();
    Membro(int id, const std::string& nome);

    int getID() const;
    std::string getNome() const;
    std::vector<std::string> getLivrosEmprestados() const;

    void adicionarLivro(const std::string& isbn);
    bool removerLivro(const std::string& isbn);
    bool possuiLivro(const std::string& isbn) const;
    void exibirDados() const;
};

#endif

