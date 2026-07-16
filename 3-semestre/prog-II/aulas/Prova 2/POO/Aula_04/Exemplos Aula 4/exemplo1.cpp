#include <iostream>
#include <array>
#include <exception> // Para a classe base de exceções
#include <stdexcept> // Para a exceção std::out_of_range

int main() {
    // 1. Declaração e inicialização de um std::array
    std::array<int, 5> valores {10, 20, 30, 40, 50}; // Um array de 5 ints

    std::cout << "--- Demonstração com Índice Válido ---\n";

    // 2. Acesso a um elemento com índice válido e modificação (sem verificação de limites de índice, use '[]')
    // Acessando o primeiro elemento (índice 0)
    std::cout << "Valor do elemento [0] (usando []): " << valores[0] << std::endl;

    // Acessando e modificando o primeiro elemento (índice 0) usando at()
    valores.at(0) = 99; // Retorna uma referência ao elemento do Array, permitindo a atribuição de valor.

    std::cout << "Novo valor do elemento [0] (usando at()): " << valores.at(0) << std::endl;

    std::cout << "\n--- Demonstração de Verificação de Limites com at() ---\n";

    // 3. Tentativa de acessar um índice fora dos limites para demonstrar a verificação
    // O array tem 5 elementos, com índices de 0 a 4. O índice 5 é inválido.
    try {
        std::cout << "Tentando acessar o elemento com índice 5 (fora dos limites)..." << std::endl;

        // A função at() verifica os limites antes de acessar seus elementos.
        // Se a função at() encontrar um índice fora dos limites, ela gera um erro em tempo de execução (exceção).
        int valorInvalido = valores.at(5); // Gera uma exceção std::out_of_range
        //int valorInvalido = valores[5]; // Gera uma exceção std::out_of_range
        // Este código só seria executado se a linha acima não lançasse uma exceção
        std::cout << "Valor lido (NÃO DEVE APARECER): " << valorInvalido << std::endl;

    } catch (const std::out_of_range& e) {
        // Bloco catch que captura a exceção lançada por at()
        std::cerr << "ERRO (Exceção capturada): Acesso fora dos limites detectado!" << std::endl;
        std::cerr << "Detalhe do erro: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        // Captura qualquer outra exceção padrão
        std::cerr << "ERRO (Outra Exceção): " << e.what() << std::endl;
    }

    return 0;
}
