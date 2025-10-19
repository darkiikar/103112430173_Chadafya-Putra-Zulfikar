#include "Singlylist.h"
#include <iostream>
using namespace std;

void createList(List &L) {
    L.first = NULL;
}

void insertFirst(List &L, int nilai) {
    Node* newNode = new Node;
    newNode->data = nilai;
    newNode->next = L.first;
    L.first = newNode;
}

void insertAfter(Node* prevNode, int nilai) {
    if (prevNode != NULL) {
        Node* newNode = new Node;
        newNode->data = nilai;
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }
}

void insertLast(List &L, int nilai) {
    Node* newNode = new Node;
    newNode->data = nilai;
    newNode->next = NULL;

    if (L.first == NULL) {
        L.first = newNode;
    } else {
        Node* temp = L.first;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void deleteFirst(List &L) {
    if (L.first != NULL) {
        Node* temp = L.first;
        L.first = temp->next;
        delete temp;
    }
}

void deleteAfter(Node* prevNode) {
    if (prevNode != NULL && prevNode->next != NULL) {
        Node* temp = prevNode->next;
        prevNode->next = temp->next;
        delete temp;
    }
}

void deleteLast(List &L) {
    if (L.first != NULL) {
        if (L.first->next == NULL) {
            delete L.first;
            L.first = NULL;
        } else {
            Node* temp = L.first;
            while (temp->next->next != NULL)
                temp = temp->next;
            delete temp->next;
            temp->next = NULL;
        }
    }
}

void deleteList(List &L) {
    while (L.first != NULL) {
        deleteFirst(L);
    }
}

void printList(List L) {
    Node* temp = L.first;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int nbList(List L) {
    int count = 0;
    Node* temp = L.first;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}