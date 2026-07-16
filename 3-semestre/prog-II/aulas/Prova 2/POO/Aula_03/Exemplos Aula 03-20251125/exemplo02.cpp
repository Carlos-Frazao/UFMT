#include <iostream>
#include <cstdlib> // Para std::abort() ou similar, se necessário para simular falhas.

// Demonstra o Vazamento de Memória (Memory Leak)
void demonstrate_memory_leak() {
    // 1. Aloca memória (na heap)
    int* data = new int(100);

    std::cout << "  - Alocado " << *data << " na memória dinâmica. Endereço: " << data << std::endl;

    // 2. O 'delete data;' foi esquecido.
    // O ponteiro 'data' sai do escopo, mas a memória alocada permanece vazando.
}

// Demonstra o Uso Após Liberação (Use After Free / Dangling Pointer)
void demonstrate_use_after_free() {
    // 1. Aloca memória e inicializa
    int* ptr = new int(42);

    std::cout << "  - Valor inicial: " << *ptr << std::endl;

    // 2. Libera a memória
    delete ptr; // Libera a memória, mas o ponteiro ainda aponta para o endereço antigo (dangling pointer).

    // 3. Tenta usar a memória já liberada (Use After Free)
    // O valor lido ou escrito neste ponto é indefinido e perigoso.
    std::cout << "  - Tentando ler *ptr após o delete: " << *ptr << " (Comportamento Indefinido!)" << std::endl;

    // Mitigação: Atribuindo nullptr.
    ptr = nullptr;
}

// Demonstra a Dupla Liberação (Double Free)
void demonstrate_double_free() {
    // 1. Aloca memória
    int* ptr1 = new int(99);

    // 2. Outro ponteiro aponta para a mesma memória
    int* ptr2 = ptr1;

    std::cout << "  - Endereço compartilhado: " << ptr1 << std::endl;

    // 3. Primeira desalocação
    delete ptr1; // Primeira desalocação.
    std::cout << "  - Primeira desalocação (ptr1) concluída." << std::endl;

    // 4. Segunda desalocação
    // Tentar liberar a mesma memória duas vezes causa corrupção de heap e comportamento indefinido.
    std::cout << "  - Tentando liberar a memória novamente com ptr2..." << std::endl;

    // O bloco try/catch é usado aqui para evitar que o programa trave imediatamente 
    // em ambientes de compilação restritos, embora este 'delete' seja um erro grave.
    try {
        delete ptr2;
        std::cout << "  - WARNING: Double Free pode ter ocorrido sem falha imediata, mas a heap pode estar corrompida." << std::endl;
    } catch (...) {
        std::cout << "  - ERRO: O sistema pode ter detectado e abortado a dupla liberação." << std::endl;
    }
}


int main() {
    std::cout << "===================================================" << std::endl;
    std::cout << "DEMONSTRAÇÃO: Perigos do new e delete" << std::endl;
    std::cout << "===================================================" << std::endl;

    // --- 1. MEMORY LEAK ---
    std::cout << "\n[1] VAZAMENTO DE MEMÓRIA (Memory Leak):" << std::endl;
    demonstrate_memory_leak();
    std::cout << "O ponteiro 'data' saiu do escopo, mas a memória não foi liberada. (Erro: Esquecer de liberar memória)" << std::endl;

    // --- 2. USE AFTER FREE (Dangling Pointer) ---
    std::cout << "\n[2] USO APÓS LIBERAÇÃO (Use After Free):" << std::endl;
    demonstrate_use_after_free();
    std::cout << "O valor lido é indefinido, pois o ponteiro acessou memória liberada. (Erro: Usar ponteiro depois da memória liberada)" << std::endl;

    // --- 3. DOUBLE FREE ---
    std::cout << "\n[3] DUPLA LIBERAÇÃO (Double Free):" << std::endl;
    demonstrate_double_free();
    std::cout << "Tentativa de liberar o mesmo bloco de memória duas vezes. (Erro: Liberando a mesma memória duas vezes)" << std::endl;

    std::cout << "\n===================================================" << std::endl;
    std::cout << "SOLUÇÃO: Usar Smart Pointers!" << std::endl;
    std::cout << "===================================================" << std::endl;

    return 0;
}