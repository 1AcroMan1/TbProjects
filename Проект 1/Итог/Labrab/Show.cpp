#include "List.h"
#include <iostream>
void FinalShow(List* l)
{
	Node* ar = l->begin;
	int allCost = 0;
	int allPassageers = 0;
	float onePassageerAvgCost = 0;
	for (int i = 0; i < l->count; i++)
	{
		allCost += ar->data->totalRaceCost;	
		allPassageers += ar->data->passageersAmmount;
		onePassageerAvgCost += ar->data->totalRaceCost / ar->data->passageersAmmount;
		ar = ar->next;
	}
	onePassageerAvgCost /= l->count;
	std::cout << "Стоимсоть всех рейсов: " << allCost << std::endl;
	std::cout << "Количество пассажиров за всё время: " << allPassageers << std::endl;
	std::cout << "Средняя стоимость провозки 1 пассажира за всё время: " << onePassageerAvgCost << std::endl;
}
void Show(List* l)
{
	int page = 0;
	int answer = 0;
	int answer2 = 0;
	int dataInPage = 10;
	bool breakflag = false;
	Node* ar = l->begin;
	do
	{
		if (breakflag)
			break;
		puts("|Номер рейса|      Название пути      |Марка самолёта|Общие затраты|Количество пассажиров|Стоимость 1 пассажира|");
		for (int i = page* dataInPage; i < page* dataInPage + dataInPage; i++)
		{
			if (i < l->count)
			{
				printf("| %9d | %23s | %12s | %11d | %19d | %20.2f|", ar->data->raceNum, (ar->data->path1 + "-" + ar->data->path2).c_str(), ar->data->planeMark.c_str(), ar->data->totalRaceCost, ar->data->passageersAmmount, ar->data->onePassageerCost);
				std::cout << std::endl;
				ar = ar->next;
			}
			else
				break;
		}
		std::cout <<"Страница: " << page <<" Введите: 1 - предыдущая страница 2 - следующая страница 3 - выбранная страница 4 - Итоговые данные 0 - выход" << std::endl;
		std::cin >> answer;
		switch (answer)
		{
		default:
			breakflag = true;
			break;
		case 1:
			if (page != 0)
			{
				page--;
				ar = l->begin;
				for (int n = 0; n < page * dataInPage; n++)
				{
					ar = ar->prev;
				}
			}
			else
			{
				ar = l->begin;
			}
			break;
		case 2:
			if ((page + 1) * dataInPage > l->count)
			{
				if (page != 0)
				{
					for (int n = page * 10; n < page * dataInPage; n++)
					{
						ar = ar->next;
					}
				}
				else
				{
					ar = l->begin;
				}
				break;
			}
			page++;
			break;
		case 3:
			std::cout << "Введите страницу" << std::endl;
			std::cin >> answer2;
			if (l->count / dataInPage > answer2)
			{
				int divide;
				if (page * dataInPage == 0)
					divide = 1;
				else
					divide = page * dataInPage;
				if (answer2 >= l->count / divide)
				{
					std::cout << "Неверная страница" << std::endl;
					if (page != 0)
					{
						for (int n = 0; n < dataInPage; n++)
						{
							ar = ar->prev;
						}
					}
					else
					{
						ar = l->begin;
					}
				}
				else
				{
					page = answer2;
					ar = l->begin;
					if (page != 0)
					{
						for (int n = page * 10; n < page * dataInPage; n++)
						{
							ar = ar->next;
						}
					}
				}
			}
			else
			{
				std::cout << "Неверная страница" << std::endl;
				if (page != 0)
				{
					for (int n = 0; n < dataInPage; n++)
					{
						ar = ar->prev;
					}
				}
				else
				{
					ar = l->begin;
				}
			}
			break;
		case 4:
			FinalShow(l);
			page = 0;
			ar = l->begin;
			break;
		}
	} while (true);
};