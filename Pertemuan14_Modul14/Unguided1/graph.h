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