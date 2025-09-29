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