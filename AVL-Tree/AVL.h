#include<iostream>
using namespace std;

struct TreeNode {
    int Entry;      // Clave del nodo
    int count;      // Contador de ocurrencias
    int bal;        // Balance del nodo (-1, 0, +1)
    TreeNode *LeftNode, *RightNode;  // Punteros a los hijos

    TreeNode(int value) : Entry(value), count(1), bal(0), LeftNode(nullptr), RightNode(nullptr) {}
    TreeNode();
};

typedef TreeNode* TreePointer;

class AVLTree {
public:
    AVLTree() : root(nullptr) {}  // Constructor inicializando el root como nullptr
    void SearchInsert(int x);
    void mostrar();  // Nueva función para mostrar el árbol
    void eliminar(int x);

private:
    TreePointer root;  // Miembro root que representa la raíz del árbol AVL
    void SearchInsert(TreePointer &pA, int x, bool &h);
    void mostrar(TreePointer node, int contador);
    
    void rotateLL(TreePointer &pA);
    void rotateRR(TreePointer &pA);
    void rotateLR(TreePointer &pA);
    void rotateRL(TreePointer &pA);

    void Delete(int x, TreePointer &p, bool &h);
    void DelMin(TreePointer &q, TreePointer &r, bool &h);
    void balanceL(TreePointer &pA, bool &h);
    void balanceR(TreePointer &pA, bool &h);

};

// Función para insertar un elemento en el árbol AVL
void AVLTree::SearchInsert(int x) {
    bool h = false;  // Variable para controlar el cambio en la altura
    SearchInsert(root, x, h);  // Llamada a la función privada de inserción
}

void AVLTree::mostrar() {
    mostrar(root, 0);  // Llamada a la función privada de mostrar
}

void AVLTree::eliminar(int x) {
    bool h = false;
    Delete(x, root, h);  
}

// Función privada para la inserción recursiva
void AVLTree::SearchInsert(TreePointer &pA, int x, bool &h) {
    TreePointer pB, pC;

    if (pA == NULL) { // Caso base: insertar nuevo nodo
        pA = new TreeNode(x);
        h = true;  // La altura ha cambiado al insertar el nuevo nodo
    }
    else if (x < pA->Entry) {  // Insertar en el subárbol izquierdo
        SearchInsert(pA->LeftNode, x, h);
        if (h) {
            switch (pA->bal) {
                case -1: 
                    pA->bal = 0; 
                    h = false;  // El árbol está balanceado
                    break;
                case 0:  
                    pA->bal = +1;  // El árbol se inclinó hacia la izquierda
                    break;
                case +1:  // Desbalance hacia la izquierda
                    pB = pA->LeftNode;
                    if (pB->bal == +1) {
                        rotateLL(pA);  // Rotación simple LL
                    } else {
                        rotateLR(pA);  // Rotación doble LR
                    }
                    h = false;  // Tras la rotación, el árbol está balanceado
                    break;
            }
        }
    }
    else if (x > pA->Entry) {  // Insertar en el subárbol derecho
        SearchInsert(pA->RightNode, x, h);
        if (h) {
            switch (pA->bal) {
                case +1: 
                    pA->bal = 0; 
                    h = false;  // El árbol está balanceado
                    break;
                case 0:  
                    pA->bal = -1;  // El árbol se inclinó hacia la derecha
                    break;
                case -1:  // Desbalance hacia la derecha
                    pB = pA->RightNode;
                    if (pB->bal == -1) {
                        rotateRR(pA);  // Rotación simple RR
                    } else {
                        rotateRL(pA);  // Rotación doble RL
                    }
                    h = false;  // Tras la rotación, el árbol está balanceado
                    break;
            }
        }
    }
    else { // El elemento ya está en el árbol, incrementar el contador
        pA->count++;
    }
}

// Nueva función para mostrar el árbol con indentación


void AVLTree::mostrar(TreePointer node, int contador) {
    if (node == nullptr) {
        return;
    } else {
        // Mostrar primero el subárbol derecho
        mostrar(node->RightNode, contador + 1);

        // Imprimir espacios según el nivel del nodo
        for (size_t i = 0; i < contador; i++) {
            std::cout << "   ";
        }
        // Mostrar el valor del nodo actual
        std::cout << node->Entry << std::endl;

        // Mostrar el subárbol izquierdo
        mostrar(node->LeftNode, contador + 1);
    }
}


void AVLTree::Delete(int x, TreePointer &p, bool &h) {
    TreePointer q;

    if (p == NULL) {
        std::cout << "Elemento inexistente";
        abort();
    }
    if (x < p->Entry) {
        Delete(x, p->LeftNode, h);
        if (h) balanceL(p, h);  // Balancear tras la eliminación del subárbol izquierdo
    }
    else if (x > p->Entry) {
        Delete(x, p->RightNode, h);
        if (h) balanceR(p, h);  // Balancear tras la eliminación del subárbol derecho
    }
    else {  // Nodo encontrado y será eliminado
        q = p;
        if (q->RightNode == NULL) {  // No tiene subárbol derecho
            p = q->LeftNode;
            h = true;
        }
        else if (q->LeftNode == NULL) {  // No tiene subárbol izquierdo
            p = q->RightNode;
            h = true;
        }
        else {  // Tiene dos hijos
            DelMin(q, q->RightNode, h);
            if (h) balanceR(p, h);  // Balancear tras la eliminación del mínimo
        }
        delete q;  // Eliminar el nodo
    }
}


// Función para eliminar el nodo mínimo de un subárbol
void AVLTree::DelMin(TreePointer &q, TreePointer &r, bool &h) {
    if (r->LeftNode != NULL) {
        DelMin(q, r->LeftNode, h);
        if (h) balanceL(r, h);  // Balancear tras la eliminación en el subárbol izquierdo
    }
    else {
        q->Entry = r->Entry;  // Reemplazar el valor del nodo a eliminar
        q->count = r->count;
        q = r;
        r = r->RightNode;
        h = true;
    }
}

// Función de balanceo tras la eliminación en el subárbol izquierdo
void AVLTree::balanceL(TreePointer &pA, bool &h) {
    TreePointer pB, pC;
    int balB, balC;
    switch (pA->bal) {
        case +1:
            pA->bal = 0;
            h = false;
            break;
        case 0:
            pA->bal = -1;
            h = false;
            break;
        case -1:
            pB = pA->RightNode;
            balB = pB->bal;
            if (balB <= 0) {  // Rotación RR
                pA->RightNode = pB->LeftNode;
                pB->LeftNode = pA;
                if (balB == -1) {
                    pA->bal = 0;
                    pB->bal = 0;
                } else {
                    pA->bal = -1;
                    pB->bal = +1;
                }
                pA = pB;
                h = false;
            } else {  // Rotación RL
                pC = pB->LeftNode;
                pB->LeftNode = pC->RightNode;
                pC->RightNode = pB;
                pA->RightNode = pC->LeftNode;
                pC->LeftNode = pA;
                if (pC->bal == -1) pA->bal = +1; else pA->bal = 0;
                if (pC->bal == +1) pB->bal = -1; else pB->bal = 0;
                pA = pC;
                pC->bal = 0;
            }
            break;
    }
}

// Función de balanceo tras la eliminación en el subárbol derecho
void AVLTree::balanceR(TreePointer &pA, bool &h) {
    TreePointer pB, pC;
    int balB, balC;
    switch (pA->bal) {
        case -1:
            pA->bal = 0;
            h = false;
            break;
        case 0:
            pA->bal = +1;
            h = false;
            break;
        case +1:
            pB = pA->LeftNode;
            balB = pB->bal;
            if (balB >= 0) {  // Rotación LL
                pA->LeftNode = pB->RightNode;
                pB->RightNode = pA;
                if (balB == 0) {
                    pA->bal = +1;
                    pB->bal = -1;
                    h = false;
                } else {
                    pA->bal = 0;
                    pB->bal = 0;
                    h = true;
                }
                pA = pB;
            } else {  // Rotación LR
                pC = pB->RightNode;
                balC = pC->bal;
                pB->RightNode = pC->LeftNode;
                pC->LeftNode = pB;
                pA->LeftNode = pC->RightNode;
                pC->RightNode = pA;
                if (balC == +1) {
                    pB->bal = -1;
                    pA->bal = 0;
                } else if (balC == -1) {
                    pB->bal = 0;
                    pA->bal = +1;
                } else {
                    pB->bal = 0;
                    pA->bal = 0;
                }
                pA = pC;
                pC->bal = 0;
                h = true;
            }
            break;
    }
}


// Rotación LL (rotación simple hacia la derecha)
void AVLTree::rotateLL(TreePointer &pA) {
    TreePointer pB = pA->LeftNode;
    pA->LeftNode = pB->RightNode;
    pB->RightNode = pA;
    pA->bal = 0;
    pA = pB;
    pA->bal = 0;
}

// Rotación RR (rotación simple hacia la izquierda)
void AVLTree::rotateRR(TreePointer &pA) {
    TreePointer pB = pA->RightNode;
    pA->RightNode = pB->LeftNode;
    pB->LeftNode = pA;
    pA->bal = 0;
    pA = pB;
    pA->bal = 0;
}

// Rotación LR (rotación doble: izquierda-derecha)
void AVLTree::rotateLR(TreePointer &pA) {
    TreePointer pB = pA->LeftNode;
    TreePointer pC = pB->RightNode;
    pB->RightNode = pC->LeftNode;
    pC->LeftNode = pB;
    pA->LeftNode = pC->RightNode;
    pC->RightNode = pA;
    if (pC->bal == +1) pA->bal = -1; else pA->bal = 0;
    if (pC->bal == -1) pB->bal = +1; else pB->bal = 0;
    pA = pC;
    pA->bal = 0;
}

// Rotación RL (rotación doble: derecha-izquierda)
void AVLTree::rotateRL(TreePointer &pA) {
    TreePointer pB = pA->RightNode;
    TreePointer pC = pB->LeftNode;
    pB->LeftNode = pC->RightNode;
    pC->RightNode = pB;
    pA->RightNode = pC->LeftNode;
    pC->LeftNode = pA;
    if (pC->bal == -1) pA->bal = +1; else pA->bal = 0;
    if (pC->bal == +1) pB->bal = -1; else pB->bal = 0;
    pA = pC;
    pA->bal = 0;
}