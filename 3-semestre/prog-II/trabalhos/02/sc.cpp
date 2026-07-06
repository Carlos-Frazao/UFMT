#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// CLASSE BASE ABSTRATA (Personagem)
class Personagem {
private:
    // Atributos obrigatórios e encapsulados
    string nome;
    int hp;
    int forca;
    int defesa;

public:
    // Construtor
    Personagem(string n, int h, int f, int d) : nome(n), hp(h), forca(f), defesa(d) {}
    
    // Destrutor virtual para garantir limpeza de memória correta das classes filhas
    virtual ~Personagem() = default;

    // Getters e Setters
    string getNome() const { return nome; }
    int getHp() const { return hp; }
    void setHp(int h) { hp = h; if(hp < 0) hp = 0; } // Impede HP negativo
    int getForca() const { return forca; }
    int getDefesa() const { return defesa; }

    // Método comum para calcular o dano recebido
    virtual void receberDano(int danoBruto) {
        int danoReal = danoBruto - defesa;
        if (danoReal < 0) danoReal = 0; // A defesa absorveu todo o dano
        
        cout << nome << " recebeu " << danoReal << " de dano real!" << endl;
        setHp(hp - danoReal);
    }
    virtual void executarGolpe(Personagem* oponente, bool isBot) = 0;
};

// Lutador Focado em Força e Defesa
class GuerreiroPesado : public Personagem {
public:
    GuerreiroPesado(string n) : Personagem(n, 120, 25, 10) {} 

    void executarGolpe(Personagem* oponente, bool isBot) override {
        int escolha;
        if (isBot) {
            escolha = (rand() % 2) + 1; // Bot escolhe golpe 1 ou 2 aleatoriamente
        } else {
            cout << "\n[Sua vez - " << getNome() << "] Escolha seu ataque:" << endl;
            cout << "1. Soco Destruidor (Dano base + 10 extra)" << endl;
            cout << "2. Cabecada (Dano base x 1.5)" << endl;
            cout << "Opcao: ";
            cin >> escolha;
        }

        cout << "\n>>> " << getNome() << " ataca " << oponente->getNome() << "!" << endl;
        if (escolha == 1) {
            int dano = getForca() + 10;
            cout << "Golpe: Soco Destruidor!" << endl;
            oponente->receberDano(dano);
        } else {
            int dano = getForca() * 1.5;
            cout << "Golpe: Cabecada!" << endl;
            oponente->receberDano(dano);
        }
    }
};

// Lutador Focado em Combos e Agilidade
class LutadorAgil : public Personagem {
public:
    LutadorAgil(string n) : Personagem(n, 80, 35, 5) {}

    void executarGolpe(Personagem* oponente, bool isBot) override {
        int escolha;
        if (isBot) {
            escolha = (rand() % 2) + 1;
        } else {
            cout << "\n[Sua vez - " << getNome() << "] Escolha seu ataque:" << endl;
            cout << "1. Chute Giratorio (Dano base x 2)" << endl;
            cout << "2. Sequencia de Socos (Acerta 3 vezes com 50% de forca)" << endl;
            cout << "Opcao: ";
            cin >> escolha;
        }

        cout << "\n>>> " << getNome() << " ataca " << oponente->getNome() << "!" << endl;
        if (escolha == 1) {
            int dano = getForca() * 2;
            cout << "Golpe: Chute Giratorio!" << endl;
            oponente->receberDano(dano);
        } else {
            cout << "Golpe: Sequencia de Socos!" << endl;
            int danoBase = getForca() * 0.5;
            for(int i = 0; i < 3; i++) {
                if(oponente->getHp() > 0) { // Garante que não continua batendo se o oponente já caiu
                    oponente->receberDano(danoBase);
                }
            }
        }
    }
};

// Função principal vulgo main
int main() {
    srand(time(0)); // Inicializa a semente de aleatoriedade do sistema

    // A. Inicialização (10 personagens predefinidos em memória)
    vector<Personagem*> plantel;
    plantel.push_back(new GuerreiroPesado("Shao Kahn"));
    plantel.push_back(new GuerreiroPesado("Geras"));
    plantel.push_back(new GuerreiroPesado("Kotal Kahn"));
    plantel.push_back(new GuerreiroPesado("Jax Briggs"));
    plantel.push_back(new GuerreiroPesado("Baraka"));
    
    plantel.push_back(new LutadorAgil("Scorpion"));
    plantel.push_back(new LutadorAgil("Sub-Zero"));
    plantel.push_back(new LutadorAgil("Liu Kang"));
    plantel.push_back(new LutadorAgil("Kitana"));
    plantel.push_back(new LutadorAgil("Raiden"));

    cout << "==== SIMULACAO DE COMBATE ====\n" << endl;
    
    // B. Seleção de Combate
    cout << "LUTADORES DISPONIVEIS:" << endl;
    for (int i = 0; i < plantel.size(); i++) {
        cout << "[" << i << "] " << plantel[i]->getNome() 
             << " (HP: " << plantel[i]->getHp() 
             << " | Forca: " << plantel[i]->getForca() 
             << " | Defesa: " << plantel[i]->getDefesa() << ")" << endl;
    }
    
    int escolhaJogador;
    cout << "\nDigite o numero do seu lutador: ";
    cin >> escolhaJogador;

    // Sistema define o oponente aleatoriamente, garantindo que seja diferente do jogador
    int escolhaBot;
    do {
        escolhaBot = rand() % 10;
    } while (escolhaBot == escolhaJogador);

    Personagem* jogador = plantel[escolhaJogador];
    Personagem* oponente = plantel[escolhaBot];

    cout << "\nVOCE ESCOLHEU: " << jogador->getNome() << endl;
    cout << "SISTEMA ESCOLHEU: " << oponente->getNome() << endl;
    cout << "Pressione ENTER para iniciar a batalha!";
    cin.ignore();
    cin.get(); 

    // Loop de Turnos
    int rodada = 1;
    while (jogador->getHp() > 0 && oponente->getHp() > 0) {
        cout << "\n================ RODADA " << rodada << " ================" << endl;
        cout << "[" << jogador->getNome() << " - HP: " << jogador->getHp() << "]" << endl;
        cout << "[" << oponente->getNome() << " - HP: " << oponente->getHp() << "]" << endl;
        cout << "------------------------------------------" << endl;

        // Turno do Jogador (isBot = false)
        jogador->executarGolpe(oponente, false);

        if (oponente->getHp() <= 0) break; // Interrompe imediatamente se a vida zerar

        // Turno do Sistema (isBot = true)
        oponente->executarGolpe(jogador, true);
        
        rodada++;
    }

    // Condição de encerramento
    cout << "\n=========== FIM DE COMBATE ===========" << endl;
    if (jogador->getHp() > 0) {
        cout << "O VENCEDOR FOI O USUARIO COM O LUTADOR " << jogador->getNome() << "!" << endl;
    } else {
        cout << "O VENCEDOR FOI O SISTEMA COM O LUTADOR " << oponente->getNome() << "!" << endl;
    }

    // Limpeza rigorosa de memória (boas práticas de C++)
    for (Personagem* p : plantel) {
        delete p;
    }

    return 0;
}