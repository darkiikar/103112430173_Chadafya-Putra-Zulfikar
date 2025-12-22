#ifndef GRAPHKOTA_H
#define GRAPHKOTA_H

#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

typedef struct ElmKota *adrKota;
typedef struct ElmEdge *adrEdge;

struct ElmKota {
    string namaKota;
    int visited; // 0: belum, 1: sudah
    adrEdge firstEdge;
    adrKota next;
};

struct ElmEdge {
    adrKota kotaTujuan;
    int jarak;
    adrEdge next;
};

struct GraphKota {
    adrKota First;
};

// Prototipe Method
void createGraph(GraphKota &G);
adrKota alokasiNode(string nama);
adrEdge alokasiEdge(adrKota tujuan, int jarak);
void insertNode(GraphKota &G, string nama);
adrKota findNode(GraphKota G, string nama);
void connectNode(GraphKota &G, string nama1, string nama2, int jarak);
void disconnectNode(GraphKota &G, string nama1, string nama2);
void deleteNode(GraphKota &G, string nama);
void printGraph(GraphKota G);

// Bagian B: Traversal
void resetVisited(GraphKota &G);
void printBFS(GraphKota G, string startNode);
void printDFS(GraphKota G, string startNode);

#endif