#include "stackmahasiswa.h"
#include <iostream>
#include <iomanip>
using namespace std;

bool isEmpty(StackMahasiswa &StackMHS) {
    return StackMHS.Top == -1;
}

bool isFull(StackMahasiswa &StackMHS) {
    return StackMHS.Top == MAX - 1;
}

void createStack(StackMahasiswa &StackMHS) {
    StackMHS.Top = -1;
    cout << "Stack berhasil dibuat (kosong)!" << endl;
}

void Push(StackMahasiswa &StackMHS) {
    if (isFull(StackMHS)) {
        cout << "Stack penuh! Tidak dapat menambah data." << endl;
        return;
    }
    
    Mahasiswa mhs;
    cout << "\n=== Input Data Mahasiswa ===" << endl;
    cout << "Nama: ";
    cin.ignore();
    getline(cin, mhs.Nama);
    cout << "NIM: ";
    getline(cin, mhs.NIM);
    cout << "Nilai Tugas: ";
    cin >> mhs.NilaiTugas;
    cout << "Nilai UTS: ";
    cin >> mhs.NilaiUTS;
    cout << "Nilai UAS: ";
    cin >> mhs.NilaiUAS;
    
    StackMHS.Top++;
    StackMHS.dataMahasiswa[StackMHS.Top] = mhs;
    cout << "Data berhasil di-push ke stack!" << endl;
}

void Pop(StackMahasiswa &StackMHS) {
    if (isEmpty(StackMHS)) {
        cout << "Stack kosong! Tidak ada data untuk di-pop." << endl;
        return;
    }
    
    cout << "\n=== Data yang di-Pop ===" << endl;
    cout << "Nama: " << StackMHS.dataMahasiswa[StackMHS.Top].Nama << endl;
    cout << "NIM: " << StackMHS.dataMahasiswa[StackMHS.Top].NIM << endl;
    cout << "Nilai Tugas: " << StackMHS.dataMahasiswa[StackMHS.Top].NilaiTugas << endl;
    cout << "Nilai UTS: " << StackMHS.dataMahasiswa[StackMHS.Top].NilaiUTS << endl;
    cout << "Nilai UAS: " << StackMHS.dataMahasiswa[StackMHS.Top].NilaiUAS << endl;
    
    StackMHS.Top--;
    cout << "Data berhasil di-pop dari stack!" << endl;
}

void Update(StackMahasiswa &StackMHS, int posisi) {
    if (isEmpty(StackMHS)) {
        cout << "Stack kosong! Tidak ada data untuk di-update." << endl;
        return;
    }
    
    if (posisi < 1 || posisi > StackMHS.Top + 1) {
        cout << "Posisi tidak valid!" << endl;
        return;
    }
    
    int index = posisi - 1;
    cout << "\n=== Update Data Mahasiswa pada Posisi " << posisi << " ===" << endl;
    cout << "Nama baru: ";
    cin.ignore();
    getline(cin, StackMHS.dataMahasiswa[index].Nama);
    cout << "NIM baru: ";
    getline(cin, StackMHS.dataMahasiswa[index].NIM);
    cout << "Nilai Tugas baru: ";
    cin >> StackMHS.dataMahasiswa[index].NilaiTugas;
    cout << "Nilai UTS baru: ";
    cin >> StackMHS.dataMahasiswa[index].NilaiUTS;
    cout << "Nilai UAS baru: ";
    cin >> StackMHS.dataMahasiswa[index].NilaiUAS;
    
    cout << "Data berhasil di-update!" << endl;
}

void View(StackMahasiswa &StackMHS) {
    if (isEmpty(StackMHS)) {
        cout << "Stack kosong! Tidak ada data untuk ditampilkan." << endl;
        return;
    }
    
    cout << "\n=== Isi Stack Mahasiswa ===" << endl;
    cout << fixed << setprecision(1);
    cout << "---------------------------------------------------------------" << endl;
    cout << "Pos | Nama       | NIM   | N.Tugas | N.UTS | N.UAS | N.Akhir" << endl;
    cout << "---------------------------------------------------------------" << endl;
    
    for (int i = StackMHS.Top; i >= 0; i--) {
        float nilaiAkhir = 0.2 * StackMHS.dataMahasiswa[i].NilaiTugas +
                          0.4 * StackMHS.dataMahasiswa[i].NilaiUTS +
                          0.4 * StackMHS.dataMahasiswa[i].NilaiUAS;
        
        cout << setw(3) << (i + 1) << " | "
             << setw(10) << left << StackMHS.dataMahasiswa[i].Nama << " | "
             << setw(5) << StackMHS.dataMahasiswa[i].NIM << " | "
             << setw(7) << right << StackMHS.dataMahasiswa[i].NilaiTugas << " | "
             << setw(5) << StackMHS.dataMahasiswa[i].NilaiUTS << " | "
             << setw(5) << StackMHS.dataMahasiswa[i].NilaiUAS << " | "
             << setw(7) << nilaiAkhir << endl;
    }
    cout << "---------------------------------------------------------------" << endl;
}

void SearchNilaiAkhir(StackMahasiswa &StackMHS, float NilaiAkhirMin, float NilaiAkhirMax) {
    if (isEmpty(StackMHS)) {
        cout << "Stack kosong! Tidak ada data untuk dicari." << endl;
        return;
    }
    
    cout << "\n=== Pencarian Mahasiswa dengan Nilai Akhir " 
         << NilaiAkhirMin << " - " << NilaiAkhirMax << " ===" << endl;
    cout << fixed << setprecision(1);
    cout << "---------------------------------------------------------------" << endl;
    cout << "Pos | Nama       | NIM   | N.Tugas | N.UTS | N.UAS | N.Akhir" << endl;
    cout << "---------------------------------------------------------------" << endl;
    
    bool found = false;
    for (int i = StackMHS.Top; i >= 0; i--) {
        float nilaiAkhir = 0.2 * StackMHS.dataMahasiswa[i].NilaiTugas +
                          0.4 * StackMHS.dataMahasiswa[i].NilaiUTS +
                          0.4 * StackMHS.dataMahasiswa[i].NilaiUAS;
        
        if (nilaiAkhir >= NilaiAkhirMin && nilaiAkhir <= NilaiAkhirMax) {
            cout << setw(3) << (i + 1) << " | "
                 << setw(10) << left << StackMHS.dataMahasiswa[i].Nama << " | "
                 << setw(5) << StackMHS.dataMahasiswa[i].NIM << " | "
                 << setw(7) << right << StackMHS.dataMahasiswa[i].NilaiTugas << " | "
                 << setw(5) << StackMHS.dataMahasiswa[i].NilaiUTS << " | "
                 << setw(5) << StackMHS.dataMahasiswa[i].NilaiUAS << " | "
                 << setw(7) << nilaiAkhir << endl;
            found = true;
        }
    }
    
    if (!found) {
        cout << "Tidak ada mahasiswa dengan nilai akhir dalam rentang tersebut." << endl;
    }
    cout << "---------------------------------------------------------------" << endl;
}

void MaxNilaiAkhir(StackMahasiswa &StackMHS) {
    if (isEmpty(StackMHS)) {
        cout << "Stack kosong! Tidak ada data untuk ditampilkan." << endl;
        return;
    }
    
    float maxNilai = -1;
    int maxIndex = -1;
    
    for (int i = 0; i <= StackMHS.Top; i++) {
        float nilaiAkhir = 0.2 * StackMHS.dataMahasiswa[i].NilaiTugas +
                          0.4 * StackMHS.dataMahasiswa[i].NilaiUTS +
                          0.4 * StackMHS.dataMahasiswa[i].NilaiUAS;
        
        if (nilaiAkhir > maxNilai) {
            maxNilai = nilaiAkhir;
            maxIndex = i;
        }
    }
    
    cout << "\n=== Mahasiswa dengan Nilai Akhir Tertinggi ===" << endl;
    cout << fixed << setprecision(1);
    cout << "Nama: " << StackMHS.dataMahasiswa[maxIndex].Nama << endl;
    cout << "NIM: " << StackMHS.dataMahasiswa[maxIndex].NIM << endl;
    cout << "Nilai Tugas: " << StackMHS.dataMahasiswa[maxIndex].NilaiTugas << endl;
    cout << "Nilai UTS: " << StackMHS.dataMahasiswa[maxIndex].NilaiUTS << endl;
    cout << "Nilai UAS: " << StackMHS.dataMahasiswa[maxIndex].NilaiUAS << endl;
    cout << "Nilai Akhir: " << maxNilai << endl;
    cout << "Posisi di Stack: " << (maxIndex + 1) << endl;
}