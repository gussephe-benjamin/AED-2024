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
class Stack {
private:
    Node<T>* top; // Puntero al nodo en el tope de la pila

public:
    Stack() : top(nullptr) {}

    // Verifica si la pila está vacía
    bool isEmpty() {
        return top == nullptr;
    }

    // Añade un elemento al tope de la pila
    void push(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = top; // El nuevo nodo apunta al nodo actual en el tope
        top = newNode;       // El tope se convierte en el nuevo nodo
    }

    // Remueve el elemento en el tope de la pila y lo devuelve
    void pop() {
        if (isEmpty()) {
            std::cout << "La pila está vacía, no se puede hacer pop.\n";
            return;
        }
        Node<T>* temp = top;
        top = top->next; // Mueve el tope al siguiente nodo
        delete temp;     // Libera el nodo anterior
    }

    // Devuelve el elemento en el tope de la pila
    T peek() {
        if (isEmpty()) {
            std::cout << "La pila está vacía.\n";
            return T(); // Devuelve un valor por defecto de tipo T
        }
        return top->data;
    }

    // Muestra todos los elementos en la pila
    void display() {
        if (isEmpty()) {
            std::cout << "La pila está vacía.\n";
            return;
        }

        Node<T>* current = top;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }

    // Destructor para liberar memoria
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};
