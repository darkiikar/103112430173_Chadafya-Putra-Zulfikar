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