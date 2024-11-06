#include <iostream>
using namespace std;

// Definición de la estructura de un nodo
struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};



int main(){

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    

    int n = 0;
    Node* temp = head;

    while(temp != nullptr){
        cout << temp->val << " ";
        temp = temp->next;
    	n += 1;
    }
    cout  << endl;

    cout << n << endl;

    if(n %2 == 0){

        n = n/2;

   

    Node * temp1 = head;

    for (size_t i = 0; i < n; i++)
    {
        temp1 = temp1->next;
               
    }

    cout << endl;

    Node * aputador = temp1;

    while (aputador != nullptr)
    {   
        cout << aputador->val << " ";
        aputador = aputador->next;
    }
    cout << endl;

    } else{

        n = (n/2) + 1;
        cout << n << endl;


        Node * apuntador;
        Node * temp = head;

        for (size_t i = 0; i < n - 1; i++)
        {
            temp = temp->next;
        }
        cout << endl;
        while (temp != nullptr)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
        

        


    }
    
}