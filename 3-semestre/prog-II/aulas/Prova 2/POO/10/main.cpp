#include <iostream>
#include "Vetor2D.h"

int main() {
    Vetor2D v1(10.5f, 20.0f);
    Vetor2D v2(5.0f, 10.0f);

    Vetor2D v3 = v1 + v2;

    std::cout << "Resultado: " << v3 << std::endl;

    if (v1 == v2) {
        std::cout << "Iguais" << std::endl;
    } else {
        std::cout << "Diferentes" << std::endl;
    }

    return 0;
}