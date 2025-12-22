#include "mll.h"

void createListParent(ListParent &L) { L.first = NULL; L.last = NULL; }
void createListChild(ListChild &L) { L.first = NULL; L.last = NULL; }

NodeParent* alokasiNodeParent(string id, string nama) {
    NodeParent *P = new NodeParent;
    P->idGenre = id; P->namaGenre = nama;
    P->next = NULL; P->prev = NULL;
    createListChild(P->childs);
    return P;
}

NodeChild* alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating) {
    NodeChild *C = new NodeChild;
    C->idFilm = id; C->judulFilm = judul;
    C->durasiFilm = durasi; C->tahunTayang = tahun; C->ratingFilm = rating;
    C->next = NULL; C->prev = NULL;
    return C;
}

void insertFirstParent(ListParent &L, NodeParent *P) {
    if (L.first == NULL) { L.first = P; L.last = P; }
    else { P->next = L.first; L.first->prev = P; L.first = P; }
}

void insertLastChild(ListChild &L, NodeChild *C) {
    if (L.first == NULL) { L.first = C; L.last = C; }
    else { L.last->next = C; C->prev = L.last; L.last = C; }
}

void hapusListChild(ListChild &L) {
    NodeChild *P = L.first;
    while (P != NULL) {
        NodeChild *temp = P;
        P = P->next;
        delete temp;
    }
    L.first = NULL; L.last = NULL;
}

void deleteAfterParent(ListParent &L, NodeParent *prec, NodeParent *&P) {
    if (prec == NULL || prec->next == NULL) return;
    P = prec->next;
    hapusListChild(P->childs); 
    prec->next = P->next;
    if (P->next != NULL) P->next->prev = prec;
    else L.last = prec;
    P->next = NULL; P->prev = NULL;
}

void searchFilmByRatingRange(ListParent L, float minR, float maxR) {
    NodeParent *P = L.first;
    int pIdx = 1;
    while (P != NULL) {
        NodeChild *C = P->childs.first;
        int cIdx = 1;
        while (C != NULL) {
            if (C->ratingFilm >= minR && C->ratingFilm <= maxR) { //
                cout << "Data Film ditemukan pada list child dari node parent " << P->namaGenre << " pada posisi ke-" << cIdx << "!" << endl;
                cout << "--- Data Film (Child) ---" << endl;
                cout << "Judul Film : " << C->judulFilm << "\nPosisi dalam list child : posisi ke-" << cIdx << endl;
                cout << "ID Film : " << C->idFilm << "\nDurasi Film : " << C->durasiFilm << " menit\nTahun Tayang : " << C->tahunTayang << "\nRating Film : " << C->ratingFilm << endl;
                cout << "--- Data Genre (Parent) ---" << endl;
                cout << "ID Genre : " << P->idGenre << "\nPosisi dalam list parent : posisi ke-" << pIdx << "\nNama Genre : " << P->namaGenre << endl;
                cout << "==========================================" << endl;
            }
            C = C->next; cIdx++;
        }
        P = P->next; pIdx++;
    }
}

void printStrukturMLL(ListParent L) {
    NodeParent *P = L.first;
    int i = 1;
    while (P != NULL) {
        cout << "=== Parent " << i << " ===" << endl;
        cout << "ID Genre : " << P->idGenre << "\nNama Genre : " << P->namaGenre << endl;
        NodeChild *C = P->childs.first;
        int j = 1;
        while (C != NULL) {
            cout << "  - Child " << j << " :\n    ID Film : " << C->idFilm << "\n    Judul Film : " << C->judulFilm << "\n    Durasi Film : " << C->durasiFilm << " menit\n    Tahun Tayang : " << C->tahunTayang << "\n    Rating Film : " << C->ratingFilm << endl;
            C = C->next; j++;
        }
        cout << "------------------------------------------" << endl;
        P = P->next; i++;
    }
}