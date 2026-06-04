#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    queue<string> filaImpressao;

    // Documentos entrando na fila
    filaImpressao.push("Relatorio_Mensal.pdf");
    filaImpressao.push("Planilha_Custos.xlsx");
    filaImpressao.push("Foto_Equipe.png");

    cout << "Total de documentos na fila: " << filaImpressao.size() << endl;

    // Processando (removendo) os documentos da fila
    while (!filaImpressao.empty()) {
        cout << "Imprimindo: " << filaImpressao.front() << endl; // Lê o primeiro
        filaImpressao.pop(); // Remove o primeiro da fila
    }

    cout << "Fila vazia. Todos os documentos foram processados." << endl;

    return 0;
}