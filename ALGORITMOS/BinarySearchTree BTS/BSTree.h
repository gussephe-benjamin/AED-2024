#include <iostream>
using namespace std;

template <typename T>
class BSTree {

private:
    struct NodeBT {
        T data;
        NodeBT *left;
        NodeBT *right;

        // Constructor para el nodo
        NodeBT(T value) : data(value), left(nullptr), right(nullptr) {}
    };

    NodeBT *raiz;

    NodeBT * insertTO(NodeBT* raiz, T valor){

        if(raiz == nullptr){ // retorna un nodo con el valor y este sería el ultimo caso de recursividad
            return new NodeBT(valor);
        } 

        if(valor > raiz->data){ // recorre por el lado derecho
            raiz->right = insertTO(raiz->right,valor);
        }

        else if(valor < raiz->data){ // recorre por el dado izquierdo
            raiz->left = insertTO(raiz->left,valor);
        }

        return raiz; // retorna la raiz actualizada
    }

    void mostrar(NodeBT * node, int contador){
        if(node == nullptr){
            return;
        } else {

            mostrar(node->right,contador + 1);

            for (size_t i = 0; i < contador; i++)
            {
                std::cout << "   ";
            }
            std::cout << node->data << std :: endl;

            mostrar(node->left,contador + 1);
        }
    }   

    bool find(NodeBT * raiz, T valor){

        if(raiz == nullptr){
            return false;
        }
        else if(raiz->data == valor){
            return true;
        }
        else if(valor < raiz->data ){
            return find(raiz->left, valor);
        }
        else{
            return find(raiz->right, valor);
        }
    }

    void preOrden(NodeBT* raiz){

        if(raiz == nullptr){
            return;
        } else {
            cout << raiz->data << " - ";
            preOrden(raiz->left);
            preOrden(raiz->right);
        }
    }

    void inOrden(NodeBT* raiz){
         if(raiz == nullptr){
            return;
        } else {

            inOrden(raiz->left);
            cout << raiz->data << " - ";
            inOrden(raiz->right);
        }
    }

    void postOrden(NodeBT* raiz){
         if(raiz == nullptr){
            return;
        } else {

            postOrden(raiz->left);
            postOrden(raiz->right);
            cout << raiz->data << " - ";
        }
    }

    NodeBT* minimo(NodeBT* raiz){
        if(raiz == nullptr){
            return NULL;
        }
        if(raiz->left){
            return minimo(raiz->left);
        }
        else{
            return raiz;
        }
    }

    // Método auxiliar para la eliminación
    NodeBT* remove(NodeBT* node, T value) {
        if (node == nullptr) {
            return nullptr; // No encontrado
        }
        if (value < node->data) {
            node->left = remove(node->left, value);
        } else if (value > node->data) {
            node->right = remove(node->right, value);
        } else {
            // Caso 1: Nodo sin hijos
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            // Caso 2: Nodo con un solo hijo
            else if (node->left == nullptr) {
                NodeBT* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                NodeBT* temp = node->left;
                delete node;
                return temp;
            }
            // Caso 3: Nodo con dos hijos
            else {
                NodeBT* temp = minimo(node->right); // Encontrar el sucesor en el subárbol derecho
                node->data = temp->data;
                node->right = remove(node->right, temp->data); // Eliminar el sucesor
            }
        }
        return node;
    }

public: 
    
    // Constructor
    BSTree() : raiz(nullptr) {}

    void insert(T valor){
        raiz = insertTO(raiz, valor);
    }

    void printBST(){
        int contador = 0;
        mostrar(raiz, contador);
    }

    bool findNode(T valor){
        return find(raiz,valor);
    }

    void preOrden(){
        preOrden(raiz);
    }

    void inOrden(){
        inOrden(raiz);
    }

    void postOrden(){
        postOrden(raiz);
    }

    void eliminar(T valor){
        raiz = remove(raiz,valor);
    }
};