#include "AddElement.h"
#include <iostream>
void Organize(List* l1)
{
	int f1 = 0;
	do
	{
		if (l1->count == 0)
		{
			AddIntoBegin(l1);
		}
		else
		{
			AddIntoEnd(l1);
		}
		printf("Добавить ещё? 1- да 0 - нет\n");
		std::cin >> f1;
	} while (f1);
}