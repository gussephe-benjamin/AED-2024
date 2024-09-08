#include"ForwardList.h"

Node* ForwardList::front(){
    Node * temp = head;
    return temp;
}


Node* ForwardList::back(){
    Node * temp = head;
    while (temp != nullptr)
    {
        temp = temp->next;
    }
    return temp;
}


void ForwardList::push_back(int val){

    Node * nodo_val = new Node(val);
    Node * temp = head;

    if(temp == nullptr){
        head = nodo_val;
    } else{
    
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = nodo_val;
    }

}

// Agrega un nodo al inicio
void ForwardList::push_front(int val) {

    Node * nodo_val = new Node(val);
    Node * temp = head;

    if(temp == nullptr){
        head = nodo_val;
    }else{
        nodo_val->next = head;
        head = nodo_val;
    }

}

void ForwardList::printList(){

    Node * temp = head;

    while (temp != nullptr)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
}

ForwardList::ForwardList(): head() {
    // Inicializa head como nullptr
}

ForwardList::~ForwardList() {
    clear();  // Libera todos los nodos al destruir el objeto
}

// Elimina el nodo al inicio
void ForwardList::pop_front() {

    Node * temp = nullptr;
    
    temp = head;
    head = head->next;
    delete temp;
}

// Elimina el nodo al final
void ForwardList::pop_back() {

    Node * temp = head;

    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = nullptr;
    
    delete temp->next;
}

// Accede al valor por índice
int ForwardList::operator[](int index) {

    
    Node * temp = head;

    if(index == 0){
        return head->val;
    }
    else if(index < 0 || head == nullptr){
        return 0;
    }
    else{
        int count = 0;
        while(count < index){
            count ++;   
            temp = temp->next;
        }
     return temp->val;
    }   
}

// Verifica si la lista está vacía
bool ForwardList::empty() {
    return head == nullptr? true: false;
}

// Devuelve el tamaño de la lista
int ForwardList::size() {
    Node * temp = head;
    int count = 0;

        while(temp->next != nullptr){
            count ++;   
            temp = temp->next;
        }
        return count;
}

// Limpia la lista
void ForwardList::clear() {

        

        while (head!= nullptr)
        {
            Node * auxiliar = nullptr;
            auxiliar = head;
            head = head->next;
            delete auxiliar;
        }

}

// Ordena la lista

Node* getMiddle(Node* head) {
    if (head == nullptr) return head;

    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* merge(Node* left, Node* right) {
    if (left == nullptr) return right;
    if (right == nullptr) return left;

    Node* result = nullptr;

    if (left->val <= right->val) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

Node* mergeSort(Node* head) {
    // Caso base: lista vacía o de un solo nodo
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Encuentra el punto medio y divide la lista en dos mitades
    Node* middle = getMiddle(head);
    Node* nextToMiddle = middle->next;

    middle->next = nullptr; // Divide la lista en dos partes

    // Ordena ambas mitades
    Node* left = mergeSort(head);
    Node* right = mergeSort(nextToMiddle);

    // Mezcla ambas mitades ordenadas
    Node* sortedList = merge(left, right);

    return sortedList;
}

void ForwardList::sort() {
head = mergeSort(head);
}


// Invierte la lista
void ForwardList::reverse() {

    Node * temp = head;
    Node * retro = nullptr;
    Node * prev = nullptr;

    while ( temp != nullptr)
    {
        prev = retro;   
        retro = temp;

        temp = temp->next;

        retro->next = prev;
    }

    head = retro;
}


