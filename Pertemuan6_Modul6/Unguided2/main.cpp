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

    cout << "Masukkan Nomor Polisi yang dicari  : ";
    string cari;
    getline(cin, cari);

    address found = findByNomorPolisi(L, cari);
    if (found != nullptr) {
        cout << endl;
        cout << "Nomor Polisi : " << found->info.nomorPolisi << endl;
        cout << "Warna        : " << found->info.warna << endl;
        cout << "Tahun        : " << found->info.tahunBuat << endl;
    } else {
        cout << "Data dengan nomor polisi '" << cari << "' tidak ditemukan." << endl;
    }

    address P = L.First;
    while (P != nullptr) {
        address next = P->next;
        dealokasi(P);
        P = next;
    }

    return 0;
}