#include "bst.h"
#include <iostream>

using namespace std;

bool isEmpty(BinTree pohon) {
    if (pohon == Nil) {
        return true;
    } else {
        return false;
    }
}

void createTree(BinTree &pohon) {
    pohon = Nil;
}

node alokasi(int x) {
    node nodeBaru = new BST;
    nodeBaru->info = x;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void insertNode(BinTree &pohon, node nodeBaru) {
    if (pohon == Nil) {
        pohon = nodeBaru;
    } else if (nodeBaru->info < pohon->info) {
        insertNode(pohon->left, nodeBaru);
    } else if (nodeBaru->info > pohon->info) {
        insertNode(pohon->right, nodeBaru);
    }
}

node findNode(int x, BinTree pohon) {
    if (pohon == Nil) {
        return Nil;
    } else if (x < pohon->info) {
        return findNode(x, pohon->left);
    } else if (x > pohon->info) {
        return findNode(x, pohon->right);
    } else {
        return pohon;
    }
}

void inOrder(BinTree pohon) {
    if (pohon == Nil) {
        return;
    }
    inOrder(pohon->left);
    cout << pohon->info << " - ";
    inOrder(pohon->right);
}

int hitungKedalaman(BinTree pohon, int awal) {
    if (pohon == Nil) {
        return awal;
    }
    int kedalamanKiri = hitungKedalaman(pohon->left, awal + 1);
    int kedalamanKanan = hitungKedalaman(pohon->right, awal + 1);
    
    if (kedalamanKiri > kedalamanKanan) {
        return kedalamanKiri;
    } else {
        return kedalamanKanan;
    }
}

int hitungTotalInfo(BinTree pohon, int awal) {
    if (pohon == Nil) {
        return 0;
    }
    return pohon->info + hitungTotalInfo(pohon->left, awal) + hitungTotalInfo(pohon->right, awal);
}

int hitungJumlahNode(BinTree pohon) {
    if (pohon == Nil) {
        return 0;
    }
    return 1 + hitungJumlahNode(pohon->left) + hitungJumlahNode(pohon->right);
}