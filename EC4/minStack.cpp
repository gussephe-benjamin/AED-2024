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

class MinStack {
private:
    Stack<int> valores; // Pila principal
    Stack<int> min;     // Pila para los mínimos

public:
    MinStack() {}

    void push(int val) {
        // Insertamos en la pila principal
        valores.push(val);

        // Si la pila de mínimos está vacía o el nuevo valor es menor o igual al mínimo actual, lo añadimos a la pila de mínimos
        if (min.isEmpty() || val <= min.peek()) {
            min.push(val);
        }
    }

    void pop() {
        // Si el valor que se va a eliminar es el mínimo actual, también lo eliminamos de la pila de mínimos
        if (valores.peek() == min.peek()) {
            min.pop();
        }
        valores.pop();
    }

    int top() {
        return valores.peek();
    }

    int getMin() {
        return min.peek();
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << "Minimum: " << minStack.getMin() << endl; // return -3
    minStack.pop();
    cout << "Top: " << minStack.top() << endl;        // return 0
    cout << "Minimum: " << minStack.getMin() << endl; // return -2

    return 0;
}
