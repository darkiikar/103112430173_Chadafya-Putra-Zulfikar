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