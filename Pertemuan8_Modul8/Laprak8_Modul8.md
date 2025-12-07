# <h1 align="center">Laporan Praktikum Modul 8 - QUEUE </h1>
<p align="center">Chadafya Putra Zulfikar - 103112430173</p>

## Dasar Teori
### 1. Definisi Teori Queue
Dalam pemrograman bahasa C, "antrian" secara harfiah diimplementasikan sebagai struktur data linier yang mengikuti prinsip FIFO (First-In, First-Out). Artinya, elemen yang pertama kali dimasukkan ke dalam antrian adalah elemen yang pertama kali dikeluarkan.

Meskipun teori antrian adalah konsep matematis, implementasi struktur data antrian dalam C sangat penting untuk mensimulasikan sistem antrian atau untuk membangun aplikasi di mana urutan pemrosesan data sangat krusial (misalnya, penjadwalan tugas pada sistem operasi atau manajemen buffer I/O).

### 2. Komponen Sistem Queue
1. Proses Kedatangan (Input Process)
Ini menjelaskan bagaimana "pelanggan" (entitas yang membutuhkan layanan) memasuki sistem. Karakteristik utama yang dimodelkan adalah:
- Ukuran Populasi: Apakah populasi pelanggan terbatas (misalnya, lima mesin yang mungkin rusak) atau tidak terbatas (misalnya, pengguna internet global).
- Pola Kedatangan: Bagaimana pelanggan tiba dari waktu ke waktu. Paling sering dimodelkan menggunakan Distribusi Poisson, yang berarti waktu antar-kedatangan (inter-arrival time) mengikuti Distribusi Eksponensial.
-Perilaku Pelanggan:
    Balking: Pelanggan memutuskan untuk tidak masuk ke antrian karena terlalu panjang.
    Reneging: Pelanggan meninggalkan antrian setelah menunggu beberapa saat.
    Jockeying: Pelanggan pindah dari satu antrian ke antrian lain.
2. Mekanisme Layanan (Service Mechanism)
Ini menjelaskan bagaimana layanan diberikan kepada pelanggan. Karakteristik utamanya meliputi:
- Jumlah Server: Berapa banyak saluran (channels) atau pekerja yang tersedia untuk melayani pelanggan (misalnya, satu kasir atau sepuluh kasir).
- Pola Layanan: Berapa lama waktu yang dibutuhkan server untuk melayani satu pelanggan. Paling sering dimodelkan menggunakan Distribusi Eksponensial (untuk model Markovian).
- Disiplin Antrian (Queue Discipline): Aturan yang menentukan pelanggan mana yang akan dilayani selanjutnya. Yang paling umum adalah:
    FIFO (First-In, First-Out) / FCFS (First-Come, First-Served): Pelanggan yang datang duluan dilayani duluan.
    LIFO (Last-In, First-Out): Pelanggan yang datang terakhir dilayani duluan (jarang di dunia nyata).
    SIRO (Service in Random Order): Pelanggan dipilih secara acak.
    Priority: Pelanggan dengan prioritas lebih tinggi dilayani lebih dulu, terlepas dari waktu kedatangan.
3. Fasilitas Antrian (Queue Facility)
Ini adalah tempat pelanggan menunggu layanan. Karakteristiknya adalah:
- Kapasitas Antrian: Apakah antrian memiliki panjang terbatas (misalnya, hanya boleh ada 10 mobil dalam antrian drive-thru) atau tidak terbatas. Jika kapasitasnya terbatas dan antrian penuh, kedatangan baru akan ditolak (balking).

### 3. Penerapan Teori Queue
Teori antrian adalah alat yang sangat kuat untuk pengambilan keputusan operasional. Penerapannya mencakup berbagai bidang:
- Telekomunikasi & Jaringan Komputer: Menganalisis traffic data, merancang router dan switch, menentukan ukuran buffer jaringan, dan memprediksi waktu tunda paket data.
- Manufaktur & Logistik: Merancang tata letak pabrik, mengelola work-in-process (WIP), dan menentukan jumlah dock pemuatan/pembongkaran yang optimal.
- Layanan Pelanggan: Menentukan jumlah operator call center yang dibutuhkan, merancang tata letak bank atau supermarket, dan memprediksi waktu tunggu di rumah sakit.
- Sistem Transportasi: Merencanakan traffic flow di jalan tol atau bandara dan mengoptimalkan jadwal kereta.

### 4. Model Khusus dan Kemajuan Teoritis
1. Model M/M/1A/B/c: M/M/1
- Deskripsi: Kedatangan berdistribusi Poisson (Markovian), waktu layanan berdistribusi Eksponensial (Markovian), dan satu server tunggal.
- Penerapan: Model paling sederhana untuk satu kasir, satu ATM, atau satu router jaringan.
2. Model M/M/c
- A/B/c: M/M/c
- Deskripsi: Sama seperti M/M/1, tetapi memiliki c server yang bekerja secara paralel (misalnya, lima teller bank yang mengambil pelanggan dari satu antrian).
- Penerapan: Panggilan ke call center dengan banyak agen, atau jalur perakitan dengan banyak stasiun kerja.
3. Model M/G/1
- A/B/c: M/G/1
- Deskripsi: Kedatangan Poisson (M), tetapi waktu layanan memiliki distribusi umum (G), dengan hanya satu server. Ini digunakan ketika waktu layanan tidak dapat dimodelkan secara akurat oleh distribusi Eksponensial.
- Rumus Kunci: Menggunakan Rumus Pollaczek-Khinchine untuk menghitung panjang antrian rata-rata, yang memerlukan varians waktu layanan.


## Guided 

### 1. Implementasi dan Pengujian Struktur Data Queue Berbasis Linked List
#### [queue.h]
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

struct queue {
    Node* head;
    Node* tail;
};

void CreateQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);   
void enQueue(queue &Q, const string &nama);
void deQueue(queue &Q);
void viewQueue(queue Q);
void clearQueue(queue &Q);

#endif
```

#### [queue.cpp]
```C++
#include "queue.h"
using namespace std;

void CreateQueue(queue &Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isEmpty(queue Q) {
    return Q.head == nullptr;
}

bool isFull(queue) {
    return false;
}

void enQueue(queue &Q, const string &nama) {
    Node* baru = new Node{nama, nullptr};
    if (isEmpty(Q)) {
        Q.head = Q.tail = baru;
    } else {
        Q.tail->next = baru;
        Q.tail = baru;
    }
    cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    Node* hapus = Q.head;
    cout << "Menghapus data " << hapus->nama << "..." << endl;
    Q.head = Q.head->next;
    if (Q.head == nullptr) {
        Q.tail = nullptr;
    }
    delete hapus;
}

void viewQueue(queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    int i = 1;
    for (Node* p = Q.head; p != nullptr; p = p->next) {
        cout << i++ << ". " << p->nama << endl;
    }
}

void clearQueue(queue &Q) {
    while (!isEmpty(Q)) {
        deQueue(Q);
    }
}
```

#### [main.cpp]
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    queue Q;
    CreateQueue(Q);

    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    clearQueue(Q);
    return 0;
}
```
Program ini mendemonstrasikan implementasi antrian (queue) menggunakan linked list. Konstruksinya dijelaskan melalui definisi struktur dan deklarasi fungsi dalam queue.h, diikuti dengan implementasi operasi FIFO (First In, First Out) di queue.cpp. Pengujian pada main.cpp secara jelas menampilkan alur kerja antrian, mencakup penambahan elemen (enqueue), penghapusan (dequeue), penampilan isi, dan pembersihan data.

### 2. Implementasi Queue Statis dengan Berbagai Metode Pergerakan Head dan Tail
#### [queue.h]
```C++
#ifndef QUEUE_H
#define QUEUE_H


#include <iostream>
using namespace std;

const int MAKSIMAL = 5;

struct queue{
    string nama[MAKSIMAL];
    int head;
    int tail;
};

bool isFull(queue Q);
bool isEmpty(queue Q);
void CreateQueue(queue &Q);
void enQueue(queue &Q, string nama);
void deQueue(queue &Q);
void viewQueue(queue Q);

#endif
```

#### [queue.cpp]
```C++
#include "queue.h"
#include <iostream>

using namespace std;

// NOTE : 
// Implementasi 1 = head diam, tail bergerak (Queue Linear Statis, kerana head nya tetap diam)
// Implementasi 2 = head bergerak, tail bergerak (Queue Linear Dinamis, karena head & tail nya sama-sama bergerak)
// Implementasi 3 = head dan tail berputar (Queue Circular, karena jika udh mentok tapi masih ada space, diputar sehingga tail bisa ada didepan head)

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

//isFull implmenetasi 1 & 2
bool isFull(queue Q){
    if(Q.tail == MAKSIMAL - 1){
        return true;
    } else {
        return false;
    }
}

// //isFull implementasi 3
// bool isFull(queue Q){
//     if((Q.tail + 1) % MAKSIMAL == Q.head){
//         return true;
//     } else {
//         return false;
//     }
// }

void CreateQueue(queue &Q){ //terbentuk queue dengan head = -1 dan tail = -1 
    Q.head = -1;
    Q.tail = -1;
}
 

//enqueue implementasi 1 & 2
void enQueue(queue &Q, string nama){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

// //enQueue implementasi 3
// void enQueue(queue &Q, string nama){
//     if(isFull(Q) == true){
//         cout << "Queue sudah penuh!" << endl;
//     } else {
//         if(isEmpty(Q) == true){
//             Q.head = Q.tail = 0;
//         } else {
//             Q.tail = (Q.tail + 1) % MAKSIMAL; // bergerak melingkar
//         }
//         Q.nama[Q.tail] = nama;
//         cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
//     }
// }

//dequeue implementasi 1
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        for(int i = 0; i < Q.tail; i++){
            Q.nama[i] =  Q.nama[i+1];
        }
        Q.tail--;
        if(Q.tail < 0){ //kalo semua isi queue nya udh dikelaurin, set head & tail ke -1
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

// //dequeue implementasi 2
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         Q.head++;
//         if(Q.head > Q.tail){ //kalo elemennya udh abis (head akan lebih 1 dari tail), maka reset ulang head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

// //deQueue implementasi 3
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         } else {
//             Q.head = (Q.head + 1) % MAKSIMAL; // bergerak melingkar
//         }
//     }
// }

//viewQueue implementasi 1 & 2
void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << i -  Q.head + 1 << ". " << Q.nama[i] << endl;
        }
    }
    cout << endl;
}

// //viewQueue implementasi 3
// void viewQueue(queue Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         int i = Q.head;
//         int count = 1;
//         while(true){
//             cout << count << ". " << Q.nama[i] << endl;
//             if(i == Q.tail){
//                 break;
//             }
//             i = (i + 1) % MAKSIMAL;
//             count++;
//         }   
//     }
// }
```

#### [main.cpp]
```C++
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;

    CreateQueue(Q);
    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Daffa");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    // deQueue(Q);
    // deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    return 0;
}
```
Program ini menyajikan implementasi struktur data antrian (queue) menggunakan array statis berkapasitas tetap. Kode ini secara khusus mendemonstrasikan tiga pendekatan berbeda: antrian linear dengan head tetap, antrian linear dengan head dan tail bergerak, dan antrian melingkar (circular queue) untuk mengoptimalkan penggunaan ruang. Melalui fungsi inti seperti CreateQueue, isFull, isEmpty, enQueue, deQueue, dan viewQueue, program yang diuji pada main.cpp ini secara jelas mengilustrasikan cara data diproses dengan prinsip FIFO (First In, First Out) di bawah berbagai mekanisme array.

## Unguided 

### 1. ![Screenshot Unguided 1_1](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan8_Modul8/soal-unguided1.png)

#### [queue.h]
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Queue {
    infotype info[5];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(const Queue &Q);
bool isFullQueue(const Queue &Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(const Queue &Q);

#endif
```

#### [queue.cpp]
```C++
#include "queue.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q)
{
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(const Queue &Q)
{
    return Q.head == -1;
}

bool isFullQueue(const Queue &Q)
{
    return Q.tail == 4;
}

void enqueue(Queue &Q, infotype x)
{
    if (isEmptyQueue(Q))
    {
        Q.head = 0;
        Q.tail = 0;
        Q.info[Q.tail] = x;
    }
    else if (!isFullQueue(Q))
    {
        Q.tail = Q.tail + 1;
        Q.info[Q.tail] = x;
    }
    else
    {
        std::cout << "Queue penuh" << std::endl;
    }
}

infotype dequeue(Queue &Q)
{
    if (!isEmptyQueue(Q))
    {
        infotype val = Q.info[0];
        for (int i = 0; i < Q.tail; i = i + 1)
        {
            Q.info[i] = Q.info[i + 1];
        }
        Q.tail = Q.tail - 1;
        if (Q.tail < 0)
        {
            Q.head = -1;
            Q.tail = -1;
        }
        return val;
    }
    else
    {
        std::cout << "Queue kosong" << std::endl;
        return -1;
    }
}

void printInfo(const Queue &Q)
{
    if (isEmptyQueue(Q))
    {
        std::cout << Q.head << " - " << Q.tail << "  : " << "empty queue" << std::endl;
        return;
    }
    std::cout << Q.head << " - " << Q.tail << "  : ";
    for (int i = 0; i <= Q.tail; i = i + 1)
    {
        std::cout << Q.info[i];
        if (i < Q.tail) std::cout << " ";
    }
    std::cout << std::endl;
}
```

#### [main.cpp]
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main()
{
    std::cout << "Hello world!" << std::endl;

    Queue Q;
    createQueue(Q);

    std::cout << "---------------------------" << std::endl;
    std::cout << " H - T  : Queue Info" << std::endl;
    std::cout << "---------------------------" << std::endl;

    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}
```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan8_Modul8/output-unguided1.png)

Program ini merealisasikan antrian statis dengan kapasitas lima elemen menggunakan array, di mana penanda head dan tail digunakan untuk manajemen posisi. Fungsi seperti createQueue, isEmptyQueue, dan isFullQueue menangani inisialisasi dan pengecekan status. Operasi penambahan (enqueue) terjadi di posisi tail, sementara penghapusan (dequeue) dari posisi head secara unik diikuti dengan penggeseran (shifting) semua elemen yang tersisa ke kiri. Seluruh fungsionalitas ini, termasuk penampilan status antrian (printInfo), diuji di program utama untuk mengilustrasikan alur FIFO (First In, First Out).

### 2. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 2 (head bergerak, tail bergerak).

#### [queue.h]
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Queue {
    infotype info[5];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(const Queue &Q);
bool isFullQueue(const Queue &Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(const Queue &Q);

#endif
```

#### [queue.cpp]
```C++
#include "queue.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q)
{
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(const Queue &Q)
{
    return Q.head == -1;
}

bool isFullQueue(const Queue &Q)
{
    if (Q.head == -1) return false; 
    const int MAX = 5;
    return ((Q.tail + 1) % MAX) == Q.head;
}

void enqueue(Queue &Q, infotype x)
{
    const int MAX = 5;
    if (isFullQueue(Q))
    {
        std::cout << "Queue penuh" << std::endl;
        return;
    }

    if (isEmptyQueue(Q))
    {
        Q.head = 0;
        Q.tail = 0;
        Q.info[Q.tail] = x;
    }
    else
    {
        Q.tail = (Q.tail + 1) % MAX;
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q)
{
    if (isEmptyQueue(Q))
    {
        std::cout << "Queue kosong" << std::endl;
        return -1;
    }

    infotype val = Q.info[Q.head];
    const int MAX = 5;
    if (Q.head == Q.tail)
    {
        Q.head = -1;
        Q.tail = -1;
    }
    else
    {
        Q.head = (Q.head + 1) % MAX;
    }
    return val;
}

void printInfo(const Queue &Q)
{
    if (isEmptyQueue(Q))
    {
        std::cout << Q.head << " - " << Q.tail << "  : " << "empty queue" << std::endl;
        return;
    }
    std::cout << Q.head << " - " << Q.tail << "  : ";
    const int MAX = 5;
    int i = Q.head;
    while (true)
    {
        std::cout << Q.info[i];
        if (i == Q.tail) break;
        std::cout << " ";
        i = (i + 1) % MAX;
    }
    std::cout << std::endl;
}
```

#### [main.cpp]
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main()
{
    std::cout << "Hello world!" << std::endl;

    Queue Q;
    createQueue(Q);

    std::cout << "---------------------------" << std::endl;
    std::cout << " H - T  : Queue Info" << std::endl;
    std::cout << "---------------------------" << std::endl;

    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}
```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan8_Modul8/output-unguided2.png)

Program ini mengimplementasikan antrian melingkar (circular queue) menggunakan array statis berkapasitas lima elemen. Untuk mengoptimalkan pemanfaatan ruang, pergerakan penanda head dan tail dilakukan secara melingkar dengan memanfaatkan operasi modulo. Fungsionalitas inti, seperti inisialisasi (createQueue), pemeriksaan status (isEmptyQueue, isFullQueue), penambahan (enqueue), dan penghapusan (dequeue), dirancang untuk memutar posisi head dan tail. Kode ini, termasuk fungsi tampilan (printInfo) yang mengakomodasi susunan melingkar, diuji dalam main.cpp untuk mendemonstrasikan aliran data FIFO (First In, First Out) dalam konfigurasi sirkular.

### 3. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 3 (head dan tail berputar)

#### [queue.h]
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Queue {
    infotype info[5];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(const Queue &Q);
bool isFullQueue(const Queue &Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(const Queue &Q);

#endif
```

#### [queue.cpp]
```C++
#include "queue.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q)
{
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(const Queue &Q)
{
    return Q.head == -1;
}

bool isFullQueue(const Queue &Q)
{
    return (Q.tail + 1) % 5 == Q.head;
}

void enqueue(Queue &Q, infotype x)
{
    if (isEmptyQueue(Q))
    {
        Q.head = 0;
        Q.tail = 0;
        Q.info[Q.tail] = x;
    }
    else if (!isFullQueue(Q))
    {
        Q.tail = (Q.tail + 1) % 5;
        Q.info[Q.tail] = x;
    }
    else
    {
        std::cout << "Queue penuh" << std::endl;
    }
}

infotype dequeue(Queue &Q)
{
    if (!isEmptyQueue(Q))
    {
        infotype val = Q.info[Q.head];
        if (Q.head == Q.tail)
        {
            Q.head = -1;
            Q.tail = -1;
        }
        else
        {
            Q.head = (Q.head + 1) % 5;
        }
        return val;
    }
    else
    {
        std::cout << "Queue kosong" << std::endl;
        return -1;
    }
}

void printInfo(const Queue &Q)
{
    if (isEmptyQueue(Q))
    {
        std::cout << Q.head << " - " << Q.tail << "  : " << "empty queue" << std::endl;
        return;
    }
    std::cout << Q.head << " - " << Q.tail << "  : ";
    int i = Q.head;
    while (true)
    {
        std::cout << Q.info[i];
        if (i == Q.tail) break;
        std::cout << " ";
        i = (i + 1) % 5;
    }
    std::cout << std::endl;
}
```

#### [main.cpp]
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main()
{
    std::cout << "Hello world!" << std::endl;

    Queue Q;
    createQueue(Q);

    std::cout << "---------------------------" << std::endl;
    std::cout << " H - T  : Queue Info" << std::endl;
    std::cout << "---------------------------" << std::endl;

    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}
```

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan8_Modul8/output-unguided3.png)

Implementasi kode ini menyajikan antrian melingkar (circular queue) yang dibangun di atas array statis berkapasitas lima elemen. Untuk mencapai pemanfaatan ruang yang maksimal, posisi head dan tail dimanipulasi agar bergerak secara sirkular menggunakan operasi modulo. Fungsionalitas intinya mencakup inisialisasi (createQueue), validasi status (isEmptyQueue, isFullQueue), penambahan elemen (enqueue) yang memutar tail, dan penghapusan elemen (dequeue) yang memutar head. Pengujian pada main.cpp menunjukkan bagaimana operasi printInfo menampilkan urutan elemen yang benar, memverifikasi kepatuhan sistem terhadap prinsip FIFO (First In, First Out) dalam konfigurasi melingkar.

## Kesimpulan
Teori Antrian merupakan cabang ilmu matematika terapan yang secara fundamental menganalisis sistem tunggu dengan memodelkan tiga komponen utama: pola kedatangan pelanggan, mekanisme layanan (termasuk jumlah server dan disiplin antrian seperti FIFO), serta fasilitas antrian. Tujuan dari teori ini, yang menggunakan model seperti M/M/1, adalah untuk memprediksi metrik kinerja kunci, seperti waktu tunggu dan panjang antrian, yang sangat penting dalam optimasi sumber daya di berbagai bidang, mulai dari jaringan komputer hingga logistik dan layanan pelanggan. Sementara Teori Antrian menyediakan kerangka matematis dan operasional, implementasi praktis konsep antrian dalam pemrograman Bahasa C direalisasikan melalui struktur data FIFO (First-In, First-Out), baik menggunakan linked list yang fleksibel, atau array statis yang, meskipun terbatas ukurannya, dapat dimodifikasi menjadi circular queue menggunakan operasi modulo untuk memaksimalkan efisiensi ruang. Dengan demikian, kode C berfungsi sebagai alat struktural untuk merealisasikan atau mensimulasikan model kinerja yang dianalisis oleh Teori Antrian.

## Referensi
[1] A. Asanjarani, Y. Nazarathy, and P. Taylor, “A survey of parameter and state estimation in queues,” arXiv preprint arXiv:2012.14614, 2020.

<br>[2] L. Kleinrock, Queueing Systems, Volume 1: Theory. New York: John Wiley & Sons, 1975

<br>[3] D. Gross and C. M. Harris, Fundamentals of Queueing Theory, 3rd ed. New York: John Wiley & Sons, 1998.

<br>[4] R. B. Cooper, Introduction to Queueing Theory, 2nd ed. North-Holland, 1981.