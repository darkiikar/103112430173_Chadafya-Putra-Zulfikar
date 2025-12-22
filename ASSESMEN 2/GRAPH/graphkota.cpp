#include "graphkota.h"

void createGraph(GraphKota &G) {
    G.First = NULL;
}

adrKota alokasiNode(string nama) {
    adrKota P = new ElmKota;
    P->namaKota = nama;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

adrEdge alokasiEdge(adrKota tujuan, int jarak) {
    adrEdge E = new ElmEdge;
    E->kotaTujuan = tujuan;
    E->jarak = jarak;
    E->next = NULL;
    return E;
}

void insertNode(GraphKota &G, string nama) {
    adrKota P = alokasiNode(nama);
    if (G.First == NULL) {
        G.First = P;
    } else {
        adrKota temp = G.First;
        while (temp->next != NULL) temp = temp->next;
        temp->next = P;
    }
}

adrKota findNode(GraphKota G, string nama) {
    adrKota temp = G.First;
    while (temp != NULL) {
        if (temp->namaKota == nama) return temp;
        temp = temp->next;
    }
    return NULL;
}

void addEdge(adrKota asal, adrKota tujuan, int jarak) {
    adrEdge E = alokasiEdge(tujuan, jarak);
    if (asal->firstEdge == NULL) {
        asal->firstEdge = E;
    } else {
        adrEdge temp = asal->firstEdge;
        while (temp->next != NULL) temp = temp->next;
        temp->next = E;
    }
}

void connectNode(GraphKota &G, string nama1, string nama2, int jarak) {
    adrKota K1 = findNode(G, nama1);
    adrKota K2 = findNode(G, nama2);
    if (K1 != NULL && K2 != NULL) {
        addEdge(K1, K2, jarak);
        addEdge(K2, K1, jarak); // Karena Undirected
    }
}

void disconnectNode(GraphKota &G, string nama1, string nama2) {
    adrKota K1 = findNode(G, nama1);
    adrKota K2 = findNode(G, nama2);
    if (K1 == NULL || K2 == NULL) return;

    // Hapus edge dari K1 ke K2
    adrEdge prec = NULL, E = K1->firstEdge;
    while (E != NULL && E->kotaTujuan != K2) { prec = E; E = E->next; }
    if (E != NULL) {
        if (prec == NULL) K1->firstEdge = E->next;
        else prec->next = E->next;
        delete E;
    }
    // Lakukan hal yang sama untuk K2 ke K1
    prec = NULL; E = K2->firstEdge;
    while (E != NULL && E->kotaTujuan != K1) { prec = E; E = E->next; }
    if (E != NULL) {
        if (prec == NULL) K2->firstEdge = E->next;
        else prec->next = E->next;
        delete E;
    }
}

void deleteNode(GraphKota &G, string nama) {
    adrKota target = findNode(G, nama);
    if (target == NULL) return;

    // 1. Hapus semua edge yang menunjuk ke node ini dari kota lain
    adrKota tempK = G.First;
    while (tempK != NULL) {
        if (tempK != target) disconnectNode(G, tempK->namaKota, nama);
        tempK = tempK->next;
    }

    // 2. Lepas node dari list kota
    if (G.First == target) {
        G.First = target->next;
    } else {
        adrKota prec = G.First;
        while (prec->next != target) prec = prec->next;
        prec->next = target->next;
    }
    delete target;
}

void printGraph(GraphKota G) {
    cout << "=== REPRESENTASI ADJACENCY LIST GRAPH ===" << endl;
    adrKota tempK = G.First;
    while (tempK != NULL) {
        cout << "Node " << tempK->namaKota << " terhubung ke: ";
        adrEdge tempE = tempK->firstEdge;
        while (tempE != NULL) {
            cout << tempE->kotaTujuan->namaKota << "(" << tempE->jarak << " KM)";
            if (tempE->next != NULL) cout << ", ";
            tempE = tempE->next;
        }
        cout << endl;
        tempK = tempK->next;
    }
}

// Bagian B Traversal
void resetVisited(GraphKota &G) {
    adrKota P = G.First;
    while (P != NULL) { P->visited = 0; P = P->next; }
}

void printBFS(GraphKota G, string startNode) {
    adrKota start = findNode(G, startNode);
    if (start == NULL) return;
    queue<adrKota> q;
    q.push(start);
    start->visited = 1;
    cout << "BFS Traversal: ";
    while (!q.empty()) {
        adrKota curr = q.front(); q.pop();
        cout << curr->namaKota << " - ";
        adrEdge e = curr->firstEdge;
        while (e != NULL) {
            if (e->kotaTujuan->visited == 0) {
                e->kotaTujuan->visited = 1;
                q.push(e->kotaTujuan);
            }
            e = e->next;
        }
    }
    cout << endl;
}

void printDFS(GraphKota G, string startNode) {
    adrKota start = findNode(G, startNode);
    if (start == NULL) return;
    stack<adrKota> s;
    s.push(start);
    start->visited = 1;
    cout << "DFS Traversal: ";
    while (!s.empty()) {
        adrKota curr = s.top(); s.pop();
        cout << curr->namaKota << " - ";
        adrEdge e = curr->firstEdge;
        while (e != NULL) {
            if (e->kotaTujuan->visited == 0) {
                e->kotaTujuan->visited = 1;
                s.push(e->kotaTujuan);
            }
            e = e->next;
        }
    }
    cout << endl;
}