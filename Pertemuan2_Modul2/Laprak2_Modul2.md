# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>
<p align="center">Chadafya Putra Zulfikar - 103112430173</p>

## Dasar Teori
C++ merupakan bahasa pemrograman yang dikembangkan sebagai perluasan dari C. Bahasa ini mendukung paradigma prosedural dan berorientasi objek, sehingga memungkinkan penulisan program yang lebih terstruktur, modular, dan efisien. Dalam modul lanjutan ini, pembahasan diarahkan pada fitur-fitur yang lebih kompleks dibandingkan pengenalan dasar, seperti penggunaan fungsi, array, pointer, dan struktur kontrol tingkat lanjut.

### 1. Pemrograman Berorientasi Objek (Object-Oriented Programming / OOP) <br/> 
Pemrograman Berorientasi Objek (OOP) adalah sebuah paradigma pemrograman yang didasarkan pada konsep "objek", yang dapat berisi data dalam bentuk field (sering dikenal sebagai atribut atau properti) dan kode dalam bentuk prosedur (sering dikenal sebagai method). Konsep utama dalam OOP meliputi Enkapsulasi (membungkus data dan metode yang bekerja pada data tersebut dalam satu unit), Pewarisan (Inheritance, di mana sebuah kelas dapat mewarisi properti dan metode dari kelas lain), Polimorfisme (kemampuan objek untuk mengambil banyak bentuk), dan Abstraksi (menyembunyikan detail implementasi yang kompleks dan hanya menunjukkan fungsionalitas yang esensial). Dengan menggunakan OOP, program dapat menjadi lebih terstruktur, modular, mudah dikelola, dan dapat digunakan kembali (reusable).

### 2. Struktur Data dan Tipe Data<br/>
Struktur data adalah cara spesifik untuk mengatur, mengelola, dan menyimpan data di komputer agar dapat diakses dan dimodifikasi secara efisien. Contohnya termasuk Array, Linked List, Stack, Queue, Tree, dan Graph. Sementara itu, tipe data adalah klasifikasi yang menentukan nilai apa yang dapat dimiliki oleh suatu variabel dan operasi matematika, relasional, atau logis apa yang dapat diterapkan padanya. Dalam C++, tipe data dasar (primitif) meliputi integer (untuk bilangan bulat, int), floating-point (untuk bilangan desimal, float, double), character (char), dan boolean (bool). Pemilihan tipe dan struktur data yang tepat sangat penting untuk membangun program yang efisien dan andal.

### 3. Kontrol Alur (Control Flow)<br/>
Kontrol alur mengacu pada urutan di mana pernyataan, instruksi, atau pemanggilan fungsi dalam suatu program dieksekusi. Tanpa kontrol alur, program akan berjalan baris per baris dari atas ke bawah. C++ menyediakan berbagai struktur untuk mengendalikan alur eksekusi ini. Struktur tersebut terbagi menjadi tiga kategori utama: percabangan (selection) yang memungkinkan program memilih jalur eksekusi yang berbeda menggunakan if, else if, else, dan switch-case; perulangan (looping) yang memungkinkan eksekusi blok kode berulang kali menggunakan for, while, dan do-while; serta lompatan (jump) yang memungkinkan eksekusi melompat ke bagian lain dari kode menggunakan break, continue, dan goto.

### 4. Fungsi dan Modularitas<br/>
Fungsi adalah blok kode yang terorganisir dan dapat digunakan kembali yang dirancang untuk melakukan satu tugas tertentu. Penggunaan fungsi mendukung prinsip modularitas, yaitu memecah program besar menjadi bagian-bagian yang lebih kecil dan dapat dikelola (modul). Setiap modul atau fungsi memiliki tanggung jawabnya sendiri, sehingga membuat kode lebih mudah untuk ditulis, dipahami, diuji, dan diperbaiki (debug). Dalam C++, sebuah fungsi didefinisikan dengan tipe return, nama fungsi, dan daftar parameter. Pendekatan modular ini meningkatkan keterbacaan kode, mengurangi redundansi, dan memfasilitasi kerja tim dalam proyek pengembangan perangkat lunak yang kompleks.

### 5. Array dan Pointer<br/>
Array adalah struktur data yang digunakan untuk menyimpan kumpulan elemen dengan tipe data yang sama dalam lokasi memori yang berdekatan.Di sisi lain, pointer adalah variabel khusus yang menyimpan alamat memori dari variabel lain. Dalam C++, array dan pointer memiliki hubungan yang sangat erat; nama sebuah array sebenarnya berfungsi sebagai pointer konstan ke elemen pertamanya. Pemahaman tentang pointer sangat penting untuk manajemen memori dinamis, manipulasi array yang efisien, dan untuk meneruskan argumen ke fungsi dengan referensi, yang memungkinkan modifikasi data asli secara langsung.

## Guided 

### 1. Program Input dan Output Array dengan Perulangan for dan while

```C++
#include <iostream>
using namespace std;

int main() {
    int arr[5];

    for (int i = 0; i < 5; i++) {
        cout << "Masukkan value indeks ke-" << i << " : ";
        cin >> arr[i];
    }
    int j = 0;
    while (j < 5) {
        cout << "Isi indeks ke-" << j << " : " << arr[j] << endl;
        j++;
    }
    return 0;
}
```
Program ini merupakan sebuah contoh sederhana yang menunjukkan cara menginput nilai ke dalam array dan menampilkan kembali nilai-nilai tersebut.

### 2. Program Operasi Matriks 2x2 (Penjumlahan dan Perkalian)

```C++
#include <iostream>
using namespace std;

void tampilkanHasil(int arr[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arrA[2][2] = {
        {1, 2},
        {3, 4}
    };
    int arrB[2][2] = {
        {2, 3},
        {4, 5}
    };
    int arrC[2][2] = {0};
    int arrD[2][2] = {0};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "Hasil penjumlahan : " << endl;
    tampilkanHasil(arrC);

    cout << endl;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "Hasil perkalian : " << endl;
    tampilkanHasil(arrD);

    return 0;
}
```
Program ini berfungsi untuk melakukan operasi aritmatika dasar pada matriks berukuran 2×2, yaitu penjumlahan dan perkalian matriks.

### 3. Program Pointer dan Fungsi Pertukaran Nilai (Swap) Menggunakan Referensi Alamat
```C++
#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y; 
    *y = temp;
}

int main() {
    int a = 20, b = 30;
    int *ptr;

    ptr = &a;

    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    cout << "Value stored in ptr (address of a): " << ptr << endl;
    cout << "Value pointed to by ptr: " << *ptr << endl;

    tukar(&a, &b);
    cout << "After swapping, value of a= " << a << " and b=" << b << endl;

    return 0;
}
```
Program ini merupakan demonstrasi tentang penggunaan pointer dalam C++, khususnya untuk mengakses alamat dan nilai dari suatu variabel, dan melakukan operasi pertukaran nilai antar variabel (swapping) menggunakan pointer agar perubahan terjadi pada variabel aslinya (disebut Call by Reference).

### 4. Program Referensi (Reference) dan Fungsi Pertukaran Nilai dengan Parameter Referensi
```C++
#include <iostream>
using namespace std;

void Tukar(int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 20,b = 30;
    int& ref = a;

    cout << "Nilai a: " << a << endl;
    cout << "Alamat a: " << &a << endl;
    cout << "Nilai ref (Alias a): " << ref << endl;
    cout << "Alamat ref (&ref): " << &ref << endl;

    ref = 50;
    cout << "\nSetelah ref = 50; " << a << endl;
    cout << "Nilai a: " << a << endl;
    cout << "Nilai ref: " << ref << endl;

    Tukar(a,b);
    cout << "After swapping, value of a= " << a << " and b=" << b << endl;
    
    return 0;
}
```
Program ini mendemonstrasikan konsep Reference (referensi atau alias) dan penggunaannya dalam fungsi untuk teknik Call by Reference.

### 5. Program Operasi Array: Mencari Nilai Maksimum, Penjumlahan, dan Perkalian Elemen
```C++
#include <iostream>
using namespace std;

int cariMAX(int arr[], int ukuran){
    int MAX = arr[0];
    for (int i = 1; i < ukuran; i++) {
        if (arr[i] > MAX) {
            MAX = arr[i];
        }
    }
    return MAX;
}

void operasiAritmatika(int arr[], int ukuran){
    int totalJumlah = 0;
    for (int i = 0; i < ukuran; i++) {
        totalJumlah += arr[i];
    }
    cout << "Total penjumlahan: " << totalJumlah << endl;

    int totalKali = 1;
    for (int i = 0; i < ukuran; i++) {
        totalKali *= arr[i];
    }
    cout << "Total perkalian: " << totalKali << endl;
}

int main() {
    const int ukuran = 5;
    int arr[ukuran];
    for (int i = 0; i < ukuran; i++) {
        cout << "masukkan nilai array ke-" << i + 1 << ": ";
        cin >> arr[i];
    }
    cout << endl;
    cout << "Nilai terbesar dalam array : " << cariMAX(arr, ukuran) << endl;

    operasiAritmatika(arr, ukuran);
    return 0;
}
```
Program ini berfungsi untuk menginput 5 nilai ke dalam sebuah array, kemudian mencari nilai maksimum, dan terakhir menghitung total penjumlahan serta perkalian dari semua elemen array.

## Unguided 

### 1. Soal Unguided 1
Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan 
perkalian matriks 3x3 

```C++
#include <iostream>
using namespace std;

void tampilkanHasil(int arr[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int arrA[3][3] = {
		{1, 0, 0}, 
		{0, 1, 0},
		{0, 0, 1}
	};
	int arrB[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};
	int arrC[3][3] = {0}; 
	int arrD[3][3] = {0}; 
	int arrE[3][3] = {0}; 

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			arrC[i][j] = arrA[i][j] + arrB[i][j];
		}
	}
	cout << "Hasil penjumlahan : " << endl;
	tampilkanHasil(arrC);
	cout << endl;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			arrD[i][j] = arrA[i][j] - arrB[i][j];
		}
	}
	cout << "Hasil pengurangan : " << endl;
	tampilkanHasil(arrD);
	cout << endl;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				arrE[i][j] += arrA[i][k] * arrB[k][j];
			}
		}
	}
	cout << "Hasil perkalian : " << endl;
	tampilkanHasil(arrE);

	return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/darkiikar/103112430137_Chadafya-Putra-Zulfikar/blob/main/Pertemuan2_Modul2/Unguided1.png)

Program ini melakukan ooperasi aritmatika dasar (penjumlahan, pengurangan, dan perkalian) pada dua matriks berukuran 3×3.

### 2. Soal Unguided 2
Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat 
menukar nilai dari 3 variabel 

```C++
#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void tukar3(int *x, int *y, int *z) {
    int temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

int main() {
    int a = 10, b = 20, c = 30;
    int *ptr;

    ptr = &a;

    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    cout << "Value stored in ptr (address of a): " << ptr << endl;
    cout << "Value pointed to by ptr: " << *ptr << endl;

    cout << "Before swapping: a=" << a << ", b=" << b << ", c=" << c << endl;
    tukar3(&a, &b, &c);
    cout << "After swapping: a=" << a << ", b=" << b << ", c=" << c << endl;

    return 0;
}
```
### Output Unguided 2_1 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/darkiikar/103112430173_Chadafya-Putra_Zulfikar/blob/main/Pertemuan2_Modul2/Unguided2.png)

Program ini mendemonstrasikan penggunaan pointer untuk memanipulasi data dan melakukan operasi seperti pertukaran nilai (swapping) pada variabel asli.

```C++
#include <iostream>
using namespace std;

void Tukar(int &x, int &y) {
	int temp;
	temp = x;
	x = y;
	y = temp;
}

void Tukar3(int &x, int &y, int &z) {
	int temp = x;
	x = y;
	y = z;
	z = temp;
}

int main() {
	int a = 10, b = 20, c = 30;
	int& ref = a;

	cout << "Nilai a: " << a << endl;
	cout << "Alamat a: " << &a << endl;
	cout << "Nilai ref (Alias a): " << ref << endl;
	cout << "Alamat ref (&ref): " << &ref << endl;

	ref = 50;
	cout << "\nSetelah ref = 50; " << a << endl;
	cout << "Nilai a: " << a << endl;
	cout << "Nilai ref: " << ref << endl;

	cout << "Sebelum Tukar3: a=" << a << ", b=" << b << ", c=" << c << endl;
	Tukar3(a, b, c);
	cout << "Setelah Tukar3: a=" << a << ", b=" << b << ", c=" << c << endl;

	return 0;
}
```
### Output Unguided 2.2 :

##### Output 1
![Screenshot Output Unguided 2_2](https://github.com/darkiikar/103112430173_Chadafya-Putra_Zulfikar/blob/main/pertemuan2_modul2/Unguided2_2.png)

Program ini menampilkan cara kerja reference sebagai alias variabel, bagaimana perubahan melalui reference memengaruhi nilai asli, serta penggunaan fungsi Tukar dan Tukar3 dengan parameter referensi untuk menukar isi dua maupun tiga variabel sekaligus.

### 3. Soal Unguided 3
Diketahui sebuah array 1 dimensi sebagai berikut :  
arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55} 
Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari 
array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan 
function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur 
hitungRataRata() untuk menghitung nilai rata – rata! Buat program menggunakan 
menu switch-case seperti berikut ini 

--- Menu Program Array --- 
1. Tampilkan isi array 
2. cari nilai maksimum 
3. cari nilai minimum 
4. Hitung nilai rata - rata

```C++
#include <iostream>
using namespace std;

int cariMinimum(int arr[], int n) {
	int min = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] < min) min = arr[i];
	}
	return min;
}

int cariMaksimum(int arr[], int n) {
	int max = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > max) max = arr[i];
	}
	return max;
}

void hitungRataRata(int arr[], int n) {
	float total = 0;
	for (int i = 0; i < n; i++) {
		total += arr[i];
	}
	cout << "Nilai rata-rata: " << total/n << endl;
}

void tampilkanArray(int arr[], int n) {
	cout << "Isi array: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arrA[] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
	int n = sizeof(arrA)/sizeof(arrA[0]);
	int pilihan;
	do {
		cout << "\n--- Menu Program Array ---" << endl;
		cout << "1. Tampilkan isi array" << endl;
		cout << "2. cari nilai maksimum" << endl;
		cout << "3. cari nilai minimum" << endl;
		cout << "4. Hitung nilai rata - rata" << endl;
		cout << "0. Keluar" << endl;
		cout << "Pilih menu: ";
		cin >> pilihan;
		switch(pilihan) {
			case 1:
				tampilkanArray(arrA, n);
				break;
			case 2:
				cout << "Nilai maksimum: " << cariMaksimum(arrA, n) << endl;
				break;
			case 3:
				cout << "Nilai minimum: " << cariMinimum(arrA, n) << endl;
				break;
			case 4:
				hitungRataRata(arrA, n);
				break;
			case 0:
				cout << "Keluar program." << endl;
				break;
			default:
				cout << "Menu tidak valid!" << endl;
		}
	} while(pilihan != 0);
	return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/darkiikar/103112430173_Chadafya-Putra-ZUlfikar/blob/main/Pertemuan2_Modul2/Unguided3.png)

Program ini merupakan sebuah aplikasi menu interaktif sederhana untuk melakukan analisis statistik dasar pada sebuah array bilangan bulat yang telah ditentukan.

## Kesimpulan
Bahasa pemrograman C++ merupakan bahasa yang kuat karena mendukung paradigma prosedural maupun berorientasi objek, sehingga dapat digunakan untuk membangun perangkat lunak yang kompleks, modular, dan efisien. Konsep-konsep dasar seperti tipe data, struktur kontrol, fungsi, array, dan pointer menjadi fondasi penting dalam memahami pemrograman C++.

Pemilihan tipe data yang tepat berpengaruh terhadap efisiensi memori dan kinerja program, sementara struktur kontrol dan fungsi mendukung pengembangan algoritma yang lebih sistematis serta modular. Array dan pointer memberikan fleksibilitas tinggi dalam pengolahan data, meskipun membutuhkan kehati-hatian untuk mencegah kesalahan memori.

Secara keseluruhan, penguasaan teori dasar C++ ini menjadi bekal penting untuk mempelajari materi lanjutan seperti struktur data, algoritma, hingga pemrograman berorientasi objek secara mendalam. Dengan pemahaman yang baik, mahasiswa maupun praktisi dapat mengembangkan perangkat lunak yang lebih terstruktur, dapat dipelihara, serta memiliki kinerja yang optimal.

## Referensi
[1] Stroustrup, B. (2013). The C++ Programming Language (4th ed.). Addison-Wesley Professional.

[2] Weiss, M. A. (2014). Data Structures and Algorithm Analysis in C++ (4th ed.). Pearson.

[3] Lippman, S. B., Lajoie, J., & Moo, B. E. (2012). C++ Primer (5th ed.). Addison-Wesley Professional.

[4] Meyers, S. (2005). Effective C++: 55 Specific Ways to Improve Your Programs and Designs (3rd ed.). Addison-Wesley Professional.

[5] Lafore, R. (2002). Object-Oriented Programming in C++ (4th ed.). Sams Publishing.
<br>...