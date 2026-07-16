#include <iostream>
#include <string>

//FAZENDO A FUNÇÃO DATA
std::string formata_data(const std::string& dia, const std::string& mes, const std::string& ano) {
    return dia + "/" + mes + "/" + ano;
}

int main() {
    //ENTRADA DE DADOS/DATA
    std::string d = "21";
    std::string m = "10";
    std::string a = "2025";

    //SAÍDA DE DADOS DA DATA FORMATADA
    std::string data_formatada1 = formata_data(d, m, a);
    std::cout << "Retorno: " << data_formatada1 << std::endl;

    return 0;

}