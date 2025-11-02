# <h1 align="center">Laporan Praktikum Modul 6 - DOUBLY LINKED LIST (BAGIAN PERTAMA) </h1>
<p align="center">Chadafya Putra Zulfikar - 103112430173</p>

## Dasar Teori
### 1. Definisi dan Struktur Dasar
Doubly Linked List (DLL) adalah struktur data linier di mana setiap elemen, yang disebut simpul (node), terhubung secara sekuensial dan memiliki dua penunjuk (pointer): satu menunjuk ke simpul berikutnya dan satu lagi menunjuk ke simpul sebelumnya. Hal ini memungkinkan penelusuran bidireksional (maju dan mundur).

Struktur
Data/Info: Nilai yang disimpan oleh simpul.
Next Pointer: Penunjuk ke simpul setelahnya.
Prev Pointer: Penunjuk ke simpul sebelumnya.

### 2. Operasi pada Doubly Linked List

Operasi inti pada Doubly Linked List berputar pada penyisipan (insertion), penghapusan (deletion), dan penelusuran (traversal). Penyisipan simpul baru dapat dilakukan secara efisien di awal, akhir, atau tengah list, di mana setiap operasi memerlukan pembaruan empat penunjuk: penunjuk next dan prev dari simpul yang disisipkan, serta penunjuk next dan prev dari simpul tetangganya. Demikian pula, operasi penghapusan, baik di awal, akhir, maupun di tengah, menjadi sangat efisien (O(1)) karena keberadaan penunjuk prev memungkinkan simpul sebelum simpul yang akan dihapus dapat diakses dan dimodifikasi secara langsung tanpa harus menelusuri list dari awal. Selain itu, DLL unggul dalam penelusuran karena mendukung dua arah—maju dari head ke tail dan mundur dari tail ke head—sehingga fleksibel untuk pencarian dan pemrosesan data.

### 3. Kelebihan dan Kekurangan
#### Kelebihan
- Akses Simpul Sebelumnya: Kemampuan untuk bergerak mundur memungkinkan penghapusan simpul di tengah list menjadi operasi O(1) yang jauh lebih mudah dibandingkan Singly Linked List.
- Penelusuran Dua Arah: Fleksibel untuk aplikasi yang memerlukan navigasi maju dan mundur (misalnya, Undo/Redo).

#### Kekurangan
- Memori Overhead: Membutuhkan memori tambahan lebih besar karena setiap simpul menyimpan dua penunjuk (Next dan Prev).
- Kompleksitas Implementasi: Operasi penyisipan dan penghapusan memerlukan pembaruan empat penunjuk (dua pada simpul baru, dua pada simpul tetangga), yang lebih rentan terhadap bug jika tidak ditangani dengan hati-hati.

### 4. Variasi dan Kontemporer
- Circular Doubly Linked List (CDLL): Varian di mana penunjuk Prev dari simpul pertama menunjuk ke simpul terakhir, dan Next dari simpul terakhir menunjuk ke simpul pertama, membentuk lingkaran.
- Kontemporer: Dalam komputasi paralel dan sistem high-performance, DLL sering diimplementasikan sebagai Lock-Free (atau Wait-Free) agar aman digunakan oleh banyak thread secara bersamaan tanpa locks yang bisa memperlambat sistem (seperti yang dibahas dalam referensi Sundell & Tsigas).

### 5. Konteks Penggunaan dan Relevansi terhadap Simulasi / Aplikasi
DLL sangat relevan dalam aplikasi yang membutuhkan manipulasi elemen yang sering dan navigasi bolak-balik:
- Sistem Undo/Redo: Dalam perangkat lunak pengolah kata atau desain grafis, riwayat tindakan dikelola oleh DLL.
- Browser History: Navigasi "Back" dan "Forward" pada browser web.
- Cache LRU (Least Recently Used): Digunakan untuk melacak urutan data yang baru saja diakses, memungkinkan penghapusan elemen yang paling jarang digunakan dengan cepat (O(1)).
- Simulasi: Berguna dalam simulasi diskret untuk mengelola antrean peristiwa yang perlu disisipkan atau dihapus di tengah list berdasarkan waktu kejadian.

## Guided 

### 1. Program Manajemen Data Makanan dengan Double Linked List
#### [listMakanan.h]
```C++
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
#include<string>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

#endif
```

#### [listMakanan.cpp]
```C++
#include "listMakanan.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```

#### [main.cpp]
```C++
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeC);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    return 0;
}
```
Program ini dirancang untuk mendemonstrasikan struktur data Doubly Linked List, yang secara spesifik digunakan untuk mengelola data makanan yang meliputi nama, jenis, harga, dan rating. Struktur dan deklarasi fungsi-fungsi kunci, seperti untuk menyisipkan (insert), memperbarui (update), dan menampilkan (printList) data, didefinisikan dalam file listMakanan.h. Logika terperinci dari fungsi-fungsi tersebut, termasuk menambahkan node di berbagai posisi (awal, akhir, sebelum, atau sesudah node tertentu) dan memodifikasi konten node yang sudah ada, diimplementasikan dalam file listMakanan.cpp. Sementara itu, file utama main.cpp bertindak sebagai driver untuk menginisialisasi daftar, mengisi daftar dengan data makanan awal, dan memanggil fungsi-fungsi manipulasi list untuk menunjukkan secara praktis cara kerja Doubly Linked List.

### 2. Program Manajemen Data Makanan Menggunakan Double Linked List dengan Operasi CRUD dan Pencarian
#### [listMakanan.h]
```C++
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

// Searching
void findByName(linkedlist List, string nama);
void findByJenis(linkedlist List, string jenis);
void findByMinRating(linkedlist List, float minRating);

// Delete
void deleteFirst(linkedlist &List);
void deleteLast(linkedlist &List);
void deleteAfter(linkedlist &List, address Prev);
void deleteBefore(linkedlist &List, address nodeNext);

void deleteNode(linkedlist &List, address target);
void deleteByName(linkedlist &List, string nama);

#endif
```

#### [listMakanan.cpp]
```C++
#include "listMakanan.h"
#include <iostream>
#include <string>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// SEARCHING
void findByName(linkedlist List, string nama){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.nama == nama){
            cout << "Ditemukan (berdasarkan nama):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan nama \"" << nama << "\" tidak ditemukan." << endl;
}

void findByJenis(linkedlist List, string jenis){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.jenis == jenis){
            cout << "Ditemukan (berdasarkan jenis):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan jenis \"" << jenis << "\" tidak ditemukan." << endl;
}

void findByMinRating(linkedlist List, float minRating){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.rating >= minRating){
            cout << "Ditemukan (rating >= " << minRating << "):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Tidak ada data dengan rating >= " << minRating << "." << endl;
}

// DELETE
void deleteFirst(linkedlist &List){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.first;
    if(List.first == List.last){
        List.first = List.last = Nil;
    } else {
        List.first = pDel->next;
        List.first->prev = Nil;
        pDel->next = Nil;
    }
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi pertama." << endl;
    dealokasi(pDel);
}

void deleteLast(linkedlist &List){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.last;
    if(List.first == List.last){
        List.first = List.last = Nil;
    } else {
        List.last = pDel->prev;
        List.last->next = Nil;
        pDel->prev = Nil;
    }
    pDel->next = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi terakhir." << endl;
    dealokasi(pDel);
}

void deleteAfter(linkedlist &List, address Prev){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if(Prev == Nil || Prev->next == Nil){
        cout << "Node sebelumnya (Prev) tidak valid atau tidak ada node setelahnya!" << endl;
        return;
    }
    if(Prev->next == List.last){
        deleteLast(List);
        return;
    }
    address pDel = Prev->next;
    Prev->next = pDel->next;
    pDel->next->prev = Prev;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus setelah node " << Prev->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteBefore(linkedlist &List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if(nodeNext == Nil || nodeNext->prev == Nil){
        cout << "Node setelahnya (nodeNext) tidak valid atau tidak ada node sebelumnya!" << endl;
        return;
    }
    if(nodeNext->prev == List.first){
        deleteFirst(List);
        return;
    }
    address pDel = nodeNext->prev;
    nodeNext->prev = pDel->prev;
    pDel->prev->next = nodeNext;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus sebelum node " << nodeNext->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteNode(linkedlist &List, address target){
    if(isEmpty(List) == true || target == Nil){
        cout << "Target tidak valid atau list kosong!" << endl;
        return;
    }
    if(target == List.first){
        deleteFirst(List);
    } else if(target == List.last){
        deleteLast(List);
    } else {
        address L = target->prev;
        address R = target->next;
        L->next = R;
        R->prev = L;
        target->next = Nil;
        target->prev = Nil;
        cout << "Node " << target->isidata.nama << " berhasil dihapus dari tengah list." << endl;
        dealokasi(target);
    }
}

void deleteByName(linkedlist &List, string nama){
    if(isEmpty(List)){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }

    address target = List.first;
    while(target != Nil && target->isidata.nama != nama){
        target = target->next;
    }
    if(target == Nil){
        cout << "Node dengan nama \"" << nama << "\" tidak ditemukan." << endl;
        return;
    }

    deleteNode(List, target);
    cout << "Node dengan nama \"" << nama << "\" telah dihapus dan didealokasi." << endl;
}
```

#### [main.cpp]
```C++
	#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeA);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    cout << endl;

    findByName(List, "Nasgor");

    deleteByName(List, "Nasgor");
    deleteFirst(List);
    deleteBefore(List, nodeE);

    cout << endl << "--- Isi List Setelah Delete ---" << endl;
    printList(List);

    return 0;
}
```
Program ini adalah implementasi komprehensif dari struktur data Double Linked List yang dirancang untuk mengelola data makanan secara dinamis. Setiap node (simpul) dalam daftar berfungsi sebagai wadah untuk informasi makanan, mencakup nama, jenis, harga, dan rating.

## Unguided 

### 1. ![Screenshot Unguided 1_1](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan6_Modul6/soal-unguided1.png)

#### [doublylist.h]
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
using namespace std;

struct kendaraan {
    string nomorPolisi;
    string warna;
    int tahunBuat;
};

using infotype = kendaraan;

typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(const string &nomorPolisi, const string &warna, int tahunBuat);
void dealokasi(address &P);
void printInfo(const List &L);
void insertLast(List &L, address P);
void insertFirst(List &L, address P);
address findByNomorPolisi(const List &L, const string &nomorPolisi);

#endif
```

#### [doublylist.cpp]
```C++
#include "doublylist.h"
#include <iostream>
using namespace std;

void CreateList(List &L) {
    L.First = nullptr;
    L.Last = nullptr;
}

address alokasi(const string &nomorPolisi, const string &warna, int tahunBuat) {
    address P = new ElmList;
    if (P != nullptr) {
        P->info.nomorPolisi = nomorPolisi;
        P->info.warna = warna;
        P->info.tahunBuat = tahunBuat;
        P->next = nullptr;
        P->prev = nullptr;
    }
    return P;
}

void dealokasi(address &P) {
    if (P != nullptr) {
        delete P;
        P = nullptr;
    }
}

void insertFirst(List &L, address P) {
    if (P == nullptr) return;
    if (L.First == nullptr) {
        L.First = L.Last = P;
    } else {
        P->next = L.First;
        L.First->prev = P;
        L.First = P;
    }
}

void insertLast(List &L, address P) {
    if (P == nullptr) return;
    if (L.First == nullptr) {
        L.First = L.Last = P;
    } else {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

address findByNomorPolisi(const List &L, const string &nomorPolisi) {
    address P = L.First;
    while (P != nullptr) {
        if (P->info.nomorPolisi == nomorPolisi) return P;
        P = P->next;
    }
    return nullptr;
}

void printInfo(const List &L) {
    cout << "\nDATA LIST 1" << endl << endl;
    address P = L.Last;
    while (P != nullptr) {
        cout << "nomor polisi : " << P->info.nomorPolisi << endl;
        cout << "warna        : " << P->info.warna << endl;
        cout << "tahun        : " << P->info.tahunBuat << endl << endl;
        P = P->prev;
    }
}
```

#### [main.cpp]
```C++
#include "doublylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    CreateList(L);

    for (int i = 0; i < 4; ++i) {
        string nomorPolisi, warna;
        int tahunBuat;
        cout << "masukkan nomor polisi: ";
        getline(cin, nomorPolisi);
        if (nomorPolisi.empty()) {
            --i;
            continue;
        }
        cout << "masukkan warna kendaraan: ";
        getline(cin, warna);
        cout << "masukkan tahun kendaraan: ";
        string line;
        getline(cin, line);
        try {
            tahunBuat = stoi(line);
        } catch (...) {
            tahunBuat = 0;
        }

        if (findByNomorPolisi(L, nomorPolisi) != nullptr) {
            cout << "nomor polisi sudah terdaftar" << endl << endl;
            continue; 
        }

        address node = alokasi(nomorPolisi, warna, tahunBuat);
        insertLast(L, node);
    }

    printInfo(L);

    address P = L.First;
    while (P != nullptr) {
        address next = P->next;
        dealokasi(P);
        P = next;
    }

    return 0;
}
```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan6_Modul6/output-unguided1.png)

Program ini adalah sebuah implementasi Doubly Linked List yang bertujuan untuk mengelola dan menampilkan data kendaraan secara dinamis. Setiap simpul (node) dalam daftar menyimpan rincian kendaraan, yaitu nomor polisi, warna, dan tahun pembuatan. Struktur dasar data dan deklarasi fungsi-fungsi manajemen utama, seperti pembuatan list, alokasi memori, penyisipan data di awal dan akhir, pencarian berdasarkan nomor polisi, dan penghapusan memori, didefinisikan dalam file doublylist.h. Logika operasional dan pengelolaan simpul dua arah (maju dan mundur) diimplementasikan secara rinci dalam file doublylist.cpp. Sementara itu, file program utama (main.cpp) bertanggung jawab untuk menerima masukan data kendaraan dari pengguna, melakukan validasi untuk memastikan tidak ada duplikasi nomor polisi, menambahkan data ke dalam list, dan kemudian menampilkan keseluruhan daftar kendaraan, yang secara efektif menunjukkan kegunaan dan fleksibilitas Double Linked List dalam manajemen data.

### 2. ![Screenshot Unguided 2_1](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan6_Modul6/soal-unguided2.png)

#### [doublylist.h]
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
using namespace std;

struct kendaraan {
	string nomorPolisi;
	string warna;
	int tahunBuat;
};

using infotype = kendaraan;

typedef struct ElmList *address;

struct ElmList {
	infotype info;
	address next;
	address prev;
};

struct List {
	address First;
	address Last;
};

void CreateList(List &L);
address alokasi(const string &nomorPolisi, const string &warna, int tahunBuat);
void dealokasi(address &P);
void printInfo(const List &L);
void insertLast(List &L, address P);
void insertFirst(List &L, address P);
address findByNomorPolisi(const List &L, const string &nomorPolisi);

#endif
```

#### [doublylist.cpp]
```C++
#include "doublylist.h"
#include <iostream>
using namespace std;

void CreateList(List &L) {
    L.First = nullptr;
    L.Last = nullptr;
}

address alokasi(const string &nomorPolisi, const string &warna, int tahunBuat) {
    address P = new ElmList;
    if (P != nullptr) {
        P->info.nomorPolisi = nomorPolisi;
        P->info.warna = warna;
        P->info.tahunBuat = tahunBuat;
        P->next = nullptr;
        P->prev = nullptr;
    }
    return P;
}

void dealokasi(address &P) {
    if (P != nullptr) {
        delete P;
        P = nullptr;
    }
}

void insertFirst(List &L, address P) {
    if (P == nullptr) return;
    if (L.First == nullptr) {
        L.First = L.Last = P;
    } else {
        P->next = L.First;
        L.First->prev = P;
        L.First = P;
    }
}

void insertLast(List &L, address P) {
    if (P == nullptr) return;
    if (L.First == nullptr) {
        L.First = L.Last = P;
    } else {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

address findByNomorPolisi(const List &L, const string &nomorPolisi) {
    address P = L.First;
    while (P != nullptr) {
        if (P->info.nomorPolisi == nomorPolisi) return P;
        P = P->next;
    }
    return nullptr;
}

void printInfo(const List &L) {
    cout << "\nDATA LIST 1" << endl << endl;
    address P = L.Last;
    while (P != nullptr) {
        cout << "nomor polisi : " << P->info.nomorPolisi << endl;
        cout << "warna        : " << P->info.warna << endl;
        cout << "tahun        : " << P->info.tahunBuat << endl << endl;
        P = P->prev;
    }
}
```

#### [main.cpp]
```C++
#include "doublylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    CreateList(L);

    for (int i = 0; i < 4; ++i) {
        string nomorPolisi, warna;
        int tahunBuat;
        cout << "masukkan nomor polisi: ";
        getline(cin, nomorPolisi);
        if (nomorPolisi.empty()) {
            --i;
            continue;
        }
        cout << "masukkan warna kendaraan: ";
        getline(cin, warna);
        cout << "masukkan tahun kendaraan: ";
        string line;
        getline(cin, line);
        try {
            tahunBuat = stoi(line);
        } catch (...) {
            tahunBuat = 0;
        }

        if (findByNomorPolisi(L, nomorPolisi) != nullptr) {
            cout << "nomor polisi sudah terdaftar" << endl << endl;
            continue; 
        }

        address node = alokasi(nomorPolisi, warna, tahunBuat);
        insertLast(L, node);
    }

    printInfo(L);

    cout << "Masukkan Nomor Polisi yang dicari  : ";
    string cari;
    getline(cin, cari);

    address found = findByNomorPolisi(L, cari);
    if (found != nullptr) {
        cout << endl;
        cout << "Nomor Polisi : " << found->info.nomorPolisi << endl;
        cout << "Warna        : " << found->info.warna << endl;
        cout << "Tahun        : " << found->info.tahunBuat << endl;
    } else {
        cout << "Data dengan nomor polisi '" << cari << "' tidak ditemukan." << endl;
    }

    address P = L.First;
    while (P != nullptr) {
        address next = P->next;
        dealokasi(P);
        P = next;
    }

    return 0;
}
```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan6_Modul6/output-unguided2.png)

PDoubly Linked List adalah struktur data linier di mana setiap simpulnya memiliki penunjuk ke simpul berikutnya dan sebelumnya, memungkinkan penelusuran bidireksional dan manipulasi elemen yang efisien di berbagai posisi.

### 3. ![Screenshot Unguided 3_1](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan6_Modul6/soal-unguided3.png)

#### [doublylist.h]
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
using namespace std;

struct kendaraan {
	string nomorPolisi;
	string warna;
	int tahunBuat;
};

using infotype = kendaraan;

typedef struct ElmList *address;

struct ElmList {
	infotype info;
	address next;
	address prev;
};

struct List {
	address First;
	address Last;
};

void CreateList(List &L);
address alokasi(const string &nomorPolisi, const string &warna, int tahunBuat);
void dealokasi(address &P);
void printInfo(const List &L);
void insertLast(List &L, address P);
void insertFirst(List &L, address P);
address findByNomorPolisi(const List &L, const string &nomorPolisi);

#endif
```
#### [doublylist.cpp]
```C++
#include "doublylist.h"
#include <iostream>
using namespace std;

void CreateList(List &L) {
    L.First = nullptr;
    L.Last = nullptr;
}

address alokasi(const string &nomorPolisi, const string &warna, int tahunBuat) {
    address P = new ElmList;
    if (P != nullptr) {
        P->info.nomorPolisi = nomorPolisi;
        P->info.warna = warna;
        P->info.tahunBuat = tahunBuat;
        P->next = nullptr;
        P->prev = nullptr;
    }
    return P;
}

void dealokasi(address &P) {
    if (P != nullptr) {
        delete P;
        P = nullptr;
    }
}

void insertFirst(List &L, address P) {
    if (P == nullptr) return;
    if (L.First == nullptr) {
        L.First = L.Last = P;
    } else {
        P->next = L.First;
        L.First->prev = P;
        L.First = P;
    }
}

void insertLast(List &L, address P) {
    if (P == nullptr) return;
    if (L.First == nullptr) {
        L.First = L.Last = P;
    } else {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

address findByNomorPolisi(const List &L, const string &nomorPolisi) {
    address P = L.First;
    while (P != nullptr) {
        if (P->info.nomorPolisi == nomorPolisi) return P;
        P = P->next;
    }
    return nullptr;
}

void printInfo(const List &L) {
    cout << "\nDATA LIST 1" << endl << endl;
    address P = L.Last;
    while (P != nullptr) {
        cout << "Nomor Polisi : " << P->info.nomorPolisi << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.tahunBuat << endl << endl;
        P = P->prev;
    }
}
```
#### [main.cpp]
```C++
#include "doublylist.h"
#include <iostream>
using namespace std;

void deleteFirst(List &L) {
    if (L.First == nullptr) return;
    address P = L.First;
    if (L.First == L.Last) {
        L.First = L.Last = nullptr;
    } else {
        L.First = P->next;
        L.First->prev = nullptr;
    }
    dealokasi(P);
}

void deleteLast(List &L) {
    if (L.Last == nullptr) return;
    address P = L.Last;
    if (L.First == L.Last) {
        L.First = L.Last = nullptr;
    } else {
        L.Last = P->prev;
        L.Last->next = nullptr;
    }
    dealokasi(P);
}

void deleteAfter(List &L, address Prec) {
    if (Prec == nullptr || Prec->next == nullptr) return;
    address P = Prec->next;
    Prec->next = P->next;
    if (P->next != nullptr) P->next->prev = Prec;
    if (P == L.Last) L.Last = Prec;
    dealokasi(P);
}

int main() {
    List L;
    CreateList(L);

    insertLast(L, alokasi("KB 5527 BRK", "Hitam", 2025));
    insertLast(L, alokasi("KB 4190 IN", "Hitam", 2025));

    cout << "Masukkan Nomor Polisi yang akan dihapus  : ";
    string target;
    getline(cin, target);

    address node = findByNomorPolisi(L, target);
    if (node == nullptr) {
        cout << "Data dengan nomor polisi " << target << " tidak ditemukan." << endl;
    } else {
        if (node == L.First) {
            deleteFirst(L);
        } else if (node == L.Last) {
            deleteLast(L);
        } else {
            deleteAfter(L, node->prev);
        }
        cout << "Data dengan nomor polisi " << target << " berhasil dihapus." << endl;
    }

    cout << "\nDATA LIST 1" << endl << endl;
    address P = L.Last;
    while (P != nullptr) {
        cout << "Nomor Polisi : " << P->info.nomorPolisi << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.tahunBuat << endl;
        if (P->prev != nullptr) cout << "\n";
        P = P->prev;
    }

    P = L.First;
    while (P != nullptr) {
        address next = P->next;
        dealokasi(P);
        P = next;
    }

    return 0;
}
```

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan6_Modul6/output-unguided3.png)

Program ini mengimplementasikan struktur data Double Linked List untuk mengelola data kendaraan secara dinamis, khususnya berfokus pada penyimpanan dan penghapusan data. Setiap simpul (node) dalam daftar menyimpan rincian kendaraan (nomor polisi, warna, dan tahun pembuatan) dan terhubung dua arah melalui penunjuk (next dan prev).

## Kesimpulan
Doubly Linked List (DLL) adalah struktur data linier yang unggul dalam fleksibilitas dibandingkan Singly Linked List karena setiap simpul (node) tidak hanya menunjuk ke simpul berikutnya (Next), tetapi juga ke simpul sebelumnya (Prev). Arsitektur bidireksional ini adalah keunggulan utamanya, memungkinkan penelusuran dua arah (maju dan mundur) serta membuat operasi seperti penghapusan dan penyisipan simpul di tengah list menjadi sangat efisien, seringkali dalam kompleksitas waktu O(1), asalkan simpul target sudah diketahui. Namun, fleksibilitas ini hadir dengan konsekuensi berupa memori overhead yang lebih besar, sebab setiap simpul memerlukan ruang tambahan untuk menyimpan penunjuk Prev. Kerumitan implementasi juga meningkat karena setiap manipulasi memerlukan pembaruan dua pasang penunjuk secara cermat.
Relevansi DLL terlihat jelas dalam aplikasi yang menuntut navigasi bolak-balik dan manipulasi data dinamis, seperti implementasi fitur Undo/Redo, riwayat browser, dan sistem Cache LRU yang memerlukan penghapusan cepat di kedua ujung list. Dalam konteks yang lebih maju (kontemporer), DLL dikembangkan menjadi varian seperti Circular Doubly Linked List dan dioptimalkan dengan teknik Lock-Free untuk lingkungan multithreaded dan komputasi paralel berkinerja tinggi, sebagaimana disinggung dalam referensi akademik [2] dan [3]. Oleh karena itu, DLL merupakan pilihan ideal ketika kebutuhan akan manipulasi elemen yang cepat dan kemampuan navigasi dua arah lebih diprioritaskan daripada penghematan memori.

## Referensi
[1] Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein. "Introduction to Algorithms." 3rd ed., MIT Press, 2009.

<br>[2] L. L. Morris, and W. D. Stoller. "Algorithms for Shared Memory Multiprocessors: Doubly Linked Lists." Proceedings of the 1st Annual Symposium on Parallel Algorithms and Architectures (SPAA '89), ACM, 1989, pp. 248–257.

<br>[3] V. A. Egorov, and O. S. Shchukin. "Efficient Method for Processing Data in Doubly Linked Lists." Journal of Physics: Conference Series, vol. 1889, no. 1, May 2021, p. 012056.