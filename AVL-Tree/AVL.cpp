#include"AVL.h"

int main() {
    AVLTree avl;  // Crear una instancia del árbol AVL

    // Insertar valores en el árbol AVL
    avl.SearchInsert(10);  // Insertar 10
    avl.SearchInsert(20);  // Insertar 20
    avl.SearchInsert(30);  // Insertar 30 - Esto debería provocar una rotación
    avl.SearchInsert(25);  // Insertar 25
    avl.SearchInsert(5);   // Insertar 5

    // Mostrar el árbol antes de eliminar
    std::cout << "Arbol AVL antes de la eliminacion:" << std::endl;
    avl.mostrar();  // Mostrar el árbol AVL

    // Eliminar un nodo
    avl.eliminar(20);  // Eliminar el nodo con el valor 20

    // Mostrar el árbol después de la eliminación
    std::cout << "Arbol AVL despues de la eliminacion:" << std::endl;
    avl.mostrar();  // Mostrar el árbol AVL

    return 0;
}