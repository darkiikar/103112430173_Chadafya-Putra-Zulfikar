#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    cout << "Binary Search Tree Pre-Order dan Post-Order" << endl;
    BinTree root = Nil;
    
    insertNode(root, alokasi(6));
    insertNode(root, alokasi(4));
    insertNode(root, alokasi(7));
    insertNode(root, alokasi(2));
    insertNode(root, alokasi(5));
    insertNode(root, alokasi(1));
    insertNode(root, alokasi(3));
    
    cout << "\nIn-Order Traversal: ";
    inOrder(root);
    cout << "\n" << endl;
    
    cout << "Pre-Order Traversal: ";
    preOrder(root);
    cout << "\n" << endl;
    
    cout << "Post-Order Traversal: ";
    postOrder(root);
    cout << "\n" << endl;
    
    return 0;
}