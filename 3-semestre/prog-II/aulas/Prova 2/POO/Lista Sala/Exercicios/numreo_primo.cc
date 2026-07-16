#include <iostream>
#include <cmath> //bibliorteca utilizada para tirra a raiz

using namespace std;

bool eh_primo(int N) {
    if (N < 2) return false;
    if (N == 2) return true;
    if (N % 2 == 0) return false;
    
    int limite = sqrt(N);
    for (int i = 3; i <= limite; i += 2) {
        if (N % i == 0) return false;
    }
    return true;
}

int main() {
    cout << "Teste de números primos" << endl;
    
    // Testando 3 valores específicos
    int valor1 = 17;
    int valor2 = 25;
    int valor3 = 29;
    
    cout << valor1 << " é primo? " << (eh_primo(valor1) ? "SIM" : "NÃO") << "\n";
    cout << valor2 << " é primo? " << (eh_primo(valor2) ? "SIM" : "NÃO") << "\n";
    cout << valor3 << " é primo? " << (eh_primo(valor3) ? "SIM" : "NÃO") << "\n";
    
    return 0;
}