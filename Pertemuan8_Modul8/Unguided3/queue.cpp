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
    return (Q.tail + 1) % 5 == Q.head;
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
        Q.tail = (Q.tail + 1) % 5;
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
        infotype val = Q.info[Q.head];
        if (Q.head == Q.tail)
        {
            Q.head = -1;
            Q.tail = -1;
        }
        else
        {
            Q.head = (Q.head + 1) % 5;
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
    int i = Q.head;
    while (true)
    {
        std::cout << Q.info[i];
        if (i == Q.tail) break;
        std::cout << " ";
        i = (i + 1) % 5;
    }
    std::cout << std::endl;
}