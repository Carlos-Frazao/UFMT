#include <iostream>
#include <vector>

using namespace std;

class Animal {
public:
    virtual void emitirSom() {
        cout << "..." << endl;
    }

    virtual ~Animal() {}
};

class Cachorro : public Animal {
public:
    void emitirSom() override {
        cout << "Au Au" << endl;
    }
};

class Gato : public Animal {
public:
    void emitirSom() override {
        cout << "Miau" << endl;
    }
};

class Vaca : public Animal {
public:
    void emitirSom() override {
        cout << "Muuu" << endl;
    }
};

int main() {
    Cachorro cachorro;
    Gato gato;
    Vaca vaca;

    vector<Animal*> animais;

    animais.push_back(&cachorro);
    animais.push_back(&gato);
    animais.push_back(&vaca);

    for (Animal* animal : animais) {
        animal->emitirSom();
    }

    return 0;
}