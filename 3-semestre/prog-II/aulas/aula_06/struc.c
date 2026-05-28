#include <stdio.h>
#include <string.h>

// Definindo a struct Pessoa
struct Pessoa {
    char nome[50];
    int idade;
    float altura;
};

int main() {
    // Declarando uma variável do tipo struct Pessoa
    struct Pessoa p1;

    // Atribuindo valores aos campos usando o operador ponto (.)
    strcpy(p1.nome, "Ana");
    p1.idade = 28;
    p1.altura = 1.68;

    // Acessando e imprimindo os valores
    printf("Nome: %s\n", p1.nome);
    printf("Idade: %s\n", p1.idade); // Erro de formato int (%d)
    printf("Altura: %.2f\n", p1.altura);

    return 0;
}