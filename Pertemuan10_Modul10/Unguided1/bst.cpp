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