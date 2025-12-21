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