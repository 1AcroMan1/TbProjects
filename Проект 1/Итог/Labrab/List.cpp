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
		printf("\n 1. ����������� ������\n"
			"2. �������� ������ � ������\n"
			"3. �������� ������ � �����\n"
			"4. ����������\n"
			"5. ��������\n"
			"6. �������� ������\n"
			"7. ������� ������� �� ��������� ��������\n"
			"8. ������������� ������ �� ��������� ��������\n"
			"9. ����������� �� ���������� �����\n"
			"10. ����� �� �����\n"
			"0. �����\n");
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
			std::cout << "������� ��� txt �����" << std::endl;
			printf("\n Press - >");
			std::cin >> answer3;
			std::cout << "�������� ��� ����������. 0 - ���������������� 1 - �������������� " << std::endl;
			printf("\n Press - >");
			std::cin >> answer;
			switch (answer)
			{
			default:
				std::cout << "������ ���������� ����" << std::endl;
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
			std::cout << "������� ��� txt �����" << std::endl;
			printf("\n Press - >");
			std::cin >> answer3;
			std::cout << "�������� ��� ��������. 0 - ���������������� 1 - �������������� " << std::endl;
			printf("\n Press - >");
			std::cin >> answer;
			switch (answer)
			{
			default:
				std::cout << "����� �������� ����" << std::endl;
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
			std::cout << "������� ������. ������ � ���� �������� ����� �������" << std::endl;
			printf("\n Press - >");
			scanf("%d", &answer);
			if (CheckIndex(answer,l1->count))
			{
				Remove(l1,answer,true);
			}
			break;
		case 8:
			std::cout << "������� ������. ������ � ���� �������� ����� ����������������" << std::endl;
			printf("\n Press - >");
			scanf("%d", &answer);
			if (CheckIndex(answer,l1->count))
			{
				Correct(l1, answer);
			}
			break;
		case 9:
			printf("\n������� ���� ����������\n"
				"1 - ����� �����\n"
				"2 - ����� �������\n"
				"3 - �������� ��������\n"
				"4 - ����� ����������� ������� �� ����\n"
				"5 - ���������� ����������\n"
				"6 - ������� ��������� ��������� 1 ��������� �� �����\n");
			printf("\n Press - >"), scanf("%d", &answer);
			std::cout << "0 - �� ����������� 1 - �� ��������" << std::endl;
			scanf("%d", &answer2);
			Sort(l1, answer, answer2);
			break;
		case 10:
			std::cout << "������� �������� ������" << std::endl;
			printf("\n Press - >");
			std::string a = "";
			std::cin >> a;
			Found(l1,a);
			break;
		}
	}
};