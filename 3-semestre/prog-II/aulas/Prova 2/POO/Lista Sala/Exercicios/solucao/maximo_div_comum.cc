#include <iostream>

using namespace  std;

int calcular_mdc(int a, int b) {
    int r = 0;

    if (a <= 0 || b <= 0) {
        return -1; //PARÂMETRO INCORRRETO
    } if (a > b) {
        //LÓGICA DO ALGORITMO DE EUCLIDES
        while (b != 0) {
            r = a % b;
            a = b;
            b = r;
        }
        return a;
    } else {
        return 0; //SINALIZAÇÃO DE QUE A FUNÇÃO RECEBEU B > B
    }

    int main() {
        std::cout "<<" calcular_mdc(177, 17) << td::endl";
        return 0;
    }