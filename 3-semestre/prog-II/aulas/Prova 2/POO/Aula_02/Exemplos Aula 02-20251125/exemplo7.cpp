#include <iostream>

int main(){
    int ival = 42;
    int *p = &ival;

    *p = 7;

    std::cout << ival << std::endl;
    
}