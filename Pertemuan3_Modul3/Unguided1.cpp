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