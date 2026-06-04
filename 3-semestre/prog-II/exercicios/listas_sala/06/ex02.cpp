#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> numeros;

    // Inserindo itens no início e no final
    numeros.push_back(10);  // Lista: [10]
    numeros.push_front(5);  // Lista: [5, 10]
    numeros.push_back(20);  // Lista: [5, 10, 20]
    numeros.push_front(10); // Lista: [10, 5, 10, 20]

    cout << "Tamanho inicial da lista: " << numeros.size() << endl;

    // Removendo itens específicos por valor (remove todas as ocorrências do 10)
    numeros.remove(10);

    cout << "Tamanho apos remover os '10's: " << numeros.size() << endl;

    // Exibindo os itens restantes
    cout << "Itens na lista: ";
    for (int num : numeros) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}