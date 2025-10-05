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