#include "doublylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    CreateList(L);

    for (int i = 0; i < 4; ++i) {
        string nomorPolisi, warna;
        int tahunBuat;
        cout << "masukkan nomor polisi: ";
        getline(cin, nomorPolisi);
        if (nomorPolisi.empty()) {
            --i;
            continue;
        }
        cout << "masukkan warna kendaraan: ";
        getline(cin, warna);
        cout << "masukkan tahun kendaraan: ";
        string line;
        getline(cin, line);
        try {
            tahunBuat = stoi(line);
        } catch (...) {
            tahunBuat = 0;
        }

        if (findByNomorPolisi(L, nomorPolisi) != nullptr) {
            cout << "nomor polisi sudah terdaftar" << endl << endl;
            continue; 
        }

        address node = alokasi(nomorPolisi, warna, tahunBuat);
        insertLast(L, node);
    }

    printInfo(L);

    address P = L.First;
    while (P != nullptr) {
        address next = P->next;
        dealokasi(P);
        P = next;
    }

    return 0;
}