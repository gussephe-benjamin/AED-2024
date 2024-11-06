#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class Queue {
private:
    Node<T>* front; // Apunta al primer nodo de la cola
    Node<T>* rear;  // Apunta al último nodo de la cola

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Verifica si la cola está vacía
    bool isEmpty() {
        return front == nullptr;
    }

    // Encola un elemento al final de la cola
    void enqueue(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (isEmpty()) {
            front = rear = newNode; // Si la cola está vacía, ambos apuntan al nuevo nodo
        } else {
            rear->next = newNode; // El último nodo actual apunta al nuevo nodo
            rear = newNode;       // Rear se mueve al nuevo nodo
        }
    }

    // Desencola el elemento al frente de la cola
    void dequeue() {
        if (isEmpty()) {
            std::cout << "La cola está vacía, no se puede desencolar.\n";
            return;
        }
        Node<T>* temp = front;
        front = front->next; // El frente se mueve al siguiente nodo
        delete temp;         // Libera el nodo anterior

        // Si el frente es nullptr, entonces la cola está vacía, rear también debe ser nullptr
        if (front == nullptr) {
            rear = nullptr;
        }
    }

    // Obtiene el valor del frente de la cola
    T getFront() {
        if (isEmpty()) {
            std::cout << "La cola está vacía.\n";
            return T(); // Devuelve un valor por defecto del tipo T
        }
        return front->data;
    }

    // Muestra todos los elementos de la cola
    void display() {
        if (isEmpty()) {
            std::cout << "La cola está vacía.\n";
            return;
        }

        Node<T>* current = front;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }

    // Destructor para liberar la memoria
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};