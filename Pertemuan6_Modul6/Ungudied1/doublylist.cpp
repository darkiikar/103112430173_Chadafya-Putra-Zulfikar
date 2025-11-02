#include "doublylist.h"
#include <iostream>
using namespace std;

void CreateList(List &L) {
    L.First = nullptr;
    L.Last = nullptr;
}

address alokasi(const string &nomorPolisi, const string &warna, int tahunBuat) {
    address P = new ElmList;
    if (P != nullptr) {
        P->info.nomorPolisi = nomorPolisi;
        P->info.warna = warna;
        P->info.tahunBuat = tahunBuat;
        P->next = nullptr;
        P->prev = nullptr;
    }
    return P;
}

void dealokasi(address &P) {
    if (P != nullptr) {
        delete P;
        P = nullptr;
    }
}

void insertFirst(List &L, address P) {
    if (P == nullptr) return;
    if (L.First == nullptr) {
        L.First = L.Last = P;
    } else {
        P->next = L.First;
        L.First->prev = P;
        L.First = P;
    }
}

void insertLast(List &L, address P) {
    if (P == nullptr) return;
    if (L.First == nullptr) {
        L.First = L.Last = P;
    } else {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

address findByNomorPolisi(const List &L, const string &nomorPolisi) {
    address P = L.First;
    while (P != nullptr) {
        if (P->info.nomorPolisi == nomorPolisi) return P;
        P = P->next;
    }
    return nullptr;
}

void printInfo(const List &L) {
    cout << "\nDATA LIST 1" << endl << endl;
    address P = L.Last;
    while (P != nullptr) {
        cout << "nomor polisi : " << P->info.nomorPolisi << endl;
        cout << "warna        : " << P->info.warna << endl;
        cout << "tahun        : " << P->info.tahunBuat << endl << endl;
        P = P->prev;
    }
}