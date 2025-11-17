#include "sllinventory.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    createList(L);
    cout << "===== ASSESSMENT STRUKTUR DATA =====" << endl;
    cout << "Single Linked List - Inventory Toko" << endl;
    cout << "====================================\n" << endl;
    
    cout << "1. Membuat list kosong..." << endl;
    cout << "List berhasil dibuat.\n" << endl;
    
    cout << "2. Menambahkan 3 produk dengan insertLast..." << endl;
    
    InventoryItem* item1 = allocate("Pulpen", "A001", 20, 2500, 0);
    insertLast(L, item1);
    cout << "   - Produk 1: Pulpen ditambahkan" << endl;
    
    InventoryItem* item2 = allocate("Buku Tulis", "A002", 15, 5000, 10);
    insertLast(L, item2);
    cout << "   - Produk 2: Buku Tulis ditambahkan" << endl;
    
    InventoryItem* item3 = allocate("Penghapus", "A003", 30, 1500, 0);
    insertLast(L, item3);
    cout << "   - Produk 3: Penghapus ditambahkan\n" << endl;
    
    cout << "3. Menampilkan list..." << endl;
    viewList(L);
    cout << endl;
    
    cout << "4. Melakukan deleteFirst..." << endl;
    InventoryItem* deletedItem = deleteFirst(L);
    if (deletedItem != NULL) {
        cout << "   - " << deletedItem->Nama << " berhasil dihapus" << endl;
        deallocate(deletedItem);
    }
    cout << endl;
    
    cout << "5. Menampilkan list setelah deleteFirst..." << endl;
    viewList(L);
    cout << endl;
    
    cout << "6. Update data pada posisi ke-2..." << endl;
    updateAtPosition(L, 1, "Stabilo", "A010", 40, 9000, 5);
    cout << "   - Data posisi ke-1 berhasil diupdate ke Stabilo\n" << endl;
    
    cout << "7. Menampilkan list setelah update..." << endl;
    viewList(L);
    cout << endl;
    
    cout << "8. Melakukan pencarian berdasarkan rentang harga akhir (2000-7000)..." << endl;
    searchByFinalPriceRange(L, 2000, 7000);
    cout << endl;
    
    cout << "Bagian B: Menampilkan produk dengan harga akhir terbesar..." << endl;
    maxHargaAkhir(L);
    cout << endl;
    
    cout << "Membersihkan memori..." << endl;
    while (!isEmpty(L)) {
        InventoryItem* temp = deleteFirst(L);
        if (temp != NULL) {
            deallocate(temp);
        }
    }
    cout << "Program selesai." << endl;
    
    return 0;
}