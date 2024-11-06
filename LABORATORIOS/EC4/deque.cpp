#include"MyCircularDeque.h"

int main() {
    MyCircularDeque deque(5); // Crear un deque circular con capacidad 5

    deque.insertLast(1);    // Deque: 1
    deque.insertLast(2);    // Deque: 1 2
    deque.insertFront(0);   // Deque: 0 1 2
    deque.insertFront(-1);  // Deque: -1 0 1 2
    deque.insertLast(3);    // Deque: -1 0 1 2 3

    cout << "Front element: " << deque.getFront() << endl; // Imprime: -1
    cout << "Rear element: " << deque.getRear() << endl;   // Imprime: 3

    deque.printDeque(); // Imprime: -1 0 1 2 3

    deque.deleteFront(); // Deque: 0 1 2 3
    deque.deleteLast();  // Deque: 0 1 2

    deque.printDeque(); // Imprime: 0 1 2

    return 0;
}
