#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>

struct Node {
    int idProduk;
    std::string namaProduk;
    int stok;
    Node *left, *right;
};

Node* createNode(int id, std::string nama, int stok);
Node* insertNode(Node* root, int id, std::string nama, int stok);
void searchById(Node* root, int id);
void searchByProduct(Node* root, std::string nama);
Node* findMin(Node* root);
Node* findMax(Node* root);
Node* deleteNode(Node* root, int id);
void deleteTree(Node*& root);
void inOrder(Node* root);
void preOrder(Node* root);
void postOrder(Node* root);

#endif