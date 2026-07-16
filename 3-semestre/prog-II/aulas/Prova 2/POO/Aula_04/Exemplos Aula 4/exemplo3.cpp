#include<iostream>
#include<array>
#include<algorithm>
#include<string>

int main(){
    std::array<std::string, 7> cores {"vermelho", "verde", "azul", "amarelo", "preto", "branco", "cinza"};
    std::sort(cores.begin(), cores.end(), std::greater<std::string>());
    for(const auto& cor : cores){
        std::cout << cor << " ";
    }


}