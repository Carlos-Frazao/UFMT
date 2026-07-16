#include <iostream>
#include <string>

// A função substr não exige uma função auxiliar, 
// o exemplo é executado diretamente no main.

int main() {
    // String original para o exemplo
    std::string texto_original = "Programacao C++ Avancada";
    std::string::size_type pos_inicial = 0; 
    std::string::size_type comprimento = 0; 
    std::string substring;

    std::cout << "Texto Original: \"" << texto_original << "\"\n";
    std::cout << "Tamanho total: " << texto_original.size() << "\n\n";

    // -----------------------------------------------------------------
    // CASO 1: Extrair a partir de uma posição até o FINAL da string
    // Sintaxe: s.substr(pos)
    // Objetivo: Extrair "Avancada" (começa no índice 17)
    // -----------------------------------------------------------------
    
    pos_inicial = 16; 
    
    // Chamada 1: a partir do índice 17 até o final
    substring = texto_original.substr(pos_inicial);
    
    std::cout << "--- Caso 1: Do índice " << pos_inicial << " ao final ---\n";
    std::cout << "Resultado (Avancada): \"" << substring << "\"\n\n";

    // -----------------------------------------------------------------
    // CASO 2: Extrair um COMPRIMENTO específico a partir de uma posição
    // Sintaxe: s.substr(pos, len)
    // Objetivo: Extrair "C++" (começa no índice 12, tem 3 caracteres)
    // -----------------------------------------------------------------
    
    pos_inicial = 12; 
    comprimento = 3;
    
    // Chamada 2: 3 caracteres a partir do índice 13
    substring = texto_original.substr(pos_inicial, comprimento);
    
    std::cout << "--- Caso 2: Comprimento fixo ---\n";
    std::cout << "Resultado (C++): \"" << substring << "\"\n";
    std::cout << "Tamanho da substring: " << substring.size() << "\n\n";
    
    // -----------------------------------------------------------------
    // Demonstração da CÓPIA (o original não muda)
    // -----------------------------------------------------------------
    substring = "X"; // Modifica SÓ a substring, não o original
    std::cout << "Após modificar 'substring', o original permanece: \"" << texto_original << "\"\n";

    return 0;
}
