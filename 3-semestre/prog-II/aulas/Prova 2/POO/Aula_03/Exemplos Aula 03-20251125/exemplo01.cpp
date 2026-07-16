#include <iostream>

// Objeto global
int globalVar = 0;

void demonstrateLocal() {
	// Objeto local
	int localVar = 0;
	std::cout << "Local variable (inside function): " << localVar << std::endl;
	localVar++;
}

void demonstrateStaticLocal() {
	// Objeto local static
	static int staticLocalVar = 0;
	std::cout << "Static local variable (inside function): " << staticLocalVar << std::endl;
	staticLocalVar++;
}

int main() {
	std::cout << "Global variable (initial): " << globalVar << std::endl;
	globalVar++;

	demonstrateLocal(); // Primeira chamada
	demonstrateLocal(); // Segunda chamada (o valor da variável local será reiniciado)

	demonstrateStaticLocal(); // Primeira chamada
	demonstrateStaticLocal(); // Segunda chamada (o valor da variável estática local será preservado)

	std::cout << "Global variable (final): " << globalVar << std::endl;
	return 0;
}