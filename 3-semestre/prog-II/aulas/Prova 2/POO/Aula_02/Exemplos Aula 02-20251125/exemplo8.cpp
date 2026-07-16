#include <iostream>

int fact(int val){
    int ret = 1;
    while(val > 1)
        ret *= val--;
    return ret;
}

void reset (int *p){
    *p = 0;
}



int main(){
    int val = 5;
    int j = fact(val);
    //std::cout << j << std::endl;
    //std::cout << val << std::endl;

    reset(&val);
    std::cout << val << std::endl;
}
