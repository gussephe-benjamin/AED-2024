#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Maneja el caso en el que la cabeza de la lista necesita ser eliminada
        while (head != nullptr && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp; // Libera la memoria del nodo eliminado
        }

        // Ahora `head` es seguro y no tiene el valor `val` en su nodo
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while (temp != nullptr) {
            if (temp->val == val) {
                // Si `prev` es válido, ajusta el puntero `next`
                prev->next = temp->next;
                delete temp; // Libera la memoria del nodo eliminado
                temp = prev->next; // Avanza `temp` al siguiente nodo
            } else {
                prev = temp;
                temp = temp->next;
            }
        }

        return head; 
    }
};

// Función para imprimir la lista (para pruebas)
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Prueba del código con algunos valores de ejemplo
    ListNode* head = new ListNode(6);
    head->next = new ListNode(6);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3); 

    cout << "Lista Original: ";
    printList(head);

    Solution sol;
    ListNode* head2 = sol.removeElements(head, 6);

    cout << "Lista Modificada: ";
    printList(head2);

    return 0;
}
