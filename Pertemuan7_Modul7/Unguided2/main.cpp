#include <iostream>
#include "stack.h"

int main()
{
    std::cout << "Hello world!" << std::endl;

    Stack S;
    createStack(S);
    pushAscending(S,3);
    pushAscending(S,4);
    pushAscending(S,8);
    pushAscending(S,2);
    pushAscending(S,3);
    pushAscending(S,9);
    printInfo(S);
    std::cout << "balik stack" << std::endl;
    balikStack(S);
    printInfo(S);
    return 0;
}