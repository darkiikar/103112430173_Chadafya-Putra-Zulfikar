#include "DLLPlaylist.h"
#include <iostream>
#include <iomanip>
using namespace std;

float calculatePopularityScore(int playCount, float rating) {
    return 0.8f * playCount + 20.0f * rating;
}

bool isEmpty(list L) {
    return L.head == nullptr;
}

void createList(list& L) {
    L.head = nullptr;
    L.tail = nullptr;
}

node* allocate(string title, string artist, int durationSec, int playCount, float rating) {
    node* P = new node();
    P->data.title = title;
    P->data.artist = artist;
    P->data.durationSec = durationSec;
    P->data.playCount = playCount;
    P->data.rating = rating;
    P->data.popularityScore = calculatePopularityScore(playCount, rating);
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void deallocate(node*& P) {
    delete P;
    P = nullptr;
}

void insertFirst(list& L, node* P) {
    if (isEmpty(L)) {
        L.head = P;
    } else {
        P->next = L.head;
        L.head->prev = P;
        L.head = P;
    }
}

void insertLast(list& L, node* P) {
    if (isEmpty(L)) {
        L.head = P;
        L.tail = P;
    } else {
        P->prev = L.tail;
        L.tail->next = P;
        L.tail = P;
    }
}

void insertAfter(list& L, node* Q, node* P) {
    if (Q != nullptr) {
        P->next = Q->next;
        P->prev = Q;
        if (Q->next != nullptr) {
            Q->next->prev = P;
        }
        Q->next = P;
    }
}

void insertBefore(list& L, node* Q, node* P) {
    if (Q != nullptr) {
        P->prev = Q->prev;
        P->next = Q;
        if (Q->prev != nullptr) {
            Q->prev->next = P;
        } else {
            L.head = P; 
        }
        Q->prev = P;
    }
}

void delFirst(list& L) {
    if (!isEmpty(L)) {
        node* P = L.head;
        if (L.head == L.tail) {
            L.head = nullptr;
            L.tail = nullptr;
        } else {
            L.head = L.head->next;
            L.head->prev = nullptr;
        }
        P->next = nullptr;
        P->prev = nullptr;
        deallocate(P);
    }
}

void delLast(list& L) {
    if (!isEmpty(L)) {
        node* Q = L.tail;
        if (L.head == L.tail) {
            L.head = nullptr;
            L.tail = nullptr;
            deallocate(Q);
        } else {
            L.tail = L.tail->prev;
            L.tail->next = nullptr;
            Q->prev = nullptr;
            Q->next = nullptr;
            deallocate(Q);
        }
    }
}

void delAfter(list& L, node* Q) {
    if (Q != nullptr && Q->next != nullptr) {
        node* P = Q->next;
        Q->next = P->next;
        if (P->next != nullptr) {
            P->next->prev = Q;
        }
        P->next = nullptr;
        P->prev = nullptr;
        deallocate(P);
    }
}

void delBefore(list& L, node* Q) {
    if (Q != nullptr && Q->prev != nullptr) {
        node* P = Q->prev;
        Q->prev = P->prev;
        if (P->prev != nullptr) {
            P->prev->next = Q;
        } else {
            L.head = Q; 
        }
        P->next = nullptr;
        P->prev = nullptr;
        deallocate(P);
    }
}

void updateAtPosition(list& L, int posisi, string title, string artist, int durationSec, int playCount, float rating) {
    int i = 1;
    node* P = L.head;
    while (i < posisi && P != nullptr) {
        P = P->next;
        i++;
    }
    if (P != nullptr) {
        P->data.title = title;
        P->data.artist = artist;
        P->data.durationSec = durationSec;
        P->data.playCount = playCount;
        P->data.rating = rating;
        P->data.popularityScore = calculatePopularityScore(playCount, rating);
    }
}

void updateBefore(list& L, node* Q, string title, string artist, int durationSec, int playCount, float rating) {
    if (Q != nullptr && Q->prev != nullptr) {
        Q->prev->data.title = title;
        Q->prev->data.artist = artist;
        Q->prev->data.durationSec = durationSec;
        Q->prev->data.playCount = playCount;
        Q->prev->data.rating = rating;
        Q->prev->data.popularityScore = calculatePopularityScore(playCount, rating);
    }
}

void viewList(list L) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
        return;
    }
    
    cout << "\n========== PLAYLIST ==========" << endl;
    cout << left << setw(3) << "No" 
         << setw(20) << "Title" 
         << setw(20) << "Artist" 
         << setw(10) << "Duration" 
         << setw(12) << "PlayCount" 
         << setw(10) << "Rating"
         << setw(15) << "PopScore" << endl;
    cout << "===================================================" << endl;
    
    int no = 1;
    node* P = L.head;
    while (P != nullptr) {
        cout << left << setw(3) << no 
             << setw(20) << P->data.title 
             << setw(20) << P->data.artist 
             << setw(10) << P->data.durationSec 
             << setw(12) << P->data.playCount 
             << setw(10) << fixed << setprecision(1) << P->data.rating
             << setw(15) << fixed << setprecision(2) << P->data.popularityScore << endl;
        P = P->next;
        no++;
    }
    cout << "===================================================" << endl;
}

void searchByPopularityScore(list L, float minScore, float maxScore) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
        return;
    }
    
    cout << "\n========== HASIL PENCARIAN ==========" << endl;
    cout << "Range PopularityScore: " << fixed << setprecision(1) << minScore << " - " << maxScore << endl;
    cout << left << setw(3) << "No" 
         << setw(20) << "Title" 
         << setw(20) << "Artist" 
         << setw(10) << "Duration" 
         << setw(12) << "PlayCount" 
         << setw(10) << "Rating"
         << setw(15) << "PopScore" << endl;
    cout << "===================================================" << endl;
    
    int no = 1;
    int found = 0;
    node* P = L.head;
    while (P != nullptr) {
        if (P->data.popularityScore >= minScore && P->data.popularityScore <= maxScore) {
            cout << left << setw(3) << no 
                 << setw(20) << P->data.title 
                 << setw(20) << P->data.artist 
                 << setw(10) << P->data.durationSec 
                 << setw(12) << P->data.playCount 
                 << setw(10) << fixed << setprecision(1) << P->data.rating
                 << setw(15) << fixed << setprecision(2) << P->data.popularityScore << endl;
            found++;
            no++;
        }
        P = P->next;
    }
    
    if (found == 0) {
        cout << "Tidak ada lagu dalam rentang PopularityScore tersebut." << endl;
    }
    cout << "===================================================" << endl;
}