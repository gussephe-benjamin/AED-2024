#include <iostream>
#include "LinkedList.h"
using namespace std;

// Funcion para mostrar el menu y permitir la interaccion con el usuario
void menu(LinkedList list) {
    int opcion, valor;

    do {
        system("cls"); // Limpiar la pantalla (solo funciona en Windows)
        cout << "\n------ MENU ------" << endl;
        cout << "1. Agregar al frente" << endl;
        cout << "2. Agregar al final" << endl;
        cout << "3. Eliminar del frente" << endl;
        cout << "4. Eliminar del final" << endl;
        cout << "5. Ver primer elemento (front)" << endl;
        cout << "6. Ver ultimo elemento (back)" << endl;
        cout << "7. Verificar si la lista esta vacia" << endl;
        cout << "8. Ver tamano de la lista" << endl;
        cout << "9. Imprimir lista" << endl; // Nueva opcion para imprimir la lista
        cout << "10. Revertir la lista" << endl;
        cout << "11. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Ingrese un valor para agregar al frente: ";
            cin >> valor;
            list.push_front(valor);
            break;
        case 2:
            cout << "Ingrese un valor para agregar al final: ";
            cin >> valor;
            list.push_back(valor);
            break;
        case 3:
            if (!list.empty()) {
                list.pop_front();
                cout << "Se elimino el primer elemento." << endl;
            } else {
                cout << "La lista esta vacia." << endl;
            }
            break;
        case 4:
            if (!list.empty()) {
                list.pop_back();
                cout << "Se elimino el ultimo elemento." << endl;
            } else {
                cout << "La lista esta vacia." << endl;
            }
            break;
        case 5:
            if (!list.empty()) {
                cout << "Primer elemento: " << list.front()->val << endl;
            } else {
                cout << "La lista esta vacia." << endl;
            }
            break;
        case 6:
            if (!list.empty()) {
                cout << "Ultimo elemento: " << list.back()->val << endl;
            } else {
                cout << "La lista esta vacia." << endl;
            }
            break;
        case 7:
            cout << (list.empty() ? "La lista esta vacia." : "La lista no esta vacia.") << endl;
            break;
        case 8:
            cout << "Tamano de la lista: " << list.size() << endl;
            break;
        case 9:
            cout << "Elementos de la lista: ";
            list.printList(); // Imprimir la lista
            break;
        case 10:
            list.reverse();
            cout << "La lista ha sido revertida." << endl;
            break;
        case 11:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opcion no valida." << endl;
        }

        cout << "\nPresiona cualquier tecla para continuar...";
        cin.ignore();
        cin.get();  // Espera que el usuario presione una tecla
    } while (opcion != 11);
}


int main() {
    // Crea una lista enlazada vacía
    LinkedList l1;
    menu(l1);  // Llama al menú para interactuar con la lista
    return 0;
}
