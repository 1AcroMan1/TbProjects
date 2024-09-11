#include "List.h"
#include "Move.h"
#include "FillDatas.h"
#include <iostream>
void Correct(List* l, int index)
{
	Node* ar = MoveToRace(l, index);
	FillData(ar);
	std::cout << "Корректировка успешна" << std::endl;
};