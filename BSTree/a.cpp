#include"BSTree.h"
int main() {
    BSTree<int> bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(20);
    bst.insert(3);
    bst.insert(7);
    bst.insert(15);
    bst.insert(25);

    bst.printBST();

    cout << "- - -" << endl;

    cout << bst.findNode(30) << endl;

    cout << "- - -" << endl;

    bst.inOrden();
    cout << endl;
    bst.postOrden();
    cout << endl;
    bst.preOrden();

    std::cout << std::endl << "- - -" << std::endl;

    bst.eliminar(10);


    bst.printBST();

    return 0;
}
