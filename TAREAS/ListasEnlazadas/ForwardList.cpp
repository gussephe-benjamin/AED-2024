#include "ForwardList.h"
// Constructor
template <typename T>
ForwardList<T>::ForwardList() : head(nullptr) {}

// Destructor
template <typename T>
ForwardList<T>::~ForwardList() {
    clear();
}

// Devuelve el primer nodo
template <typename T>
Node<T>* ForwardList<T>::front() {
    return head;
}

// Devuelve el último nodo
template <typename T>
Node<T>* ForwardList<T>::back() {
    Node<T>* temp = head;
    if (!temp) return nullptr;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    return temp;
}

// Agrega un nodo al final
template <typename T>
void ForwardList<T>::push_back(T val) {
    Node<T>* nodo_val = new Node<T>(val);
    if (!head) {
        head = nodo_val;
    } else {
        Node<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = nodo_val;
    }
}

// Agrega un nodo al inicio
template <typename T>
void ForwardList<T>::push_front(T val) {
    Node<T>* nodo_val = new Node<T>(val);
    nodo_val->next = head;
    head = nodo_val;
}

// Elimina el nodo al inicio
template <typename T>
void ForwardList<T>::pop_front() {
    if (!head) return;
    Node<T>* temp = head;
    head = head->next;
    delete temp;
}

// Elimina el nodo al final
template <typename T>
void ForwardList<T>::pop_back() {
    if (!head) return;
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Node<T>* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

// Accede al valor por índice
template <typename T>
T ForwardList<T>::operator[](int index) {
    Node<T>* temp = head;
    int count = 0;
    while (temp && count < index) {
        temp = temp->next;
        count++;
    }
    return temp ? temp->val : T(); // Devuelve un valor por defecto si el índice es inválido
}

// Verifica si la lista está vacía
template <typename T>
bool ForwardList<T>::empty() {
    return head == nullptr;
}

// Devuelve el tamaño de la lista
template <typename T>
int ForwardList<T>::size() {
    int count = 0;
    Node<T>* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Limpia la lista
template <typename T>
void ForwardList<T>::clear() {
    while (head) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

// Ordena la lista usando Merge Sort
template <typename T>
Node<T>* merge(Node<T>* left, Node<T>* right) {
    if (!left) return right;
    if (!right) return left;
    if (left->val <= right->val) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}

template <typename T>
Node<T>* mergeSort(Node<T>* head) {
    if (!head || !head->next) return head;
    Node<T>* slow = head;
    Node<T>* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node<T>* mid = slow->next;
    slow->next = nullptr;
    return merge(mergeSort(head), mergeSort(mid));
}

template <typename T>
void ForwardList<T>::sort() {
    head = mergeSort(head);
}

// Invierte la lista
template <typename T>
void ForwardList<T>::reverse() {
    Node<T>* prev = nullptr;
    Node<T>* current = head;
    Node<T>* next = nullptr;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

// Imprime la lista
template <typename T>
void ForwardList<T>::printList() {
    Node<T>* temp = head;
    while (temp) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}
