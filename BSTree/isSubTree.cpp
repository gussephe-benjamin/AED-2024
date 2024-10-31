
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    // Función auxiliar para verificar si dos árboles son iguales
    bool areIdentical(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr) {
            return true;  // Ambos son null, son iguales
        }
        if (root == nullptr || subRoot == nullptr) {
            return false; // Uno es null y el otro no, no son iguales
        }
        // Comparar el valor del nodo actual y los subárboles izquierdo y derecho
        return (root->val == subRoot->val) &&
               areIdentical(root->left, subRoot->left) &&
               areIdentical(root->right, subRoot->right);
    }

    // Función principal para verificar si subRoot es un subárbol de root
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) {
            return false; // Si root es null, no puede contener subRoot
        }
        // Si el subárbol a partir del nodo actual de root es idéntico a subRoot
        if (areIdentical(root, subRoot)) {
            return true;
        }
        // Buscar recursivamente en los subárboles izquierdo y derecho
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};