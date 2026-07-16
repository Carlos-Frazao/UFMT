#include <iostream>
#include <string>
#include <vector>

// 1. Classe Abstrata Notificacao
class Notificacao {
public:
    // Método puramente virtual
    virtual void enviar(std::string msg) = 0;

    // Destrutor virtual obrigatório para garantir limpeza correta da memória
    virtual ~Notificacao() {}
};

// 2. Classes Deriva
class Email : public Notificacao {
private:
    std::string destinatario;
    std::string assunto;
public:
    Email(std::string dest, std::string ass) : destinatario(dest), assunto(ass) {}

    void enviar(std::string msg) override {
        std::cout << "[EMAIL] Para: " << destinatario << "\n";
        std::cout << "Assunto: " << assunto << "\n";
        std::cout << "Corpo: " << msg << "\n";
    }
};

class SMS : public Notificacao {
private:
    std::string numero;
public:
    SMS(std::string num) : numero(num) {}

    void enviar(std::string msg) override {
        std::cout << "[SMS] Enviando para " << numero << ": " << msg << "\n";
    }
};

class PushNotification : public Notificacao {
private:
    std::string device;
    std::string app;
public:
    PushNotification(std::string d, std::string a) : device(d), app(a) {}

    void enviar(std::string msg) override {
        std::cout << "[PUSH] App: " << app << " | Device: " << device << "\n";
        std::cout << "Msg: " << msg << "\n";
    }
};

// Código principal 
int main() {
    std::cout << "--- Sistema de Alerta de Servidores ---\n";

    // Vetor de ponteiros para a classe BASE
    std::vector <Notificacao*> canais;
    canais.push_back(new Email("admin@sys.com", "FALHA CRITICA"));
    canais.push_back(new SMS("11 -99999 -8888: "));
    canais.push_back(new PushNotification("Device -X", "MonitorApp"));
    std::cout << ">>> Ocorreu um erro no Servidor DB -01! Enviando alertas ...\n" << std::endl;
    std:: string erro = "O servidor parou de responder.";

    // Loop Polimorfico
    for (Notificacao* canal : canais) {
    canal ->enviar(erro); // Cada objeto reage de uma forma
    std::cout << "\n";
    }

    // Limpeza
    for (auto c : canais) delete c;
    canais.clear();
    return 0;
}

/*Requisitos das Classes
    1. Classe Abstrata Notificacao:
        •Metodo puramente virtual: virtual void enviar(string msg) = 0;
        •Destrutor virtual obrigat ́orio.
    2. Classes Derivadas (Email, SMS, PushNotification):
        •Cada uma deve implementar o m ́etodo enviar formatando a sa ́ıda de maneira  ́unica (ex: SMS
        exibe n ́umero, Email exibe assunto).
    
    Saida Esperada:
        --- Sistema de Alerta de Servidores ---
    >>> Ocorreu um erro no Servidor DB-01! Enviando alertas...
    [EMAIL] Para: admin@empresa.com
    Assunto: FALHA CRITICA
    Corpo: O servidor parou de responder.
    [SMS] Enviando para 11-99999-8888: O servidor parou de responder.
    [PUSH] App: MonitorApp | Device: Device-X
    Msg: O servidor parou de responder.
*/