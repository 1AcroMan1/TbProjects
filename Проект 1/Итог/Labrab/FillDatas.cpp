#include "List.h"
#include <iostream>
#include <limits>
void PrintPathName(Node* ar, bool nameFlag)
{
	if (nameFlag == true)
	{
		puts("Напишите имя второго города (Лондон, Севастополь и т.п). Название маршрута не должно превышать 20 символов");
		try
		{
			std::string b;
			std::cin >> b;
			if (b.size() > 20)
			{
				std::cout << "Название маршрута больше 20 символов. Попробуйте ещё раз" << std::endl;
				ar->data->path2 = "";
				ar->data->path1 = "";
				PrintPathName(ar, 0);
			}
			ar->data->path2 = b;
			if (ar->data->path1.length() + ar->data->path2.length() > 20)
			{
				std::cout << "Название маршрута больше 20 символов. Попробуйте ещё раз" << std::endl;
				ar->data->path1 = "";
				ar->data->path2 = "";
				PrintPathName(ar, 0);
			}
		}
		catch (...)
		{
			std::cout << "Вы не можете импользовать это значение. Попробуйте снова" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			PrintPathName(ar, nameFlag);
		}
	}
	else
	{
		puts("Напишите имя первого города (Лондон, Севастополь и т.п). Название маршрута не должно превышать 20 символов");
		try
		{
			if (ar == NULL)
			{
				std::cout << "NULL!!!";
			}
			std::cin >> ar->data->path1;
			if (ar->data->path1.size() > 20)
			{
				std::cout << "Название маршрута больше 20 символов. Попробуйте ещё раз" << std::endl;
				ar->data->path1 = "";
				PrintPathName(ar, 0);
			}
			nameFlag = true;
			PrintPathName(ar, nameFlag);
		}
		catch (...)
		{
			std::cout << "Вы не можете импользовать это значение. Попробуйте снова" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			PrintPathName(ar, nameFlag);
		}
	}
};
void PrintPlaneMark(Node* ar)
{
	puts("Введите марку самолёта. Значение не должно превышать 6 символов");
	try
	{
		std::cin >> ar->data->planeMark;
		if (ar->data->planeMark.size() > 6)
		{
			std::cout << "Значение маршрута больше 6 символов. Попробуйте ещё раз" << std::endl;
			PrintPlaneMark(ar);
		}
	}
	catch (...)
	{
		std::cout << "Вы не можете импользовать это значение. Попробуйте снова" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		PrintPlaneMark(ar);
	}
};
void PrintTotalRaceCost(Node* ar)
{
	puts("Введите затраты на рейс");
	try
	{
		std::cin >> ar->data->totalRaceCost;
		if (!std::cin)
			throw 1;
	}
	catch (...)
	{
		std::cout << "Вы не можете импользовать это значение. Попробуйте снова" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		PrintTotalRaceCost(ar);
	}
};
void PrintAmmountPassageers(Node* ar)
{
	puts("Введите количество пассажиров");
	try
	{
		std::cin >> ar->data->passageersAmmount;
		if (!std::cin)
			throw 1;
		puts("Создание успешно");
	}
	catch (...)
	{
		std::cout << "Вы не можете импользовать это значение. Попробуйте снова" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		PrintAmmountPassageers(ar);
	}
};
void FillData(Node* ar)
{
	PrintPathName(ar, false);
	PrintPlaneMark(ar);
	PrintTotalRaceCost(ar);
	PrintAmmountPassageers(ar);
	ar->data->onePassageerCost = ar->data->totalRaceCost / ar->data->passageersAmmount;
};