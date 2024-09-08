
#include"ForwardList.h"


int main(){

ForwardList l1;

l1.push_back(1);
l1.push_back(2);
l1.push_back(3);
l1.push_back(4);

l1.push_front(10);
l1.push_front(9);
l1.push_front(8);
l1.push_front(7);

l1.pop_front();
l1.pop_back();


l1.printList();

cout << endl;

cout << l1[2] << endl;

cout << l1.empty() << endl;

cout << l1.size() << endl;

cout << " - - - " << endl;

cout << endl;

l1.reverse();

cout << endl;

cout << " - - - " << endl;

l1.printList();

cout << endl;

cout << " - - - " << endl;
cout << endl;

l1.sort();


cout << " - - - " << endl;

l1.printList();

cout << endl;

cout << " - - - " << endl;

l1.clear();

cout << endl;

cout << " - - - " << endl;

cout << endl;

l1.printList();

cout << endl;

cout << " - - - " << endl;



}