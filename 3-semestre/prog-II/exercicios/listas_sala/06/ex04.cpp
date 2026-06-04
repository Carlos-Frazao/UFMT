#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack<string> editor;

    // Empilhando as palavras digitadas
    editor.push("Ola");
    editor.push("mundo");
    editor.push("maravilhoso");

    cout << "Ultima palavra digitada (no topo): " << editor.top() << endl;

    // Simulando um 'Ctrl+Z' (apagando a última palavra)
    cout << "Apagando a ultima palavra..." << endl;
    editor.pop(); 

    cout << "Palavra agora no topo: " << editor.top() << endl;

    return 0;
}