#include <string>
#include <iostream>
#include "List.h"
#include "AddElement.h"
#include "Show.h"
void Found(List* l2, std::string name)
{
	List* l = new List();
	Node* ar = l2->begin;
	for (int i = 0; i < l2->count;i++)
	{
		if (strcmp(ar->data->path1.c_str(), name.c_str()) == 0 || strcmp(ar->data->path2.c_str(), name.c_str()) == 0)
		{
			AddIntoBegin2(l, ar);
		}
		ar = ar->next;
	}
	if (l->count > 0)
	{
		std::cout << "Записи с соответствующим именем: " << std::endl;
		Show(l);
	}
	else
	{
		std::cout << "Записей с таким названием не найдено" << std::endl;
	}
	delete(l);
}