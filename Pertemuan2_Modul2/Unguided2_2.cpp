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
	int a =10, b = 20, c = 30;
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