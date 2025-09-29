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