#include<iostream>
using namespace std;

void square(int *p){
    cout << p << endl;
    int a = 10;
    p = &a;
    cout << p << endl;
    *p = (*p) * (*p);
}



// lo que hace la función es que cualquier dirección en memeoria que se le asigne a 
// p no va a servir de nada ya que dentro de square, este apunta a otra variable interna
// de manera que no cambia nada el valor ingresado inicialmente. 

int main (){

int x = 10;

square(&x);

cout << x << endl;

}

// x = 10 y no afecta que la función square modifique esto.