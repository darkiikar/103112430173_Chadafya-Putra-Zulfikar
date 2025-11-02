#include "listAngka.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    CreateList(L);

    address node1 = alokasi(50);
    address node2 = alokasi(20);
    address node3 = alokasi(25);
    address node4 = alokasi(29); 
    address node5 = alokasi(45);

    address nodeA = node4;

    address nodeB = alokasi(999);

    insertLast(L, node1);
    insertLast(L, node2);
    insertLast(L, node3);
    insertLast(L, node4);
    insertLast(L, node5);

    cout << "List setelah operasi insert/del: " << endl;
    printList(L);

    cout << endl;
    cout << "Mencari data nilai 20" << endl;
    address found = SearchByData(L, 20);
    if (found != nullptr) {
        int pos = SearchByAddress(L, found);
        cout << "Data 20 ditemukan pada posisi ke-" << pos << "!" << endl;
    } else {
        cout << "Data 20 tidak ditemukan!" << endl;
    }

    cout << endl;
    cout << "Mencari data nilai 55" << endl;
    found = SearchByData(L, 55);
    if (found != nullptr) {
        int pos = SearchByAddress(L, found);
        cout << "Data 55 ditemukan pada posisi ke-" << pos << "!" << endl;
    } else {
        cout << "Node dengan data 55 tidak ditemukan!" << endl;
    }

    cout << endl;
    cout << "Mencari data alamat nodeB" << endl;
    int posB = SearchByAddress(L, nodeB);
    if (posB == -1) {
        cout << "Node dengan alamat " << nodeB << " tidak ditemukan dalam list!" << endl;
    } else {
        cout << "Node ditemukan pada posisi ke-" << posB << "!" << endl;
        cout << "Alamat node : " << nodeB << endl;
    }

    cout << endl;
    cout << "Mencari data alamat nodeA" << endl;
    int posA = SearchByAddress(L, nodeA);
    if (posA == -1) {
        cout << "Node dengan alamat " << nodeA << " tidak ditemukan dalam list!" << endl;
    } else {
        cout << "Node ditemukan pada posisi ke-" << posA << "!" << endl;
        cout << "Alamat node : " << nodeA << endl;
    }

    cout << endl;
    cout << "Mencari data dengan nilai minimal 40" << endl;
    SearchByRange(L, 40);

    while (L.First != nullptr) {
        address temp = L.First;
        L.First = L.First->Next;
        dealokasi(temp);
    }

    return 0;
}