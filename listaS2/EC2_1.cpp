#include<iostream>
using namespace std;

struct Node
{
    Node* next;
    int val;
     Node(int x) : val(x), next(nullptr) {}
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}



int main(){

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(6);
    head->next->next->next = new Node(3);
    head->next->next->next->next=new Node(4);
    head->next->next->next->next->next=new Node(5);
    head->next->next->next->next->next->next=new Node(6);

    int val = 6;
    Node * temp = head;
    Node* prev = nullptr;


    while (temp != nullptr )
    {
        if (temp->val == val) {

            prev->next = temp->next;
            delete temp;
            temp = prev->next;
        }else{
            prev = temp;
            temp=temp->next;
        }
        
    }

    printList(head);

    cout << endl;   

}