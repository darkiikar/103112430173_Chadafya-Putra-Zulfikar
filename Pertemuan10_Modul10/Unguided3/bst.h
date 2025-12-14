#ifndef BST_H
#define BST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef struct BST *node;

struct BST {
    int info;
    node left;
    node right;
};

typedef node BinTree;

bool isEmpty(BinTree pohon);
void createTree(BinTree &pohon);
node alokasi(int x);
void insertNode(BinTree &pohon, node nodeBaru);
node findNode(int x, BinTree pohon);
void inOrder(BinTree pohon);
void preOrder(BinTree pohon);
void postOrder(BinTree pohon);
int hitungKedalaman(BinTree pohon, int awal);
int hitungTotalInfo(BinTree pohon, int awal);
int hitungJumlahNode(BinTree pohon);

#endif