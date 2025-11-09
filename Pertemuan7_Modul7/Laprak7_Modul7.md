# <h1 align="center">Laporan Praktikum Modul 7 - STACK </h1>
<p align="center">Chadafya Putra Zulfikar - 103112430173</p>

## Dasar Teori
### 1. Definisi dan Sifat Dasar
Stack adalah struktur data linear yang beroperasi berdasarkan prinsip LIFO (Last-In, First-Out). Prinsip ini berarti elemen terakhir yang dimasukkan ke dalam stack akan menjadi elemen pertama yang dikeluarkan. Secara analogi, stack dapat dibayangkan seperti tumpukan piring; piring yang paling baru diletakkan (paling atas) harus diambil lebih dulu. Dalam C++, stack dapat diimplementasikan menggunakan array, linked list (secara kustom), atau dengan menggunakan container adapter std::stack dari Standard Template Library (STL).

### 2. Operasi dasar pada Stack
Operasi pada stack hanya terjadi di satu ujung yang disebut top (puncak). Kompleksitas waktu untuk semua operasi ini adalah $O(1)$ (waktu konstan).
- Push: Menambahkan elemen baru ke puncak stack.
- Pop: Menghapus elemen dari puncak stack.
- Top/Peek: Mengakses elemen di puncak stack tanpa menghapusnya.
- isEmpty: Memeriksa apakah stack kosong.
- isFull: (Khusus implementasi array) Memeriksa apakah stack sudah penuh (overflow).

### 3. Kelebihan dan Kekurangan
#### Kelebihan
Implementasi sederhana dan mudah dipahami; sangat efisien (O(1)) untuk akses dan manipulasi elemen di puncak; efisien dalam penggunaan memori untuk penyimpanan sementara.

#### Kekurangan
Akses terbatas (hanya diizinkan pada elemen teratas); tidak mendukung akses acak; implementasi array memiliki kapasitas tetap (fixed size); berisiko stack overflow pada kasus rekursi yang sangat dalam.

### 4. Aplikasi dan kegunaan
- Manajemen Panggilan Fungsi: Digunakan oleh kompiler dan sistem operasi untuk mengelola pemanggilan fungsi, variabel lokal, dan alamat kembali (return address).
- Rekursi: Semua proses rekursif secara internal menggunakan stack.
- Mekanisme Undo/Redo: Digunakan pada editor teks atau perangkat lunak desain grafis untuk menyimpan riwayat tindakan.
- Evaluasi Ekspresi: Mengubah ekspresi infix menjadi postfix (Reverse Polish Notation) dan mengevaluasi ekspresi tersebut.
- Pemeriksaan Sintaks: Digunakan untuk memverifikasi keseimbangan kurung kurawal, kurung siku, atau tanda kurung dalam kode program.

## Guided 

### 1. Implementasi Struktur Data Stack Menggunakan Linked List
#### [stack.h]
```C++
#ifndef STACK
#define STACK
#define Nil NULL

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);

void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif
```

#### [stack.cpp]
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```

#### [main.cpp]
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```
Program ini mengimplementasikan struktur data Stack (tumpukan) yang beroperasi dengan prinsip LIFO (Last In, First Out) menggunakan pendekatan Linked List dan pointer dinamis. Deklarasi strukturnya (node dan stack) serta antarmuka fungsi dasar (seperti push, pop, update, view, dan searchData) berada di stack.h, sementara implementasi logikanya ada di stack.cpp. Seluruh fungsionalitas ini diuji dan didemonstrasikan di main.cpp dengan menjalankan serangkaian operasi tambah, hapus, perbarui, dan cari elemen.

### 2. Implementasi Struktur Data Stack Menggunakan Array
#### [stack.h]
```C++
#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
using namespace std;

const int MAX = 10;

struct stackTable {
    int data[MAX];
    int top;
};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);

void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);

#endif
```

#### [stack.cpp]
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stackTable s){
    return s.top == -1;
}

bool isFull(stackTable s){
    return s.top == MAX - 1;
}

void createStack(stackTable &s){
    s.top = -1;
}

void push(stackTable &s, int angka){
    if(isFull(s)){
        cout << "Stack penuh!" << endl;
    } else {
        s.top++;
        s.data[s.top] = angka;
        cout << "Data " << angka << " berhasil ditambahkan ke dalam stack!" << endl;
    }
}

void pop(stackTable &s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        int val = s.data[s.top];
        s.top--;
        cout << "Data " << val << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stackTable &s, int posisi){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }
    if(posisi <= 0){
        cout << "Posisi tidak valid!" << endl;
        return;
    }

    int idx = s.top - (posisi + 1);
    if(idx < 0 || idx > s.top){
        cout << "Posisi " << posisi << " tidak valid!" << endl;
        return;
    }

    cout << "Update data posisi ke- " << posisi << endl;
    cout << "Masukkan angka : ";
    cin >> s.data[idx];
    cout << "Data berhasil diupdate!" << endl;
    cout << endl;
}

void view(stackTable s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        for(int i = s.top; i >= 0; --i){
            cout << s.data[i] << " ";
        }
    }
    cout << endl;
}

void searchData(stackTable s, int data){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }
    cout << "Mencari data " << data << "..." << endl;
    int posisi = -1;
    bool found = false;

    for(int i = s.top; i >= 0; --i){
        if(s.data[i] == data){
            cout << "Data " << data << " ditemukan pada posisi ke- " << posisi << endl;
            cout << endl;
            found = true;
            break;
        }
        posisi++;
    }

    if(!found){
        cout << "Data " << data << " tidak ditemukan dalam stack!" << endl;
        cout << endl;
    }
}
```

#### [main.cpp]
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stackTable s;
    createStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(s);
    cout << endl;

    pop(s);
    pop(s);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(s);
    cout << endl;

    // posisi dihitung dari TOP (1-based index)
    update(s, 2);
    update(s, 1);
    update(s, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(s);
    cout << endl;

    searchData(s, 4);
    searchData(s, 9);

    return 0;
}
```
Kode ini merupakan implementasi dasar dari struktur data Stack yang patuh pada prinsip LIFO (Last-In, First-Out), menggunakan array statis berkapasitas tetap (MAX = 10) yang didefinisikan dalam stack.h bersama indeks top; fungsionalitasnya (yaitu push, pop, update, view, dan searchData) diimplementasikan dalam stack.cpp dan diuji secara komprehensif oleh main.cpp untuk mendemonstrasikan manajemen data tumpukan.

## Unguided 

### 1. ![Screenshot Unguided 1_1](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan7_Modul7/soal-unguided1.png)

#### [stack.h]
```C++
#ifndef STACK_H
#define STACK_H

typedef int infotype;

struct Stack {
    infotype info[20];
    int top;
};

void createStack(Stack &S);
void Push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(const Stack &S);
void balikStack(Stack &S);

#endif
```

#### [stack.cpp]
```C++
#include "stack.h"
#include <iostream>

void createStack(Stack &S)
{
	S.top = 0;
}

void Push(Stack &S, infotype x)
{
	if (S.top < 20)
	{
		S.info[S.top] = x;
		S.top = S.top + 1;
	}
	else
	{
		std::cout << "Stack penuh" << std::endl;
	}
}

infotype pop(Stack &S)
{
	if (S.top > 0)
	{
		S.top = S.top - 1;
		return S.info[S.top];
	}
	else
	{
		std::cout << "Stack kosong" << std::endl;
		return -1;
	}
}

void printInfo(const Stack &S)
{
	std::cout << "[TOP] ";
	for (int i = S.top - 1; i >= 0; i = i - 1)
	{
		std::cout << S.info[i];
		if (i > 0) std::cout << " ";
	}
	std::cout << std::endl;
}

void balikStack(Stack &S)
{
	int i = 0;
	int j = S.top - 1;
	while (i < j)
	{
		infotype temp = S.info[i];
		S.info[i] = S.info[j];
		S.info[j] = temp;
		i = i + 1;
		j = j - 1;
	}
}
```

#### [main.cpp]
```C++
#include <iostream>
#include "stack.h"

int main()
{
	std::cout << "Hello world!" << std::endl;

	Stack S;
	createStack(S);
	Push(S,3);
	Push(S,4);
	Push(S,8);
	pop(S);
	Push(S,2);
	Push(S,3);
	pop(S);
	Push(S,9);
	printInfo(S);
	std::cout << "balik stack" << std::endl;
	balikStack(S);
	printInfo(S);
	return 0;
}
```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan7_Mdul7/output-unguided1.png)

Implementasi Stack dasar ini menggunakan array statis untuk penyimpanan, di mana stack.h mendefinisikan strukturnya dengan info dan top, stack.cpp mengimplementasikan operasinya (LIFO) seperti Push, pop, dan balikStack, dan main.cpp menguji fungsionalitasnya.

### 2. ![Screenshot Unguided 2_1](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan7_Modul7/soal-unguided2.png)

#### [stack.h]
```C++
#ifndef STACK_H
#define STACK_H

typedef int infotype;

struct Stack {
	infotype info[20];
	int top;
};

void createStack(Stack &S);
void Push(Stack &S, infotype x);
infotype pop(Stack &S);
void pushAscending(Stack &S, infotype x);
void printInfo(const Stack &S);
void balikStack(Stack &S);

#endif
```

#### [stack.cpp]
```C++
#include "stack.h"
#include <iostream>

void createStack(Stack &S)
{
    S.top = 0;
}

void Push(Stack &S, infotype x)
{
    if (S.top < 20)
    {
        S.info[S.top] = x;
        S.top = S.top + 1;
    }
    else
    {
        std::cout << "Stack penuh" << std::endl;
    }
}

infotype pop(Stack &S)
{
    if (S.top > 0)
    {
        S.top = S.top - 1;
        return S.info[S.top];
    }
    else
    {
        std::cout << "Stack kosong" << std::endl;
        return -1;
    }
}

void pushAscending(Stack &S, infotype x)
{
    Stack T;
    createStack(T);
    while (S.top > 0 && S.info[S.top - 1] > x)
    {
        Push(T, pop(S));
    }
    Push(S, x);
    while (T.top > 0)
    {
        Push(S, pop(T));
    }
}

void printInfo(const Stack &S)
{
    std::cout << "[TOP] ";
    for (int i = S.top - 1; i >= 0; i = i - 1)
    {
        std::cout << S.info[i];
        if (i > 0) std::cout << " ";
    }
    std::cout << std::endl;
}

void balikStack(Stack &S)
{
    int i = 0;
    int j = S.top - 1;
    while (i < j)
    {
        infotype temp = S.info[i];
        S.info[i] = S.info[j];
        S.info[j] = temp;
        i = i + 1;
        j = j - 1;
    }
}
```

#### [main.cpp]
```C++
#include <iostream>
#include "stack.h"

int main()
{
    std::cout << "Hello world!" << std::endl;

    Stack S;
    createStack(S);
    pushAscending(S,3);
    pushAscending(S,4);
    pushAscending(S,8);
    pushAscending(S,2);
    pushAscending(S,3);
    pushAscending(S,9);
    printInfo(S);
    std::cout << "balik stack" << std::endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan7_Modul7/output-unguided2.png)

Kode ini mengimplementasikan struktur data Stack berbasis array statis (LIFO) dengan fitur unik pushAscending yang menyisipkan elemen secara terurut dari kecil ke besar menggunakan stack bantu, sementara fungsi lain seperti Push, pop, printInfo, dan balikStack menyediakan operasi dasar, yang seluruhnya diuji coba di main.cpp.

### 3. ![Screenshot Unguided 3_1](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan7_Modul7/soal-unguided3.png)

#### [stack.h]
```C++
#ifndef STACK_H
#define STACK_H

typedef int infotype;

struct Stack {
    infotype info[20];
    int top;
};

void createStack(Stack &S);
void Push(Stack &S, infotype x);
infotype pop(Stack &S);
void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);
void printInfo(const Stack &S);
void balikStack(Stack &S);

#endif
```

#### [stack.cpp]
```C++
#include "stack.h"
#include <iostream>

void createStack(Stack &S)
{
    S.top = 0;
}

void Push(Stack &S, infotype x)
{
    if (S.top < 20)
    {
        S.info[S.top] = x;
        S.top = S.top + 1;
    }
    else
    {
        std::cout << "Stack penuh" << std::endl;
    }
}

infotype pop(Stack &S)
{
    if (S.top > 0)
    {
        S.top = S.top - 1;
        return S.info[S.top];
    }
    else
    {
        std::cout << "Stack kosong" << std::endl;
        return -1;
    }
}

void pushAscending(Stack &S, infotype x)
{
    Stack T;
    createStack(T);
    while (S.top > 0 && S.info[S.top - 1] > x)
    {
        Push(T, pop(S));
    }
    Push(S, x);
    while (T.top > 0)
    {
        Push(S, pop(T));
    }
}

void getInputStream(Stack &S)
{
    char ch;
    while (true)
    {
        ch = std::cin.get();
        if (!std::cin)
            break;
        if (ch == '\r')
            continue;
        if (ch == '\n')
            break;
        if (ch >= '0' && ch <= '9')
            Push(S, ch - '0');
        else
            Push(S, ch);
    }
}

void printInfo(const Stack &S)
{
    std::cout << "[TOP] ";
    for (int i = S.top - 1; i >= 0; i = i - 1)
    {
        std::cout << S.info[i];
        if (i > 0) std::cout << " ";
    }
    std::cout << std::endl;
}

void balikStack(Stack &S)
{
    int i = 0;
    int j = S.top - 1;
    while (i < j)
    {
        infotype temp = S.info[i];
        S.info[i] = S.info[j];
        S.info[j] = temp;
        i = i + 1;
        j = j - 1;
    }
}
```

#### [main.cpp]
```C++
#include <iostream>
#include "stack.h"

int main()
{
    std::cout << "Hello world!" << std::endl;
    Stack S;
    createStack(S);
    getInputStream(S);
    printInfo(S);
    std::cout << "balik stack" << std::endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan7_Modul7/output-unguided3.png)

Implementasi Stack berbasis array statis ini menyediakan operasi dasar (LIFO) seperti Push, pop, dan balikStack, fitur khusus pushAscending untuk penyisipan terurut, serta fitur getInputStream yang inovatif untuk membaca dan menyimpan input karakter interaktif dari pengguna ke dalam stack, yang semuanya diuji di main.cpp.

## Kesimpulan
Stack adalah struktur data linear yang fundamental, beroperasi berdasarkan prinsip ketat LIFO (Last-In, First-Out), artinya elemen terakhir yang masuk adalah elemen pertama yang keluar. Operasi pada stack—yaitu Push (memasukkan), Pop (mengeluarkan), dan Top/Peek (melihat elemen teratas)—semuanya dilakukan hanya pada satu ujung yang disebut Top (Puncak), dan memiliki kompleksitas waktu yang sangat efisien, yaitu O(1) (waktu konstan). Dalam C++, stack dapat diimplementasikan secara kustom menggunakan array atau linked list, namun cara yang paling umum dan disarankan adalah menggunakan container adapter std::stack dari Standard Template Library (STL), yang mengadaptasi kontainer lain untuk memaksakan perilaku LIFO ini. Meskipun sederhana dan sangat cepat dalam manipulasi elemen teratas, kekurangan utama stack adalah aksesnya yang terbatas; ia tidak memungkinkan akses acak ke elemen di tengah tumpukan. Namun, aplikasi dan kegunaannya sangat luas dan krusial dalam ilmu komputer. Stack digunakan secara internal oleh kompiler dan sistem operasi untuk manajemen panggilan fungsi dan rekursi. Selain itu, stack menjadi tulang punggung untuk fitur seperti Undo/Redo dalam perangkat lunak, serta dalam evaluasi ekspresi aritmatika dan pemeriksaan sintaks untuk memverifikasi keseimbangan kurung dalam kode. Singkatnya, stack adalah alat vital untuk tugas yang memerlukan penyimpanan dan pengambilan data secara berurutan dan terbalik.

## Referensi
[1] Jain, Harshit. "Applications, Advantages and Disadvantages of Stack." Scribd (dokumen akademis atau publikasi teknis), 2024.

<br>[2] CPlusPlus.com. "std::stack." C++ Reference, 2024.

<br>[3] Programiz. "Stack Data Structure and Implementation in Python, Java and C/C++." Programiz, 2024.