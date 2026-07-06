#include <iostream>

class MatrizDinamica {
private:
    int** matriz;
    int linhas;
    int colunas;

public:
    // Construtor Aloca a matriz no heap
    MatrizDinamica(int l, int c) : linhas(l), colunas(c) {
        matriz = new int*[linhas]; // Aloca array de ponteiros
        for (int i = 0; i < linhas; ++i) {
            matriz[i] = new int[colunas]; // Aloca as colunas para cada linha
            // Inicializando com zero só para deixar limpo
            for(int j = 0; j < colunas; ++j) {
                matriz[i][j] = 0; 
            }
        }
        std::cout << "Matriz " << linhas << "x" << colunas << " alocada.\n";
    }

    // Construtor de Cópi
    MatrizDinamica(const MatrizDinamica& outra) : linhas(outra.linhas), colunas(outra.colunas) {
        matriz = new int*[linhas];
        for (int i = 0; i < linhas; ++i) {
            matriz[i] = new int[colunas];
            for (int j = 0; j < colunas; ++j) {
                // Copia o VALOR real, não o ponteiro
                matriz[i][j] = outra.matriz[i][j]; 
            }
        }
        std::cout << "Copia profunda realizada.\n";
    }

    // Destrutor: Libera a memória para prevenir vazamentos 
    ~MatrizDinamica() {
        for (int i = 0; i < linhas; ++i) {
            delete[] matriz[i]; // Deleta cada linha
        }
        delete[] matriz; // Deleta o array de ponteiros
        std::cout << "Memoria da matriz liberada.\n";
    }
};