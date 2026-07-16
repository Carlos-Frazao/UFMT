#include "Biblioteca.h"
#include "Livro.h"
#include "Membro.h"

#include <iostream>
#include <limits>
#include <string>

int main() {
    Biblioteca biblioteca;
    const std::string arqLivros = "livros.txt";
    const std::string arqMembros = "membros.txt";

    biblioteca.carregarLivros(arqLivros);
    biblioteca.carregarMembros(arqMembros);

    int opcao = 0;

    do {
        std::cout << "\n=== Menu Biblioteca ===\n";
        std::cout << "1. Registrar livro\n";
        std::cout << "2. Registrar membro\n";
        std::cout << "3. Listar livros\n";
        std::cout << "4. Listar membros\n";
        std::cout << "5. Emprestar livro\n";
        std::cout << "6. Devolver livro\n";
        std::cout << "7. Sair\n";
        std::cout << "Escolha: ";

        if (!(std::cin >> opcao)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Opcao invalida.\n";
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (opcao == 1) {
            std::string isbn;
            std::string titulo;

            std::cout << "ISBN: ";
            std::getline(std::cin, isbn);
            std::cout << "Titulo: ";
            std::getline(std::cin, titulo);

            if (biblioteca.registrarLivro(Livro(isbn, titulo, true))) {
                std::cout << "Livro registrado com sucesso.\n";
                biblioteca.gravarLivros(arqLivros);
            } else {
                std::cout << "Ja existe livro com esse ISBN.\n";
            }
        } else if (opcao == 2) {
            int id = 0;
            std::string nome;

            std::cout << "ID do membro: ";
            if (!(std::cin >> id)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "ID invalido.\n";
                continue;
            }

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Nome: ";
            std::getline(std::cin, nome);

            if (biblioteca.registrarMembro(Membro(id, nome))) {
                std::cout << "Membro registrado com sucesso.\n";
                biblioteca.gravarMembros(arqMembros);
            } else {
                std::cout << "Ja existe membro com esse ID.\n";
            }
        } else if (opcao == 3) {
            biblioteca.listarLivros();
        } else if (opcao == 4) {
            biblioteca.listarMembros();
        } else if (opcao == 5) {
            std::string isbn;
            int id = 0;

            std::cout << "ISBN do livro: ";
            std::getline(std::cin, isbn);
            std::cout << "ID do membro: ";
            if (!(std::cin >> id)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "ID invalido.\n";
                continue;
            }

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (biblioteca.emprestarLivro(isbn, id)) {
                biblioteca.gravarLivros(arqLivros);
                biblioteca.gravarMembros(arqMembros);
            }
        } else if (opcao == 6) {
            std::string isbn;
            int id = 0;

            std::cout << "ISBN do livro: ";
            std::getline(std::cin, isbn);
            std::cout << "ID do membro: ";
            if (!(std::cin >> id)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "ID invalido.\n";
                continue;
            }

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (biblioteca.devolverLivro(isbn, id)) {
                biblioteca.gravarLivros(arqLivros);
                biblioteca.gravarMembros(arqMembros);
            }
        } else if (opcao != 7) {
            std::cout << "Opcao invalida.\n";
        }

    } while (opcao != 7);

    biblioteca.gravarLivros(arqLivros);
    biblioteca.gravarMembros(arqMembros);
    std::cout << "Dados salvos. Encerrando.\n";

    return 0;
}

