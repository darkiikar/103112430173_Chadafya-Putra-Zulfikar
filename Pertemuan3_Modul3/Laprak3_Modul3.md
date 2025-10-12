# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE (ADT) </h1>
<p align="center">Chadafya Putra Zulfikar - 103112430173</p>

## Dasar Teori
Dalam C++, ADT adalah tentang enkapsulasi dan abstraksi. Kita membuat sebuah tipe data baru (misalnya, Stack) dan menyembunyikan detail internalnya dari pengguna. Pengguna hanya berinteraksi dengan tipe data tersebut melalui serangkaian fungsi publik (metode) yang telah kita sediakan. Mereka tidak perlu tahu—dan tidak seharusnya peduli—apakah Stack tersebut diimplementasikan menggunakan std::vector, array C-style, atau std::list.Fokus pada Perilaku: Pengguna hanya tahu bahwa mereka bisa memanggil push(), pop(), top(), dan isEmpty().Penyembunyian Implementasi (Information Hiding): Data internal (misalnya, array yang menyimpan elemen) dibuat private untuk mencegah akses langsung yang bisa merusak konsistensi data.

### A. Komponen ADT<br/>
Beberapa unsur yang biasa ada dalam definisi ADT:
#### 1. Domain nilai (value domain) — himpunan nilai-nilai yang bisa dimiliki oleh objek dari tipe data tersebut.

#### 2. Operasi-operasi (operations) — fungsi atau prosedur yang diizinkan terhadap objek ADT (seperti insert, delete, find, push, pop, dll).

#### 3. Aksioma atau spesifikasi formal — aturan-aturan yang mendefinisikan sifat operasi-operasi tersebut (misalnya identitas, komutatif, asosiatif, batasan, precondition/postcondition).

#### 4. Abstraksi dari implementasi — pengguna tidak melihat detail struktur internal (contoh: apakah implementasi menggunakan list, array, pointer, pohon, dsb).

#### 5. Spesifikasi formal sering menggunakan teknik aljabar atau logika (equational specification, algebraic specification), dan kadang operational semantics atau model matematis lainnya. 

### B. Tipe Spesifikasi<br/>

Spesifikasi Aljabar: Dalam C++, ini direpresentasikan oleh antarmuka publik di file .h dan didukung oleh dokumentasi atau komentar yang menjelaskan apa yang dilakukan setiap fungsi, prasyaratnya (preconditions), dan hasil akhirnya (postconditions).

Spesifikasi Model-Based: Pendekatan ini sangat umum di C++. Daripada mengimplementasikan Stack dari nol dengan new/delete, kita bisa menggunakan tipe data yang sudah ada seperti std::vector sebagai model dasarnya. Ini jauh lebih aman dan mudah.

### 3. ADT dalam Teori Tipe dan Sistem Formal <br/>

Dalam C++, sistem tipe berperan sangat penting.

Keamanan Tipe (Type Safety): Compiler C++ memastikan bahwa Anda hanya bisa melakukan operasi yang didefinisikan untuk Stack. Anda tidak bisa, misalnya, mencoba mengakses elemen Stack dengan operator [] karena kita tidak mendefinisikannya di antarmuka publik.

Generic Programming (Templates): Konsep ADT dapat diperluas dengan template untuk menciptakan tipe data yang bekerja dengan tipe data lain (misalnya, Stack<string>, Stack<double>). Ini adalah bentuk abstraksi tingkat lanjut di mana ADT kita tidak bergantung pada satu tipe data konkret.

### 4. Keunggulan dan Masalah<br/>
#### Keunggulan:<br/>
Abstraksi & Modularitas: Sangat mudah untuk mengganti implementasi Stack (misalnya dari array ke std::vector atau std::deque) tanpa mengubah kode klien sama sekali, selama antarmuka publiknya tetap sama.

Reusabilitas: Class Stack yang sudah dibuat dan diuji dapat digunakan di banyak proyek berbeda.

Keamanan: Dengan menyembunyikan data internal (menggunakan private), kita mencegah pengguna mengubah state objek secara tidak sengaja, yang menjaga integritas data.

#### Keterbatasan / tantangan:<br/>
Kompleksitas Desain: Merancang antarmuka yang baik (mudah digunakan, lengkap, dan minimalis) adalah sebuah tantangan. Antarmuka yang buruk akan sulit digunakan dan dipelihara.

Penanganan Error: ADT harus memiliki strategi yang jelas untuk menangani error (misalnya, pop dari stack kosong). Di C++, ini biasanya dilakukan dengan exceptions (seperti throw std::out_of_range) atau dengan mengembalikan kode error. Pilihan ini harus konsisten.

Efisiensi: Abstraksi terkadang bisa menimbulkan sedikit overhead performa (misalnya, pemanggilan fungsi). Namun, pada C++ modern, compiler sangat pintar dalam mengoptimalkan ini, sehingga seringkali biayanya bisa diabaikan (zero-cost abstraction).

Manajemen Memori: Untuk implementasi yang menggunakan alokasi memori manual (new/delete), sangat penting untuk mengelola memori dengan benar (mengikuti Rule of Three/Five/Zero) untuk menghindari kebocoran memori (memory leaks). Inilah sebabnya penggunaan kontainer standar seperti std::vector lebih disarankan.

## Guided 

### 1. Program Menghitung Rata-Rata Nilai Mahasiswa Menggunakan Struct

```C++
#include <iostream>
using namespace std; 

struct mahasiswa {
    string nama;
    float nilai1, nilai2;
};

void inputMhs(mahasiswa &m) {
    cout << "Masukkan nama mahasiswa: ";
    cin >> m.nama;
    cout << "Masukkan nilai 1 : ";
    cin >> m.nilai1;
    cout << "Masukkan nilai 2: ";
    cin >> m.nilai2;
}

float rata2(mahasiswa m) {
    return (m.nilai1 + m.nilai2) / 2;
}

int main() {
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "Rata-rata : " << rata2(mhs);
    return 0;
}
```
Program tersebut mendefinisikan struktur data untuk mahasiswa yang menyimpan nama dan dua nilai, kemudian meminta pengguna menginput data tersebut dan menghitung serta menampilkan nilai rata-ratanya.

### 2. Program Manajemen Data Pelajaran

```C++
[main.cpp]

#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}

[pelajaran.cpp]

#include "pelajaran.h"

pelajaran create_pelajaran(string namaMapel, string kodepel) {
    pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodepel;
    return p;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "Nama Pelajaran : " << pel.namaMapel << endl;
    cout << "kode : " << pel.kodeMapel << endl;
}

[pelajaran.h]
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namaMapel, string kodepel);

void tampil_pelajaran(pelajaran pel);

#endif
```
Tiga bagian kode tersebut merepresentasikan sebuah program C++ modular yang mengelola data mata pelajaran: file header pelajaran.h mendefinisikan struktur data pelajaran dan mendeklarasikan fungsi-fungsi, file implementasi mendefinisikan bagaimana fungsi create_pelajaran membuat objek baru dan tampil_pelajaran menampilkannya, dan fungsi utama main menggunakan file header dan fungsi implementasi tersebut untuk membuat objek pelajaran "Struktur Data" dengan kode "STD" lalu menampilkannya di konsol.

## Unguided 

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3* uts+0.4* uas+0.3* tugas.

```C++
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    Mahasiswa mhs[10];
    int n;

    cout << "Masukkan jumlah mahasiswa (maks 10): ";
    cin >> n;

    if (n > 10) {
        cout << "Jumlah mahasiswa tidak boleh lebih dari 10!" << endl;
        return 0;
    }

    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << "Data mahasiswa ke-" << i + 1 << endl;
        cout << "Nama   : ";
        cin.ignore(); 
        getline(cin, mhs[i].nama);
        cout << "NIM    : ";
        getline(cin, mhs[i].nim);
        cout << "Nilai UTS   : ";
        cin >> mhs[i].uts;
        cout << "Nilai UAS   : ";
        cin >> mhs[i].uas;
        cout << "Nilai Tugas : ";
        cin >> mhs[i].tugas;

        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
        cout << endl;
    }

    cout << "\n==============================================\n";
    cout << setw(20) << left << "Nama"
         << setw(15) << left << "NIM"
         << setw(10) << "Nil. Akhir" << endl;
    cout << "==============================================\n";

    for (int i = 0; i < n; i++) {
        cout << setw(20) << left << mhs[i].nama
             << setw(15) << left << mhs[i].nim
             << setw(10) << fixed << setprecision(2) << mhs[i].nilaiAkhir << endl;
    }

    cout << "==============================================\n";

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan3_Modul3/Output-Unguided1.png)

Program ini mendefinisikan struktur data untuk mahasiswa, meminta input nama, NIM, serta tiga nilai komponen (UTS, UAS, Tugas) untuk sejumlah mahasiswa (maksimal 10), menghitung nilai akhir dengan pembobotan 30% UTS, 40% UAS, dan 30% Tugas, kemudian menampilkan hasilnya dalam format tabel.

### 2. Tugas pemrograman C++ yang meminta Anda membuat dan mengimplementasikan sebuah Abstract Data Type (ADT) untuk "pelajaran" menggunakan konsep modular programming (pemrograman modular) dengan memisahkan kode ke dalam tiga file:

```C++ 
[main.cpp]

#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}

[pelajaran.cpp]

#include "pelajaran.h"

pelajaran create_pelajaran(string namaMapel, string kodepel) {
    pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodepel;
    return p;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "Nama Pelajaran : " << pel.namaMapel << endl;
    cout << "kode : " << pel.kodeMapel << endl;
}

[pelajaran.h]
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namaMapel, string kodepel);

void tampil_pelajaran(pelajaran pel);

#endif
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan3_Modul3/Output-Unguided2.png)

Tiga bagian kode tersebut merepresentasikan sebuah program C++ modular yang mengelola data mata pelajaran: file header pelajaran.h mendefinisikan struktur data pelajaran dan mendeklarasikan fungsi-fungsi, file implementasi mendefinisikan bagaimana fungsi create_pelajaran membuat objek baru dan tampil_pelajaran menampilkannya, dan fungsi utama main menggunakan file header dan fungsi implementasi tersebut untuk membuat objek pelajaran "Struktur Data" dengan kode "STD" lalu menampilkannya di konsol.

### 3. Buatlah program dengan ketentuan :
- 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
- fungsi/prosedur yang menampilkan isi sebuah array integer 2D
- fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
- fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer
```C++
#include <iostream>
#include <iomanip>
using namespace std;

void tampilkanArray(int arr[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << std::setw(4) << arr[i][j];
        }
        std::cout << '\n';
    }
}

void tukarElem(int arr1[3][3], int arr2[3][3], int i, int j) {
    if (i < 0 || i >= 3 || j < 0 || j >= 3) return;
    int tmp = arr1[i][j];
    arr1[i][j] = arr2[i][j];
    arr2[i][j] = tmp;
}

void tukarPointer(int *p, int *q) {
    if (!p || !q) return;
    int tmp = *p;
    *p = *q;
    *q = tmp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };

    int x = 100;
    int y = 200;
    int *px = &x;
    int *py = &y;

    std::cout << "Array A awal:\n";
    tampilkanArray(A);
    std::cout << "\nArray B awal:\n";
    tampilkanArray(B);

    std::cout << "\nMenukar elemen A[1][1] dengan B[1][1] (indeks 1,1 = baris kedua kolom kedua)\n";
    tukarElem(A, B, 1, 1);

    std::cout << "Array A setelah tukar:\n";
    tampilkanArray(A);
    std::cout << "\nArray B setelah tukar:\n";
    tampilkanArray(B);

    std::cout << "\nNilai sebelum tukar via pointer: x=" << x << ", y=" << y << '\n';
    tukarPointer(px, py);
    std::cout << "Nilai setelah tukar via pointer: x=" << x << ", y=" << y << '\n';

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan3_Modul3/Output-Unguided3.png)

Program ini mendemonstrasikan dua cara penukaran nilai: pertama, menukar elemen tertentu dari dua array dua dimensi 3×3 (A[1][1] dengan B[1][1]) menggunakan fungsi tukarElem, dan kedua, menukar nilai dua variabel (x dan y) menggunakan pointer melalui fungsi tukarPointer

## Kesimpulan
Abstract Data Type adalah konsep penting dalam ilmu komputer yang memungkinkan pemisahan antara antarmuka dan implementasi, fokus pada perilaku yang diharapkan daripada detail representasi.

ADT mendasari banyak prinsip dalam pemrograman, seperti abstraksi data, modularitas, dan spesifikasi formal, dan juga muncul di teori tipe dan semantik pemrograman.

Untuk desain sistem yang handal dan dapat diverifikasi, penggunaan ADT dengan spesifikasi formal sangat berguna; namun, harus ada keseimbangan antara abstraksi dan kebutuhan praktis (misalnya performa, kegunaan implementasi).

Penelitian tentang ADT terus berkembang terutama dalam konteks model formal, teori tipe, dan aplikasi himpunan aksioma yang lebih kompleks (misalnya nondeterminisme, kesalahan, higher-order types).

## Referensi
[1]Goguen, J. A., Thatcher, J. W., & Wagner, E. G. (1978). An initial algebra approach to the specification, correctness, and implementation of abstract data types. In R. T. Yeh (Ed.), Current Trends in Programming Methodology, Vol. 4: Data Structuring (pp. 80-149). Prentice-Hall.

<br>[2]Liskov, B., & Zilles, S. (1974). Programming with abstract data types. ACM SIGPLAN Notices, 9(4), 50–59.

<br>[3]Guttag, J. V. (1977). Abstract data types and the development of data structures. Communications of the ACM, 20(6), 396–404.