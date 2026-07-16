#include <iostream>

using namespace  std;

int calcular_mdc(int a, int b) {
    //int resto; 

    while (b != 0) {
        int resto = a % b; 
        a = b;
        b = resto;
    }
    return a;
}

int main() {

    int n1, n2;

    cout << "Informe o valor de A: ";
    cin >> n1;

    cout << "Informe o valor de B: ";
    cin >> n2;

    int mdc = calcular_mdc(n1, n2);
    
    cout << "O mdc de " << n1 << " e " << n2 << "é igual a " << mdc << "\n";
}
