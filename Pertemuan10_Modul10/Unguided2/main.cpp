#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    cout << "Hello World!" << endl;
    BinTree root = Nil;
    insertNode(root, alokasi(1));
    insertNode(root, alokasi(2));
    insertNode(root, alokasi(6));
    insertNode(root, alokasi(4));
    insertNode(root, alokasi(5));
    insertNode(root, alokasi(3));
    insertNode(root, alokasi(6));
    insertNode(root, alokasi(7));
    inOrder(root);
    cout << "\n";
    cout << "kedalaman : " << hitungKedalaman(root, 0) << endl;
    cout << "jumlah Node : " << hitungJumlahNode(root) << endl;
    cout << "total : " << hitungTotalInfo(root, 0) << endl;
    
    return 0;
}