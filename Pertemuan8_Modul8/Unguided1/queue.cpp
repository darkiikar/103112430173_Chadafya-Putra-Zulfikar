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
    return Q.tail == 4;
}

void enqueue(Queue &Q, infotype x)
{
    if (isEmptyQueue(Q))
    {
        Q.head = 0;
        Q.tail = 0;
        Q.info[Q.tail] = x;
    }
    else if (!isFullQueue(Q))
    {
        Q.tail = Q.tail + 1;
        Q.info[Q.tail] = x;
    }
    else
    {
        std::cout << "Queue penuh" << std::endl;
    }
}

infotype dequeue(Queue &Q)
{
    if (!isEmptyQueue(Q))
    {
        infotype val = Q.info[0];
        for (int i = 0; i < Q.tail; i = i + 1)
        {
            Q.info[i] = Q.info[i + 1];
        }
        Q.tail = Q.tail - 1;
        if (Q.tail < 0)
        {
            Q.head = -1;
            Q.tail = -1;
        }
        return val;
    }
    else
    {
        std::cout << "Queue kosong" << std::endl;
        return -1;
    }
}

void printInfo(const Queue &Q)
{
    if (isEmptyQueue(Q))
    {
        std::cout << Q.head << " - " << Q.tail << "  : " << "empty queue" << std::endl;
        return;
    }
    std::cout << Q.head << " - " << Q.tail << "  : ";
    for (int i = 0; i <= Q.tail; i = i + 1)
    {
        std::cout << Q.info[i];
        if (i < Q.tail) std::cout << " ";
    }
    std::cout << std::endl;
}