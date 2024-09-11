
#include<iostream>
using namespace std;

struct Node
{
    int val;
    Node * next;
    Node * prev;

    Node(): next(nullptr),prev(nullptr){};
};

class DList{

private:

    Node * head;

    Node * tail;

public:

    Node* front();

    Node* back();

    void push_front(int);

    void push_back(int);

    void pop_back();

    void pop_front();

    void insert(Node*,int ); // inserta en cualquier posición 

    void remove(int); // elimina en cualquier posición

    int operator[](int); // retorna el elemento en la posición indicada

    bool empty();

    int size();

    void clear();

    void reverse();
};

