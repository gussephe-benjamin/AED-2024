#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};




int main (){

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;



    while (current != nullptr) {

        next = current->next; // next = 2
        
        current->next = prev; // next del head = null

        prev = current; // prev = Nodo(1)

        current = next; // current = 2
        
    }

    while(prev != nullptr){
        cout << prev->val << " ";
        prev=prev->next;
    }

}