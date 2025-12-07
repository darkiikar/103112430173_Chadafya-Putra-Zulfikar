#ifndef SSLINVENTORY_H
#define SSLINVENTORY_H

#include <iostream>
using namespace std;

struct InventoryItem {
    string Nama;
    string SKU;
    int jumlah;
    float harga_satuan;
    float DiskonPersen;
    InventoryItem* next;
};

struct List {
    InventoryItem* head;
};

bool isEmpty(List L);
void createList(List& L);
InventoryItem* allocate(string nama, string sku, int jumlah, float hargaSatuan, float diskonPersen);
void deallocate(InventoryItem*& P);
void insertFirst(List& L, InventoryItem* P);
void insertLast(List& L, InventoryItem* P);
void insertAfter(List& L, InventoryItem* Q, InventoryItem* P);
InventoryItem* deleteFirst(List& L);
InventoryItem* deleteLast(List& L);
InventoryItem* deleteAfter(List& L, InventoryItem* Q);
void updateAtPosition(List& L, int posisi, string nama, string sku, int jumlah, float hargaSatuan, float diskonPersen);
void viewList(List L);
void searchByFinalPriceRange(List L, float minPrice, float maxPrice);
void maxHargaAkhir(List L);

#endif