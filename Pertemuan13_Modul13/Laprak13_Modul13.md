# <h1 align="center">Laporan Praktikum Modul 13 - MULTI LINKED LIST </h1>
<p align="center">Chadafya Putra Zulfikar - 103112430173</p>

## Dasar Teori

### 1. Definisi Multi Linked List (MLL)
- Multi-Linked List (Daftar Berantai Multitautan) adalah jenis struktur data daftar berantai yang memiliki dua atau lebih urutan kunci (key sequence) logis untuk satu set elemen data yang sama.
- Secara umum, Multi-Linked List adalah daftar berantai yang lebih umum di mana setiap node (simpul) dapat memiliki N jumlah pointer (penunjuk/referensi) ke node lain.
- Tujuan Utama: Digunakan untuk mengorganisir satu set elemen data dalam berbagai urutan secara bersamaan. Contoh klasiknya adalah menyimpan daftar mahasiswa dan mengaturnya secara alfabetis berdasarkan nama sekaligus diurutkan berdasarkan nilai/IPK.

### 2. Struktur dan Komponen Multi Linked List
Multi Linked List terdiri dari beberapa komponen utama:

#### 2.1 Node Parent
- Definisi: Node yang bertindak sebagai simpul utama yang dapat memiliki satu atau lebih anak
- Elemen Data: Menyimpan informasi identitas dan karakteristik kategoris
- Pointer: Memiliki pointer `next` dan `prev` untuk navigasi antar parent, serta pointer ke list anak
- Contoh: Kategori makanan, golongan hewan, departemen perusahaan

#### 2.2 Node Child
- Definisi: Node yang berada di bawah parent dan membentuk linked list terpisah
- Elemen Data: Menyimpan informasi spesifik yang termasuk dalam kategori parent
- Pointer: Memiliki pointer `next` dan `prev` untuk navigasi antar child dalam satu parent
- Contoh: Menu makanan dalam kategori, spesies dalam golongan hewan, karyawan dalam departemen

#### 2.3 List Induk (Parent List)
- Linked list yang menampung semua node parent
- Dapat berupa singly linked list, doubly linked list, atau circular linked list
- Memungkinkan navigasi antar kategori utama

#### 2.4 List Anak (Child List)
- Linked list yang melekat pada setiap node parent
- Menyimpan semua data yang termasuk dalam kategori tersebut
- Struktur independen untuk setiap parent memungkinkan fleksibilitas

### 3. Karakteristik dan Keuntungan Multi Linked List
Keuntungan:
- Organisasi Hierarki: Secara natural merepresentasikan hubungan parent-child dalam data
- Efisiensi Memori: Hanya mengalokasikan memori untuk data yang ada tanpa overhead array
- Fleksibilitas: Memungkinkan penambahan dan penghapusan node tanpa reorganisasi keseluruhan
- Operasi Cepat: Pencarian, penyisipan, dan penghapusan dapat dilakukan dalam O(n) waktu linear
- Skalabilitas: Dapat menangani data dengan jumlah child yang berbeda-beda untuk setiap parent

Keterbatasan:
- Akses Tidak Acak: Tidak memungkinkan akses langsung ke elemen, harus traversal dari awal
- Overhead Pointer: Memerlukan memori tambahan untuk pointer di setiap node
- Kompleksitas Implementasi: Lebih kompleks dibanding array dalam implementasi operasi-operasi umum
- Cache Unfriendly: Akses node tidak berdekatan secara fisik dapat menyebabkan cache miss

### 4. Operasi Dasar pada Multi Linked List
Operasi dasar pada Multi Linked List meliputi [2][3]:

#### 4.1 Operasi pada Node Parent
- Insert Parent: Menambahkan kategori baru ke dalam list induk (insertFirst, insertLast, insertAfter)
- Delete Parent: Menghapus kategori dari list induk (deleteFirst, deleteLast, deleteAfter)
- Find Parent: Mencari parent berdasarkan identitas atau kriteria tertentu
- Update Parent: Mengubah data parent yang sudah ada

#### 4.2 Operasi pada Node Child
- Insert Child: Menambahkan item baru ke dalam list anak dari parent tertentu
- Delete Child: Menghapus item dari list anak
- Find Child: Mencari child berdasarkan identitas di seluruh struktur MLL
- Update Child: Mengubah data child yang sudah ada

#### 4.3 Operasi Traversal
- Traversal Horizontal: Mengunjungi semua parent dalam list induk
- Traversal Vertikal: Mengunjungi semua child dalam list anak dari satu parent
- Traversal Keseluruhan: Mengunjungi semua node baik parent maupun child dalam urutan tertentu.

### 5. Implementasi Multi Linked List dalam C++
Penggunaan utama dari Multi-Linked List adalah untuk mewakili hubungan kompleks di mana data perlu dilihat dan diakses dalam berbagai cara yang terstruktur.
1. Representasi Sparse Matrix (Matriks Jarang):
- Matriks yang sebagian besar elemennya bernilai nol.
- Multi-Linked List dapat digunakan untuk hanya menyimpan elemen non-nol. Setiap node (elemen non-nol) memiliki pointer yang menghubungkannya ke elemen non-nol berikutnya di baris yang sama dan di kolom yang sama, menghemat ruang memori yang signifikan.
2. Mengorganisir Data dalam Berbagai Urutan:
- Seperti contoh mahasiswa di atas, di mana data dasar yang sama (mahasiswa) harus diurutkan secara bersamaan (misalnya, berdasarkan abjad dan berdasarkan nilai).
3. Representasi List of Lists (Daftar dari Daftar) atau Struktur Hierarki:
- Digunakan untuk mewakili struktur data 2-dimensi, di mana setiap node utama dapat menunjuk ke daftar node lain (disebut sublist).

## Guided 

### 1. Implementasi Multi Linked List - Sistem Menu Restoran

#### [mll.h]
```C++
#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>

using namespace std;

struct DataMakanan {
    string idMakanan;
    string namaMakanan;
    float harga;
};

struct KategoriMakanan {
    string idKategori;
    string namaKategori;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    DataMakanan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listAnak {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    KategoriMakanan isidata;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;
};

struct listInduk {
    NodeParent first;
    NodeParent last;
};

//isEmpty & create list
bool isEmptyInduk(listInduk LInduk);
bool isEmptyAnak(listAnak LAnak);
void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &LAnak);

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori);
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga);
void dealokasiNodeChild(NodeChild &nodeAnak);
void dealokasiNodeParent(NodeParent &nodeInduk);

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent);
void deleteFirstParent(listInduk &LInduk);
void deleteLastParent(listInduk &LInduk);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);
void findParentByID(listInduk &LInduk, string IDCari);
void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori);

//operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild);
void deleteFirstChild(listAnak &LAnak);
void deleteLastChild(listAnak &LAnak);
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev);
void findChildByID(listInduk &LInduk, string IDCari);
void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga);

//operasi print
void printStrukturMLL(listInduk &LInduk);
void printListInduk(listInduk &LInduk);
void printListAnak(listInduk &LInduk, NodeParent nodeInduk);

//operasi hapus list
void hapusListInduk(listInduk &LInduk);
void hapusListAnak(listAnak &LAnak);

#endif
```

#### [mll.cpp]
```C++
#include "mll.h"
#include <iostream>
#include <string>

using namespace std;

//isEmpty & create list
bool isEmptyInduk(listInduk LInduk){
    if(LInduk.first == NULL){
        return true;
    } else {
        return false;
    }
}

bool isEmptyAnak(listAnak LAnak){
    if(LAnak.first == NULL){
        return true;
    } else {
        return false;
    }
}

void createListInduk(listInduk &LInduk) {
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak) {
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori) {
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->isidata.idKategori = idKategori;
    nodeBaruParent->isidata.namaKategori = namaKategori;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga) {
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->isidata.idMakanan = idMakanan;
    nodeBaruChild->isidata.namaMakanan = namaMakanan;
    nodeBaruChild->isidata.harga = harga;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak) {
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

void dealokasiNodeParent(NodeParent &nodeInduk) {
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(isEmptyInduk(LInduk) == true) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->next = LInduk.first;
        LInduk.first->prev = nodeBaruParent;
        LInduk.first = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan pertama di list Induk!" << endl;
}

void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(isEmptyInduk(LInduk) == true) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent) {
    if(nodePrevParent == NULL) {
        cout << "Node Prev Parent tidak valid!" << endl;
    } else {
        if(nodePrevParent == LInduk.last){
            insertLastParent(LInduk, nodeBaruParent);
            return;
        } else {
            nodeBaruParent->next = nodePrevParent->next;
            nodeBaruParent->prev = nodePrevParent;
            (nodePrevParent->next)->prev = nodeBaruParent;
            nodePrevParent->next = nodeBaruParent;
            cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam list induk setelah node parent "<< nodePrevParent->isidata.namaKategori << endl;
        }
    }
}

void deleteFirstParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LInduk.first;
        if (LInduk.first == LInduk.last) {
            LInduk.first = NULL;
            LInduk.last = NULL;
        } else {
            LInduk.first = LInduk.first->next;
            LInduk.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        if(nodeHapus->L_Anak.first != NULL){
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node pertama list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteLastParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LInduk.last;
        if (LInduk.first == LInduk.last) {
            LInduk.first = NULL;
            LInduk.last = NULL;
        } else {
            LInduk.last = LInduk.last->prev;
            nodeHapus->prev = NULL;
            LInduk.last->next = NULL;
        }
        if(nodeHapus->L_Anak.first != NULL){
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node terakhir list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->isidata.namaKategori << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findParentByID(listInduk &LInduk, string IDCari){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantu = LInduk.first;
        int index = 1;
        int ketemu = false;
        while(nodeBantu != NULL){
            if(nodeBantu->isidata.idKategori == IDCari){
                cout << "Data ID parent ditemukan pada list induk posisi ke-" << index << "!" << endl;
                cout << "ID : " << nodeBantu->isidata.idKategori << endl;
                cout << "Posisi dalam list induk : posisi ke-" << index << endl;
                cout << "Nama Kategori : " << nodeBantu->isidata.namaKategori << endl;
                ketemu = true;
                break;
            } else {
                nodeBantu = nodeBantu->next;
                index++;
            }
        }
        if(!ketemu){
            cout << "Data ID parent tidak ditemukan didalam list induk!" << endl;
        }
    }
}

void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori) {
    if (isEmptyInduk(LInduk) == true) {
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeBantu = LInduk.first;
        bool ketemu = false;
        while (nodeBantu != NULL) {
            if (nodeBantu->isidata.idKategori == IDCari) {
                nodeBantu->isidata.namaKategori = newNamaKategori;
                cout << "Update Parent Berhasil!" << endl;
                cout << "Node parent dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                cout << "Nama Kategori baru  : " << newNamaKategori << endl;
                ketemu = true;
                break; 
            } else {
                nodeBantu = nodeBantu->next;
            }
        }
        if (!ketemu) {
            cout << "Parent dengan ID " << IDCari << " tidak ditemukan" << endl;
        }
    }
}

//operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->next = LAnak.first;
        LAnak.first->prev = nodeBaruChild;
        LAnak.first = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan pertama di list Anak!" << endl;
}

void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild) {
    if(nodePrevChild == NULL) {
        cout << "Node Prev Parent tidak valid!" << endl;
    } else {
        if(nodePrevChild == LAnak.last){
            insertLastChild(LAnak, nodeBaruChild);
            return;
        } else {
            nodeBaruChild->next = nodePrevChild->next;
            nodeBaruChild->prev = nodePrevChild;
            (nodePrevChild->next)->prev = nodeBaruChild;
            nodePrevChild->next = nodeBaruChild;
            cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam list anak setelah node child "<< nodePrevChild->isidata.namaMakanan << endl;
        }
    }
}

void deleteFirstChild(listAnak &LAnak){
    if(isEmptyAnak(LAnak) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.first;
        if (LAnak.first == LAnak.last) {
            LAnak.first = NULL;
            LAnak.last = NULL;
        } else {
            LAnak.first = LAnak.first->next;
            LAnak.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node pertama list anak berhasil dihapus!" << endl;
    }
}

void deleteLastChild(listAnak &LAnak){
    if(isEmptyAnak(LAnak) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.last;
        if (LAnak.first == LAnak.last) {
            LAnak.first = NULL;
            LAnak.last = NULL;
        } else {
            LAnak.last = LAnak.last->prev;
            nodeHapus->prev = NULL;
            LAnak.last->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node terakhir list anak berhasil dihapus!" << endl;
    }
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(isEmptyAnak(LAnak) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->isidata.namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findChildByID(listInduk &LInduk, string IDCari){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->isidata.idMakanan == IDCari){
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->isidata.namaKategori << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "ID Child : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga) {
    if (isEmptyInduk(LInduk) == true) {
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        bool ketemu = false;
        while (nodeBantuParent != NULL) {
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            while (nodeBantuChild != NULL) {
                if (nodeBantuChild->isidata.idMakanan == IDCari) {
                    nodeBantuChild->isidata.namaMakanan = newNamaMakanan;
                    nodeBantuChild->isidata.harga = newHarga;
                    cout << "Update Child Berhasil!" << endl;
                    cout << "Child dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                    cout << "Nama Makanan baru : " << newNamaMakanan << endl;
                    cout << "Harga baru : " << newHarga << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                }
            }
            if (ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
            }
        }
        if (!ketemu) {
            cout << "Child dengan ID " << IDCari << " tidak ditemukan di parent manapun." << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;

            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "    ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "    Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "    Harga : " << nodeBantuChild->isidata.harga << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}

void printListInduk(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk Kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int index = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << index << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            index++;
        }
    }
}

void printListAnak(listInduk &LInduk, NodeParent nodeInduk) {
    if(isEmptyInduk(LInduk) == true || nodeInduk == NULL){
        cout << "List induk kosong atau node induk tidak valid!" << endl;
    } else {
        NodeChild nodeBantuChild = nodeInduk->L_Anak.first;
        if(nodeBantuChild == NULL) {
            cout << "node parent " << nodeInduk->isidata.namaKategori << " tidak memiliki list anak!" << endl;
        } else {
            cout << "=== List Anak Node Parent " << nodeInduk->isidata.namaKategori << " ===" << endl;
            int index = 1;
            while(nodeBantuChild != NULL) {
                cout << "Child " << index << " :" << endl;
                cout << "ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                cout << "---------------------------" << endl;
                nodeBantuChild = nodeBantuChild->next;
                index++;
            }
        }
    }
}

//operasi hapus list
void hapusListInduk(listInduk &LInduk) {
    NodeParent nodeBantu = LInduk.first;
    while(nodeBantu != NULL) {
        NodeParent nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        hapusListAnak(nodeHapus->L_Anak);
        dealokasiNodeParent(nodeHapus);
    }
    LInduk.first = LInduk.last = NULL;
}

void hapusListAnak(listAnak &LAnak) {
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}
```

#### [main.cpp]
```C++
#include "mll.h"
#include <iostream>

using namespace std;

int main() {
    // 1. Inisialisasi List
    listInduk L;
    createListInduk(L);
    cout << "=== MENU RESTORAN DIBUAT ===" << endl << endl;

    // 2. Membuat Data Parent (Kategori Makanan)
    NodeParent Kat1 = alokasiNodeParent("K01", "Makanan Berat");
    insertFirstParent(L, Kat1);

    NodeParent Kat2 = alokasiNodeParent("K02", "Minuman");
    insertAfterParent(L, Kat2, Kat1);

    NodeParent Kat3 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(L, Kat3);
    
    cout << endl;

    // 3. Memasukkan Data Child (Menu Makanan) ke Kategori Tertentu
    
    // --> Isi Kategori Makanan Berat (K01)
    NodeChild Mkn1 = alokasiNodeChild("M01", "Nasi Goreng Spesial", 25000);
    insertFirstChild(Kat1->L_Anak, Mkn1);

    NodeChild Mkn2 = alokasiNodeChild("M02", "Ayam Bakar Madu", 30000);
    insertLastChild(Kat1->L_Anak, Mkn2);

    // --> Isi Kategori Minuman (K02)
    NodeChild Min1 = alokasiNodeChild("D01", "Es Teh Manis", 5000);
    insertLastChild(Kat2->L_Anak, Min1);
    
    NodeChild Min2 = alokasiNodeChild("D02", "Jus Alpukat", 15000);
    insertFirstChild(Kat2->L_Anak, Min2);

    // --> Isi Kategori Dessert (K03)
    NodeChild Des1 = alokasiNodeChild("S01", "Puding Coklat", 10000);
    insertLastChild(Kat3->L_Anak, Des1);
    cout << endl;

    cout << "=== TAMPILAN AWAL MENU ===" << endl;
    printStrukturMLL(L);
    cout << endl;

    // 4. Test Pencarian (Find)
    cout << "=== TEST PENCARIAN ===" << endl;
    findParentByID(L, "K02"); // Cari Kategori Minuman
    cout << "---------------------------" << endl;
    findChildByID(L, "M01");  // Cari Nasi Goreng
    cout << "---------------------------" << endl;
    findChildByID(L, "X99");  // Cari data ngawur (harus not found)
    cout << "---------------------------" << endl;
    cout << endl;

    // 5. Test Update Data
    cout << "=== TEST UPDATE ===" << endl;
    // Update Nama Kategori (Parent)
    updateDataParentByID(L, "K03", "Makanan Penutup");
    cout << "---------------------------" << endl;
    
    // Update Data Makanan (Child)
    updateDataChildByID(L, "M01", "Nasgor Gila", 28000);
    cout << "---------------------------" << endl;
    
    cout << "\n=== SETELAH UPDATE ===" << endl;
    printListInduk(L); // Cek nama kategori saja
    cout << endl;
    printListAnak(L, Kat1); // Cek list anak di kategori 1
    cout << endl;

    // 6. Test Penghapusan (Delete)
    cout << "=== TEST DELETE ===" << endl;
    
    // Hapus Child: Hapus Jus Alpukat (D02) dari Minuman
    cout << "> Menghapus Child D02..." << endl;
    deleteFirstChild(Kat2->L_Anak); 
    
    // Hapus Parent: Hapus Kategori Dessert/Makanan Penutup (K03)
    cout << "> Menghapus Parent Terakhir (K03)..." << endl;
    deleteLastParent(L); 

    cout << "\n=== TAMPILAN AKHIR MENU ===" << endl;
    printStrukturMLL(L);

    return 0;
}
```

Program ini adalah implementasi doubly-linked list untuk membangun sistem menu restoran dengan hierarki parent-child (kategori-menu), yang mendukung operasi lengkap seperti penyisipan, penghapusan (dengan pembersihan turunan rekursif), pencarian, pembaruan, dan penelusuran struktur secara efisien.


## Unguided

### 1. Sistem Klasifikasi Hewan dengan Multi Linked List (Unguided 1)

#### [mll.h]
```C++
#ifndef MLL_H
#define MLL_H

#include <string>

struct Child {
	std::string id;
	std::string name;
	std::string habitat;
	int ekor;
	double bobot;
	Child* next;
	Child(const std::string &i, const std::string &n, const std::string &h, int e, double b) : id(i), name(n), habitat(h), ekor(e), bobot(b), next(nullptr) {}
};

struct Parent {
	std::string id;
	std::string name;
	Parent* next;
	Child* child;
	Parent(const std::string &i, const std::string &n) : id(i), name(n), next(nullptr), child(nullptr) {}
};

class MultiLL {
public:
	MultiLL();
	~MultiLL();
	void addParent(const std::string &id, const std::string &name);
	void addChildToParent(const std::string &parentId, const std::string &cid, const std::string &cname, const std::string &habitat, int ekor, double bobot);
	void printAll() const;
	bool findChild(const std::string &childId, std::string &outParentName, int &parentPos, int &childPos, Child &outChild) const;

private:
	Parent* head;
	void clear();
};

#endif
```

#### [mll.cpp]
```C++
#include "mll.h"
#include <iostream>

MultiLL::MultiLL() : head(nullptr) {}

MultiLL::~MultiLL() { clear(); }

void MultiLL::addParent(const std::string &id, const std::string &name) {
	Parent* p = new Parent(id, name);
	if (!head) head = p;
	else {
		Parent* cur = head;
		while (cur->next) cur = cur->next;
		cur->next = p;
	}
}

void MultiLL::addChildToParent(const std::string &parentId, const std::string &cid, const std::string &cname, const std::string &habitat, int ekor, double bobot) {
	Parent* cur = head;
	while (cur) {
		if (cur->id == parentId) {
			Child* c = new Child(cid, cname, habitat, ekor, bobot);
			if (!cur->child) cur->child = c;
			else {
				Child* cc = cur->child;
				while (cc->next) cc = cc->next;
				cc->next = c;
			}
			return;
		}
		cur = cur->next;
	}
}

void MultiLL::printAll() const {
	const Parent* p = head;
	int pidx = 1;
	while (p) {
		std::cout << "---- Parent " << pidx << " ----" << std::endl;
		std::cout << "ID Golongan : " << p->id << std::endl;
		std::cout << "Nama Golongan : " << p->name << std::endl;
		if (!p->child) {
			std::cout << "(tidak ada child)" << std::endl;
		} else {
			const Child* c = p->child;
			int cidx = 1;
			while (c) {
				std::cout << " - Child " << cidx << " :" << std::endl;
				std::cout << "ID Hewan : " << c->id << std::endl;
				std::cout << "Nama Hewan : " << c->name << std::endl;
				std::cout << "Habitat : " << c->habitat << std::endl;
				std::cout << "Ekor : " << c->ekor << std::endl;
				std::cout << "Bobot : " << c->bobot << std::endl;
				c = c->next;
				cidx++;
			}
		}
		std::cout << "-------------------------------" << std::endl;
		p = p->next;
		pidx++;
	}
}

bool MultiLL::findChild(const std::string &childId, std::string &outParentName, int &parentPos, int &childPos, Child &outChild) const {
	const Parent* p = head;
	parentPos = 0;
	while (p) {
		parentPos++;
		const Child* c = p->child;
		int cidx = 0;
		while (c) {
			cidx++;
			if (c->id == childId) {
				outParentName = p->name;
				childPos = cidx;
				outChild = *c;
				return true;
			}
			c = c->next;
		}
		p = p->next;
	}
	parentPos = 0;
	childPos = 0;
	return false;
}

void MultiLL::clear() {
	Parent* p = head;
	while (p) {
		Child* c = p->child;
		while (c) {
			Child* nc = c->next;
			delete c;
			c = nc;
		}
		Parent* np = p->next;
		delete p;
		p = np;
	}
	head = nullptr;
}
```

#### [main.cpp]
```C++
#include <iostream>
#include "mll.h"

int main() {
	MultiLL m;
	m.addParent("G001", "Aves");
	m.addChildToParent("G001", "AV001", "Cendrawasih", "Hutan", 1, 0.3);
	m.addChildToParent("G001", "AV002", "Bebek", "Air", 1, 2);

	m.addParent("G002", "Mamalia");
	m.addChildToParent("G002", "M001", "Harimau", "Hutan", 1, 200);
	m.addChildToParent("G002", "M003", "Gorila", "Hutan", 0, 160);
	m.addChildToParent("G002", "M002", "Kucing", "Darat", 1, 4);

	m.addParent("G003", "Pisces");

	m.addParent("G004", "Amfibi");
	m.addChildToParent("G004", "AM001", "Kodok", "Sawah", 0, 0.2);

	m.addParent("G005", "Reptil");

	m.printAll();
	return 0;
}
```

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan13_Modul13/Output-Unguided1_1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan13_Modul13/Output-Unguided1_2.png)

Program ini mengimplementasikan sebuah Multi-Linked List berbasis kelas untuk membuat sistem klasifikasi hewan, di mana setiap golongan (parent) dapat menampung beberapa spesies (child), dengan fungsionalitas utama untuk menambah golongan (addParent), menambah spesies ke golongan (addChildToParent), dan menampilkan seluruh struktur hierarki (printAll), didukung oleh constructor dan destructor untuk manajemen memori yang efisien.

### 2. Pencarian Data dalam Multi Linked List

#### [mll.h]
```C++
#ifndef MLL_H
#define MLL_H

#include <string>

struct Child {
	std::string id;
	std::string name;
	std::string habitat;
	int ekor;
	double bobot;
	Child* next;
	Child(const std::string &i, const std::string &n, const std::string &h, int e, double b) : id(i), name(n), habitat(h), ekor(e), bobot(b), next(nullptr) {}
};

struct Parent {
	std::string id;
	std::string name;
	Parent* next;
	Child* child;
	Parent(const std::string &i, const std::string &n) : id(i), name(n), next(nullptr), child(nullptr) {}
};

class MultiLL {
public:
	MultiLL();
	~MultiLL();
	void addParent(const std::string &id, const std::string &name);
	void addChildToParent(const std::string &parentId, const std::string &cid, const std::string &cname, const std::string &habitat, int ekor, double bobot);
	bool findChild(const std::string &childId, std::string &outParentId, std::string &outParentName, int &parentPos, int &childPos, Child &outChild) const;
	void printAll() const;
private:
	Parent* head;
	void clear();
};

#endif
```

#### [mll.cpp] 
```C++
#include "mll.h"
#include <iostream>

MultiLL::MultiLL() : head(nullptr) {}

MultiLL::~MultiLL() { clear(); }

void MultiLL::addParent(const std::string &id, const std::string &name) {
	Parent* p = new Parent(id, name);
	if (!head) head = p;
	else {
		Parent* cur = head;
		while (cur->next) cur = cur->next;
		cur->next = p;
	}
}

void MultiLL::addChildToParent(const std::string &parentId, const std::string &cid, const std::string &cname, const std::string &habitat, int ekor, double bobot) {
	Parent* cur = head;
	while (cur) {
		if (cur->id == parentId) {
			Child* c = new Child(cid, cname, habitat, ekor, bobot);
			if (!cur->child) cur->child = c;
			else {
				Child* cc = cur->child;
				while (cc->next) cc = cc->next;
				cc->next = c;
			}
			return;
		}
		cur = cur->next;
	}
}

bool MultiLL::findChild(const std::string &childId, std::string &outParentId, std::string &outParentName, int &parentPos, int &childPos, Child &outChild) const {
	const Parent* p = head;
	parentPos = 0;
	while (p) {
		parentPos++;
		const Child* c = p->child;
		int cidx = 0;
		while (c) {
			cidx++;
			if (c->id == childId) {
				outParentId = p->id;
				outParentName = p->name;
				childPos = cidx;
				outChild = *c;
				return true;
			}
			c = c->next;
		}
		p = p->next;
	}
	parentPos = 0;
	childPos = 0;
	return false;
}

void MultiLL::printAll() const {
	const Parent* p = head;
	int pidx = 1;
	while (p) {
		std::cout << "---- Parent " << pidx << " ----" << std::endl;
		std::cout << "ID Golongan : " << p->id << std::endl;
		std::cout << "Nama Golongan : " << p->name << std::endl;
		if (!p->child) {
			std::cout << "(tidak ada child)" << std::endl;
		} else {
			const Child* c = p->child;
			int cidx = 1;
			while (c) {
				std::cout << " - Child " << cidx << " :" << std::endl;
				std::cout << "ID Hewan : " << c->id << std::endl;
				std::cout << "Nama Hewan : " << c->name << std::endl;
				std::cout << "Habitat : " << c->habitat << std::endl;
				std::cout << "Ekor : " << c->ekor << std::endl;
				std::cout << "Bobot : " << c->bobot << std::endl;
				c = c->next;
				cidx++;
			}
		}
		std::cout << "-------------------------------" << std::endl;
		p = p->next;
		pidx++;
	}
}

void MultiLL::clear() {
	Parent* p = head;
	while (p) {
		Child* c = p->child;
		while (c) {
			Child* nc = c->next;
			delete c;
			c = nc;
		}
		Parent* np = p->next;
		delete p;
		p = np;
	}
	head = nullptr;
}
```

#### [main.cpp]
```C++
#include <iostream>
#include "mll.h"

void buildSample(MultiLL &m) {
	m.addParent("G001", "Aves");
	m.addChildToParent("G001", "AV001", "Cendrawasih", "Hutan", 1, 0.3);
	m.addChildToParent("G001", "AV002", "Bebek", "Air", 1, 2);

	m.addParent("G002", "Mamalia");
	m.addChildToParent("G002", "M001", "Harimau", "Hutan", 1, 200);
	m.addChildToParent("G002", "M003", "Gorila", "Hutan", 0, 160);
	m.addChildToParent("G002", "M002", "Kucing", "Darat", 1, 4);

	m.addParent("G003", "Pisces");

	m.addParent("G004", "Amfibi");
	m.addChildToParent("G004", "AM001", "Kodok", "Sawah", 0, 0.2);

	m.addParent("G005", "Reptil");
}

int main() {
	MultiLL m;
	buildSample(m);

	std::string pid, pname;
	int ppos, cpos;
	Child found("", "", "", 0, 0.0);

	if (m.findChild("M003", pid, pname, ppos, cpos, found)) {
		std::cout << "Data ditemukan pada list anak dari node parent " << pname << " pada posisi ke-" << cpos << "!" << std::endl;
		std::cout << "---- Data Child ----" << std::endl;
		std::cout << "ID Child : " << found.id << std::endl;
		std::cout << "Posisi dalam list anak : posisi ke-" << cpos << std::endl;
		std::cout << "Nama Hewan : " << found.name << std::endl;
		std::cout << "Habitat : " << found.habitat << std::endl;
		std::cout << "Ekor : " << found.ekor << std::endl;
		std::cout << "Bobot : " << found.bobot << std::endl;
		std::cout << "-----------------------" << std::endl;
		std::cout << "--- Data Parent ---" << std::endl;
		std::cout << "ID Parent : " << pid << std::endl;
		std::cout << "Posisi dalam list induk : posisi ke-" << ppos << std::endl;
		std::cout << "Nama golongan : " << pname << std::endl;
		std::cout << "-----------------------" << std::endl;
	}

	if (m.findChild("AM001", pid, pname, ppos, cpos, found)) {
		std::cout << "Data ditemukan pada list anak dari node parent " << pname << " pada posisi ke-" << cpos << "!" << std::endl;
		std::cout << "--- Data Child ---" << std::endl;
		std::cout << "ID Child : " << found.id << std::endl;
		std::cout << "Posisi dalam list induk : posisi ke-" << cpos << std::endl;
		std::cout << "Nama Hewan : " << found.name << std::endl;
		std::cout << "Habitat : " << found.habitat << std::endl;
		std::cout << "Ekor : " << found.ekor << std::endl;
		std::cout << "Bobot : " << found.bobot << std::endl;
		std::cout << "-----------------------" << std::endl;
		std::cout << "--- Data Parent ---" << std::endl;
		std::cout << "ID Parent : " << pid << std::endl;
		std::cout << "Posisi dalam list induk : posisi ke-" << ppos << std::endl;
		std::cout << "Nama golongan : " << pname << std::endl;
	}

	return 0;
}
```

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan13_Modul13/Output-Unguided2.png)

Program ini menampilkan kemampuan pencarian canggih dalam Multi-Linked List hierarki, menggunakan metode findChild untuk menemukan data turunan (misalnya, "M003" Gorila dan "AM001" Kodok) berdasarkan ID, lalu mengembalikan dan menampilkan detail lengkap dari data turunan tersebut beserta informasi dan posisi dari golongan induknya (parent).

### 3. Tampilan Struktur Lengkap Multi Linked List 

#### [mll.h]
```C++
#ifndef MLL_H
#define MLL_H

#include <string>

struct Child {
	std::string id;
	std::string name;
	std::string habitat;
	int ekor;
	double bobot;
	Child* next;
	Child(const std::string &i, const std::string &n, const std::string &h, int e, double b) : id(i), name(n), habitat(h), ekor(e), bobot(b), next(nullptr) {}
};

struct Parent {
	std::string id;
	std::string name;
	Parent* next;
	Child* child;
	Parent(const std::string &i, const std::string &n) : id(i), name(n), next(nullptr), child(nullptr) {}
};

class MultiLL {
public:
	MultiLL();
	~MultiLL();
	void addParent(const std::string &id, const std::string &name);
	void addChildToParent(const std::string &parentId, const std::string &cid, const std::string &cname, const std::string &habitat, int ekor, double bobot);
	void printAll() const;
private:
	Parent* head;
	void clear();
};

#endif
```

#### [mll.cpp]
```C++
#include "mll.h"
#include <iostream>

MultiLL::MultiLL() : head(nullptr) {}

MultiLL::~MultiLL() { clear(); }

void MultiLL::addParent(const std::string &id, const std::string &name) {
	Parent* p = new Parent(id, name);
	if (!head) head = p;
	else {
		Parent* cur = head;
		while (cur->next) cur = cur->next;
		cur->next = p;
	}
}

void MultiLL::addChildToParent(const std::string &parentId, const std::string &cid, const std::string &cname, const std::string &habitat, int ekor, double bobot) {
	Parent* cur = head;
	while (cur) {
		if (cur->id == parentId) {
			Child* c = new Child(cid, cname, habitat, ekor, bobot);
			if (!cur->child) cur->child = c;
			else {
				Child* cc = cur->child;
				while (cc->next) cc = cc->next;
				cc->next = c;
			}
			return;
		}
		cur = cur->next;
	}
}

void MultiLL::printAll() const {
	const Parent* p = head;
	int pidx = 1;
	while (p) {
		std::cout << "=== Parent " << pidx << " ===" << std::endl;
		std::cout << "ID Golongan : " << p->id << std::endl;
		std::cout << "Nama Golongan : " << p->name << std::endl;
		if (!p->child) {
			std::cout << "(tidak ada child)" << std::endl;
		} else {
			const Child* c = p->child;
			int cidx = 1;
			while (c) {
				std::cout << " - Child " << cidx << " :" << std::endl;
				std::cout << "ID Hewan : " << c->id << std::endl;
				std::cout << "Nama Hewan : " << c->name << std::endl;
				std::cout << "Habitat : " << c->habitat << std::endl;
				std::cout << "Ekor : " << c->ekor << std::endl;
				std::cout << "Bobot : " << c->bobot << std::endl;
				c = c->next;
				cidx++;
			}
		}
		std::cout << "-------------------------------" << std::endl;
		p = p->next;
		pidx++;
	}
}

void MultiLL::clear() {
	Parent* p = head;
	while (p) {
		Child* c = p->child;
		while (c) {
			Child* nc = c->next;
			delete c;
			c = nc;
		}
		Parent* np = p->next;
		delete p;
		p = np;
	}
	head = nullptr;
}
```

#### [main.cpp]
```C++
#include <iostream>
#include "mll.h"

int main() {
	MultiLL m;
	m.addParent("G001", "Aves");
	m.addChildToParent("G001", "AV001", "Cendrawasih", "Hutan", 1, 0.3);
	m.addChildToParent("G001", "AV002", "Bebek", "Air", 1, 2);

	m.addParent("G002", "Mamalia");
	m.addChildToParent("G002", "M001", "Harimau", "Hutan", 1, 200);
	m.addChildToParent("G002", "M003", "Gorila", "Hutan", 0, 160);
	m.addChildToParent("G002", "M002", "Kucing", "Darat", 1, 4);

	m.addParent("G003", "Pisces");

	m.addParent("G004", "Amfibi");

	m.printAll();
	return 0;
}
```

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan13_Modul13/Output-Unguided3_1.png)

##### Output 1
![Screenshot Output Unguided 3_2](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan13_Modul13/Output-Unguided3_2.png)

Program ini menyajikan implementasi Multi-Linked List lengkap menggunakan kelas MultiLL yang berisi struktur Parent dan Child, di mana seluruh hierarki data ditampilkan dalam format terstruktur dengan header ===, mendemonstrasikan penanganan berbagai jumlah child (termasuk parent tanpa child seperti "Pisces"), serta menerapkan manajemen memori yang kuat melalui destructor rekursif untuk mencegah memory leak.

## Kesimpulan
- Berdasarkan referensi-referensi fundamental dalam ilmu komputer, terutama karya-karya dari Knuth, Cormen et al., dan Aho et al., Multi-Linked List (Daftar Berantai Multitautan) adalah struktur data tingkat lanjut yang esensial untuk mengatasi masalah organisasi data yang membutuhkan berbagai urutan logis secara simultan atas satu set elemen data yang sama. Struktur ini dicapai dengan mendefinisikan node yang memiliki N jumlah pointer, di mana setiap pointer merepresentasikan tautan ke node berikutnya dalam urutan pengurutan yang berbeda.  Keunggulan utamanya terletak pada efisiensi ruang dan waktu dalam menangani data yang perlu diakses atau diolah melalui berbagai kunci. Operasi seperti penyisipan dan penghapusan menjadi lebih kompleks karena harus memelihara konsistensi semua $N$ urutan pointer secara serentak, namun imbalannya adalah representasi data yang kuat, seperti dalam implementasi Matriks Jarang (Sparse Matrix) atau sistem hierarki parent-child.
- Secara keseluruhan, referensi-referensi tersebut menggarisbawahi bahwa Multi-Linked List adalah solusi elegan untuk skenario di mana data perlu dilihat secara multidimensi tanpa harus menduplikasi data itu sendiri. Dalam konteks pemrograman modern, meskipun sering diimplementasikan melalui kelas dan objek, prinsip dasarnya tetap sama: menghubungkan satu node data ke banyak node lain melalui berbagai jalur penelusuran. Pemahaman mendalam tentang manajemen pointer dan alokasi memori (seperti yang ditunjukkan dalam program-program implementasi yang Anda jelaskan) sangat penting untuk memastikan integritas struktural dan mencegah memory leak, yang merupakan perhatian utama dalam manipulasi struktur data dinamis yang kompleks ini.
## Referensi

[1] D. E. Knuth, "The Art of Computer Programming, Vol. 1: Fundamental Algorithms," 3rd ed. Reading, MA, USA: Addison-Wesley, 1997.

[2] T. H. Cormen, C. E. Leiserson, R. L. Rivest, and C. Stein, "Introduction to Algorithms," 3rd ed. Cambridge, MA, USA: The MIT Press, 2009.

[3] A. V. Aho, J. E. Hopcroft, and J. D. Ullman, "Data Structures and Algorithms," Reading, MA, USA: Addison-Wesley, 1983.