# <h1 align="center">Laporan Praktikum Modul 14 - GRAPH </h1>
<p align="center">Chadafya Putra Zulfikar - 103112430173</p>

## Dasar Teori

### 1. Definisi dan Struktur Dasar
Graph adalah struktur data non-linear yang merepresentasikan sekumpulan objek (vertex) yang saling terhubung oleh garis atau jalur (edge) untuk memodelkan hubungan antar elemen tersebut.

### 2. Komponen Dasar
Secara matematis, sebuah graph dinyatakan dengan notasi G = (V, E), yang terdiri dari:
- Vertex (V): Disebut juga sebagai node atau simpul, yaitu unit fundamental atau titik yang menyimpan data dalam graph.
- Edge (E): Disebut juga sebagai busur atau garis, yaitu penghubung antara dua vertex yang menyatakan adanya relasi atau jalur komunikasi di antara mereka.
- Weight (Opsional): Nilai atau beban yang diberikan pada sebuah edge untuk merepresentasikan biaya, jarak, atau waktu tempuh antar vertex.
- Degree: Jumlah edge yang terhubung ke sebuah vertex tertentu.


### 3. Representasi Graph Dalam C++
Ada dua cara utama untuk mengimplementasikan graf dalam C++ menggunakan STL:
A. Adjacency Matrix (Matriks Ketetanggaan)
Menggunakan array dua dimensi matrix[V][V]. Jika matrix[i][j] = 1, maka ada hubungan antara vertex i dan j.
- Kelebihan: Cepat untuk mengecek hubungan antar dua titik (O(1)).
- Kekurangan: Memakan banyak memori (O(V^2)), tidak efisien untuk graf yang renggang (sparse).
B. Adjacency List (Daftar Ketetanggaan)
Menggunakan array dari std::vector atau std::list. Setiap indeks mewakili sebuah vertex yang berisi daftar tetangganya.
- Kelebihan: Hemat memori (O(V + E)).
- Kekurangan: Pencarian hubungan spesifik lebih lambat (O(V)). 

## Guided 

### 1. 

#### [graph.h]
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct Graph {
    adrNode First;
};

void createGraph(Graph &G);
adrNode AlokasiNode(infoGraph data);
adrEdge AlokasiEdge(adrNode nodeTujuan);

void InsertNode(Graph &G, infoGraph data);
adrNode FindNode(Graph G, infoGraph data);
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2);
void DisconnectNode(adrNode node1, adrNode node2);
void DeleteNode(Graph &G, infoGraph X);

void PrintInfoGraph(Graph G);
void ResetVisited(Graph &G);
void PrintBFS(Graph G, infoGraph StartInfo);
void PrintDFS(Graph G, infoGraph StartInfo);

#endif
```

#### [graph.cpp]
```C++
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;

//prosedur untuk mengeset first dari graph sebagai NULL
void CreateGraph(Graph &G) {
    G.First = NULL;
}

//alokasi Node baru
adrNode AlokasiNode(infoGraph data) {
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = data;
    nodeBaru->visited = 0; //isinya 0/1
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;
    return nodeBaru;
}

//alokasi Edge baru
adrEdge AlokasiEdge(adrNode nodeTujuan) {
    adrEdge edgeBaru = new ElmEdge;
    edgeBaru->Node = nodeTujuan;
    edgeBaru->Next = NULL;
    return edgeBaru;
}

//Menambahkan Node ke dalam Graph
void InsertNode(Graph &G, infoGraph data) {
    adrNode nodeBaru = AlokasiNode(data);
    if (G.First == NULL) {
        G.First = nodeBaru;
    } else {
        //konsepnya insert last
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != NULL) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

//function untuk mencari alamat Node berdasarkan infonya
adrNode FindNode(Graph G, infoGraph data) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        if (nodeBantu->info == data) {
            return nodeBantu;
        }
        nodeBantu = nodeBantu->Next;
    }
    return NULL;
}

//prosedur untuk menghubungkan dua Node (Undirected Graph)
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2) {
    adrNode node1 = FindNode(G, info1);
    adrNode node2 = FindNode(G, info2);

    if (node1 != NULL && node2 != NULL) {
        //Hubungkan node1 ke node2
        adrEdge Edge1 = AlokasiEdge(node2);
        Edge1->Next = node1->firstEdge; // Insert First pada list edge
        node1->firstEdge = Edge1;

        //Hubungkan node2 ke node1 (Karena Undirected/Bolak-balik)
        adrEdge Edge2 = AlokasiEdge(node1);
        Edge2->Next = node2->firstEdge;
        node2->firstEdge = Edge2;
    } else {
        cout << "Node tidak ditemukan!" << endl;
    }
}

//prosedur untuk memutuskan hubungan dua node
void DisconnectNode(adrNode node1, adrNode node2) {
    if (node1 != NULL && node2 != NULL) {
        adrEdge edgeBantu = node1->firstEdge;
        adrEdge PrevE = NULL;

        //Cari edge yang mengarah ke node2 di dalam list milik node1
        while (edgeBantu != NULL && edgeBantu->Node != node2) {
            PrevE = edgeBantu;
            edgeBantu = edgeBantu->Next;
        }

        if (edgeBantu != NULL) { //jika Edge ditemukan
            if (PrevE == NULL) {
                //Hapus edge pertama
                node1->firstEdge = edgeBantu->Next;
            } else {
                //Hapus edge di tengah/akhir
                PrevE->Next = edgeBantu->Next;
            }
            delete edgeBantu;
        }
    }
}

//prosedur untuk menghapus Node X beserta semua edge yang berhubungan dengannya
void DeleteNode(Graph &G, infoGraph X) {
    //1. Cari Node yang akan dihapus (nodeHapus)
    adrNode nodeHapus = FindNode(G, X);
    if (nodeHapus == NULL) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }

    //2. Hapus semua Edge yang MENGARAH ke nodeHapus (Incoming Edges)
    //cek setiap node di graph, apakah punya edge ke nodeHapus
    adrNode nodeLainnya = G.First;
    while (nodeLainnya != NULL) {
        DisconnectNode(nodeLainnya, nodeHapus); //putus hubungan nodeLainnya ke nodeHapus
        nodeLainnya = nodeLainnya->Next;
    }

    //3. Hapus semua Edge yang KELUAR dari nodeHapus (Outgoing Edges)
    //Deallokasi list edge milik nodeHapus
    adrEdge edgeBantu = nodeHapus->firstEdge;
    while (edgeBantu != NULL) {
        adrEdge tempE = edgeBantu;
        edgeBantu = edgeBantu->Next;
        delete tempE;
    }
    nodeHapus->firstEdge = NULL;

    //4. Hapus nodeHapus dari List Utama Graph
    if (G.First == nodeHapus) {
        //jika nodeHapus di awal
        G.First = nodeHapus->Next;
    } else {
        //jika nodeHapus di tengah/akhir
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != nodeHapus) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeHapus->Next;
    }

    //5. delete nodeHapus
    delete nodeHapus;
}

//Menampilkan isi Graph (Adjacency List) 
void PrintInfoGraph(Graph G) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        cout << "Node " << nodeBantu->info << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            cout << edgeBantu->Node->info << " "; //Akses info dari node tujuan
            edgeBantu = edgeBantu->Next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}

//Reset status visited sebelum traversal
void ResetVisited(Graph &G) {
    adrNode nodeReset = G.First;
    while (nodeReset != NULL) {
        nodeReset->visited = 0;
        nodeReset = nodeReset->Next;
    }
}

//traversal Breadth First Search / BFS (Menggunakan Queue)
void PrintBFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    queue<adrNode> Qyu;
    
    //Enqueue start
    Qyu.push(StartNode);
    StartNode->visited = 1;

    cout << "BFS Traversal: ";
    while (!Qyu.empty()) {
        adrNode nodeBantu = Qyu.front();
        Qyu.pop();
        cout << nodeBantu->info << " - ";

        //Cek semua tetangga atau edge nya
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            if (edgeBantu->Node->visited == 0) {
                edgeBantu->Node->visited = 1;
                Qyu.push(edgeBantu->Node);
            }
            edgeBantu = edgeBantu->Next;
        }
    }
    cout << endl;
}

//Traversal Depth First Search / DFS (Menggunakan Stack)
void PrintDFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    stack<adrNode> Stak;
    
    Stak.push(StartNode);

    cout << "DFS Traversal: ";
    while (!Stak.empty()) {
        adrNode nodeBantu = Stak.top();
        Stak.pop();

        if (nodeBantu->visited == 0) {
            nodeBantu->visited = 1;
            cout << nodeBantu->info << " - ";

            //masukkan tetangga ke stack
            adrEdge edgeBantu = nodeBantu->firstEdge;
            while (edgeBantu != NULL) {
                if (edgeBantu->Node->visited == 0) {
                    Stak.push(edgeBantu->Node);
                }
                edgeBantu = edgeBantu->Next;
            }
        }
    }
    cout << endl;
}
```

#### [main.cpp]
```C++
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS
using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');

    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'D');
    ConnectNode(G, 'B', 'C');
    ConnectNode(G, 'D', 'C');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'E', 'F');

    cout <<  "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    PrintBFS(G, 'A');
    PrintDFS(G, 'A');
    cout << endl;

    cout << "=== HAPUS NODE E ===" << endl;
    DeleteNode(G, 'E');
    if(FindNode(G, 'E') == NULL) {
        cout << "Node E berhasil terhapus" << endl;
    } else {
        cout << "Node E tidak berhasil terhapus" << endl;
    }
    cout << endl;

    cout <<  "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    PrintBFS(G, 'A');
    PrintDFS(G, 'A');

    return 0;
}
```

## Unguided

### 1. ![Screenshot Unguided 1_1](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan14_Modul14/Soal-Unguided1.png)


#### [graph.h]
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;

struct ElementNode;
struct ElementEdge;

typedef ElementNode* addressNode;
typedef ElementEdge* addressEdge;

struct ElementNode {
    infoGraph info;
    int visited;
    addressEdge firstEdge;
    addressNode next;
};

struct ElementEdge {
    addressNode node;
    addressEdge next;
};

struct Graph {
    addressNode first;
};

void CreateGraph(Graph &graph);
void InsertNode(Graph &graph, infoGraph value);
addressNode FindNode(Graph graph, infoGraph value);
void ConnectNode(addressNode firstNode, addressNode secondNode);
void PrintInfoGraph(Graph graph);

#endif
```

#### [graph.cpp]
```C++
#include "graph.h"
#include <iostream>
using namespace std;

void CreateGraph(Graph &graph) {
    graph.first = nullptr;
}

void InsertNode(Graph &graph, infoGraph value) {
    addressNode newNode = new ElementNode;
    newNode->info = value;
    newNode->visited = 0;
    newNode->firstEdge = nullptr;
    newNode->next = nullptr;

    if (graph.first == nullptr) {
        graph.first = newNode;
    } else {
        addressNode temp = graph.first;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

addressNode FindNode(Graph graph, infoGraph value) {
    addressNode temp = graph.first;
    while (temp != nullptr) {
        if (temp->info == value) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void ConnectNode(addressNode firstNode, addressNode secondNode) {
    addressEdge newEdge1 = new ElementEdge;
    newEdge1->node = secondNode;
    newEdge1->next = firstNode->firstEdge;
    firstNode->firstEdge = newEdge1;

    addressEdge newEdge2 = new ElementEdge;
    newEdge2->node = firstNode;
    newEdge2->next = secondNode->firstEdge;
    secondNode->firstEdge = newEdge2;
}

void PrintInfoGraph(Graph graph) {
    addressNode tempNode = graph.first;
    while (tempNode != nullptr) {
        std::cout << tempNode->info << " : ";
        addressEdge tempEdge = tempNode->firstEdge;
        while (tempEdge != nullptr) {
            std::cout << tempEdge->node->info << " ";
            tempEdge = tempEdge->next;
        }
        std::cout << std::endl;
        tempNode = tempNode->next;
    }
}
```

#### [main.cpp]
```C++
#include "graph.h"
#include <iostream>
using namespace std;

int main() {
    Graph graph;
    CreateGraph(graph);

    InsertNode(graph, 'A');
    InsertNode(graph, 'B');
    InsertNode(graph, 'C');
    InsertNode(graph, 'D');
    InsertNode(graph, 'E');
    InsertNode(graph, 'F');
    InsertNode(graph, 'G');
    InsertNode(graph, 'H');

    addressNode A = FindNode(graph, 'A');
    addressNode B = FindNode(graph, 'B');
    addressNode C = FindNode(graph, 'C');
    addressNode D = FindNode(graph, 'D');
    addressNode E = FindNode(graph, 'E');
    addressNode F = FindNode(graph, 'F');
    addressNode G = FindNode(graph, 'G');
    addressNode H = FindNode(graph, 'H');

    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, G);
    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(G, H);

    PrintInfoGraph(graph);

    return 0;
}
```

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan14_Modul14/Output-Unguided1.png)

Program ini mengimplementasikan struktur data graph tak berarah menggunakan metode adjacency list berbasis pointer. Setiap simpul (node) menyimpan data karakter, status kunjungan, serta daftar sisi (edge) yang terhubung. Implementasi ini mencakup fungsi manajemen graf seperti penambahan simpul, pencarian, dan penghubungan antar-simpul secara dua arah. Pada bagian utama (main.cpp), graf dikonstruksi dengan delapan simpul (A-H) dan ditampilkan dalam format daftar ketetanggaan.

### 2. Buatlah prosedur untuk menampilkanhasil penelusuran DFS. prosedur PrintDFS (Graph G, adrNode N);prosedur PrintDFS (Graph G, adrNode N);

#### [graph.h]
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;

struct ElementNode;
struct ElementEdge;

typedef ElementNode* addressNode;
typedef ElementEdge* addressEdge;

struct ElementNode {
    infoGraph info;
    int visited;
    addressEdge firstEdge;
    addressNode next;
};

struct ElementEdge {
    addressNode node;
    addressEdge next;
};

struct Graph {
    addressNode first;
};

void CreateGraph(Graph &graph);
void InsertNode(Graph &graph, infoGraph value);
addressNode FindNode(Graph graph, infoGraph value);
void ConnectNode(addressNode firstNode, addressNode secondNode);
void PrintInfoGraph(Graph graph);
void ResetVisited(Graph &graph);
void PrintDFS(Graph &graph, addressNode node);

#endif
```

#### [graph.cpp] 
```C++
#include "graph.h"
#include <iostream>
using namespace std;

void CreateGraph(Graph &graph) {
    graph.first = nullptr;
}

void InsertNode(Graph &graph, infoGraph value) {
    addressNode newNode = new ElementNode;
    newNode->info = value;
    newNode->visited = 0;
    newNode->firstEdge = nullptr;
    newNode->next = nullptr;

    if (graph.first == nullptr) {
        graph.first = newNode;
    } else {
        addressNode temp = graph.first;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

addressNode FindNode(Graph graph, infoGraph value) {
    addressNode temp = graph.first;
    while (temp != nullptr) {
        if (temp->info == value) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void ConnectNode(addressNode firstNode, addressNode secondNode) {
    addressEdge newEdge1 = new ElementEdge;
    newEdge1->node = secondNode;
    newEdge1->next = firstNode->firstEdge;
    firstNode->firstEdge = newEdge1;

    addressEdge newEdge2 = new ElementEdge;
    newEdge2->node = firstNode;
    newEdge2->next = secondNode->firstEdge;
    secondNode->firstEdge = newEdge2;
}

void PrintInfoGraph(Graph graph) {
    addressNode tempNode = graph.first;
    while (tempNode != nullptr) {
        std::cout << tempNode->info << " : ";
        addressEdge tempEdge = tempNode->firstEdge;
        while (tempEdge != nullptr) {
            std::cout << tempEdge->node->info << " ";
            tempEdge = tempEdge->next;
        }
        std::cout << std::endl;
        tempNode = tempNode->next;
    }
}

void ResetVisited(Graph &graph) {
    addressNode temp = graph.first;
    while (temp != nullptr) {
        temp->visited = 0;
        temp = temp->next;
    }
}

void PrintDFS(Graph &graph, addressNode node) {
    if (node == nullptr) {
        return;
    }

    node->visited = 1;
    std::cout << node->info << " ";

    addressEdge tempEdge = node->firstEdge;
    while (tempEdge != nullptr) {
        if (tempEdge->node->visited == 0) {
            PrintDFS(graph, tempEdge->node);
        }
        tempEdge = tempEdge->next;
    }
}
```

#### [main.cpp]
```C++
#include "graph.h"
#include <iostream>
using namespace std;

int main() {
    Graph graph;
    CreateGraph(graph);

    InsertNode(graph, 'A');
    InsertNode(graph, 'B');
    InsertNode(graph, 'C');
    InsertNode(graph, 'D');
    InsertNode(graph, 'E');
    InsertNode(graph, 'F');
    InsertNode(graph, 'G');
    InsertNode(graph, 'H');

    addressNode A = FindNode(graph, 'A');
    addressNode B = FindNode(graph, 'B');
    addressNode C = FindNode(graph, 'C');
    addressNode D = FindNode(graph, 'D');
    addressNode E = FindNode(graph, 'E');
    addressNode F = FindNode(graph, 'F');
    addressNode G = FindNode(graph, 'G');
    addressNode H = FindNode(graph, 'H');

    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, G);
    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(G, H);

    PrintInfoGraph(graph);

    ResetVisited(graph);
    PrintDFS(graph, A);

    return 0;
}
```

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan14_Modul14/Output-Unguided2.png)

Program ini merepresentasikan graph tak berarah melalui implementasi adjacency list yang memanfaatkan struktur data pointer. Setiap unit ElementNode membawa atribut berupa data karakter, flag kunjungan, serta referensi ke daftar sisi dan simpul berikutnya. Logika utama dalam graph.cpp mencakup manajemen graf, visualisasi daftar ketetanggaan, serta algoritma penelusuran Depth First Search (DFS) rekursif. Dalam main.cpp, struktur graf dibentuk dari simpul A hingga H dan diuji melalui proses penelusuran yang dimulai dari titik A.

### 3. Buatlah prosedur untuk menampilkanhasil penelusuran DFS. prosedur PrintBFS (Graph G, adrNode N);

#### [graph.h]
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;

struct ElementNode;
struct ElementEdge;

typedef ElementNode* addressNode;
typedef ElementEdge* addressEdge;

struct ElementNode {
    infoGraph info;
    int visited;
    addressEdge firstEdge;
    addressNode next;
};

struct ElementEdge {
    addressNode node;
    addressEdge next;
};

struct Graph {
    addressNode first;
};

void CreateGraph(Graph &graph);
void InsertNode(Graph &graph, infoGraph value);
addressNode FindNode(Graph graph, infoGraph value);
void ConnectNode(addressNode firstNode, addressNode secondNode);
void PrintInfoGraph(Graph graph);
void ResetVisited(Graph &graph);
void PrintDFS(Graph &graph, addressNode node);
void PrintBFS(Graph &graph, addressNode node);

#endif
```

#### [graph.cpp]
```C++
#include "graph.h"
#include <queue>
#include <iostream>
using namespace std;

void CreateGraph(Graph &graph) {
    graph.first = nullptr;
}

void InsertNode(Graph &graph, infoGraph value) {
    addressNode newNode = new ElementNode;
    newNode->info = value;
    newNode->visited = 0;
    newNode->firstEdge = nullptr;
    newNode->next = nullptr;

    if (graph.first == nullptr) {
        graph.first = newNode;
    } else {
        addressNode temp = graph.first;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

addressNode FindNode(Graph graph, infoGraph value) {
    addressNode temp = graph.first;
    while (temp != nullptr) {
        if (temp->info == value) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void ConnectNode(addressNode firstNode, addressNode secondNode) {
    addressEdge newEdge1 = new ElementEdge;
    newEdge1->node = secondNode;
    newEdge1->next = firstNode->firstEdge;
    firstNode->firstEdge = newEdge1;

    addressEdge newEdge2 = new ElementEdge;
    newEdge2->node = firstNode;
    newEdge2->next = secondNode->firstEdge;
    secondNode->firstEdge = newEdge2;
}

void PrintInfoGraph(Graph graph) {
    addressNode tempNode = graph.first;
    while (tempNode != nullptr) {
        std::cout << tempNode->info << " : ";
        addressEdge tempEdge = tempNode->firstEdge;
        while (tempEdge != nullptr) {
            std::cout << tempEdge->node->info << " ";
            tempEdge = tempEdge->next;
        }
        std::cout << std::endl;
        tempNode = tempNode->next;
    }
}

void ResetVisited(Graph &graph) {
    addressNode temp = graph.first;
    while (temp != nullptr) {
        temp->visited = 0;
        temp = temp->next;
    }
}

void PrintDFS(Graph &graph, addressNode node) {
    if (node == nullptr) {
        return;
    }

    node->visited = 1;
    std::cout << node->info << " ";

    addressEdge tempEdge = node->firstEdge;
    while (tempEdge != nullptr) {
        if (tempEdge->node->visited == 0) {
            PrintDFS(graph, tempEdge->node);
        }
        tempEdge = tempEdge->next;
    }
}

void PrintBFS(Graph &graph, addressNode node) {
    if (node == nullptr) {
        return;
    }

    std::queue<addressNode> queueNode;
    node->visited = 1;
    queueNode.push(node);

    while (!queueNode.empty()) {
        addressNode current = queueNode.front();
        queueNode.pop();
        std::cout << current->info << " ";

        addressEdge tempEdge = current->firstEdge;
        while (tempEdge != nullptr) {
            if (tempEdge->node->visited == 0) {
                tempEdge->node->visited = 1;
                queueNode.push(tempEdge->node);
            }
            tempEdge = tempEdge->next;
        }
    }
}
```

#### [main.cpp]
```C++
#include "graph.h"
#include <iostream>
#include <queue>
using namespace std;

int main() {
    Graph graph;
    CreateGraph(graph);

    InsertNode(graph, 'A');
    InsertNode(graph, 'B');
    InsertNode(graph, 'C');
    InsertNode(graph, 'D');
    InsertNode(graph, 'E');
    InsertNode(graph, 'F');
    InsertNode(graph, 'G');
    InsertNode(graph, 'H');

    addressNode A = FindNode(graph, 'A');
    addressNode B = FindNode(graph, 'B');
    addressNode C = FindNode(graph, 'C');
    addressNode D = FindNode(graph, 'D');
    addressNode E = FindNode(graph, 'E');
    addressNode F = FindNode(graph, 'F');
    addressNode G = FindNode(graph, 'G');
    addressNode H = FindNode(graph, 'H');

    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, G);
    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(G, H);

    PrintInfoGraph(graph);

    ResetVisited(graph);
    PrintDFS(graph, A);

    std::cout << std::endl;

    ResetVisited(graph);
    PrintBFS(graph, A);

    return 0;
}
```

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan14_Modul14/Output-Unguided3.png)

Kode ini mengimplementasikan struktur data graph tak berarah (undirected graph) menggunakan adjacency list berbasis pointer, di mana setiap simpul (ElementNode) menyimpan data (info), penanda kunjungan (visited), daftar sisi (firstEdge), dan penunjuk ke simpul berikutnya, sedangkan sisi (ElementEdge) menyimpan referensi ke simpul tujuan. File graph.cpp berisi fungsi untuk membuat graph, menambah simpul, mencari simpul, menghubungkan dua simpul secara dua arah, menampilkan isi graph, serta melakukan penelusuran DFS (Depth First Search) secara rekursif dan BFS (Breadth First Search) menggunakan queue dengan memanfaatkan atribut visited. Pada main.cpp, graph dibangun dengan simpul A–H, dihubungkan membentuk struktur tertentu, lalu ditampilkan adjacency list-nya, diikuti hasil penelusuran DFS dan BFS mulai dari simpul A.

## Kesimpulan
- Graph merupakan struktur data non-linear fundamental yang terdiri dari vertex (simpul) dan edge (sisi) untuk memodelkan hubungan kompleks antar objek, baik yang bersifat searah maupun dua arah. Dalam implementasinya, setiap elemen dapat memiliki bobot (weight) untuk merepresentasikan nilai tertentu seperti jarak, serta derajat (degree) yang menunjukkan intensitas koneksi pada suatu titik. Pemahaman terhadap komponen-komponen ini sangat krusial karena graph menjadi basis bagi berbagai solusi algoritma modern, mulai dari pemetaan jalur terpendek hingga analisis jaringan sosial.
- Dalam pemrograman C++, efisiensi struktur ini sangat bergantung pada pemilihan metode representasi yang tepat, yaitu Adjacency Matrix atau Adjacency List. Adjacency Matrix unggul dalam kecepatan akses pemeriksaan hubungan antar dua titik namun boros memori, sehingga lebih cocok untuk graf padat (dense graph). Sebaliknya, Adjacency List yang memanfaatkan STL std::vector jauh lebih hemat memori karena hanya menyimpan hubungan yang ada, menjadikannya pilihan standar untuk menangani graf besar atau renggang (sparse graph) yang umum dijumpai dalam kasus dunia nyata.

## Referensi
[1] R. Lafore, Data Structures and Algorithms in Java, 2nd ed. Indianapolis, IN: Sams Publishing, 2002.

[2] T. H. Cormen, C. E. Leiserson, R. L. Rivest, and C. Stein, Introduction to Algorithms, 3rd ed. Cambridge, MA: MIT Press, 2009.

[3] S. Halim and F. Halim, Competitive Programming 3: The New Lower Bound of Programming Contests. Lulu Editorial, 2013.

[4] G. L. Miller, Data Structures and Algorithms in C++, 2nd ed. Hoboken, NJ: John Wiley & Sons, 2011.