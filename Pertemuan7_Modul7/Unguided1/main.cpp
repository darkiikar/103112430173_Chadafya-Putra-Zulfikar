#include <iostream>
#include "stack.h"

int main()
{
	std::cout << "Hello world!" << std::endl;

	Stack S;
	createStack(S);
	Push(S,3);
	Push(S,4);
	Push(S,8);
	pop(S);
	Push(S,2);
	Push(S,3);
	pop(S);
	Push(S,9);
	printInfo(S);
	std::cout << "balik stack" << std::endl;
	balikStack(S);
	printInfo(S);
	return 0;
}
