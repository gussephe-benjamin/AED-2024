#include <iostream>
using namespace std;

// Función que realiza varias operaciones usando punteros
int f(int x, int *py, int **ppz) {
    int y, z;

    **ppz += 1; // Incrementa el valor al que apunta **ppz (es decir, 'c') en 1
    z = **ppz;  // Asigna el nuevo valor de **ppz a 'z'
    *py += 2;   // Incrementa el valor al que apunta 'py' (es decir, 'c') en 2
    y = *py;    // Asigna el nuevo valor de *py a 'y'
    x += 3;     // Incrementa el valor de 'x' en 3

    cout << x << endl; // Imprime el valor de 'x'
    cout << y << endl; // Imprime el valor de 'y'
    cout << z << endl; // Imprime el valor de 'z'

    return x + y + z;  // Devuelve la suma de 'x', 'y' y 'z'
}

int main() {
    int c, *b, **a;
    c = 4;    // Inicializa 'c' con 4
    b = &c;   // 'b' apunta a 'c'
    a = &b;   // 'a' apunta a 'b'

    // **a += 1; // Incrementa 'c' en 1, es lo mismo que **a += 1

    // cout << c << endl; // Imprime el valor de 'c'
    // cout << *b << endl; // Imprime el valor al que apunta 'b' (que es 'c')
    // cout << **a << endl; // Imprime el valor al que apunta 'a' (que es 'b', y 'b' apunta a 'c')

    cout << f(c, b, a) << endl; // Llama a la función 'f' con 'c', 'b' y 'a', e imprime el resultado

    return 0;
}


/*

El error que se cometió en este código es que se está tomando el valor entero que pasa por la función
como un dato que cambia con respecto a los punteros, ese dato es un dato extra, por lo tanto
se mentiene en la función, sin embargo en el main si se modifica debido a que estos punteros apuntan a
la variable fuera de la función.

*/