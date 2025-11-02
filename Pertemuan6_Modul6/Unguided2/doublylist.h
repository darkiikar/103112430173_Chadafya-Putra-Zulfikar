#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
using namespace std;

struct kendaraan {
	string nomorPolisi;
	string warna;
	int tahunBuat;
};

using infotype = kendaraan;

typedef struct ElmList *address;

struct ElmList {
	infotype info;
	address next;
	address prev;
};

struct List {
	address First;
	address Last;
};

void CreateList(List &L);
address alokasi(const string &nomorPolisi, const string &warna, int tahunBuat);
void dealokasi(address &P);
void printInfo(const List &L);
void insertLast(List &L, address P);
void insertFirst(List &L, address P);
address findByNomorPolisi(const List &L, const string &nomorPolisi);

#endif
