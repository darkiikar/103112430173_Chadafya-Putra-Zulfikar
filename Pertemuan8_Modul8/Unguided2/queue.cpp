#include "queue.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q)
{
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(const Queue &Q)
{
    return Q.head == -1;
}

bool isFullQueue(const Queue &Q)
{
    if (Q.head == -1) return false; 
    const int MAX = 5;
    return ((Q.tail + 1) % MAX) == Q.head;
}

void enqueue(Queue &Q, infotype x)
{
    const int MAX = 5;
    if (isFullQueue(Q))
    {
        std::cout << "Queue penuh" << std::endl;
        return;
    }

    if (isEmptyQueue(Q))
    {
        Q.head = 0;
        Q.tail = 0;
        Q.info[Q.tail] = x;
    }
    else
    {
        Q.tail = (Q.tail + 1) % MAX;
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q)
{
    if (isEmptyQueue(Q))
    {
        std::cout << "Queue kosong" << std::endl;
        return -1;
    }

    infotype val = Q.info[Q.head];
    const int MAX = 5;
    if (Q.head == Q.tail)
    {
        Q.head = -1;
        Q.tail = -1;
    }
    else
    {
        Q.head = (Q.head + 1) % MAX;
    }
    return val;
}

void printInfo(const Queue &Q)
{
    if (isEmptyQueue(Q))
    {
        std::cout << Q.head << " - " << Q.tail << "  : " << "empty queue" << std::endl;
        return;
    }
    std::cout << Q.head << " - " << Q.tail << "  : ";
    const int MAX = 5;
    int i = Q.head;
    while (true)
    {
        std::cout << Q.info[i];
        if (i == Q.tail) break;
        std::cout << " ";
        i = (i + 1) % MAX;
    }
    std::cout << std::endl;
}