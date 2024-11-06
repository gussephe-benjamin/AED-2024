#include "queue.h"
int main() {
    Queue<int> intQueue;

    // Encolar elementos de tipo int
    intQueue.enqueue(10);
    intQueue.enqueue(20);
    intQueue.enqueue(30);

    std::cout << "Cola de enteros actual: ";
    intQueue.display();

    std::cout << "Frente de la cola de enteros: " << intQueue.getFront() << "\n";

    intQueue.dequeue();
    std::cout << "Cola de enteros después de desencolar un elemento: ";
    intQueue.display();

    Queue<std::string> stringQueue;

    // Encolar elementos de tipo string
    stringQueue.enqueue("Hola");
    stringQueue.enqueue("Mundo");
    stringQueue.enqueue("!");

    std::cout << "Cola de strings actual: ";
    stringQueue.display();

    stringQueue.dequeue();
    std::cout << "Cola de strings luego de desencolar un elemento: ";
    stringQueue.display();
    

    return 0;
}