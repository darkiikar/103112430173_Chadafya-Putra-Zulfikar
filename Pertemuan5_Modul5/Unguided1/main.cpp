#include "listAngka.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    CreateList(L);

    address nodeA = alokasi(8);
    address nodeB = alokasi(13);
    address nodeC = alokasi(18);
    address nodeD = alokasi(25);
    address nodeE = alokasi(33);
    address nodeF = alokasi(40);

    insertFirst(L, nodeB);    
    insertLast(L, nodeA);     
    insertAfter(L, nodeD, nodeB); 

    insertFirst(L, nodeC);  
    insertLast(L, nodeE);      
    insertFirst(L, nodeF);    
    delAfter(L, nodeC);

    cout << "List setelah operasi insert/del: " << endl;
    printList(L);

    int nilai;

    cout << "\nMasukkan update data node pertama :" << endl;
    cout << "masukkan angka : ";
    if (cin >> nilai) {
        updateFirst(L, nilai);
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }

    cout << "masukkan update data node setelah node 25 :" << endl;
    cout << "Masukkan angka : ";
    if (cin >> nilai) {
        updateAfter(L, nodeD, nilai);
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }

    cout << "masukkan update data node terakhir :" << endl;
    cout << "Masukkan angka : ";
    if (cin >> nilai) {
        updateLast(L, nilai);
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }

    cout << "masukkan update data node setelah node 50 :" << endl;
    cout << "Masukkan angka : ";
    if (cin >> nilai) {
        updateAfter(L, L.First, nilai);
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }

    cout << "List setelah update: " << endl;
    printList(L);

    while (L.First != nullptr) {
        address temp = L.First;
        L.First = L.First->Next;
        dealokasi(temp);
    }

    return 0;
}