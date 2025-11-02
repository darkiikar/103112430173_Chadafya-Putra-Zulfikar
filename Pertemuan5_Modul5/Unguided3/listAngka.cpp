#include "listAngka.h"
#include <iostream>
using namespace std;

void CreateList(List &L) {
    L.First = nullptr;
}

address alokasi(dataAngka x) {
    address P = new node;
    if (P != nullptr) {
        P->Angka = x;
        P->Next = nullptr;
    }
    return P;
}

void dealokasi(address &P) {
    if (P != nullptr) {
        delete P;
        P = nullptr;
    }
}

void printList(const List &L) {
    address P = L.First;
    while (P != nullptr) {
        std::cout << P->Angka << " - ";
        P = P->Next;
    }
    std::cout << std::endl;
}

void insertFirst(List &L, address nodeBaru) {
    if (nodeBaru == nullptr) return;
    nodeBaru->Next = L.First;
    L.First = nodeBaru;
}

void insertLast(List &L, address nodeBaru) {
    if (nodeBaru == nullptr) return;
    if (L.First == nullptr) {
        L.First = nodeBaru;
    } else {
        address P = L.First;
        while (P->Next != nullptr) P = P->Next;
        P->Next = nodeBaru;
    }
}

void insertAfter(List &L, address nodeBaru, address nodePrev) {
    if (nodeBaru == nullptr || nodePrev == nullptr) return;
    nodeBaru->Next = nodePrev->Next;
    nodePrev->Next = nodeBaru;
}

int nbList(const List &L) {
    int cnt = 0;
    address P = L.First;
    while (P != nullptr) {
        cnt++;
        P = P->Next;
    }
    return cnt;
}

void delAfter(List &L, address nodePrev) {
    if (nodePrev == nullptr || nodePrev->Next == nullptr) return;
    address hapus = nodePrev->Next;
    nodePrev->Next = hapus->Next;
    dealokasi(hapus);
}

void updateFirst(List &L, dataAngka newVal) {
    if (L.First != nullptr) L.First->Angka = newVal;
}

void updateLast(List &L, dataAngka newVal) {
    if (L.First == nullptr) return;
    address P = L.First;
    while (P->Next != nullptr) P = P->Next;
    P->Angka = newVal;
}

void updateAfter(List &L, address nodePrev, dataAngka newVal) {
    if (nodePrev == nullptr || nodePrev->Next == nullptr) return;
    nodePrev->Next->Angka = newVal;
}

long long SumList(const List &L) {
    long long sum = 0;
    address P = L.First;
    while (P != nullptr) {
        sum += P->Angka;
        P = P->Next;
    }
    return sum;
}

long long SubtractList(const List &L) {
    if (L.First == nullptr) return 0;
    long long acc = L.First->Angka;
    address P = L.First;
    while (P != nullptr) {
        acc -= P->Angka; 
        P = P->Next;
    }
    return acc;
}

long long MultiplyList(const List &L) {
    long long prod = 1;
    address P = L.First;
    while (P != nullptr) {
        prod *= P->Angka;
        P = P->Next;
    }
    return prod;
}