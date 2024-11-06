#include"stack.h"

int main() {
    Stack<int> intStack;

    // Apilar elementos en la pila
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    std::cout << "Pila actual: ";
    intStack.display();

    // Obtener el elemento en el tope de la pila
    std::cout << "Tope de la pila: " << intStack.peek() << "\n";

    // Remover el elemento en el tope
    intStack.pop();
    std::cout << "Pila después de hacer pop: ";
    intStack.display();

    return 0;
}