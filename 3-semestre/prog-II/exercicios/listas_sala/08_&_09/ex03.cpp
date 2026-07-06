#include <iostream>
#include <string>
#include <utility> // Para std::move

class StringSegura {
private:
    std::string dados;

public:
    StringSegura(std::string str) : dados(std::move(str)) {}

    // Proibir a CÓPIA (Construtor de Cópia e Operador de Atribuição)
    StringSegura(const StringSegura&) = delete;
    StringSegura& operator=(const StringSegura&) = delete;

    // Permitir a MOVIMENTAÇÃO (Construtor de Movimento e Atribuição de Movimento)
    StringSegura(StringSegura&&) = default;
    StringSegura& operator=(StringSegura&&) = default;

    void mostrar() const {
        std::cout << "Dado seguro: " << dados << "\n";
    }
};