# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Chadafya Putra Zulfikar - 103112430173</p>

## Dasar Teori
Code block (atau compound statement, blok kode) adalah suatu struktur leksikal dalam kode sumber di mana beberapa pernyataan (statements) dan/atau deklarasi dikelompokkan bersama menjadi satu kesatuan. Blok kode biasanya dibatasi oleh tanda tertentu (misalnya kurung kurawal { … } dalam C, C++, Java) atau dengan indentasi (misalnya di Python)[1].

### A. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

### B. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

## Guided 

### 1. Introduction C++

```C++
#include <iostream>

using namespace std;
int main() {
    cout << "Hello, World!" << endl;
    return 0;
}
```
Program ini biasanya sebagai pengenalan materi awal yang hanya menampilkan dengan bertuliskan "Hellow, World!"

### 2. Perulangan Menggunakan While

```C++
#include <iostream>
using namespace std;
int main() {
    int i=1;
    int jum;
    cout << "Masukkan jumlah baris: ";
    cin >> jum;
    while (i <= jum) {
        cout << "Baris ke-" << i << endl;
        i++;
    }
    return 0;
}
```
Program ini merupakan perulangan dengan menggunakan While, user diminta untuk memasukkan jumlah baris yang di inginkan. Setelah itu program akan menghasilkan jumlah baris sesuai dengan input user.

### 3. Program Struct Input dan Cetak Data Raport Siswa

```C++
#include <iostream>
#include <iomanip>
using namespace std;

struct Raport {
	char nama[50];
	int nis;
	float matematika;
	float bahasaIndonesia;
	float bahasaInggris;
	float ipa;
};

int main() {
	int jumlah;
	cout << "Masukkan jumlah siswa: ";
	cin >> jumlah;
	cin.ignore(); 

	Raport siswa[100]; 

	for (int i = 0; i < jumlah; i++) {
		cout << "\nData siswa ke-" << i+1 << ":\n";
		cout << "Nama: ";
		cin.getline(siswa[i].nama, 50);
		cout << "NIS: ";
		cin >> siswa[i].nis;
		cout << "Nilai Matematika: ";
		cin >> siswa[i].matematika;
		cout << "Nilai Bahasa Indonesia: ";
		cin >> siswa[i].bahasaIndonesia;
		cout << "Nilai Bahasa Inggris: ";
		cin >> siswa[i].bahasaInggris;
		cout << "Nilai IPA: ";
		cin >> siswa[i].ipa;
		cin.ignore(); 
	}

	cout << "\n--- Data Raport Siswa ---\n";
	cout << left << setw(20) << "Nama" << setw(10) << "NIS" << setw(10) << "Mat" << setw(10) << "B.Ind" << setw(10) << "B.Ing" << setw(10) << "IPA" << setw(10) << "Rata2" << endl;
	for (int i = 0; i < jumlah; i++) {
		float rata2 = (siswa[i].matematika + siswa[i].bahasaIndonesia + siswa[i].bahasaInggris + siswa[i].ipa) / 4.0;
		cout << left << setw(20) << siswa[i].nama << setw(10) << siswa[i].nis << setw(10) << siswa[i].matematika << setw(10) << siswa[i].bahasaIndonesia << setw(10) << siswa[i].bahasaInggris << setw(10) << siswa[i].ipa << setw(10) << rata2 << endl;
	}

	return 0;
}
```
Program ini bertujuan untuk menginput nilai siswa menggunakan Struck dan For. User diminta untuk memasukkan jumlah siswa, setelah itu program akan meminta user untuk memasukkan data siswa seperti Nama, NIS, Nilai Matematikan, Nilai Bahasa Indonesia, Nilai Bahasa Inggris dan Nilai IPA. Terakhir program akan menampilkan data siswa berbentuk seperti tabel.

## Unguided 

### 1. Unguided 1

```C++
#include <iostream>
using namespace std;

int main() {
	float a, b;
	cout << "Masukkan bilangan pertama: ";
	cin >> a;
	cout << "Masukkan bilangan kedua: ";
	cin >> b;

	cout << "Hasil Penjumlahan: " << (a + b) << endl;
	cout << "Hasil Pengurangan: " << (a - b) << endl;
	cout << "Hasil Perkalian: " << (a * b) << endl;
	if (b != 0)
		cout << "Hasil Pembagian: " << (a / b) << endl;
	else
		cout << "Hasil Pembagian: Tidak dapat membagi dengan nol." << endl;

	return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan1_Modul1/Unguided1.png)

Program ini merupakan perhitungan sederhana dengan menggnakan metode penjumlahan, pengurangan, perkalian, dan pembagian. User diminta untuk memasukkan 2 bilangan, setelah itu program akan menampilkan output. 

### 2. Soal Unguided 2

```C++
#include <iostream>
using namespace std;

string angkaKeTulisan(int n) {
	string satuan[] = {"Nol", "Satu", "Dua", "Tiga", "Empat", "Lima", "Enam", "Tujuh", "Delapan", "Sembilan", "Sepuluh", "Sebelas", "Dua belas", "Tiga belas", "Empat belas", "Lima belas", "Enam belas", "Tujuh belas", "Delapan belas", "Sembilan belas"};
	string puluhan[] = {"", "", "Dua puluh", "Tiga puluh", "Empat puluh", "Lima puluh", "Enam puluh", "Tujuh puluh", "Delapan puluh", "Sembilan puluh"};

	if (n < 0 || n > 100)
		return "Angka di luar jangkauan";
	if (n < 20)
		return satuan[n];
	if (n == 100)
		return "seratus";
	int puluh = n / 10;
	int satu = n % 10;
	string hasil = puluhan[puluh];
	if (satu > 0)
		hasil += " " + satuan[satu];
	return hasil;
}

int main() {
	int angka;
	cout << "Masukkan angka (0-100): ";
	cin >> angka;
	cout << angka << " : " << angkaKeTulisan(angka) << endl;
	return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/darkiikar/1031124230173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan1_Modul1/Unguided2.png)

Program ini berfungsi untuk menjabarkan angka ke tulisan. User diminta untuk memasukkan angka rentan 1-100, setelah itu program akan mengeluarkan hasil.

### 3. Soal Unguided 3

```C++
#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "input: ";
	cin >> n;
	cout << "output:\n";

	for (int i = n; i >= 1; i--) {
		
		for (int j = i; j >= 1; j--) {
			cout << j << " ";
		}
	
		cout << "* ";
		
		for (int j = 1; j <= i; j++) {
			cout << j << " ";
		}
		cout << endl;
	}

	cout << "*" << endl;
	return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/darkiikar/103112430173_Chadafya-Putra-Zulfikar/blob/main/Pertemuan1_Modul1/Unguided3.png)

Program ini berfungsi untuk mencetak pola segitiga terbalik.

## Kesimpulan
Materi ini mencakup perkenalan C++, While, Struct, For, dan IF. Dalam konteks rekayasa perangkat lunak, pemahaman terhadap blok kode berperan penting dalam praktik code review, refactoring, dan pengukuran kompleksitas perangkat lunak.

## Referensi
[1] SSchantong, B., Siegmund, N., & Siegmund, J. (2024). Toward a theory on programmer’s block inspired by writer’s block. Empirical Software Engineering.
