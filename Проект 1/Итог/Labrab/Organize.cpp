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
		printf("�������� ���? 1- �� 0 - ���\n");
		std::cin >> f1;
	} while (f1);
}