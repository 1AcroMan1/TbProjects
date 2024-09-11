#include "List.h"
#include "CheckIndex.h"
#include "Move.h"
#include <iostream>
void Remove(List* l, int index,bool needAsk)
{
	if (l->count == 0)
		return;
	if (!CheckIndex(index, l->count))
		return;
	Node* ar = MoveToRace(l,index);
	if (ar != NULL)
	{
		int an = 0;
		if (needAsk)
		{
			std::cout << "Вы уверены, что хотите удалить запись под номером: " << ar->data->raceNum << " Путь: " << ar->data->path1 << "-" << ar->data->path2 << " 1 - да 0 - нет" << std::endl;
			std::cin >> an;
		}
		if (an == 1||needAsk == false)
		{
			Node* _prev = ar->prev;
			Node* _next = ar->next;
			if (index == 0)
			{
				l->begin = _next;
			}

			else if (index == l->count - 1)
			{
				l->end = _prev;
			}
			else if (l->count > 1 && _next != NULL)
			{
				_prev->next = ar->next;
			}
			else if (l->count > 1 && _next != NULL)
			{
				_next->prev = _prev;
			}
			delete(ar);
			l->count--;
			std::cout << "Удаление успешно" << std::endl;
		}
	}
};
//----------- Clear all elements ------------------------
void Clear(List* l)
{
	int count = l->count;
	for (int i = 0; i < count-1; i++)
	{
		Remove(l, i, false);
	}
};