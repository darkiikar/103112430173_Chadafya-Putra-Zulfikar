#include "sllinventory.h"
#include <iostream>
#include <iomanip>
using namespace std;

bool isEmpty(List L) {
    return L.head == NULL;
}

void createList(List& L) {
    L.head = NULL;
}

InventoryItem* allocate(string nama, string sku, int jumlah, float hargaSatuan, float diskonPersen) {
    InventoryItem* P = new InventoryItem();
    P->Nama = nama;
    P->SKU = sku;
    P->jumlah = jumlah;
    P->harga_satuan = hargaSatuan;
    P->DiskonPersen = diskonPersen;
    P->next = NULL;
    return P;
}

void deallocate(InventoryItem*& P) {
    delete P;
    P = NULL;
}

void insertFirst(List& L, InventoryItem* P) {
    if (isEmpty(L)) {
        L.head = P;
    } else {
        P->next = L.head;
        L.head = P;
    }
}

void insertLast(List& L, InventoryItem* P) {
    if (isEmpty(L)) {
        L.head = P;
    } else {
        InventoryItem* Q = L.head;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertAfter(List& L, InventoryItem* Q, InventoryItem* P) {
    if (Q != NULL) {
        P->next = Q->next;
        Q->next = P;
    }
}

InventoryItem* deleteFirst(List& L) {
    InventoryItem* P;
    if (!isEmpty(L)) {
        P = L.head;
        L.head = L.head->next;
        P->next = NULL;
        return P;
    }
    return NULL;
}

InventoryItem* deleteLast(List& L) {
    if (isEmpty(L)) {
        return NULL;
    }
    if (L.head->next == NULL) {
        InventoryItem* P = L.head;
        L.head = NULL;
        P->next = NULL;
        return P;
    }
    InventoryItem* Q = L.head;
    InventoryItem* P = NULL;
    while (Q->next != NULL) {
        P = Q;
        Q = Q->next;
    }
    P->next = NULL;
    Q->next = NULL;
    return Q;
}

InventoryItem* deleteAfter(List& L, InventoryItem* Q) {
    if (Q != NULL && Q->next != NULL) {
        InventoryItem* P = Q->next;
        Q->next = P->next;
        P->next = NULL;
        return P;
    }
    return NULL;
}

void updateAtPosition(List& L, int posisi, string nama, string sku, int jumlah, float hargaSatuan, float diskonPersen) {
    int i = 1;
    InventoryItem* P = L.head;
    while (i < posisi && P != NULL) {
        P = P->next;
        i++;
    }
    if (P != NULL) {
        P->Nama = nama;
        P->SKU = sku;
        P->jumlah = jumlah;
        P->harga_satuan = hargaSatuan;
        P->DiskonPersen = diskonPersen;
    }
}

void viewList(List L) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
        return;
    }
    
    cout << "\n========== DATA INVENTORY ==========" << endl;
    cout << left << setw(3) << "No" 
         << setw(15) << "Nama" 
         << setw(10) << "SKU" 
         << setw(8) << "Jumlah" 
         << setw(12) << "Harga/Stuan" 
         << setw(10) << "Diskon %" 
         << setw(12) << "Harga Akhir" << endl;
    cout << "===================================" << endl;
    
    int no = 1;
    InventoryItem* P = L.head;
    while (P != NULL) {
        float hargaAkhir = P->harga_satuan * (1 - P->DiskonPersen / 100);
        cout << left << setw(3) << no 
             << setw(15) << P->Nama 
             << setw(10) << P->SKU 
             << setw(8) << P->jumlah 
             << setw(12) << fixed << setprecision(2) << P->harga_satuan 
             << setw(10) << P->DiskonPersen 
             << setw(12) << hargaAkhir << endl;
        P = P->next;
        no++;
    }
    cout << "===================================" << endl;
}

void searchByFinalPriceRange(List L, float minPrice, float maxPrice) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
        return;
    }
    
    cout << "\n========== HASIL PENCARIAN ==========" << endl;
    cout << "Range Harga: " << minPrice << " - " << maxPrice << endl;
    cout << left << setw(3) << "No" 
         << setw(15) << "Nama" 
         << setw(10) << "SKU" 
         << setw(8) << "Jumlah" 
         << setw(12) << "Harga/Stuan" 
         << setw(10) << "Diskon %" 
         << setw(12) << "Harga Akhir" << endl;
    cout << "====================================" << endl;
    
    int no = 1;
    int found = 0;
    InventoryItem* P = L.head;
    while (P != NULL) {
        float hargaAkhir = P->harga_satuan * (1 - P->DiskonPersen / 100);
        if (hargaAkhir >= minPrice && hargaAkhir <= maxPrice) {
            cout << left << setw(3) << no 
                 << setw(15) << P->Nama 
                 << setw(10) << P->SKU 
                 << setw(8) << P->jumlah 
                 << setw(12) << fixed << setprecision(2) << P->harga_satuan 
                 << setw(10) << P->DiskonPersen 
                 << setw(12) << hargaAkhir << endl;
            found++;
            no++;
        }
        P = P->next;
    }
    
    if (found == 0) {
        cout << "Tidak ada produk dalam rentang harga tersebut." << endl;
    }
    cout << "====================================" << endl;
}

void maxHargaAkhir(List L) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
        return;
    }
    
    InventoryItem* maxNode = L.head;
    float maxPrice = L.head->harga_satuan * (1 - L.head->DiskonPersen / 100);

    InventoryItem* P = L.head->next;
    while (P != NULL) {
        float hargaAkhir = P->harga_satuan * (1 - P->DiskonPersen / 100);
        if (hargaAkhir > maxPrice) {
            maxPrice = hargaAkhir;
            maxNode = P;
        }
        P = P->next;
    }
    
    cout << "\n========== HARGA AKHIR TERTINGGI ==========" << endl;
    cout << "Nama        : " << maxNode->Nama << endl;
    cout << "SKU         : " << maxNode->SKU << endl;
    cout << "Jumlah      : " << maxNode->jumlah << endl;
    cout << "Harga Satuan: " << fixed << setprecision(2) << maxNode->harga_satuan << endl;
    cout << "Diskon (%)  : " << maxNode->DiskonPersen << endl;
    cout << "Harga Akhir : " << maxPrice << endl;
    cout << "==========================================" << endl;
}