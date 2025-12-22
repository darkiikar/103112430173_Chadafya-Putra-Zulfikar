#include "bst.h"
#include <iomanip> // Untuk merapikan tampilan tabel

void printHeader(std::string title) {
    std::cout << "\n========================================" << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << "========================================" << std::endl;
}

int main() {
    Node* root = nullptr;
    std::cout << "\n\nCHADAFYA PUTRA ZULFIKAR | IF-12-02" << std::endl;

    printHeader("1) INPUT DATA PRODUK");
    // Proses input sesuai tabel
    root = insertNode(root, 50, "Monitor LED", 10);  std::cout << "ID PRODUK: 50 | NAMA PRODUK: Monitor LED  | STOCK: 10\n";
    root = insertNode(root, 30, "Keyboard RGB", 20); std::cout << "ID PRODUK: 30 | NAMA PRODUK: Keyboard RGB | STOCK: 20\n";
    root = insertNode(root, 70, "Mouse Gaming", 15); std::cout << "ID PRODUK: 70 | NAMA PRODUK: Mouse Gaming | STOCK: 15\n";
    root = insertNode(root, 20, "Kabel HDMI", 50);   std::cout << "ID PRODUK: 20 | NAMA PRODUK: Kabel HDMI   | STOCK: 50\n";
    root = insertNode(root, 40, "Headset 7.1", 12);  std::cout << "ID PRODUK: 40 | NAMA PRODUK: Headset 7.1  | STOCK: 12\n";
    root = insertNode(root, 60, "Webcam HD", 8);     std::cout << "ID PRODUK: 60 | NAMA PRODUK: Webcam HD    | STOCK: 8\n";
    root = insertNode(root, 80, "Speaker BT", 5);    std::cout << "ID PRODUK: 80 | NAMA PRODUK: Speaker BT   | STOCK: 5\n";

    printHeader("2) TRAVERSAL TREE");
    std::cout << "InOrder   : "; inOrder(root);   std::cout << std::endl;
    std::cout << "PreOrder  : "; preOrder(root);  std::cout << std::endl;
    std::cout << "PostOrder : "; postOrder(root); std::cout << std::endl;

    printHeader("3 & 4) SEARCH BY ID");
    searchById(root, 40);
    searchById(root, 99);

    printHeader("5 & 6) SEARCH BY PRODUCT NAME");
    searchByProduct(root, "Webcam HD");
    searchByProduct(root, "Printer");  

    printHeader("7) FIND MIN & MAX");
    Node* min = findMin(root);
    Node* max = findMax(root);
    if(min) std::cout << "Min ID: " << min->idProduk << " (" << min->namaProduk << ")" << std::endl;
    if(max) std::cout << "Max ID: " << max->idProduk << " (" << max->namaProduk << ")" << std::endl;

    printHeader("8 - 13) DELETE OPERATIONS");
    std::cout << "Deleting ID 20..." << std::endl; root = deleteNode(root, 20);
    std::cout << "InOrder After Delete 20: "; inOrder(root); std::cout << std::endl;

    std::cout << "\nDeleting ID 30..." << std::endl; root = deleteNode(root, 30);
    std::cout << "InOrder After Delete 30: "; inOrder(root); std::cout << std::endl;

    std::cout << "\nDeleting ID 50 (Root)..." << std::endl; root = deleteNode(root, 50);
    std::cout << "InOrder After Delete 50: "; inOrder(root); std::cout << std::endl;

    printHeader("14 & 15) DELETE ALL TREE");
    deleteTree(root);
    std::cout << "InOrder After deleteTree(): "; inOrder(root);
    if (root == nullptr) std::cout << "(Pohon Kosong)";
    std::cout << "\n\nPROGRAM SELESAI KING" << std::endl;

    return 0;
}