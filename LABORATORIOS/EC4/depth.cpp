#include<iostream>
#include"Stack.h"
using namespace std;

struct depth{
private:

    Stack<string> p;

    string s ;

public:
    depth(string st){
        s = st;
    }




public:

    void stackk(){
        while(!p.isEmpty()){

              cout << p.peek() << endl;
              p.pop();  
        }
    }

    int getOutput(){

        int c1 = 0;
        int c2 = 0;

        for (size_t i = 0; i < s.size(); i++)
        {
            string caracter;
            caracter = s.at(i);

            if(caracter == "("){
                p.push(caracter);
                c1 ++;

            } else if(caracter == ")"){
                p.pop();
                c1 --;
            }

            if(c1 > c2){ c2 = c1;}
        }
        return c2;
    }
};

int main(){

    string s1 = "8*((1*(5+6))*(8/6))";

    depth p1(s1);

    cout << p1.getOutput() ;

}