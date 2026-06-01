/* Escreva um programa que declare e inicialize duas variáveis inteiras x e y. Em 
seguida, você deve exibir o conteúdo dessas variáveis e seus respectivos 
endereços. */

#include <iostream>

using namespace std;

int main() {
    int x, y;

    x = 10;
    y = 20;

    // Conteúdo das váriaveis
    cout << "Conteúdo de x -> " << x << endl;
    cout << "Conteúdo de y -> " << y << endl;

    // Endereço das vaiáveis
    cout << "Endereço de x -> " << &x << endl;
    cout << "Endereço de y -> " << &y << endl;

    return 0;
}