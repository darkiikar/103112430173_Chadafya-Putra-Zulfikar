#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct List {
    Node* first;
};

void createList(List &L);
void insertFirst(List &L, int nilai);
void insertAfter(Node* prevNode, int nilai);
void insertLast(List &L, int nilai);
void deleteFirst(List &L);
void deleteAfter(Node* prevNode);
void deleteLast(List &L);
void deleteList(List &L);
void printList(List L);
int nbList(List L);

#endif