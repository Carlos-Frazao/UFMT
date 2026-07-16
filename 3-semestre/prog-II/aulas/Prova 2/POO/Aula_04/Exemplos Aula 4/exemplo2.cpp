#include <iostream>
#include <array>



int main() {
    // Declaração e inicialização de um std::array
    std::array<int, 5> numeros {1, 2, 3, 4, 5};

    // Acesso e impressão dos elementos do array
    for (auto &valor : numeros){
        valor = valor*2;
    }

    for(size_t i{0}; i < numeros.size(); ++i){
        std::cout << numeros.at(i) << " ";
    }

    return 0;
}