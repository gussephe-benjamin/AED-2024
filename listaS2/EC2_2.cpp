#include<iostream>
using namespace std;

struct Node{
    int val;
    Node * next;
    Node(int x) : val(x), next(nullptr) {}
};


int MCD (int a, int b){
    if (b == 0)
    {
        return a;
    }
    else
    {
        return MCD(b, a%b);
    }
}


class ListSolution{
    public:
    Node * juntar (Node * head){

        if(head == nullptr || head->next == nullptr) return head;



        Node * temp = head;
        Node * auxiliar = nullptr;
        

        while (temp != nullptr && temp->next != nullptr)
        {   
            
                Node * valor = new Node(MCD(temp->val, temp->next->val));
           
                auxiliar = temp->next;
                temp->next = valor;
                valor->next = auxiliar;

                temp = auxiliar; 
        }
        return head;
    }
    
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

    Node * head = new Node(18);
    head->next = new Node(6);
    head->next->next = new Node(10);
    head->next->next->next = new Node(3); 


    printList(head);


    ListSolution sol;
    Node * head2 = sol.juntar(head);
    printList(head2);

    

}