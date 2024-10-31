#include"stack.h"

struct Node{

    int val;
    Node * next;

    Node(int v, Node *nxt):val(v),next(nxt){}
    Node(int val): val(val), next(nullptr) {}
    Node(){};
};



class stack
{
private:

    Node * head;

public:
    stack(/* args */);
    ~stack();

    bool isEmpty();

    bool isFull();

    int * top();

    void push();

    void pop();

};

stack::stack(/* args */)
{
}

stack::~stack()
{
}
