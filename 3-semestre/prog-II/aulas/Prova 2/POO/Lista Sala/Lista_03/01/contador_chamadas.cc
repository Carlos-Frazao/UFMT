#include <iostream> [cite: 15]
#include <cstdlib> //PARA RAND()
#include <ctime> //PARA TIME()

void registrarEvento() { [cite: 15]
    static int eventID = 1; [cite: 12, 10];
    int processingcode = rand(); [cite: 13, 11];

    std::cout << "ID de evento: "
}


int main() {
    srand(time(0));
    std::cout << "--- Registrando 5 eventos ---" << std::endl;
    for (int i = 0; i < 5; i++){
        registrarEvento();
    }
    return 0;
}


#include <iostream> [cite: 15]
#include <cstdlib>  // Para rand() [cite: 16]
#include <ctime>    // Para time() [cite: 17]

void registrarEvento() { [cite: 18]
    static int eventID = 1; [cite: 12, 10]
    int processingCode = rand(); [cite: 13, 11]

    std::cout << "ID de Evento: " << eventID << ", Código de Processamento: " << processingCode << std::endl; [cite: 10, 11]
    eventID++; [cite: 22]
} [cite: 23]

int main() { [cite: 24]
    srand(time(0)); [cite: 25]
    std::cout << "Registrando 5 eventos" << std::endl; [cite: 26, 32]

    for (int i = 0; i < 5; ++i) { [cite: 27]
        registrarEvento(); [cite: 9, 30]
    } [cite: 28]
    return 0; [cite: 31]
}
