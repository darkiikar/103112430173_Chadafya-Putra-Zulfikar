#include "queuepengiriman.h"
#include <iostream>
using namespace std;

int main() {
    QueueEkspedisi Q;
    createQueue(Q);
    int pilihan;
    
    cout << "====== SISTEM ANTRIAN PAKET EKSPEDISI KOMANIYA EXPRESS ======" << endl << endl;
    
    while (true) {
        cout << "Menu Utama:" << endl;
        cout << "1. Input Data Paket" << endl;
        cout << "2. Hapus Data Paket" << endl;
        cout << "3. Tampilkan Queue Paket" << endl;
        cout << "4. Hitung Total Biaya Pengiriman" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan anda : ";
        cin >> pilihan;
        cout << endl;
        
        switch (pilihan) {
            case 1: {
                if (isFull(Q)) {
                    cout << "Queue sudah penuh! Tidak bisa menambah data lagi." << endl << endl;
                } else {
                    Paket paketBaru;
                    
                    cout << "--- Input Data Paket ---" << endl;
                    cout << "KodeResi : ";
                    cin >> paketBaru.KodeResi;
                    cout << "NamaPengirim : ";
                    cin >> paketBaru.NamaPengirirm;
                    cout << "BeratBarang (kg) : ";
                    cin >> paketBaru.BeratBarang;
                    cout << "Tujuan : ";
                    cin >> paketBaru.Tujuan;
                    cout << endl;
                    
                    enQueue(Q, paketBaru);
                    cout << endl;
                }
                break;
            }
            
            case 2: {
                deQueue(Q);
                cout << endl;
                break;
            }
            
            case 3: {
                viewQueue(Q);
                break;
            }
            
            case 4: {
                int totalBiaya = TotalBiayaPengiriman(Q);
                if (!isEmpty(Q)) {
                    cout << "\n========== TOTAL BIAYA PENGIRIMAN ==========" << endl;
                    cout << "Total Biaya Pengiriman Semua Paket: Rp. " << totalBiaya << endl;
                    cout << "===========================================" << endl << endl;
                }
                break;
            }
            
            case 5: {
                cout << "Terima kasih telah menggunakan sistem ini. Selamat tinggal!" << endl;
                return 0;
            }
            
            default:
                cout << "Pilihan tidak valid! Silakan coba lagi." << endl << endl;
        }
    }
    return 0;
}
