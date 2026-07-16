#include <iostream>
#include <memory>

int main() {
    // Cria um shared_ptr apontando para um int
    auto ptr1 = std::make_shared<int>(0);
    std::cout << "Reference count after ptr1 creation: " << ptr1.use_count() << std::endl;

    // Cria outro shared_ptr apontando para o mesmo objeto
    auto ptr2 = ptr1;
    std::cout << "Reference count after ptr2 creation: " << ptr1.use_count() << std::endl;

    // Cria mais um shared_ptr apontando para o mesmo objeto
    auto ptr3(ptr1);
    std::cout << "Reference count after ptr3 creation: " << ptr1.use_count() << std::endl;

    // Destroi ptr2 e ptr3
    ptr2.reset();
    std::cout << "Reference count after ptr2 reset: " << ptr1.use_count() << std::endl;

    ptr3.reset();
    std::cout << "Reference count after ptr3 reset: " << ptr1.use_count() << std::endl;

    // Destroi ptr1
    ptr1.reset();
    std::cout << "Reference count after ptr1 reset: " << ptr1.use_count() << std::endl;

    return 0;
}
