#include "Singlylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    createList(L);

    insertFirst(L, 9);
    insertLast(L, 12);
    insertLast(L, 8);
    insertLast(L, 0);
    insertLast(L, 2);

    printList(L); 

    deleteFirst(L);     
    deleteLast(L);
    deleteAfter(L.first); 

    printList(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    deleteList(L);
    cout << "\n- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}