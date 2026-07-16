#include <iostream>
#include <memory>
#include <list>
// Códigows feito no papel e testando nesse arquivo
using namespace std;

int tamanhoVariavel() {
    int a, tamanhoINT, tamanhoFLOAT;
    float b [5][5]; // Array de 5x5, ou seja, 25 elementos

    tamanhoINT = sizeof(a); // Uma variável tem 4 bytes, Depende do tipo tbm né
    tamanhoFLOAT = sizeof(b);
    cout << tamanhoINT << endl;
    cout << tamanhoFLOAT << endl;
    return 0;
}

int ponteiro() {
    int a = 10;
    int *p; // Ponteiro para inteiro
    p = &a; // Atribuindo o endereço de a para o ponteiro p

    cout << "Valor de a: " << a << endl;
    cout << "Endereço de a: " << &a << endl;
    cout << "Valor do ponteiro p: " << p << endl;
    cout << "Valor apontado por p: " << *p << endl;

    return 0;
}

int ponteiroInteligente() {
    // unique_ptr:
    unique_ptr<int> p(new int(10)); // Ponteiro inteligente para inteiro
    cout << "Valor apontado por p: " << *p << endl;
    // ptr é destruído automaticamente aqui e a memória é libertada

    //shared_ptr:
    shared_ptr<int> sp(new int(20)); // Ponteiro inteligente compartilhado
    cout << "Valor apontado por sp: " << *sp << endl;

    // weak_ptr:
    weak_ptr<int> wp(sp); // Ponteiro inteligente fraco
    if (auto spt = wp.lock()) { // Tenta obter um shared_ptr
        cout << "Valor apontado por wp: " << *spt << endl;
    } else {
        cout << "O objeto apontado por wp foi destruído." << endl;
    }

    return 0;
}

// Função principal do programa, vou chamar meus teste de funções aqui
int main(){
    cout << "@ Tamanho de variáveis com sizeof()" << endl;
    tamanhoVariavel();
    cout << "@ Ponteiro" << endl;
    ponteiro();
    cout << "@ Ponteiro Inteligente" << endl;
    ponteiroInteligente();
    return 0;
}