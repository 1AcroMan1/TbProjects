#define _CRT_SECURE_NO_DEPRECATE
#include "List.h"
#include "CheckIndex.h"
#include "AddElement.h"
#include "Show.h"
#include "Correct.h"
#include "Delete.h"
#include "Sort.h"
#include "Found.h"
#include "Organize.h"
#include "Save.h"
#include "Load.h"
#include <locale.h>
#include <iostream>
int ClientCode()
{
	setlocale(LC_ALL, "Russian");
	List* l1 = new List();
	int answer;
	int answer2;
	std::string answer3;
	while (1) {
		printf("\n 1. Организация списка\n"
			"2. Добавить запись в начало\n"
			"3. Добавить запись в конец\n"
			"4. Сохранение\n"
			"5. Загрузка\n"
			"6. Просмотр списка\n"
			"7. Удалить элемент со следующим индексом\n"
			"8. Корректировка записи со следующим индексом\n"
			"9. Сортировать по выбранному ключу\n"
			"10. Поиск по имени\n"
			"0. Выход\n");
		printf("\n Press - >"), scanf("%d", &answer);
		switch (answer) {
		case 0:
			return 0;
		case 1:
			Organize(l1);
			break;
		case 2:
			AddIntoBegin(l1);
			break;
		case 3:
			AddIntoEnd(l1);
			break;
		case 4:
			std::cout << "Введите имя txt файла" << std::endl;
			printf("\n Press - >");
			std::cin >> answer3;
			std::cout << "Выберите тип сохранения. 0 - нетипизированное 1 - типизированное " << std::endl;
			printf("\n Press - >");
			std::cin >> answer;
			switch (answer)
			{
			default:
				std::cout << "Такого сохранения нету" << std::endl;
				break;
			case 0:
				Save2(l1, answer3);
				break;
			case 1:
				Save1(l1, answer3);
				break;
			}
			break;
		case 5:
			std::cout << "Введите имя txt файла" << std::endl;
			printf("\n Press - >");
			std::cin >> answer3;
			std::cout << "Выберите тип загрузки. 0 - нетипизированная 1 - типизированная " << std::endl;
			printf("\n Press - >");
			std::cin >> answer;
			switch (answer)
			{
			default:
				std::cout << "Такой загрузки нету" << std::endl;
				break;
			case 0:
				Load2(l1, answer3);
				break;
			case 1:
				Load1(l1, answer3);
				break;
			}
			break;
		case 6:
			Show(l1);
			break;
		case 7:
			std::cout << "Введите индекс. Запись с этим индексом будет удалена" << std::endl;
			printf("\n Press - >");
			scanf("%d", &answer);
			if (CheckIndex(answer,l1->count))
			{
				Remove(l1,answer,true);
			}
			break;
		case 8:
			std::cout << "Введите индекс. Запись с этим индексом будет отредактированна" << std::endl;
			printf("\n Press - >");
			scanf("%d", &answer);
			if (CheckIndex(answer,l1->count))
			{
				Correct(l1, answer);
			}
			break;
		case 9:
			printf("\nВведите ключ сортировки\n"
				"1 - Номер рейса\n"
				"2 - Марка самолёта\n"
				"3 - Название маршрута\n"
				"4 - Общие стоимостные затраты на рейс\n"
				"5 - Количество пассажиров\n"
				"6 - Средняя стоимость перевозки 1 пассажира на рейсе\n");
			printf("\n Press - >"), scanf("%d", &answer);
			std::cout << "0 - По возрастанию 1 - По убыванию" << std::endl;
			scanf("%d", &answer2);
			Sort(l1, answer, answer2);
			break;
		case 10:
			std::cout << "Введите название города" << std::endl;
			printf("\n Press - >");
			std::string a = "";
			std::cin >> a;
			Found(l1,a);
			break;
		}
	}
};