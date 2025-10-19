# <h1 align="center">Laporan Praktikum Modul 4 - SINGLY LINKED LIST (BAGIAN PERTAMA) </h1>
<p align="center">Chadafya Putra Zulfikar - 103112430173</p>

## Dasar Teori
Single Linked List adalah struktur data linear dinamis yang terdiri dari serangkaian elemen, yang disebut node (simpul), yang terhubung secara sekuensial. Tidak seperti array di mana elemen disimpan di lokasi memori yang berdekatan, node dalam Linked List dapat tersebar di memori. Keterhubungan dipertahankan melalui pointer.

Dalam C++, setiap node biasanya didefinisikan sebagai struct atau class yang memiliki dua bidang:
1.Data: Menyimpan nilai aktual.
2.next (Pointer): Menyimpan alamat (referensi) dari node berikutnya dalam urutan.

Node pertama disebut Head. Node terakhir memiliki pointer next yang menunjuk ke NULL, menandakan akhir dari list.

### Karakteristik utama

- Arah tunggal: Node hanya memiliki pointer next, sehingga penelusuran (traversal) hanya bisa maju, dimulai dari head.
- Dinamis: Memori dialokasikan menggunakan new (dan dibebaskan dengan delete) pada runtime, memungkinkan list tumbuh/menyusut tanpa batas ukuran awal.
- Akses Sekuensial: Untuk mengakses node ke-i, harus memulai dari head dan mengikuti pointer next sebanyak i-1 kali. Tidak ada akses acak.
- Pengelolaan Head: Kelas SingleLinkedList harus menyimpan pointer head (Node* head;) untuk melacak awal list.

### A. Operasi Dasar <br/>
Berikut beberapa operasi dasar yang umum dilakukan pada SLL:
#### 1. Traversal (pengaksesan semua node)
Tujuan: Mengunjungi setiap node dari awal hingga akhir.

#### 2. Insertion (penyisipan node)
Beberapa lokasi penyisipan umum: di awal list, di akhir list, atau di antara dua node.

a. Insert di Awal (head)
Kompleksitas Waktu: O(1)
Langkah: Buat node baru -> newNode -> next menunjuk ke head lama -> head dipindahkan ke newNode.
b. Insert di Akhir (tail)
Kompleksitas Waktu: O(N) (jika tidak menyimpan pointer tail)
Langkah: Traversal untuk mencari node terakhir -> Ubah lastNode -> next menunjuk ke newNode -> newNode -> next menunjuk ke NULL.

#### 3. Deletion (penghapusan node)
a. Delete di Awal (head)
Kompleksitas Waktu: O(1)
Langkah: Simpan pointer head lama -> Pindahkan head ke head -> next -> Bebaskan memori head lama menggunakan delete.
b. Delete di Posisi ke-$i$ atau Tengah
Kompleksitas Waktu: O(N)
Langkah: Cari node sebelum target (prev) -> Ubah prev -> next menunjuk ke target -> next -> Bebaskan memori target menggunakan delete.

#### 4. Pencarian (search)
Tujuan: Menemukan node berdasarkan nilai data tertentu.
Kompleksitas Waktu: O(N)
Langkah: Lakukan traversal, bandingkan current->data dengan nilai target di setiap langkah.

#### 5. Kompleksitas ruang dan waktu
Kompleksitas Waktu (T(n))
Operasi            Waktu Rata-Rata       Penjelasan
Akses/Pencarian    0(N)                  Harus menelusuri list dari head
Inset di Awal      0(1)                  Hanya manipulasi tiga pointer (node baru, head,
                                         head-next )
Delete di Awal     0(1)                  Hanya manipulasi head
Insert/Delete do   0(N)                  Membutuhkan traversal penuh ke node terakhir.
Akhir

Kompleksitas Ruang (S(n))
O(N): Ruang yang dibutuhkan berbanding lurus dengan jumlah elemen (N).
O(1) Overhead per Node: Setiap node memiliki overhead memori berupa satu pointer (next) selain data yang disimpan.

### B. Kelebihan dan Kekurangan<br/>
#### Kelebihan
Memori Dinamis: Efisien dalam penggunaan memori karena hanya mengalokasikan ruang saat dibutuhkan (menggunakan new di C++).
Insert/Delete di Awal Cepat: O(1), jauh lebih cepat daripada array yang memerlukan pergeseran data.

#### Kekurangan
Tidak Ada Akses Acak: Tidak dapat langsung mengakses elemen ke-i; selalu memerlukan O(N) traversal.
Overhead Memori: Setiap elemen membutuhkan memori ekstra untuk pointer next.
Arah Tunggal: Sulit (membutuhkan O(N) traversal dari head) untuk menemukan node sebelumnya.

### C. Aplikasi dan Varian <br/>
Aplikasi
Implementasi Struktur Data: Dasar untuk Stack (menggunakan Insert/Delete di Awal) dan Queue (menggunakan Insert di Akhir dan Delete di Awal).
Sistem Manajemen Memori: Digunakan oleh sistem operasi untuk mengelola alokasi memori bebas.
Representasi Polinomial: Setiap node menyimpan koefisien dan pangkat suatu suku.
Varian
Circular Single Linked List: Pointer next pada node terakhir menunjuk kembali ke head, membentuk lingkaran.
Doubly Linked List: Setiap node memiliki dua pointer (prev dan next), memungkinkan traversal dua arah, tetapi menambah overhead memori.

## Guided 

### 1. Implementasi Linked List Sederhana untuk Data Mahasiswa
```C++
[list.h] 
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;

typedef struct node *address;

struct node {
    dataMahasiswa isidata;
    address next;
};

struct linkedlist {
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &L);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);

void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif

[list.cpp]
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

[main.cpp]
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);
    
    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```
Program ini memanfaatkan struktur data linked list dasar untuk secara dinamis mengelola dan menyimpan informasi mahasiswa. Logika implementasi (pembuatan list, penambahan node, dan output) diletakkan di list.cpp, sementara antarmuka dan definisi struktur utama berada di list.h. Eksekusi utama (main.cpp) mendemonstrasikan penambahan beberapa data ke list tersebut dan menampilkan hasilnya, menekankan peran pointer dan manajemen memori dalam konteks data dinamis.

### 2. Program Implementasi Linked List Lengkap untuk Data Mahasiswa

```C++
[list.h]
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;

typedef struct node *address;

struct node {
    dataMahasiswa isidata;
    address next;
};

struct linkedlist {
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &L);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif

[list.cpp]
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    /* I.S. list tidak kosong
    F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    /* I.S. list tidak kosong
    F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    /* I.S. list tidak kosng, Prev alamat salah satu elemen list
    F.S. nodeBantu adalah alamat dari Prev→next, menghapus Prev→next dari list */
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}

[main.cpp]
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
Melalui tiga file (list.h, list.cpp, dan main.cpp), program ini menyajikan implementasi praktis dari linked list untuk memproses data mahasiswa. Fungsionalitas inti, seperti penambahan/pengurangan elemen dari berbagai posisi (insertFirst, delLast, dsb.) dan fungsi analisis (nbList), seluruhnya dienkapsulasi dalam list.cpp. Inti dari program ini adalah menunjukkan bagaimana pointer dimanfaatkan untuk mengelola memori secara dinamis (heap) guna membangun struktur data yang dapat bertambah dan berkurang ukurannya selama runtime.

## Unguided 

### 1. ![Screenshot Unguided 1_1](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan4_Modul4/Soal_Unguided1.png)

### ![Screenshot Unguided 1_2](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan4_Modul4/Soal_Unguided1_2.png)

```C++
[singlylist.h]
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address P);
void insertFirst(List &L, address P);
void printInfo(List L);

#endif

[singlylist.cpp]
#include "Singlylist.h"

void createList(List &L) {
    L.first = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address P) {
    delete P;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

[main.cpp]
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;

    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L); 

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan4_Modul4/Output_Soal_Unguided1.png)

Program ini menyajikan implementasi dasar dari singly linked list yang dirancang untuk menyimpan data bilangan bulat. Definisi struktur node (ElmList) dan list (List), serta deklarasi fungsi manajemen (seperti createList, alokasi, insertFirst, dan printInfo) berada dalam file header singlylist.h. Implementasi fungsi-fungsi tersebut terdapat pada singlylist.cpp, yang memastikan list diinisialisasi kosong, node dialokasikan secara heap, dan penyisipan elemen baru selalu dilakukan di posisi terdepan. Melalui main.cpp, list diisi dengan lima node menggunakan penyisipan awal secara berurutan, diikuti dengan pencetakan isi list untuk mendemonstrasikan operasi pembuatan, penambahan, dan penelusuran list berkait tunggal.

### 2. ![Screenshot Soal Unguided 2_1](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan4_Modul4/Soal_Unguided2.png)

```C++ 
[Singlylist.h]
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

[Singlylist.cpp]
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

[main.cpp]
#include "Singlylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    createList(L);

    insertFirst(L, 9);
    insertLast(L, 12);
    insertLast(L, 8);
    insertLast(L, 0);
    insertLast(L, 2);

    printList(L); 

    deleteFirst(L);     
    deleteLast(L);
    deleteAfter(L.first); 

    printList(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    deleteList(L);
    cout << "\n- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan4_Modul4/Output_Soal_Unguided2.png)

Implementasi Singly Linked List ini dirancang secara modular, menggunakan Singlylist.h untuk mendefinisikan struktur data (Node dan List) serta mendeklarasikan operasi. File Singlylist.cpp mengimplementasikan seluruh logika, termasuk pembuatan list dan manipulasi node (penambahan dan penghapusan di awal, tengah, dan akhir), serta penghitungan jumlah node. File main.cpp berfungsi sebagai driver untuk menguji operasi-operasi ini secara dinamis, mendemonstrasikan bagaimana data dikelola menggunakan pointer dalam struktur linked list.

## Kesimpulan
Single Linked List adalah struktur data linear dinamis yang terdiri dari node-node yang terhubung secara sekuensial melalui pointer satu arah (next).  Karakteristik utamanya adalah akses sekuensial (O(N)) dan fleksibilitas ukuran karena alokasi memori dinamis. Meskipun operasi penyisipan dan penghapusan di awal (head) sangat efisien (O(1)), kelemahan utamanya adalah kebutuhan untuk traversal penuh (O(N)) untuk operasi di akhir atau tengah list serta overhead memori karena penyimpanan pointer di setiap node. Diimplementasikan secara luas dalam C++ menggunakan struktur Node dan pointer, Linked List berfungsi sebagai dasar untuk struktur data lain seperti Stack dan Queue.

## Referensi
[1]Bhatnagar, Sarvesh Rakesh. “Speeding Up Search in Singly Linked List.” International Journal of Computer Applications, vol. 182, no. 18, Sep 2018, pp. 19-24.

<br>[2]Harihayati Mardzuki, Tati. "Contoh Kasus Algoritma Lengkap Single Linked List." Teaching Resource, Repository UNIKOM, 2020.

<br>[3]Sedgewick, Robert, and Kevin Wayne. "Algorithms, 4th Edition." Addison-Wesley Professional, 2011. (Buku teks klasik yang membahas struktur data dasar seperti Linked List).