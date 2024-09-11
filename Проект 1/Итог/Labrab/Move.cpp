#include "List.h"
#include "CheckIndex.h"
//----------- return object with index ------------------------
Node* Move(List* l, int index)
{
	if (CheckIndex(index,l->count))
	{
		Node* ar = l->begin;
		for (int i = 0; i < index; i++)
		{
			ar = ar->next;
		}
		return ar;
	}
};

Node* MoveToRace(List* l, int race)
{
	if (CheckIndex(race,l->count))
	{
		Node* ar = l->begin;
		for (int i = 0; i < l->count; i++)
		{
			if (ar->data->raceNum == race)
			{
				return ar;
			}
			ar = ar->next;
		}
		return NULL;
	}
};