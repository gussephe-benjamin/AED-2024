#include <iostream>
using namespace std;

// Nodo de la lista doblemente enlazada
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

// Deque circular utilizando lista doblemente enlazada
class MyCircularDeque {
private:
    Node* head; // Puntero al nodo "cabeza"
    Node* tail; // Puntero al nodo "cola"
    int size;   // Número de elementos en el deque
    int capacity; // Capacidad máxima del deque

public:
    // Constructor para inicializar el deque con capacidad dada
    MyCircularDeque(int k) : head(nullptr), tail(nullptr), size(0), capacity(k) {}

    // Destructor para liberar la memoria
    ~MyCircularDeque() {
        while (!isEmpty()) {
            deleteFront();
        }
    }

    // Inserta un elemento al frente del deque
    bool insertFront(int value) {
        if (isFull()) {
            return false; // Retorna falso si el deque está lleno
        }
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = tail = newNode;
            head->next = head; // Para hacerlo circular, conecta con sí mismo
            head->prev = head;
        } else {
            newNode->next = head;
            newNode->prev = tail;
            head->prev = newNode;
            tail->next = newNode;
            head = newNode; // Actualiza la cabeza
        }
        size++;
        return true;
    }

    // Inserta un elemento al final del deque
    bool insertLast(int value) {
        if (isFull()) {
            return false; // Retorna falso si el deque está lleno
        }
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = tail = newNode;
            head->next = head; // Para hacerlo circular, conecta con sí mismo
            head->prev = head;
        } else {
            newNode->prev = tail;
            newNode->next = head;
            tail->next = newNode;
            head->prev = newNode;
            tail = newNode; // Actualiza la cola
        }
        size++;
        return true;
    }

    // Elimina un elemento del frente del deque
    bool deleteFront() {
        if (isEmpty()) {
            return false; // Retorna falso si el deque está vacío
        }
        Node* temp = head;
        if (head == tail) { // Solo un elemento
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = tail;
            tail->next = head;
        }
        delete temp;
        size--;
        return true;
    }

    // Elimina un elemento del final del deque
    bool deleteLast() {
        if (isEmpty()) {
            return false; // Retorna falso si el deque está vacío
        }
        Node* temp = tail;
        if (head == tail) { // Solo un elemento
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
        }
        delete temp;
        size--;
        return true;
    }

    // Obtiene el elemento del frente del deque
    int getFront() const {
        if (isEmpty()) {
            return -1; // Retorna -1 si el deque está vacío
        }
        return head->data;
    }

    // Obtiene el elemento del final del deque
    int getRear() const {
        if (isEmpty()) {
            return -1; // Retorna -1 si el deque está vacío
        }
        return tail->data;
    }

    // Verifica si el deque está vacío
    bool isEmpty() const {
        return size == 0;
    }

    // Verifica si el deque está lleno
    bool isFull() const {
        return size == capacity;
    }

    // Imprime el contenido actual del deque
    void printDeque() const {
        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return;
        }
        Node* current = head;
        cout << "Deque: ";
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head); // Recorre circularmente hasta regresar a la cabeza
        cout << endl;
    }
};
