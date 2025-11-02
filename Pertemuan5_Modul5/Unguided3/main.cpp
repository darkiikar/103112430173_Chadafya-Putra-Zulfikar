#include "listAngka.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    CreateList(L);

    insertLast(L, alokasi(50));
    insertLast(L, alokasi(20));
    insertLast(L, alokasi(25));
    insertLast(L, alokasi(29));
    insertLast(L, alokasi(45));

    cout << "List: ";
    printList(L);

    long long totalSum = SumList(L);
    long long totalSub = SubtractList(L);
    long long totalMul = MultiplyList(L);

    cout << "\nTotal penjumlahan : " << totalSum << endl << endl;
    cout << "Total pengurangan : " << totalSub << endl << endl;
    cout << "Total perkalian : " << totalMul << endl;

    while (L.First != nullptr) {
        address temp = L.First;
        L.First = L.First->Next;
        dealokasi(temp);
    }

    return 0;
}