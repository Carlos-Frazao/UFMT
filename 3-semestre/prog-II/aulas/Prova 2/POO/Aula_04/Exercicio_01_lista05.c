#include<iostream>


class Sala{
    public:
    int identificador;
    int capacidade;
    bool disponivel;

    bool reservar(int qteAlunos, std::string tipoUsuario){
        if(tipoUsuario != "Aluno"){
            if (estaDisponivel() && capacidade >= qteAlunos){
                disponivel = false;
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
        
    }

    void liberar(){
        if(!estaDisponivel()){
            disponivel = true;
        }
    }

    bool estaDisponivel(){
        return disponivel;
    }
};

class Usuario{
    public:
    std::string nome;
    std::string tipo;

    void mostrarDados(){
        std::cout << "Nome: " << nome << std::endl;
        std::cout << "Tipo: " << tipo << std::endl;
    }

    void cadastrar(std::string novoNome, std::string novoTipo){
        nome = novoNome;
        tipo = novoTipo;
    }

};

 bool solicitaReserva(Usuario u, Sala s, int qteAlunos){
    if(s.reservar(qteAlunos, u.tipo)){
        std::cout << "Reserva realizada com sucesso!" << std::endl;
        return true;
    }else{
        std::cout << "Reserva nao autorizada." << std::endl;
        return false;
    }
 }

int main(){
    Sala sala1;
    sala1.identificador = 101;
    sala1.capacidade = 30;
    sala1.disponivel = true;

    Usuario professor;
    professor.cadastrar("Dr. Silva", "Professor");
    professor.mostrarDados();

    Usuario aluno;
    aluno.cadastrar("Joao", "Aluno");
    aluno.mostrarDados();

    solicitaReserva(professor, sala1, 25); // Deve autorizar
    solicitaReserva(aluno, sala1, 25);     // Nao deve autorizar

    sala1.liberar(); // Liberar a sala

    solicitaReserva(aluno, sala1, 25);     // Nao deve autorizar

    return 0;
}