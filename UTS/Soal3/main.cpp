#include "stackmahasiswa.h"
#include <iostream>
using namespace std;

int main() {
    StackMahasiswa StackMHS;
    
    cout << "=== Soal 3: Stack Mahasiswa ===" << endl;
    createStack(StackMHS);
    
    cout << "\n--- Menginput 6 data mahasiswa ---" << endl;
    
    cout << "\nMahasiswa 1:" << endl;
    StackMHS.Top++;
    StackMHS.dataMahasiswa[StackMHS.Top] = {"Venti", "11111", 75.7, 82.1, 65.5};
    cout << "Data Venti berhasil ditambahkan" << endl;
    
    cout << "\nMahasiswa 2:" << endl;
    StackMHS.Top++;
    StackMHS.dataMahasiswa[StackMHS.Top] = {"Xiao", "22222", 87.4, 88.9, 81.9};
    cout << "Data Xiao berhasil ditambahkan" << endl;
    
    cout << "\nMahasiswa 3:" << endl;
    StackMHS.Top++;
    StackMHS.dataMahasiswa[StackMHS.Top] = {"Kazuha", "33333", 92.3, 88.8, 82.4};
    cout << "Data Kazuha berhasil ditambahkan" << endl;
    
    cout << "\nMahasiswa 4:" << endl;
    StackMHS.Top++;
    StackMHS.dataMahasiswa[StackMHS.Top] = {"Wanderer", "44444", 95.5, 85.5, 90.5};
    cout << "Data Wanderer berhasil ditambahkan" << endl;
    
    cout << "\nMahasiswa 5:" << endl;
    StackMHS.Top++;
    StackMHS.dataMahasiswa[StackMHS.Top] = {"Lynette", "55555", 77.7, 65.4, 79.9};
    cout << "Data Lynette berhasil ditambahkan" << endl;
    
    cout << "\nMahasiswa 6:" << endl;
    StackMHS.Top++;
    StackMHS.dataMahasiswa[StackMHS.Top] = {"Chasca", "66666", 99.9, 93.6, 87.3};
    cout << "Data Chasca berhasil ditambahkan" << endl;
    
    cout << "\n--- 3) Tampilkan stack setelah input ---" << endl;
    View(StackMHS);
    
    cout << "\n--- 4) Lakukan Pop 1x ---" << endl;
    Pop(StackMHS);
    
    cout << "\n--- 5) Tampilkan stack setelah Pop ---" << endl;
    View(StackMHS);
    
    cout << "\n--- 6) Update data pada posisi ke-3 ---" << endl;
    StackMHS.dataMahasiswa[2] = {"Heizou", "77777", 99.9, 88.8, 77.7};
    cout << "Data pada posisi 3 berhasil di-update menjadi Heizou" << endl;
    
    cout << "\n--- 7) Tampilkan stack setelah Update ---" << endl;
    View(StackMHS);
    
    cout << "\n--- 8) Searching Mahasiswa dengan Nilai Akhir 85.5 - 95.5 ---" << endl;
    SearchNilaiAkhir(StackMHS, 85.5, 95.5);
    
    cout << "\n--- Bagian B: Mahasiswa dengan Nilai Akhir Tertinggi ---" << endl;
    MaxNilaiAkhir(StackMHS);
    
    return 0;
}