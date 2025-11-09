#include <iostream>
#include "stack.h"

int main()
{
    std::cout << "Hello world!" << std::endl;
    Stack S;
    createStack(S);
    getInputStream(S);
    printInfo(S);
    std::cout << "balik stack" << std::endl;
    balikStack(S);
    printInfo(S);
    return 0;
}