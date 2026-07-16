#include <iostream>
#include <string>

//FUNÇÃO PARA VERIFICAR A SENHA, VERIFICAR AS CONDIÇÕES
bool verificar_senha (const std::string &senha) {
    //ESSE length ELE VAI ME AJUDAR A SABER SE O TAMANHO DA STRING É MENOR DO QUE 8 CARACTERE
    if (senha.length() < 8) {
        return false;
    }

    //CRIANDO VERIFICAÇÕES E INICIANDO COM "false" PARA FAZER A VERIFICAÇÃO LOGO ABAIXO
    bool tem_maiuscula = false;
    bool tem_minuscula = false;
    bool tem_digito = false;
    bool tem_simbolo = false;
    //PASSANDO PELO PRESUPOSTO QUE NÃO TENHA NADA 

    for (char ch : senha) {
        if (std::isupper(ch)) {
            tem_maiuscula = true;
        } else if (std::islower(ch)) {
            tem_minuscula = true;
        } else if (std::isdigit(ch)) {
            tem_digito = true;
        } else if (std::ispunct(ch)) {
            tem_simbolo = true;
        }
    }

    // A senha só é válida se TODAS as flags forem verdadeiras
        return tem_maiuscula && tem_minuscula && tem_digito && tem_simbolo;
}

int main() {
    std::string senha;

    //ENTRADA DE DADOS DO USUÁRIO
    std::cout << "\nDigite sua senha: ";
    std::getline(std::cin, senha);

    //VERIFICANDO A SENHA USANDO A FUNÇÃO
    if (verificar_senha(senha)) {
        std::cout << "\nResultado: Senha valida." << std::endl;
    }else {
        std::cout << "\nResultado: Senha invalida. Nao atende aos requisitos minimos." << std::endl;
    }

    return 0;
}