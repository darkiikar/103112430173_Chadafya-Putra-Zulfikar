#include <iostream>
#include <iomanip>
using namespace std;

void tampilkanArray(int arr[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << std::setw(4) << arr[i][j];
        }
        std::cout << '\n';
    }
}

void tukarElem(int arr1[3][3], int arr2[3][3], int i, int j) {
    if (i < 0 || i >= 3 || j < 0 || j >= 3) return;
    int tmp = arr1[i][j];
    arr1[i][j] = arr2[i][j];
    arr2[i][j] = tmp;
}

void tukarPointer(int *p, int *q) {
    if (!p || !q) return;
    int tmp = *p;
    *p = *q;
    *q = tmp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };

    int x = 100;
    int y = 200;
    int *px = &x;
    int *py = &y;

    std::cout << "Array A awal:\n";
    tampilkanArray(A);
    std::cout << "\nArray B awal:\n";
    tampilkanArray(B);

    std::cout << "\nMenukar elemen A[1][1] dengan B[1][1] (indeks 1,1 = baris kedua kolom kedua)\n";
    tukarElem(A, B, 1, 1);

    std::cout << "Array A setelah tukar:\n";
    tampilkanArray(A);
    std::cout << "\nArray B setelah tukar:\n";
    tampilkanArray(B);

    std::cout << "\nNilai sebelum tukar via pointer: x=" << x << ", y=" << y << '\n';
    tukarPointer(px, py);
    std::cout << "Nilai setelah tukar via pointer: x=" << x << ", y=" << y << '\n';

    return 0;
}