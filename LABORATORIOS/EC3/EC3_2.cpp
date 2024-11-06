struct Node {
    string url;
    Node* prev;
    Node* next;
    Node(string u) : url(u), prev(nullptr), next(nullptr) {}
};


class BrowserHistory {
    
    Node* head;  // Nodo ficticio al principio de la lista
    Node* tail;  // Nodo ficticio al final de la lista
    Node* current;  // Nodo que representa la página actual



public:
    BrowserHistory(string homepage) {
        
        head = new Node("");  // Nodo ficticio de inicio
        tail = new Node("");  // Nodo ficticio de fin
        head->next = tail;
        tail->prev = head;
        current = new Node(homepage);
        head->next = current;
        current->prev = head;
        current->next = tail;
        tail->prev = current;

    }
    
    void visit(string url) {

        Node* newNode = new Node(url);
        // Elimina todos los nodos hacia adelante del nodo actual
        while (current->next != tail) {
            Node* temp = current->next;
            current->next = temp->next;
            temp->next->prev = current;
            delete temp;
        }
        // Inserta el nuevo nodo
        newNode->prev = current;
        newNode->next = tail;
        current->next = newNode;
        tail->prev = newNode;
        current = newNode;
    }
    
    string back(int steps) {
       while (steps > 0 && current->prev != head) {
            current = current->prev;
            steps--;
        }
        return current->url;

    }
    
    string forward(int steps) {

        while (steps > 0 && current->next != tail) {
            current = current->next;
            steps--;
        }
        return current->url;
    }

    
};