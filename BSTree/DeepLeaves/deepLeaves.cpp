#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Función auxiliar para recorrer el árbol y encontrar el LCA y la profundidad
pair<int, TreeNode*> dfs(TreeNode* node) {
    if (!node) {
        return {0, nullptr};  // Si es un nodo nulo, devuelve profundidad 0 y nullptr como LCA
    }

    auto left = dfs(node->left);   // Llamada recursiva al subárbol izquierdo
    auto right = dfs(node->right); // Llamada recursiva al subárbol derecho

    // Si las profundidades son iguales, este nodo es el ancestro común más bajo
    if (left.first == right.first) {
        return {left.first + 1, node};
    }
    // Si el subárbol izquierdo tiene más profundidad, devuelve su LCA
    else if (left.first > right.first) {
        return {left.first + 1, left.second};
    }
    // Si el subárbol derecho tiene más profundidad, devuelve su LCA
    else {
        return {right.first + 1, right.second};
    }
}

// Función principal para encontrar el LCA de las hojas más profundas
TreeNode* lcaDeepestLeaves(TreeNode* root) {
    return dfs(root).second;  // Solo nos interesa el segundo valor de la tupla (el LCA)
}

// Función para construir el árbol a partir de un array (similar a LeetCode)
TreeNode* buildTree(const vector<int>& values) {
    if (values.empty()) return nullptr;

    TreeNode* root = new TreeNode(values[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    
    while (i < values.size()) {
        TreeNode* node = q.front();
        q.pop();
        
        if (i < values.size() && values[i] != -1) {  // -1 representa 'null' en el array
            node->left = new TreeNode(values[i]);
            q.push(node->left);
        }
        i++;
        
        if (i < values.size() && values[i] != -1) {
            node->right = new TreeNode(values[i]);
            q.push(node->right);
        }
        i++;
    }
    
    return root;
}

int main() {
    vector<int> values = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};  // Array de entrada, donde -1 es null
    TreeNode* root = buildTree(values);
    
    TreeNode* lca = lcaDeepestLeaves(root);
    
    if (lca) {
        cout << "El ancestro común más bajo de las hojas más profundas es: " << lca->val << endl;  // Debe imprimir 2
    } else {
        cout << "No hay ancestro común." << endl;
    }
    
    return 0;
}
