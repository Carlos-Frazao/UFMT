#include<iostream>
#include<array>



int main(){
    std::array<std::array<int, 3>, 3> matriz = {
        std::array{1, 2, 3},
        std::array{4, 5, 6},
        std::array{7, 8, 9}
    };

    for(const auto& linha : matriz){
        for(const auto& elemento : linha){
            std::cout << elemento << " ";
        }
        std::cout << std::endl;
    }


}