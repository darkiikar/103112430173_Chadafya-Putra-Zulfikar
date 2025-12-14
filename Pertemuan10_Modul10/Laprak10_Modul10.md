# <h1 align="center">Laporan Praktikum Modul 10 - TREE (BAGIAN PERTAMA) </h1>
<p align="center">Chadafya Putra Zulfikar - 103112430173</p>

## Dasar Teori
### 1. Definisi Pohon (Tree)
Tree adalah sebuah struktur data non-linear dan hierarkis yang digunakan untuk merepresentasikan data yang memiliki hubungan bertingkat (satu-ke-banyak). Berbeda dengan struktur data linear seperti array atau linked list, data pada tree diatur dalam beberapa level yang terhubung satu sama lain.

### 2. Komponen dan Terminologi Tree
Beberapa terminologi penting dalam struktur data tree:
- Node (Simpul): Elemen dasar yang menyimpan data.
- Root (Akar): Node paling atas dalam tree. Node ini unik karena tidak memiliki parent.
- Edge (Cabang/Tepi): Garis penghubung antara dua node. Merepresentasikan hubungan antara parent dan child.
- Parent (Induk): Node yang berada satu tingkat di atas node lain dan terhubung dengannya.
- Child (Anak): Node yang berada satu tingkat di bawah parent dan terhubung dengannya.
- Leaf (Daun): Node yang tidak memiliki child (node terakhir dalam sebuah cabang).
- Subtree (Sub-pohon): Bagian dari tree yang juga merupakan tree itu sendiri.
- Depth (Kedalaman): Jarak (jumlah edge) dari root ke node tertentu. Root memiliki kedalaman 0.
- Height (Tinggi): Panjang maksimum dari root ke leaf terjauh.

### 3. Jenis-Jenis Tree Utama
- Binary Tree: tree di mana setiap simpul memiliki paling banyak dua child (left child dan right child). Merupakan dasar untuk banyak struktur data yang lebih kompleks.
- Binary Search Tree (BST): binary tree terurut di mana untuk setiap simpul, semua nilai pada subtree kiri lebih kecil dan semua nilai pada subtree kanan lebih besar. Memungkinkan pencarian, penyisipan, dan penghapusan dengan kompleksitas rata-rata O(log n).
- AVL Tree: self-balancing binary search tree yang mempertahankan keseimbangan tinggi dengan faktor keseimbangan antara -1 dan 1, menjamin kompleksitas O(log n) untuk semua operasi.
- Red-Black Tree: self-balancing binary search tree dengan properti warna yang menjamin keseimbangan dan kinerja O(log n) untuk operasi dasar, lebih fleksibel dari AVL tree.
- B-Tree: tree berderajat tinggi yang dioptimalkan untuk sistem penyimpanan disk, digunakan dalam database dan sistem file untuk mengurangi jumlah akses disk.

### 4. Operasi Dasar pada Tree
Dalam implementasi tree menggunakan C++, biasanya digunakan struktur Node yang berisi data dan pointer ke child (misalnya left dan right untuk Binary Tree).
Berikut adalah operasi dasar yang umum pada tree:
1. Create/Initialization (Pembuatan):
- Membuat root node pertama (untuk tree kosong).
- Dalam C++, ini biasanya melibatkan alokasi memori untuk node baru.
2. Insert (Penyisipan):
- Menambahkan node baru ke tree. Posisinya bergantung pada jenis tree (misalnya pada BST, penempatan dilakukan secara rekursif berdasarkan perbandingan nilai).
3. Delete (Penghapusan):
- Menghapus node tertentu dari tree. Operasi ini kompleks, terutama pada BST, karena harus memastikan struktur tree dan properti BST tetap terjaga.
4. Search (Pencarian):
- Mencari node dengan nilai tertentu. Pada BST, pencarian dilakukan dengan efisien dengan membandingkan nilai saat ini dan bergerak ke kiri atau kanan.
5. Traversal (Penelusuran):
- Mengunjungi semua node dalam tree dengan urutan tertentu. Traversal yang paling umum adalah:
- Inorder (Kiri -> Root -> Kanan): Menghasilkan data terurut pada BST.
- Preorder (Root -> Kiri -> Kanan): Cocok untuk menyalin tree.
- Postorder (Kiri -> Kanan -> Root): Cocok untuk menghapus tree (delete).

## Guided 

### 1. Implementasi dan Pengujian Binary Search Tree (BST)
#### [bst.h]
```C++
#ifndef BST_H
#define BST_H
#define Nil NULL 

using namespace std;

typedef struct BST *node;

struct BST {
    int angka;
    node left;
    node right;
};

typedef node BinTree;

bool isEmpty(BinTree tree);
void createTree(BinTree &tree);
node alokasi(int angka);
void deAlokasi(node nodeHapus);

void insertNode(BinTree &tree, node nodeBaru);
void searchByData(BinTree tree, int angka);
void preOrder(BinTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

bool deleteNode(BinTree &tree, int angka);
node mostRight(BinTree tree);
node mostLeft(BinTree tree);
void deleteTree(BinTree &tree);
int size(BinTree tree);
int height(BinTree tree);

#endif
```

#### [bst.cpp]
```C++
#include "bst.h"
#include <iostream>

using namespace std;
//NOTE : parameter tree disini maksudnya merujuk ke node; baik itu node root atau node lain dari tree

bool isEmpty(BinTree tree){
    if(tree == Nil){
        return true;
    } else {
        return false;
    }
}

void createTree(BinTree &tree){
    tree = Nil;
}

node alokasi(int angkaInput){
    node nodeBaru = new BST;
    nodeBaru->angka = angkaInput;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus){
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru){
    if(tree == Nil){
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan ke dalam tree!" << endl;
        return;
    } else if(nodeBaru->angka < tree->angka){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->angka > tree->angka){
        insertNode(tree->right, nodeBaru);
    }
}

void searchByData(BinTree tree, int angkaCari){
    if(isEmpty(tree) == true){
        cout << "Tree kosong!" << endl;
    } else {
        node nodeBantu = tree;
        node parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(angkaCari < nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(angkaCari > nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(angkaCari == nodeBantu->angka){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data Angka : " << nodeBantu->angka << endl;

            //menampilkan parentnya & pengecekan sibling
            node sibling = Nil;
            if(parent != Nil){
                cout << "Parent : " << parent->angka << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != Nil){
                cout << "Sibling : " << sibling->angka << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != Nil){
                cout << "Child kiri : " << nodeBantu->left->angka << endl;
            } else if(nodeBantu->left == Nil){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != Nil){
                cout << "Child kanan : " << nodeBantu->right->angka << endl;
            } else if(nodeBantu->right == Nil){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}

void preOrder(BinTree tree){ //tengah - kiri - kanan atau root - child kiri - child kanan
    if(tree == Nil){
        return;
    }
    cout << tree->angka << " - ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(BinTree tree){ //kiri - tengah - kanan atau child kiri - root - child kanan
    if(tree == Nil){
        return;
    }
    inOrder(tree->left);
    cout << tree->angka << " - ";
    inOrder(tree->right);
}

void postOrder(BinTree tree){ //kiri - kanan - tengah atau child kiri - child kanan - root
    if(tree == Nil){
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->angka << " - ";
}



bool deleteNode(BinTree &tree, int angka) {
    if (tree == Nil) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (angka < tree->angka) {
            return deleteNode(tree->left, angka);
        } else if (angka > tree->angka) {
            return deleteNode(tree->right, angka);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (tree->left == Nil && tree->right == Nil) {
                node tmp = tree;
                tree = Nil;
                dealokasi(tmp);
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (tree->left == Nil) {
                node tmp = tree;
                tree = tree->right;
                dealokasi(tmp);
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (tree->right == Nil) {
                node tmp = tree;
                tree = tree->left;
                dealokasi(tmp);
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                node successor = mostLeft(tree->right);
                //salin data successor ke node saat ini
                tree->angka = successor->angka;
                //hapus successor pada subtree kanan
                return deleteNode(tree->right, successor->angka);
            }
            return true; //berhasil dihapus
        }
    }
}

node mostRight(BinTree tree){
    while (tree->right != Nil){
        tree = tree->right;
    }
    return tree;    
}

node mostLeft(BinTree tree){
    while (tree->left != Nil){
        tree = tree->left;
    }
    return tree;
}

void deleteTree(BinTree &tree){
    if(tree == Nil){
        return;
    } else {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}

int size(BinTree tree){ //mengembalikan jumlah semua node
    if(isEmpty(tree) == true){
        return 0;
    } else {
        return 1 + size(tree->left) + size(tree->right);
    }
    cout << endl;
}

int height(BinTree tree){ //mengembalikan jumlah level tree
    if(isEmpty(tree) == true){
        return -1; //tree kosong jika height = -1
    } else {
        int hl = height(tree->left);
        int hr = height(tree->right);
        int maxHeight;
        if (hl > hr){
            maxHeight = hl;
        } else {
            maxHeight = hr;
        }
        return 1 + maxHeight;
    }
    cout << endl;
}
```

#### [main.cpp]
```C++
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    BinTree tree;
    createTree(tree);

    int pilih, angka;

    do {
        cout << "========= MENU BST =========" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Data" << endl;
        cout << "4. Tampilkan PreOrder" << endl;
        cout << "5. Tampilkan InOrder" << endl;
        cout << "6. Tampilkan PostOrder" << endl;
        cout << "7. Size Tree (jumlah node)" << endl;
        cout << "8. Height Tree (tinggi level)" << endl;
        cout << "9. Tampilkan mostright" << endl;
        cout << "10. Tampilkan mostleft" << endl;
        cout << "11. Delete Seluruh Tree" << endl;
        cout << "0. Keluar" << endl;
        cout << "pilihan anda : ";
        cin >> pilih;
        cout << endl;

        switch (pilih){
        case 1:
            cout << "Masukkan angka: ";
            cin >> angka;
            insertNode(tree, alokasi(angka));
            cout << endl;
            break;

        case 2:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dihapus: ";
                cin >> angka;
                if(deleteNode(tree, angka)){
                    cout << "Data " << angka << " berhasil dihapus!" << endl;
                } else {
                    cout << "Data " << angka << " tidak ditemukan!" << endl;
                }
            }
            cout << endl;
            break;

        case 3:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dicari: ";
                cin >> angka;
                searchByData(tree, angka);
            }
            cout << endl;
            break;

        case 4:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PreOrder : ";
                preOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 5:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "InOrder : ";
                inOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 6:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PostOrder : ";
                postOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 7:
            cout << "Size Tree = " << size(tree) << endl;
            cout << endl;
            break;

        case 8:
            cout << "Height Tree = " << height(tree) << endl;
            cout << endl;
            break;

        case 9: 
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostright : " << mostRight(tree)->angka << endl;
                cout << endl;
            }
            break;
        
        case 10:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostleft : " << mostLeft(tree)->angka << endl;
                cout << endl;
            }
            break;

        case 11:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                deleteTree(tree);
                cout << "Seluruh tree berhasil dihapus!" << endl;
            }
            cout << endl;
            break;

        case 0:
            cout << "Keluar dari program..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }

    } while (pilih != 0);

    return 0;
}
```

Kode program ini mengimplementasikan Binary Search Tree (BST), sebuah struktur data hierarkis yang memastikan data tersusun rapi: nilai di sub-pohon kiri selalu lebih kecil dari node induk, dan nilai di sub-pohon kanan selalu lebih besar. Program ini menyediakan seluruh operasi fundamental BST, termasuk penyisipan, penghapusan (mengatasi empat skenario yang kompleks), dan pencarian data yang lengkap dengan detail hubungan kekerabatan (parent, sibling, child). Selain itu, tersedia fungsi utilitas untuk penelusuran (traversal Pre-order, In-order, Post-order), menghitung ukuran dan tinggi tree, serta mencari nilai ekstrem (mostleft dan mostright). Implementasi ini menunjukkan efisiensi BST dalam memproses data, dengan kompleksitas waktu rata-rata.

## Unguided 

### 1. ![Screenshot Unguided 1_1](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan10_Modul10/Soal-Unguided1.png)

#### [bst.h]
```C++
#ifndef BST_H
#define BST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef struct BST *node;

struct BST {
    int info;
    node left;
    node right;
};

typedef node BinTree;

bool isEmpty(BinTree pohon);
void createTree(BinTree &pohon);
node alokasi(int x);
void insertNode(BinTree &pohon, node nodeBaru);
node findNode(int x, BinTree pohon);
void inOrder(BinTree pohon);

#endif
```

#### [bst.cpp]
```C++
#include "bst.h"
#include <iostream>

using namespace std;

bool isEmpty(BinTree pohon) {
    if (pohon == Nil) {
        return true;
    } else {
        return false;
    }
}

void createTree(BinTree &pohon) {
    pohon = Nil;
}

node alokasi(int x) {
    node nodeBaru = new BST;
    nodeBaru->info = x;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void insertNode(BinTree &pohon, node nodeBaru) {
    if (pohon == Nil) {
        pohon = nodeBaru;
    } else if (nodeBaru->info < pohon->info) {
        insertNode(pohon->left, nodeBaru);
    } else if (nodeBaru->info > pohon->info) {
        insertNode(pohon->right, nodeBaru);
    }
}

node findNode(int x, BinTree pohon) {
    if (pohon == Nil) {
        return Nil;
    } else if (x < pohon->info) {
        return findNode(x, pohon->left);
    } else if (x > pohon->info) {
        return findNode(x, pohon->right);
    } else {
        return pohon;
    }
}

void inOrder(BinTree pohon) {
    if (pohon == Nil) {
        return;
    }
    inOrder(pohon->left);
    cout << pohon->info << " - ";
    inOrder(pohon->right);
}
```

#### [main.cpp]
```C++
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    cout << "Hello World!" << endl;
    BinTree root = Nil;
    insertNode(root, alokasi(1));
    insertNode(root, alokasi(2));
    insertNode(root, alokasi(6));
    insertNode(root, alokasi(4));
    insertNode(root, alokasi(5));
    insertNode(root, alokasi(3));
    insertNode(root, alokasi(6));
    insertNode(root, alokasi(7));
    inOrder(root);
    cout << endl;
    
    return 0;
}
```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan10_Modul10/Output-Unguided1.png)

Kode ini adalah implementasi dasar dari Binary Search Tree (BST), struktur data pohon yang secara inheren mengurutkan data dengan aturan: nilai node di cabang kiri harus lebih kecil, dan di cabang kanan harus lebih besar dari node induk.  Program ini mencakup operasi fundamental seperti pembuatan tree, alokasi node, penyisipan (insert), dan pencarian. Secara khusus, program ini menggunakan fungsi In-order Traversal yang menelusuri tree dengan urutan Kiri -> Root -> Kanan, yang secara efektif menghasilkan daftar data yang tersimpan dalam BST dalam urutan menaik (ascending).

### 2. ![Screenshot Unguided 2_1](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan10_Modul10/Soal-Unguided2.png)

#### [bst.h]
```C++
#ifndef BST_H
#define BST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef struct BST *node;

struct BST {
    int info;
    node left;
    node right;
};

typedef node BinTree;

bool isEmpty(BinTree pohon);
void createTree(BinTree &pohon);
node alokasi(int x);
void insertNode(BinTree &pohon, node nodeBaru);
node findNode(int x, BinTree pohon);
void inOrder(BinTree pohon);
int hitungKedalaman(BinTree pohon, int awal);
int hitungTotalInfo(BinTree pohon, int awal);
int hitungJumlahNode(BinTree pohon);

#endif
```

#### [bst.cpp]
```C++
#include "bst.h"
#include <iostream>

using namespace std;

bool isEmpty(BinTree pohon) {
    if (pohon == Nil) {
        return true;
    } else {
        return false;
    }
}

void createTree(BinTree &pohon) {
    pohon = Nil;
}

node alokasi(int x) {
    node nodeBaru = new BST;
    nodeBaru->info = x;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void insertNode(BinTree &pohon, node nodeBaru) {
    if (pohon == Nil) {
        pohon = nodeBaru;
    } else if (nodeBaru->info < pohon->info) {
        insertNode(pohon->left, nodeBaru);
    } else if (nodeBaru->info > pohon->info) {
        insertNode(pohon->right, nodeBaru);
    }
}

node findNode(int x, BinTree pohon) {
    if (pohon == Nil) {
        return Nil;
    } else if (x < pohon->info) {
        return findNode(x, pohon->left);
    } else if (x > pohon->info) {
        return findNode(x, pohon->right);
    } else {
        return pohon;
    }
}

void inOrder(BinTree pohon) {
    if (pohon == Nil) {
        return;
    }
    inOrder(pohon->left);
    cout << pohon->info << " - ";
    inOrder(pohon->right);
}

int hitungKedalaman(BinTree pohon, int awal) {
    if (pohon == Nil) {
        return awal;
    }
    int kedalamanKiri = hitungKedalaman(pohon->left, awal + 1);
    int kedalamanKanan = hitungKedalaman(pohon->right, awal + 1);
    
    if (kedalamanKiri > kedalamanKanan) {
        return kedalamanKiri;
    } else {
        return kedalamanKanan;
    }
}

int hitungTotalInfo(BinTree pohon, int awal) {
    if (pohon == Nil) {
        return 0;
    }
    return pohon->info + hitungTotalInfo(pohon->left, awal) + hitungTotalInfo(pohon->right, awal);
}

int hitungJumlahNode(BinTree pohon) {
    if (pohon == Nil) {
        return 0;
    }
    return 1 + hitungJumlahNode(pohon->left) + hitungJumlahNode(pohon->right);
}
```

#### [main.cpp]
```C++
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    cout << "Hello World!" << endl;
    BinTree root = Nil;
    insertNode(root, alokasi(1));
    insertNode(root, alokasi(2));
    insertNode(root, alokasi(6));
    insertNode(root, alokasi(4));
    insertNode(root, alokasi(5));
    insertNode(root, alokasi(3));
    insertNode(root, alokasi(6));
    insertNode(root, alokasi(7));
    inOrder(root);
    cout << "\n";
    cout << "kedalaman : " << hitungKedalaman(root, 0) << endl;
    cout << "jumlah Node : " << hitungJumlahNode(root) << endl;
    cout << "total : " << hitungTotalInfo(root, 0) << endl;
    
    return 0;
}
```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan10_Modul10/Output-Unguided2.png)

Kode program ini mengimplementasikan Binary Search Tree (BST) dasar, yang mendukung operasi penyisipan (insert) dan traversal In-order. Fitur unik dari implementasi ini adalah penambahan fungsionalitas analisis struktur tree. Fungsi-fungsi analisis yang disediakan meliputi hitungKedalaman (menentukan tinggi maksimum tree), hitungJumlahNode (menghitung total elemen), dan hitungTotalInfo (menjumlahkan semua nilai data yang tersimpan dalam tree). Traversal In-order digunakan untuk memvalidasi BST dengan menghasilkan daftar data yang terurut secara menaik (ascending). Program ini secara efektif mendemonstrasikan bagaimana BST tidak hanya mengatur data secara efisien tetapi juga memfasilitasi pemeriksaan metrik struktural dan agregasi nilai.

### 3. ![Screenshot Unguided 3_1](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan10_Modul10/Soal-Unguided3.png)

#### [bst.h]
```C++
#ifndef BST_H
#define BST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef struct BST *node;

struct BST {
    int info;
    node left;
    node right;
};

typedef node BinTree;

bool isEmpty(BinTree pohon);
void createTree(BinTree &pohon);
node alokasi(int x);
void insertNode(BinTree &pohon, node nodeBaru);
node findNode(int x, BinTree pohon);
void inOrder(BinTree pohon);
void preOrder(BinTree pohon);
void postOrder(BinTree pohon);
int hitungKedalaman(BinTree pohon, int awal);
int hitungTotalInfo(BinTree pohon, int awal);
int hitungJumlahNode(BinTree pohon);

#endif
```

#### [bst.cpp]
```C++
#include "bst.h"
#include <iostream>

using namespace std;

bool isEmpty(BinTree pohon) {
    if (pohon == Nil) {
        return true;
    } else {
        return false;
    }
}

void createTree(BinTree &pohon) {
    pohon = Nil;
}

node alokasi(int x) {
    node nodeBaru = new BST;
    nodeBaru->info = x;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void insertNode(BinTree &pohon, node nodeBaru) {
    if (pohon == Nil) {
        pohon = nodeBaru;
    } else if (nodeBaru->info < pohon->info) {
        insertNode(pohon->left, nodeBaru);
    } else if (nodeBaru->info > pohon->info) {
        insertNode(pohon->right, nodeBaru);
    }
}

node findNode(int x, BinTree pohon) {
    if (pohon == Nil) {
        return Nil;
    } else if (x < pohon->info) {
        return findNode(x, pohon->left);
    } else if (x > pohon->info) {
        return findNode(x, pohon->right);
    } else {
        return pohon;
    }
}

void inOrder(BinTree pohon) {
    if (pohon == Nil) {
        return;
    }
    inOrder(pohon->left);
    cout << pohon->info << " - ";
    inOrder(pohon->right);
}

void preOrder(BinTree pohon) {
    if (pohon == Nil) {
        return;
    }
    cout << pohon->info << " - ";
    preOrder(pohon->left);
    preOrder(pohon->right);
}

void postOrder(BinTree pohon) {
    if (pohon == Nil) {
        return;
    }
    postOrder(pohon->left);
    postOrder(pohon->right);
    cout << pohon->info << " - ";
}

int hitungKedalaman(BinTree pohon, int awal) {
    if (pohon == Nil) {
        return awal;
    }
    int kedalamanKiri = hitungKedalaman(pohon->left, awal + 1);
    int kedalamanKanan = hitungKedalaman(pohon->right, awal + 1);
    
    if (kedalamanKiri > kedalamanKanan) {
        return kedalamanKiri;
    } else {
        return kedalamanKanan;
    }
}

int hitungTotalInfo(BinTree pohon, int awal) {
    if (pohon == Nil) {
        return 0;
    }
    return pohon->info + hitungTotalInfo(pohon->left, awal) + hitungTotalInfo(pohon->right, awal);
}

int hitungJumlahNode(BinTree pohon) {
    if (pohon == Nil) {
        return 0;
    }
    return 1 + hitungJumlahNode(pohon->left) + hitungJumlahNode(pohon->right);
}
```

#### [main.cpp]
```C++
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    cout << "Binary Search Tree Pre-Order dan Post-Order" << endl;
    BinTree root = Nil;
    
    insertNode(root, alokasi(6));
    insertNode(root, alokasi(4));
    insertNode(root, alokasi(7));
    insertNode(root, alokasi(2));
    insertNode(root, alokasi(5));
    insertNode(root, alokasi(1));
    insertNode(root, alokasi(3));
    
    cout << "\nIn-Order Traversal: ";
    inOrder(root);
    cout << "\n" << endl;
    
    cout << "Pre-Order Traversal: ";
    preOrder(root);
    cout << "\n" << endl;
    
    cout << "Post-Order Traversal: ";
    postOrder(root);
    cout << "\n" << endl;
    
    return 0;
}
```

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan10_Modul10/Output-Unguided3.png)

Kode ini mengimplementasikan Binary Search Tree (BST) dengan menampilkan tiga metode traversal—In-Order (menghasilkan data terurut), Pre-Order, dan Post-Order—untuk menunjukkan bagaimana setiap metode menghasilkan urutan output yang berbeda meskipun struktur tree yang diakses sama, memberikan fleksibilitas pemrosesan data.

## Kesimpulan
- Struktur data Tree adalah fondasi vital dalam ilmu komputer, berfungsi sebagai representasi data hierarkis non-linear yang efisien, di mana setiap elemen data (Node) terhubung melalui hubungan induk-anak (Parent-Child).  Komponen penting seperti Root (akar, titik awal), Leaf (daun, titik akhir tanpa anak), dan Edge (koneksi) mendefinisikan topologinya. Berbagai jenis tree, seperti Binary Tree (maksimum dua anak) dan sub-tipe kritisnya, Binary Search Tree (BST), memungkinkan pengorganisasian data yang logis. Properti utama BST—nilai kiri lebih kecil dari parent dan nilai kanan lebih besar—membuatnya sangat ideal untuk operasi pencarian, penyisipan, dan penghapusan data, jauh lebih efisien dibandingkan dengan struktur linear, yang performanya cenderung pada kasus terburuk.
- Implementasi tree dalam bahasa pemrograman seperti C++ bergantung pada penggunaan structs dan pointers untuk mendefinisikan setiap Node dan menghubungkannya secara dinamis. Operasi dasar seperti Insertion (penyisipan), Deletion (penghapusan), dan Search (pencarian) harus dilakukan secara rekursif atau iteratif sambil menjaga properti tree tetap utuh, terutama pada BST.  Selain itu, Traversal adalah operasi penting untuk mengakses semua node dengan urutan yang terdefinisi (seperti Inorder, Preorder, dan Postorder). Kemampuan tree untuk meniru struktur dunia nyata, mulai dari sistem file hingga pohon keputusan (decision tree), memastikan perannya tak tergantikan dalam merancang algoritma yang kompleks dan sistem manajemen data berkinerja tinggi.

## Referensi
[1] D. E. Knuth, "The Art of Computer Programming, Vol. 1: Fundamental Algorithms," 3rd ed. Reading, MA, USA: Addison-Wesley, 1997.

<br>[2] T. H. Cormen, C. E. Leiserson, R. L. Rivest, and C. Stein, "Introduction to Algorithms," 4th ed. Cambridge, MA, USA: MIT Press, 2022.

<br>[3] E. Horowitz, S. Sahni, and D. Mehta, "Fundamentals of Data Structures in C++," 2nd ed. Summit, NJ, USA: Silicon Press, 2007.

<br>[4] M. T. Goodrich, R. Tamassia, and D. M. Mount, "Data Structures and Algorithms in C++," 2nd ed. Hoboken, NJ, USA: John Wiley & Sons, 2011.