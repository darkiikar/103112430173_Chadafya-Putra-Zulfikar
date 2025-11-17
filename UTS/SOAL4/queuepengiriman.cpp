#include "queuepengiriman.h"

void createQueue(QueueEkspedisi &Q) {
    Q.Head = -1;
    Q.Tail = -1;
}

bool isEmpty(QueueEkspedisi Q) {
    return (Q.Head == -1 && Q.Tail == -1);
}

bool isFull(QueueEkspedisi Q) {
    return (Q.Tail == MAX - 1);
}

void enQueue(QueueEkspedisi &Q, Paket data) {
    if (isFull(Q)) {
        cout << "Queue penuh! Tidak bisa menambah data." << endl;
    } else {
        if (isEmpty(Q)) {
            Q.Head = 0;
        }
        Q.Tail++;
        Q.dataPaket[Q.Tail] = data;
        cout << "Data paket berhasil ditambahkan ke queue." << endl;
    }
}

void deQueue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong! Tidak ada data untuk dihapus." << endl;
    } else {
        cout << "Paket dengan kode resi " << Q.dataPaket[Q.Head].KodeResi 
             << " telah dikirimkan (dihapus dari queue)." << endl;
        Q.Head++;
        
        if (Q.Head > Q.Tail) {
            Q.Head = -1;
            Q.Tail = -1;
        }
    }
}

void viewQueue(QueueEkspedisi Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
    } else {
        cout << "\n========== ISI QUEUE PAKET ==========" << endl;
        cout << "No. | Kode Resi | Nama Pengirim | Berat (kg) | Tujuan" << endl;
        cout << "====|========|=============|============|===========" << endl;
        
        int nomor = 1;
        for (int i = Q.Head; i <= Q.Tail; i++) {
            cout << nomor << "   | " << Q.dataPaket[i].KodeResi << " | " 
                 << Q.dataPaket[i].NamaPengirirm << " | " 
                 << Q.dataPaket[i].BeratBarang << " | " 
                 << Q.dataPaket[i].Tujuan << endl;
            nomor++;
        }
        cout << "====================================" << endl << endl;
    }
}

int TotalBiayaPengiriman(QueueEkspedisi Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong! Tidak ada paket untuk dihitung." << endl;
        return 0;
    }
    
    int totalBiaya = 0;
    int tarifPerKg = 8250;
    
    for (int i = Q.Head; i <= Q.Tail; i++) {
        totalBiaya += Q.dataPaket[i].BeratBarang * tarifPerKg;
    }
    
    return totalBiaya;
}
