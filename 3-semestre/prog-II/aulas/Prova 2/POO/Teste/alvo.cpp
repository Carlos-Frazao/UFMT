#include <iostream>

int main() {
    // Vamos tentar mudar essa palavra de "ERRO" para "BOM!" no binário
    // IMPORTANTE: A nova palavra deve ter exatamente o mesmo tamanho (4 letras)
    const char* mensagem = "ERRO"; 
    
    std::cout << "Status do sistema: " << mensagem << std::endl;
    
    return 0;
}
// ERRO: 0045 5252 4f00
// BOM!: 0042 4f4d 2100