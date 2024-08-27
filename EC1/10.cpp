#include<iostream>
using namespace std;

// void selectionSort(int * arr, int n) {
//     int i, j, min_idx;

//     for (i = 0; i < n - 1; i++) {
//         min_idx = i;

//         for (j = i + 1; j < n; j++) {
//             if (arr[j] < arr[min_idx]) {
//                 min_idx = j;
//             }
//         }

//         if (min_idx != i) {
//             swap(arr[min_idx], arr[i]);
//         }
//     }
// }

void selectionSort(int *arr, int n) {
    int *i, *j, *min_ptr;

    // Recorre el array usando punteros
    for (i = arr; i < arr + n - 1; i++) {
        min_ptr = i; // Establece el puntero min_ptr al primer elemento de la sublista no ordenada

        // Encuentra el menor elemento en la sublista no ordenada
        for (j = i + 1; j < arr + n; j++) {
            if (*j < *min_ptr) {
                min_ptr = j; // Actualiza min_ptr si encuentra un elemento menor
            }
        }

        // Intercambia el menor elemento encontrado con el primer elemento de la sublista no ordenada
        if (min_ptr != i) {
            swap(*min_ptr, *i);
        }
    }
}

// basicamente se usa el concepto de iteradores y saber como usarlos, ademas recordar que los arrays
// como parametro de una función pueden entrar como puntero. 

int main (){

    int n = 5;

    int arr[5];

    arr[0] = 3;
    arr[1] = 0;
    arr[2] = 5;
    arr[3] = 1;
    arr[4] = 2;
    arr[5] = 4;

    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

   
    selectionSort(arr, n);


    for (size_t i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl << "a";
        




}