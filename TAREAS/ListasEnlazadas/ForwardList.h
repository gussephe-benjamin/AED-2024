#include<iostream>
using namespace std;


struct Node
{
    int val;
    Node* next;

    Node(int val):val(val),next(nullptr){};
    
};

class ForwardList
{
private:
    Node* head;
public:
    ForwardList();
    ~ForwardList();

    Node* front();

    Node* back();

    void push_front(int);

    void push_back(int);

    void pop_front();

    void pop_back();

    int operator[](int);

    bool empty();

    int size();

    void clear();

    void sort();

    void reverse();

    void printList();
};
