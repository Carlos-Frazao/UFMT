#include<iostream>
#include<vector>

int main(){
    std::vector<std::string> nomes = {"Ana", "Bruno", "Carlos", "Diana"};
    std::vector<std::string> nomes2 = {"Ana", "Bruno", "Carlos", "Diana"};
    nomes.push_back("Eduardo");
    std::cout << "Tamanho: " << nomes.size() << std::endl;
    nomes.pop_back();
    std::cout << "Tamanho: " << nomes.size() << std::endl;
    std::cout << (nomes == nomes2 ? "iguais" : "diferentes") << std::endl;

}