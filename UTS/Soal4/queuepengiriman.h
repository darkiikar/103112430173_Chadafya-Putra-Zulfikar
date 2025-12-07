#ifndef QUEUEPENGIRIMAN_H
#define QUEUEPENGIRIMAN_H

#include <iostream>
#include <string>
using namespace std;

typedef struct {
    string KodeResi;
    string NamaPengirirm;
    int BeratBarang;  
    string Tujuan;
} Paket;

const int MAX = 5;

typedef struct {
    Paket dataPaket[MAX];
    int Head;
    int Tail;
} QueueEkspedisi;

void createQueue(QueueEkspedisi &Q);
bool isEmpty(QueueEkspedisi Q);
bool isFull(QueueEkspedisi Q);
void enQueue(QueueEkspedisi &Q, Paket data);
void deQueue(QueueEkspedisi &Q);
void viewQueue(QueueEkspedisi Q);
int TotalBiayaPengiriman(QueueEkspedisi Q);

#endif

