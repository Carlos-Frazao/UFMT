#include <iostream>

using namespace std;

class Termometro {
private:
    double temperaturaCelsius;

public:
    // Construtor
    Termometro() {
        temperaturaCelsius = 25.0; // Valor padrao inicial
    }

    // Setter com bloqueio de valores abaixo do zero absoluto
    void setTemperaturaCelsius(double temp) {
        if (temp >= -273.15) {
            temperaturaCelsius = temp;
        } else {
            cout << "Erro: Temperatura abaixo do zero absoluto (-273.15C)!" << endl;
        }
    }

    // Getter para Celsius
    double getTemperaturaCelsius() {
        return temperaturaCelsius;
    }

    // Getter que calcula e retorna Fahrenheit diretamente
    double getTemperaturaFahrenheit() {
        return (temperaturaCelsius * 9.0 / 5.0) + 32.0;
    }
};

int main() {
    Termometro term;

    cout << "Temperatura inicial:" << endl;
    cout << "Celsius: " << term.getTemperaturaCelsius() << "C" << endl;
    cout << "Fahrenheit: " << term.getTemperaturaFahrenheit() << "F" << endl;

    cout << "\nAlterando para 100C..." << endl;
    term.setTemperaturaCelsius(100.0);
    cout << "Fahrenheit: " << term.getTemperaturaFahrenheit() << "F" << endl;

    cout << "\nTentando definir temperatura abaixo de -273.15C..." << endl;
    term.setTemperaturaCelsius(-300.0); // Vai disparar a mensagem de erro

    return 0;
}