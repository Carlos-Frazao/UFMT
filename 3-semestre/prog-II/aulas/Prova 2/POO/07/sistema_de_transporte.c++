#include <iostream>
#include <vector>

using namespace std;

class Transporte {
public:
    virtual void iniciar() = 0;
    virtual void parar() = 0;
    virtual ~Transporte() {}
};

class Carro : public Transporte {
public:
    void iniciar() override {
        cout << "Carro iniciando" << endl;
    }

    void parar() override {
        cout << "Carro parando" << endl;
    }
};

class Bicicleta : public Transporte {
public:
    void iniciar() override {
        cout << "Bicicleta iniciando" << endl;
    }

    void parar() override {
        cout << "Bicicleta parando" << endl;
    }
};

class Aviao : public Transporte {
public:
    void iniciar() override {
        cout << "Avião decolando" << endl;
    }

    void parar() override {
        cout << "Avião pousando" << endl;
    }
};

int main() {
    vector<Transporte*> transportes;

    transportes.push_back(new Carro());
    transportes.push_back(new Bicicleta());
    transportes.push_back(new Aviao());

    for (Transporte* t : transportes) {
        t->iniciar();
        t->parar();
    }

    for (Transporte* t : transportes) {
        delete t;
    }

    return 0;
}