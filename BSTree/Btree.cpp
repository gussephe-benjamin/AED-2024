#include <iostream>
#include <queue>
#include <iomanip>
#include <cmath>

template <typename T>
class BSTree {
    struct NodeBT {
        T data;
        NodeBT *left;
        NodeBT *right;

        // Constructor para el nodo
        NodeBT(T value) : data(value), left(nullptr), right(nullptr) {}
    };

    NodeBT *root;

    // Método auxiliar para la inserción
    NodeBT* insert(NodeBT* node, T value) {
        if (node == nullptr) {
            return new NodeBT(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }
        return node;
    }

    // Método para obtener la altura del árbol
    int getHeight(NodeBT* node) {
        if (node == nullptr) return 0;
        return 1 + std::max(getHeight(node->left), getHeight(node->right));
    }

    // Método para imprimir el árbol con niveles y aristas
    void printTreeLevelOrder() {
        if (root == nullptr) {
            std::cout << "El árbol está vacío." << std::endl;
            return;
        }

        int height = getHeight(root);
        int maxWidth = (1 << height) - 1; // Ancho máximo (2^h - 1)

        std::queue<NodeBT*> q;
        q.push(root);

        // Bucle para cada nivel
        for (int level = 0; level < height; ++level) {
            int levelSize = q.size();
            int nodeSpace = maxWidth / (1 << level); // Espacios entre los nodos
            int halfSpace = nodeSpace / 2; // Espacio previo a los nodos

            // Imprimir nodos en el nivel actual
            for (int i = 0; i < levelSize; ++i) {
                NodeBT* currentNode = q.front();
                q.pop();

                // Imprimir el nodo si existe, de lo contrario un espacio vacío
                if (currentNode) {
                    std::cout << std::setw(halfSpace) << "" << currentNode->data << std::setw(halfSpace) << "";
                    q.push(currentNode->left);
                    q.push(currentNode->right);
                } else {
                    std::cout << std::setw(nodeSpace) << "";  // Espacio vacío
                    q.push(nullptr);
                    q.push(nullptr);
                }
            }
            std::cout << std::endl;

            // Imprimir las aristas si no es el último nivel
            if (level < height - 1) {
                for (int i = 0; i < levelSize; ++i) {
                    NodeBT* currentNode = q.front();

                    // Imprimir aristas solo si el nodo existe
                    if (currentNode) {
                        std::cout << std::setw(halfSpace - 1) << "" 
                                  << (currentNode->left ? "/" : " ") // Arista izquierda
                                  << std::setw(2) << "" 
                                  << (currentNode->right ? "\\" : " "); // Arista derecha
                    } else {
                        std::cout << std::setw(nodeSpace) << "";
                    }
                }
                std::cout << std::endl;
            }

            maxWidth /= 2;
        }
    }

public:
    // Constructor
    BSTree() : root(nullptr) {}

    // Método público para insertar un valor
    void insert(T value) {
        root = insert(root, value);
    }

    // Método público para imprimir el árbol en niveles con aristas
    void printTree() {
        printTreeLevelOrder();
    }
};

// Ejemplo de uso
int main() {
    BSTree<int> bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(20);
    bst.insert(3);
    bst.insert(7);
    bst.insert(15);
    bst.insert(25);

    std::cout << "Árbol binario impreso de forma visual con aristas:\n";
    bst.printTree();

    return 0;
}
