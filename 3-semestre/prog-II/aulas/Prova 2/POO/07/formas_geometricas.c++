#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Forma {
public:
    virtual double area() = 0;
    virtual ~Forma() {}
};

class Circulo : public Forma {
private:
    double raio;

public:
    Circulo(double r) : raio(r) {}

    double area() override {
        return M_PI * raio * raio;
    }
};

class Retangulo : public Forma {
private:
    double largura;
    double altura;

public:
    Retangulo(double l, double a) : largura(l), altura(a) {}

    double area() override {
        return largura * altura;
    }
};

class Triangulo : public Forma {
private:
    double base;
    double altura;

public:
    Triangulo(double b, double a) : base(b), altura(a) {}

    double area() override {
        return (base * altura) / 2.0;
    }
};

int main() {
    vector<Forma*> formas;

    formas.push_back(new Circulo(5.0));
    formas.push_back(new Retangulo(4.0, 6.0));
    formas.push_back(new Triangulo(4.0, 5.0));

    for (Forma* forma : formas) {
        cout << "Area: " << forma->area() << endl;
    }

    for (Forma* forma : formas) {
        delete forma;
    }

    return 0;
}