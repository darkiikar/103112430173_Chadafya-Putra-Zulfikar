#include "bst.h"

Node* createNode(int id, std::string nama, int stok) {
    Node* newNode = new Node();
    newNode->idProduk = id;
    newNode->namaProduk = nama;
    newNode->stok = stok;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* insertNode(Node* root, int id, std::string nama, int stok) {
    if (root == nullptr) return createNode(id, nama, stok);
    if (id < root->idProduk)
        root->left = insertNode(root->left, id, nama, stok);
    else if (id > root->idProduk)
        root->right = insertNode(root->right, id, nama, stok);
    return root;
}

void searchById(Node* root, int id) {
    if (root == nullptr) {
        std::cout << "ID " << id << " tidak ditemukan.\n";
        return;
    }
    if (root->idProduk == id) {
        std::cout << "Ditemukan: " << root->namaProduk << " (Stok: " << root->stok << ")\n";
    } else if (id < root->idProduk) {
        searchById(root->left, id);
    } else {
        searchById(root->right, id);
    }
}

// Pencarian berdasarkan nama produk (Linear Search pada BST)
void searchByProduct(Node* root, std::string nama) {
    if (root == nullptr) return;
    searchByProduct(root->left, nama);
    if (root->namaProduk == nama) {
        std::cout << "Ditemukan: ID " << root->idProduk << " | Stok: " << root->stok << "\n";
    }
    searchByProduct(root->right, nama);
}

Node* findMin(Node* root) {
    while (root && root->left != nullptr) root = root->left;
    return root;
}

Node* findMax(Node* root) {
    while (root && root->right != nullptr) root = root->right;
    return root;
}

Node* deleteNode(Node* root, int id) {
    if (root == nullptr) return root;
    if (id < root->idProduk) root->left = deleteNode(root->left, id);
    else if (id > root->idProduk) root->right = deleteNode(root->right, id);
    else {
        if (root->left == nullptr) {
            Node* temp = root->right; delete root; return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left; delete root; return temp;
        }
        Node* temp = findMin(root->right);
        root->idProduk = temp->idProduk;
        root->namaProduk = temp->namaProduk;
        root->stok = temp->stok;
        root->right = deleteNode(root->right, temp->idProduk);
    }
    return root;
}

void deleteTree(Node*& root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = nullptr;
}

void inOrder(Node* root) {
    if (root == nullptr) return;
    inOrder(root->left);
    std::cout << root->idProduk << " ";
    inOrder(root->right);
}

void preOrder(Node* root) {
    if (root == nullptr) return;
    std::cout << root->idProduk << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root) {
    if (root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    std::cout << root->idProduk << " ";
}