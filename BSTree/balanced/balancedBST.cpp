
#include <iostream>
#include <vector>
using namespace std;

// Estructura para representar un nodo de árbol binario
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Función para recorrer el árbol en inorden y almacenar los nodos en un vector
void inorderTraversal(TreeNode* root, vector<int>& nodes) {
    if (!root) return; // Si el nodo es nulo, terminamos
    inorderTraversal(root->left, nodes); // Recursivamente procesamos el subárbol izquierdo
    nodes.push_back(root->val); // Agregamos el valor del nodo actual
    inorderTraversal(root->right, nodes); // Recursivamente procesamos el subárbol derecho
}

// Función recursiva para construir un árbol balanceado a partir de un vector ordenado
TreeNode* buildBalancedBST(const vector<int>& nodes, int left, int right) {
    if (left > right) return nullptr; // Condición base: si no hay más elementos

    // Encontramos el elemento del medio
    int mid = left + (right - left) / 2;
    TreeNode* root = new TreeNode(nodes[mid]); // El medio es la nueva raíz

    // Construimos recursivamente los subárboles izquierdo y derecho
    root->left = buildBalancedBST(nodes, left, mid - 1);  // Subárbol izquierdo
    root->right = buildBalancedBST(nodes, mid + 1, right); // Subárbol derecho

    return root; // Retornamos el nodo raíz
}

// Función principal que balancea el BST
TreeNode* balanceBST(TreeNode* root) {
    // Paso 1: Recopilar los nodos en orden ascendente
    vector<int> nodes;
    inorderTraversal(root, nodes); // Realizamos el recorrido en inorden

    // Paso 2: Construir un nuevo árbol balanceado desde los nodos ordenados
    return buildBalancedBST(nodes, 0, nodes.size() - 1); // Construimos el árbol balanceado
}

// Función para imprimir el árbol en inorden
void printInOrder(TreeNode* root) {
    if (root == nullptr) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

// Función principal para probar el código en VS Code
int main() {
    // Creamos un árbol BST desbalanceado de ejemplo
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    cout << "Árbol original (inorden): ";
    printInOrder(root);
    cout << endl;

    // Balanceamos el BST
    TreeNode* balancedRoot = balanceBST(root);

    // Imprimimos el árbol balanceado
    cout << "Árbol balanceado (inorden): ";
    printInOrder(balancedRoot);
    cout << endl;

    return 0;
}
