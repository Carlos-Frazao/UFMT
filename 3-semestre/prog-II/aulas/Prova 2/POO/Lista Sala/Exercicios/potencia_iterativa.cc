#include <iostream>

using namespace std;

double calcular_potencia(double b, double e) {
    if (e == 0) {
        return 1;
    }

    //exp negativo
    if (b < 0) {
        b = 1.0 / b;
        e = -e; 
    }

    double resultado = 1;
    for (int i = 0; i < e;   i++) {
        resultado *= b;
    }

    return resultado;
}

int main() {
    int b, e;

    cout << "Base: ";
    cin >> b;   

    cout << "Expoente: ";
    cin >> e;

    if (e < 0) {
        cout << "expoentes negativos!" << endl;
        return 1;

    long long resultado = calcular_potencia(b, e);

    cout << b << "elevado a " << e << " eh " << resultado << "\n";
}