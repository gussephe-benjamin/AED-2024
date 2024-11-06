#include <iostream>
using namespace std;

// Definición de la estructura de un nodo
struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

// Función para convertir la lista enlazada a un valor decimal
int getDecimalValue(Node* head) {
    int result = 0;
    Node* current = head;
    while (current != nullptr) {
        result = result * 2 + current->val;  // Multiplicamos por 2 y sumamos el valor actual
        current = current->next;
    }
    return result;
}

int main() {
    // Creación de la lista enlazada [1 -> 0 -> 1]
    Node* head = new Node(1);
    head->next = new Node(1);
    head->next->next = new Node(1);
    head->next->next->next = new Node(1);

    // Llamada a la función y salida del resultado
    cout << "El valor decimal es: " << getDecimalValue(head) << endl;

    // Liberar memoria
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
