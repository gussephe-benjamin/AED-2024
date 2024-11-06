#include <iostream>
#include <vector>
#include <climits>  // Para INT_MIN y INT_MAX

using namespace std;

// Estructura para representar un nodo de árbol binario
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Función recursiva para construir el árbol BST
// Ahora usando nombres más claros para los límites
TreeNode* buildBST(vector<int>& preorder, int& idx, int lowerBound, int upperBound) {
    // Si todos los elementos del preorder ya fueron procesados o el valor actual no está en el rango permitido
    if (idx >= preorder.size() || preorder[idx] < lowerBound || preorder[idx] > upperBound) {
        return nullptr;  // No se puede colocar un nodo en esta posición
    }

    // El valor actual del preorden será la raíz de este subárbol
    int val = preorder[idx];
    idx++;  // Avanzamos al siguiente valor en el preorder
    TreeNode* root = new TreeNode(val);

    // Construimos recursivamente el subárbol izquierdo y derecho
    // Para el subárbol izquierdo: todos los valores deben estar entre lowerBound y 'val'
    root->left = buildBST(preorder, idx, lowerBound, val);

    // Para el subárbol derecho: todos los valores deben estar entre 'val' y upperBound
    root->right = buildBST(preorder, idx, val, upperBound);

    return root;
}

// Función principal para construir el árbol a partir de un vector de preorden
TreeNode* bstFromPreorder(vector<int>& preorder) {
    int idx = 0;  // Índice para rastrear la posición actual en el preorden
    return buildBST(preorder, idx, INT_MIN, INT_MAX);  // Llamada inicial con rango infinito
}

// Función para imprimir el árbol en orden (para verificar el resultado)
void inorderPrint(TreeNode* root) {
    if (root == nullptr) return;
    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}

int main() {
    // Ejemplo 1
    vector<int> preorder1 = {8, 5, 1, 7, 10, 12};
    TreeNode* root1 = bstFromPreorder(preorder1);
    cout << "Inorder del Árbol 1: ";
    inorderPrint(root1);  // Debería imprimir 1 5 7 8 10 12
    cout << endl;

    // Ejemplo 2
    vector<int> preorder2 = {1, 3};
    TreeNode* root2 = bstFromPreorder(preorder2);
    cout << "Inorder del Árbol 2: ";
    inorderPrint(root2);  // Debería imprimir 1 3
    cout << endl;

    return 0;
}
