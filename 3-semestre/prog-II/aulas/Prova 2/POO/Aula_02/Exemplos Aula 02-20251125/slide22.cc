#include <iostream>
#include <string>

// Usamos string::size_type para seguir a boa prática do C++
typedef std::string::size_type size_type;

int main() {
    std::string frase = "C++ utiliza strings para texto.";
    size_type pos = 0;

    std::cout << "Frase Original: \"" << frase << "\"\n\n";

    // -----------------------------------------------------------------
    // CASO 1: Usando find() para procurar uma substring específica
    // -----------------------------------------------------------------
    
    std::string busca = "strings";
    pos = frase.find(busca);
    
    std::cout << "--- Usando find(\"strings\") ---\n";
    if (pos != std::string::npos) { // std::string::npos é o valor "não encontrado"
        std::cout << "Substring \"" << busca << "\" encontrada no índice: " << pos << "\n";
    } else {
        std::cout << "Substring não encontrada.\n";
    }

    // -----------------------------------------------------------------
    // CASO 2: Usando find_first_of() para localizar o primeiro delimitador
    // Objetivo: Achar o primeiro espaço para isolar a primeira palavra ("C++")
    // -----------------------------------------------------------------
    
    std::string delimitadores = " "; // Buscando apenas o espaço
    size_type pos_espaco = 0;
    
    // Inicia a busca a partir do índice 0
    pos_espaco = frase.find_first_of(delimitadores, 0); 
    
    std::cout << "\n--- Usando find_first_of(\" \") ---\n";
    if (pos_espaco != std::string::npos) {
        std::cout << "Primeiro espaço (fim da 1ª palavra) encontrado no índice: " << pos_espaco << "\n";
        
        // Usando substr() do Slide 21 para ISOLAR a palavra:
        std::string primeira_palavra = frase.substr(0, pos_espaco);
        std::cout << "A primeira palavra (isolada com substr) é: \"" << primeira_palavra << "\"\n";
    }
    
    // -----------------------------------------------------------------
    // CASO 3: find_first_of() para pular delimitadores (início da próxima palavra)
    // Objetivo: Achar o primeiro caractere que não seja espaço após o índice 4
    // -----------------------------------------------------------------
    
    // Usamos find_first_not_of para encontrar o início do que NÃO é delimitador.
    // Começamos após o "C++" (índice 3), então a busca inicia no índice 4.
    size_type pos_proximo = frase.find_first_not_of(delimitadores, pos_espaco); 
    
    std::cout << "\n--- Usando find_first_not_of() ---\n";
    if (pos_proximo != std::string::npos) {
        std::cout << "A próxima palavra inicia no índice: " << pos_proximo << " (letra 'u')\n";
    }

    return 0;
}
