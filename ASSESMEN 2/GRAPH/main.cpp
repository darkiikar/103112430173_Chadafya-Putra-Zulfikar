#include "graphkota.h"

int main() {
    GraphKota G;
    createGraph(G);

     std::cout << "\n\nCHADAFYA PUTRA ZULFIKAR | IF-12-02\n" << std::endl;

    // 1. Operasi Insert Node
    insertNode(G, "Jakarta");
    insertNode(G, "Bogor");
    insertNode(G, "Depok");
    insertNode(G, "Tangerang");
    insertNode(G, "Bekasi");

    // 1. Operasi Connect Node (berdasarkan Gambar 1)
    connectNode(G, "Jakarta", "Tangerang", 24);
    connectNode(G, "Jakarta", "Depok", 21);
    connectNode(G, "Jakarta", "Bekasi", 16);
    connectNode(G, "Jakarta", "Bogor", 42);
    connectNode(G, "Bogor", "Bekasi", 60);
    connectNode(G, "Bogor", "Depok", 22);
    connectNode(G, "Depok", "Bekasi", 25);
    connectNode(G, "Depok", "Tangerang", 30);
    connectNode(G, "Tangerang", "Bekasi", 45);

    // 2. Print Graph Awal
    printGraph(G);
    cout << endl;

    // 3. Delete Node Depok
    cout << "Menghapus node Depok..." << endl;
    deleteNode(G, "Depok");
    
    // 4. Print Graph setelah Delete
    printGraph(G);
    cout << endl;

    // Bagian B: Traversal
    cout << "=== HASIL TRAVERSAL BFS & DFS ===" << endl;
    resetVisited(G);
    printBFS(G, "Tangerang");
    
    resetVisited(G);
    printDFS(G, "Tangerang");

     std::cout << "\n\nPRORAM SELESAI KING" << std::endl;

    return 0;
}