#include "doublylist.h"
#include <iostream>
using namespace std;

void deleteFirst(List &L) {
    if (L.First == nullptr) return;
    address P = L.First;
    if (L.First == L.Last) {
        L.First = L.Last = nullptr;
    } else {
        L.First = P->next;
        L.First->prev = nullptr;
    }
    dealokasi(P);
}

void deleteLast(List &L) {
    if (L.Last == nullptr) return;
    address P = L.Last;
    if (L.First == L.Last) {
        L.First = L.Last = nullptr;
    } else {
        L.Last = P->prev;
        L.Last->next = nullptr;
    }
    dealokasi(P);
}

void deleteAfter(List &L, address Prec) {
    if (Prec == nullptr || Prec->next == nullptr) return;
    address P = Prec->next;
    Prec->next = P->next;
    if (P->next != nullptr) P->next->prev = Prec;
    if (P == L.Last) L.Last = Prec;
    dealokasi(P);
}

int main() {
    List L;
    CreateList(L);

    insertLast(L, alokasi("KB 5527 BRK", "Hitam", 2025));
    insertLast(L, alokasi("KB 4190 IN", "Hitam", 2025));

    cout << "Masukkan Nomor Polisi yang akan dihapus  : ";
    string target;
    getline(cin, target);

    address node = findByNomorPolisi(L, target);
    if (node == nullptr) {
        cout << "Data dengan nomor polisi " << target << " tidak ditemukan." << endl;
    } else {
        if (node == L.First) {
            deleteFirst(L);
        } else if (node == L.Last) {
            deleteLast(L);
        } else {
            deleteAfter(L, node->prev);
        }
        cout << "Data dengan nomor polisi " << target << " berhasil dihapus." << endl;
    }

    cout << "\nDATA LIST 1" << endl << endl;
    address P = L.Last;
    while (P != nullptr) {
        cout << "Nomor Polisi : " << P->info.nomorPolisi << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.tahunBuat << endl;
        if (P->prev != nullptr) cout << "\n";
        P = P->prev;
    }

    P = L.First;
    while (P != nullptr) {
        address next = P->next;
        dealokasi(P);
        P = next;
    }

    return 0;
}