#include <iostream>
#include <string>

int main() {
    //DEFININDO UMA CONSTANTE PARA O TAMANHO DA STRING
    const std::string::size_type LIMITE = 80;

    std::string linha_atual;
    std::string primeira_linha_longa;
    int contador_linhas_longas = 0;

    while (std::getline(std::cin, linha_atual)) {
        if (linha_atual == "SAIR") {
            break; // Sai do loop 'while'
        }

        // Verifica se o comprimento da linha atual é *maior que* o limite
        if (linha_atual.length() > LIMITE) {
            // Se for maior, incrementa o contador
            contador_linhas_longas++;

            // Verifica se a string 'primeira_linha_longa' ainda está vazia.
            // Se estiver, significa que esta é a *primeira* vez que
            // encontramos uma linha longa.
            if (primeira_linha_longa.empty()) {
                // Armazena a linha atual
                primeira_linha_longa = linha_atual;
            }
        }
    }
        // Impressão dos resultados após o fim do loop
    std::cout << "\n--- Analise Concluida ---" << std::endl;
    std::cout << "Total de linhas que excederam o limite: " << contador_linhas_longas << std::endl;

    // Verifica se alguma linha longa foi encontrada antes de tentar imprimi-la
    if (contador_linhas_longas > 0) {
        std::cout << "Primeira linha longa encontrada: " << primeira_linha_longa << std::endl;
    } else {
        std::cout << "Nenhuma linha longa foi encontrada." << std::endl;
    }
    return 0;
}