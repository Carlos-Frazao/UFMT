#include <iostream>

class Contador {
private:
    unsigned int valor; // Usando unsigned para garantir que seja positivo

public:
    Contador(unsigned int v = 0) : valor(v) {}

    // Incremento PRÉ-FIXADO (++c)
    // Assinatura: não recebe parâmetros.
    // Retorno: Referência para o próprio objeto (modificado).
    Contador& operator++() {
        ++valor;
        return *this; 
    }

    // Incremento PÓS-FIXADO (c++)
    // Assinatura: recebe um 'int' (dummy/fantasma) para diferenciar do pré.
    // Retorno: Retorna uma CÓPIA do estado anterior por valor, não por referência.
    Contador operator++(int) {
        Contador temp = *this; // Salva o estado atual
        ++valor;               // Incrementa o objeto atual
        return temp;           // Retorna o estado antigo salvo
    }

    void exibir() const {
        std::cout << "Valor do contador: " << valor << "\n";
    }
};