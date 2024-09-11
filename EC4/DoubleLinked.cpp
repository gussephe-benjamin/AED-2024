#include"DoubleLinked.h"

Node* DList::front(){
    return head;
}

Node* DList::back(){
    return tail;
}

bool DList::empty(){

    if(head == nullptr && tail == nullptr){
        return true;
    } else{
        return false;
    }
}

int DList::size(){

    int contador = 0;

    Node * temp = head;

    while (temp != tail)
    {
        temp = temp->next;
        contador ++;
    }
    
    return contador;
}

void DList::clear(){    

    Node * temp = nullptr;

    while(head != nullptr){
        
        temp = head;

        head = head->next;

        head->prev = nullptr;

        delete temp;

    }
}

void DList::reverse(){

    Node * temp = nullptr;

    temp = head;

    head = tail;

    tail = temp;

}


