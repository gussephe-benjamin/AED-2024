#include<iostream>
using namespace std;

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value, Node* nextNode = nullptr) : data(value), next(nextNode) {}
    };

    Node* top; // Apunta al elemento superior de la pila

public:
    Stack() : top(nullptr) {}

    Stack(Node * nuevo) : top(nuevo) {}
    
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(const T& value) {
        top = new Node(value, top);
    }

    void pop() {
        if (isEmpty()) {
            std::cerr << "Stack is empty" << std::endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    T peek() const {
        if (isEmpty()) {
            std::cerr << "Stack is empty" << std::endl;
            exit(EXIT_FAILURE); // Salir del programa si la pila está vacía
        }
        return top->data;
    }

    bool isEmpty() const {
        return top == nullptr;
    }


    void printStack(){

        Node * temp = top;
        cout << endl;
        while(temp != nullptr){
            cout << temp->data << endl;
            temp = temp->next;
        }
        cout << endl;
    }

};