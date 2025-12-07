#include "queue.h"
#include <iostream>
using namespace std;

int main()
{
    std::cout << "Hello world!" << std::endl;

    Queue Q;
    createQueue(Q);

    std::cout << "---------------------------" << std::endl;
    std::cout << " H - T  : Queue Info" << std::endl;
    std::cout << "---------------------------" << std::endl;

    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}