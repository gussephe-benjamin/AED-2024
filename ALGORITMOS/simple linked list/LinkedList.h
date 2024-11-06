#include<iostream>
using namespace std;

// Estructura del nodo
struct Node {
    int val;
    Node* next;

    Node(int valor) : val(valor), next(nullptr) {} // Agregar solo valor
    Node(int valor, Node* siguiente) : val(valor), next(siguiente) {} // Agregar valor y siguiente nodo
};

// Clase LinkedList
class LinkedList {
private:
    Node* head;
    int list_size; // Atributo para almacenar el tamaño de la lista

public:
    LinkedList() : head(nullptr), list_size(0) {} // Constructor por defecto inicializando en nullptr

    LinkedList(Node* head) : head(head), list_size(1) {} // Inicializar la lista con un nodo

    // Retorna el primer nodo (head)
    Node* front() {
        return head;
    }

    // Retorna el último nodo de la lista
    Node* back() {
        if (head == nullptr) return nullptr; // Si la lista está vacía, retorna nullptr

        Node* temp = head;
        while (temp->next != nullptr) { // Busca el último nodo
            temp = temp->next;
        }
        return temp;
    }

    // Agregar un valor al inicio de la lista
    void push_front(int v) {
        Node* newNode = new Node(v);
        newNode->next = head;
        head = newNode;
        list_size++; // Aumentar tamaño de la lista
    }

    // Agregar un valor al final de la lista
    void push_back(int v) {
        Node* newNode = new Node(v);

        if (head == nullptr) { // Si la lista está vacía
            head = newNode;
        } else {
            Node* last = back();
            last->next = newNode; // Agregar nuevo nodo al final
        }
        list_size++; // Aumentar tamaño de la lista
    }

    // Eliminar el primer elemento de la lista
    void pop_front() {
        if (head == nullptr) return; // Si la lista está vacía, no hacer nada

        Node* temp = head;
        head = head->next;
        delete temp; // Liberar memoria
        list_size--; // Disminuir tamaño de la lista
    }

    // Eliminar el último elemento de la lista
    void pop_back() {
        if (head == nullptr) return; // Si la lista está vacía, no hacer nada

        if (head->next == nullptr) { // Si solo hay un nodo
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next->next != nullptr) { // Buscar el penúltimo nodo
                temp = temp->next;
            }
            delete temp->next; // Eliminar el último nodo
            temp->next = nullptr;
        }
        list_size--; // Disminuir tamaño de la lista
    }

    // Operador para obtener el valor en una posición específica (ejemplo, list[3])
    int operator[](int index) {
        if (index >= list_size || index < 0) return -1; // Validar rango

        Node* temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        return temp->val;
    }

    // Verificar si la lista está vacía
    bool empty() {
        return head == nullptr;
    }

    // Retornar el tamaño de la lista
    int size() {
        return list_size;
    }

    // Limpiar la lista (eliminar todos los nodos)
    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    // Revertir la lista enlazada
    void reverse() {
        if (head == nullptr || head->next == nullptr) return; // Si está vacía o solo tiene un nodo

        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next; // Guardar el siguiente nodo
            current->next = prev; // Revertir el enlace
            prev = current; // Mover prev a current
            current = next; // Mover current al siguiente nodo
        }
        head = prev; // Actualizar head al nuevo inicio de la lista
    }

    // Imprimir la lista enlazada
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    // Destructor para limpiar la memoria
    ~LinkedList() {
        clear(); // Liberar todos los nodos
    }
};
