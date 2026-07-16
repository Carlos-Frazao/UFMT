#include <iostream>
using namespace std; 

int main() {
    cout << "Bem-vindo ao Sistema de Serviço de Oficina Mecânica!" << endl;
    cout << "Por favor, selecione uma opção:" << endl;
    cout << "1. Agendar serviço" << endl;
    cout << "2. Consultar agendamento" << endl;
    cout << "3. Cancelar agendamento" << endl;
    cout << "4. Sair" << endl;

    int opcao;
    cin >> opcao;

    switch (opcao) {
        case 1:
            cout << "Agendamento de serviço selecionado." << endl;
            // Lógica para agendar serviço
            break;
        case 2:
            cout << "Consulta de agendamento selecionada." << endl;
            // Lógica para consultar agendamento
            break;
        case 3:
            cout << "Cancelamento de agendamento selecionado." << endl;
            // Lógica para cancelar agendamento
            break;
        case 4:
            cout << "Saindo do sistema. Obrigado!" << endl;
            break;
        default:
            cout << "Opção inválida. Por favor, tente novamente." << endl;
            break;
    }

    return 0;
}