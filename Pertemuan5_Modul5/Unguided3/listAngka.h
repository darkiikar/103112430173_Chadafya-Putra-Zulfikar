#ifndef LISTANGKA_H
#define LISTANGKA_H

#include <iostream>
using namespace std;

using dataAngka = int;

struct node {
    dataAngka Angka;
    node* Next;
};

using address = node*;

struct List {
    address First;
};

void CreateList(List &L);
address alokasi(dataAngka x);
void dealokasi(address &P);
void printList(const List &L);
void insertFirst(List &L, address nodeBaru);
void insertLast(List &L, address nodeBaru);
void insertAfter(List &L, address nodeBaru, address nodePrev);
int nbList(const List &L);
void delAfter(List &L, address nodePrev);

void updateFirst(List &L, dataAngka newVal);
void updateLast(List &L, dataAngka newVal);
void updateAfter(List &L, address nodePrev, dataAngka newVal);

long long SumList(const List &L);
long long SubtractList(const List &L);
long long MultiplyList(const List &L);

#endif