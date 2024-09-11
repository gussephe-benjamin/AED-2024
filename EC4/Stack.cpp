#include"Stack.h"




int main(){

    Stack<int> s1;

    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(6);
    s1.push(7);
    s1.push(8);
    s1.push(9);
    s1.push(10);

    s1.printStack();

    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();

    s1.printStack();

    cout << s1.peek() << endl;
    


}