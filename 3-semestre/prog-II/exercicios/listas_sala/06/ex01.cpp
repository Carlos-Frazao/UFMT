#include <iostream>
#include <memory> // Necessário para std::unique_ptr e std::make_unique

using namespace std;

int main() {
    // Código antigo (comentado para referência):
    // int *ptr = new int(42);
    // cout << *ptr << endl;
    // delete ptr;

    // Código refatorado:
    unique_ptr<int> ptr = make_unique<int>(42);

    cout << "Valor armazenado: " << *ptr << endl;

    // O delete não é mais necessário. 
    // A memória será liberada automaticamente ao final da função main.

    return 0;
}