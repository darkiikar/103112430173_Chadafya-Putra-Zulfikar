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