#include <iostream>
#include <string>

class PersonagemRPG {
private:
    std::string nome;
    int nivel;
    int vidaAtual;
    int vidaMaxima;
    int experiencia;

    // Método auxiliar para recalcular vida máxima baseado no nível
    void atualizarVidaMaxima() {
        vidaMaxima = nivel * 50;
    }

public:
    // Construtor
    PersonagemRPG(std::string n) : nome(n) {
        nivel = 1;
        experiencia = 0;
        atualizarVidaMaxima();
        vidaAtual = vidaMaxima;
    }

    // Métodos Públicos
    void receberDano(int dano) {
        vidaAtual -= dano;
        if (vidaAtual < 0) {
            vidaAtual = 0;
        }
        std::cout << nome << " recebeu " << dano << " de dano. Vida restante: " << vidaAtual << "/" << vidaMaxima << "\n";
    }

    void curar(int cura) {
        vidaAtual += cura;
        if (vidaAtual > vidaMaxima) {
            vidaAtual = vidaMaxima;
        }
        std::cout << nome << " curou " << cura << " HP. Vida atual: " << vidaAtual << "/" << vidaMaxima << "\n";
    }

    void ganharExperiencia(int xp) {
        experiencia += xp;
        std::cout << nome << " ganhou " << xp << " XP.\n";
        
        // Verifica se subiu de nível (a cada 100 XP)
        while (experiencia >= 100) {
            experiencia -= 100;
            nivel++;
            atualizarVidaMaxima();
            vidaAtual = vidaMaxima; // Cura total ao subir de nível
            std::cout << "*** LEVEL UP! " << nome << " subiu para o nivel " << nivel << "! Vida totalmente restaurada. ***\n";
        }
    }

    void exibirStatus() {
        std::cout << "Status -> Nome: " << nome 
                  << " | Nivel: " << nivel 
                  << " | Vida: " << vidaAtual << "/" << vidaMaxima 
                  << " | XP: " << experiencia << "\n";
    }
};

//Código principal
int main() {
    std::cout << "--- Inicio do Jogo ---\n";
    PersonagemRPG heroi("Aragorn");
    heroi.exibirStatus ();

    // Teste de Dano
    std::cout << "\n--- Batalha contra Orc ---\n";
    heroi.receberDano (30);
    heroi.exibirStatus ();
    
    // TENTATIVA DE TRAPACA (Deve dar erro se descomentado)
    // heroi.vidaAtual = 1000;
    // heroi.nivel = 50;
    // Teste de Cura
    
    std::cout << "\n--- Bebendo Porco ---\n";
    heroi.curar (200); // Nao deve passar da vida maxima!
    heroi.exibirStatus ();
    
    // Teste de L ́ogica de N ́ıvel
    std::cout << "\n--- Ganho de Experiencia ---\n";
    heroi.ganharExperiencia (80);
    heroi.ganharExperiencia (30); // Total 110 XP -> Level Up + Sobra 10 XP
    std::cout << "\n--- Status Final ---\n";
    heroi.exibirStatus ();
    return 0;
}

/*Requisitos da Classe
    •Atributos Privados: Nome, N ́ıvel (inicia em 1), Vida Atual, Vida M ́axima (N ́ıvel * 50), Ex-periˆencia (inicia em 0).
    •Metodos Publico:
        – receberDano(int): Reduz a vida. M ́ınimo zero.
        – curar(int): Aumenta a vida. N ̃ao pode ultrapassar Vida M ́axima.
        – ganharExperiencia(int): Soma XP. A cada 100 XP, sobe de n ́ıvel, recalcula Vida Maxima e cura totalmente.*/
