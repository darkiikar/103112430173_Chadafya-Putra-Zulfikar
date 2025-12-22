#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>
using namespace std;

struct NodeChild {
    string idFilm, judulFilm;
    int durasiFilm, tahunTayang;
    float ratingFilm;
    NodeChild *next, *prev;
};

struct ListChild {
    NodeChild *first, *last;
};
struct NodeParent {
    string idGenre, namaGenre;
    ListChild childs; // Masing-masing node parent memiliki 1 list child
    NodeParent *next, *prev;
};

struct ListParent {
    NodeParent *first, *last;
};

void createListParent(ListParent &L);
void createListChild(ListChild &L);
NodeParent* alokasiNodeParent(string id, string nama);
NodeChild* alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating);
void insertFirstParent(ListParent &L, NodeParent *P);
void insertLastChild(ListChild &L, NodeChild *C);
void deleteAfterParent(ListParent &L, NodeParent *prec, NodeParent *&P);
void hapusListChild(ListChild &L);
void searchFilmByRatingRange(ListParent L, float minR, float maxR);
void printStrukturMLL(ListParent L);

#endif