	#include "List.h"
	#include "FillDatas.h"
	void AddIntoBegin(List* l)
	{
		Node* ar = new Node();
		ar->data = new AirRace();
		FillData(ar);
		ar->data->raceNum = l->count;
		ar->prev = nullptr;
		ar->next = l->begin;
		if (l->count > 0)
		{
			l->begin->prev = ar;
			l->begin = ar;
		}
		else
		{
			l->begin = l->end = ar;
		}
		l->count++;
	};
	void AddIntoEnd(List* l)
	{
		Node* ar = new Node();
		ar->data = new AirRace();
		ar->next = nullptr;
		ar->prev = l->end;
		FillData(ar);
		ar->data->raceNum = l->count;
		if (l->end != nullptr)
			l->end->next = ar;
		if (l->count == 0)
		{
			l->begin = l->end = ar;
		}
		else
		{
			l->end = ar;
		}
		l->count++;
	};
	void AddIntoBegin2(List* l, Node* ar2)
	{
		Node* ar = new Node();
		ar->data = new AirRace();
		ar->prev = nullptr;
		ar->next = l->begin;
		if (l->count > 0)
		{
			l->begin->prev = ar;
			l->begin = ar;
		}
		else
		{
			l->begin = l->end = ar;
		}
		l->count++;
		ar->data = ar2->data;
	};