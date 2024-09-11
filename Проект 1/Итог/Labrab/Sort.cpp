#include "List.h"
#include "Reverse.h"
#include <iostream>
void Sort(List* l, int keyType, bool isReverse)
{
	Node* ar = l->begin;
	Node* arc = l->begin;
	switch (keyType)
	{
	case 1:
		for (int i = 0; i < l->count; i++)
		{
			ar = arc;
			for (int j = i; j < l->count; j++)
			{
				if (ar->data->raceNum < arc->data->raceNum)
				{
					std::swap(ar->data, arc->data);
				}
				ar = ar->next;
			}
			arc = arc->next;
		}
		break;
	case 2:
		for (int i = 0; i < l->count; i++)
		{
			ar = arc;
			for (int j = i; j < l->count; j++)
			{
				if (strcmp(ar->data->planeMark.c_str(), arc->data->planeMark.c_str())<0)
				{
					std::swap(ar->data, arc->data);
				}
				ar = ar->next;
			}
			arc = arc->next;
		}
		break;
	case 3:
		for (int i = 0; i < l->count; i++)
		{
			ar = arc;
			for (int j = i; j < l->count; j++)
			{
				if (strcmp(ar->data->path1.c_str(), arc->data->path1.c_str()) < 0)
				{
					std::swap(ar->data, arc->data);
				}
				ar = ar->next;
			}
			arc = arc->next;
		}
		break;
		break;
	case 4:
		for (int i = 0; i < l->count; i++)
		{
			ar = arc;
			for (int j = i; j < l->count; j++)
			{
				if (ar->data->totalRaceCost > arc->data->totalRaceCost)
				{
					std::swap(ar->data, arc->data);
				}
				ar = ar->next;
			}
			arc = arc->next;
		}
		break;
	case 5:
		for (int i = 0; i < l->count; i++)
		{
			ar = arc;
			for (int j = i; j < l->count; j++)
			{
				if (ar->data->passageersAmmount > arc->data->passageersAmmount)
				{
					std::swap(ar->data, arc->data);
				}
				ar = ar->next;
			}
			arc = arc->next;
		}
		break;
	case 6:
		for (int i = 0; i < l->count; i++)
		{
			ar = arc;
			for (int j = i; j < l->count; j++)
			{
				if (ar->data->onePassageerCost > arc->data->onePassageerCost)
				{
					std::swap(ar->data, arc->data);
				}
				ar = ar->next;
			}
			arc = arc->next;
		}
		break;
	default:
		std::cout << "Неверные данные" << std::endl;
		break;
	}
	if (!isReverse)
	{
		Reverse(l);
	}
};