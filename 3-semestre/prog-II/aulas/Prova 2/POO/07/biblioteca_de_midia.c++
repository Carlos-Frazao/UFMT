#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Midia {
public:
    virtual void exibirInfo() = 0;
    virtual void reproduzir() = 0;
    virtual ~Midia() {}
};

class Livro : public Midia {
private:
    string titulo;
    string autor;

public:
    Livro(string t, string a) : titulo(t), autor(a) {}

    void exibirInfo() override {
        cout << "Livro: " << titulo << " por " << autor << endl;
    }

    void reproduzir() override {
        cout << "Abrindo o livro " << titulo << endl;
    }
};

class CD : public Midia {
private:
    string titulo;
    string artista;

public:
    CD(string t, string a) : titulo(t), artista(a) {}

    void exibirInfo() override {
        cout << "CD: " << titulo << " por " << artista << endl;
    }

    void reproduzir() override {
        cout << "Tocando CD " << titulo << endl;
    }
};

class DVD : public Midia {
private:
    string titulo;
    string diretor;

public:
    DVD(string t, string d) : titulo(t), diretor(d) {}

    void exibirInfo() override {
        cout << "DVD: " << titulo << " dirigido por " << diretor << endl;
    }

    void reproduzir() override {
        cout << "Reproduzindo DVD " << titulo << endl;
    }
};

int main() {
    vector<Midia*> midias;

    midias.push_back(new Livro("Senhor dos Anéis", "J.R.R. Tolkien"));
    midias.push_back(new CD("Thriller", "Michael Jackson"));
    midias.push_back(new DVD("Inception", "Christopher Nolan"));

    for (Midia* m : midias) {
        m->exibirInfo();
        m->reproduzir();
    }

    for (Midia* m : midias) {
        delete m;
    }

    return 0;
}