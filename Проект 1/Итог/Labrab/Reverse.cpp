#include "List.h"
#include "AddElement.h"
void Reverse(List* l2)
{
	List* l = new List();
	Node* ar = l2->begin;
	while (ar != nullptr)
	{
		AddIntoBegin2(l,ar);
		ar = ar->next;
	}
	l2 = l;
};