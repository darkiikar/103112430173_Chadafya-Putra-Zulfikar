#include "DLLPlaylist.h"
#include <iostream>
using namespace std;

int main() {
    list L;
    createList(L);
    
    cout << "===== ASSESSMENT STRUKTUR DATA =====" << endl;
    cout << "Doubly Linked List - Playlist Musik" << endl;
    cout << "====================================\n" << endl;
    
    cout << "1. Membuat list kosong (createList)..." << endl;
    cout << "   List berhasil dibuat.\n" << endl;
    
    cout << "2. Menambahkan 3 lagu dengan insertLast..." << endl;
    
    node* song1 = allocate("Senja di Kota", "Nona Band", 210, 150, 4.2);
    insertLast(L, song1);
    cout << "   - Lagu 1: Senja di Kota (Nona Band) ditambahkan" << endl;
    
    node* song2 = allocate("Langkahmu", "Delta", 185, 320, 4.8);
    insertLast(L, song2);
    cout << "   - Lagu 2: Langkahmu (Delta) ditambahkan" << endl;
    
    node* song3 = allocate("Hujan Minggu", "Arka", 240, 90, 3.9);
    insertLast(L, song3);
    cout << "   - Lagu 3: Hujan Minggu (Arka) ditambahkan\n" << endl;
    
    cout << "3. Menampilkan list..." << endl;
    viewList(L);
    cout << endl;
    
    cout << "4. Melakukan deleteLast sebanyak 1x..." << endl;
    delLast(L);
    cout << "   - Lagu terakhir berhasil dihapus\n" << endl;
    
    cout << "5. Menampilkan playlist setelah deleteLast..." << endl;
    viewList(L);
    cout << endl;
    
    cout << "6. Update node pada posisi ke-2..." << endl;
    updateAtPosition(L, 2, "Pelita", "Luna", 200, 260, 4.5);
    cout << "   - Data posisi ke-2 berhasil diupdate ke Pelita (Luna)\n" << endl;
    
    cout << "7. Menampilkan playlist setelah update..." << endl;
    viewList(L);
    cout << endl;
    
    cout << "8. Operasi BEFORE pada node posisi ke-2..." << endl;
    
    cout << "   a. insertBefore pada node posisi 2" << endl;
    node* insertNode = allocate("Senandung", "Mira", 175, 120, 4.0);
    insertBefore(L, L.head->next, insertNode);
    cout << "       - Lagu 'Senandung' berhasil diinsert sebelum node ke-2" << endl;
    
    cout << "       Menampilkan list setelah insertBefore:" << endl;
    viewList(L);
    cout << endl;
    
    cout << "   b. updateBefore pada node posisi 3" << endl;
    node* thirdNode = L.head->next->next;
    updateBefore(L, thirdNode, "Bintang Malam", "Rara", 195, 280, 4.6);
    cout << "       - Data sebelum node ke-3 berhasil diupdate\n" << endl;
    
    cout << "       Menampilkan list setelah updateBefore:" << endl;
    viewList(L);
    cout << endl;
    
    cout << "   c. deleteBefore pada node posisi 4" << endl;
    node* fourthNode = L.head->next->next->next;
    if (fourthNode != nullptr) {
        delBefore(L, fourthNode);
        cout << "       - Node sebelum posisi ke-4 berhasil dihapus" << endl;
    }
    cout << endl;
    
    cout << "9. Menampilkan list akhir sebelum searching..." << endl;
    viewList(L);
    cout << endl;
    
    cout << "10. Searching berdasarkan PopularityScore" << endl;
    cout << "    Min: 150.0, Max: 300.0..." << endl;
    searchByPopularityScore(L, 150.0, 300.0);
    cout << endl;

    cout << "Membersihkan memori..." << endl;
    while (!isEmpty(L)) {
        delFirst(L);
    }
    
    cout << "Memori berhasil dibersihkan." << endl;

    return 0;
}