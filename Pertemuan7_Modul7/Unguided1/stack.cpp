#include "stack.h"
#include <iostream>

void createStack(Stack &S)
{
	S.top = 0;
}

void Push(Stack &S, infotype x)
{
	if (S.top < 20)
	{
		S.info[S.top] = x;
		S.top = S.top + 1;
	}
	else
	{
		std::cout << "Stack penuh" << std::endl;
	}
}

infotype pop(Stack &S)
{
	if (S.top > 0)
	{
		S.top = S.top - 1;
		return S.info[S.top];
	}
	else
	{
		std::cout << "Stack kosong" << std::endl;
		return -1;
	}
}

void printInfo(const Stack &S)
{
	std::cout << "[TOP] ";
	for (int i = S.top - 1; i >= 0; i = i - 1)
	{
		std::cout << S.info[i];
		if (i > 0) std::cout << " ";
	}
	std::cout << std::endl;
}

void balikStack(Stack &S)
{
	int i = 0;
	int j = S.top - 1;
	while (i < j)
	{
		infotype temp = S.info[i];
		S.info[i] = S.info[j];
		S.info[j] = temp;
		i = i + 1;
		j = j - 1;
	}
}
