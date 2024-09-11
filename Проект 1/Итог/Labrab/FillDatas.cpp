#include "List.h"
#include <iostream>
#include <limits>
void PrintPathName(Node* ar, bool nameFlag)
{
	if (nameFlag == true)
	{
		puts("�������� ��� ������� ������ (������, ����������� � �.�). �������� �������� �� ������ ��������� 20 ��������");
		try
		{
			std::string b;
			std::cin >> b;
			if (b.size() > 20)
			{
				std::cout << "�������� �������� ������ 20 ��������. ���������� ��� ���" << std::endl;
				ar->data->path2 = "";
				ar->data->path1 = "";
				PrintPathName(ar, 0);
			}
			ar->data->path2 = b;
			if (ar->data->path1.length() + ar->data->path2.length() > 20)
			{
				std::cout << "�������� �������� ������ 20 ��������. ���������� ��� ���" << std::endl;
				ar->data->path1 = "";
				ar->data->path2 = "";
				PrintPathName(ar, 0);
			}
		}
		catch (...)
		{
			std::cout << "�� �� ������ ������������ ��� ��������. ���������� �����" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			PrintPathName(ar, nameFlag);
		}
	}
	else
	{
		puts("�������� ��� ������� ������ (������, ����������� � �.�). �������� �������� �� ������ ��������� 20 ��������");
		try
		{
			if (ar == NULL)
			{
				std::cout << "NULL!!!";
			}
			std::cin >> ar->data->path1;
			if (ar->data->path1.size() > 20)
			{
				std::cout << "�������� �������� ������ 20 ��������. ���������� ��� ���" << std::endl;
				ar->data->path1 = "";
				PrintPathName(ar, 0);
			}
			nameFlag = true;
			PrintPathName(ar, nameFlag);
		}
		catch (...)
		{
			std::cout << "�� �� ������ ������������ ��� ��������. ���������� �����" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			PrintPathName(ar, nameFlag);
		}
	}
};
void PrintPlaneMark(Node* ar)
{
	puts("������� ����� �������. �������� �� ������ ��������� 6 ��������");
	try
	{
		std::cin >> ar->data->planeMark;
		if (ar->data->planeMark.size() > 6)
		{
			std::cout << "�������� �������� ������ 6 ��������. ���������� ��� ���" << std::endl;
			PrintPlaneMark(ar);
		}
	}
	catch (...)
	{
		std::cout << "�� �� ������ ������������ ��� ��������. ���������� �����" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		PrintPlaneMark(ar);
	}
};
void PrintTotalRaceCost(Node* ar)
{
	puts("������� ������� �� ����");
	try
	{
		std::cin >> ar->data->totalRaceCost;
		if (!std::cin)
			throw 1;
	}
	catch (...)
	{
		std::cout << "�� �� ������ ������������ ��� ��������. ���������� �����" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		PrintTotalRaceCost(ar);
	}
};
void PrintAmmountPassageers(Node* ar)
{
	puts("������� ���������� ����������");
	try
	{
		std::cin >> ar->data->passageersAmmount;
		if (!std::cin)
			throw 1;
		puts("�������� �������");
	}
	catch (...)
	{
		std::cout << "�� �� ������ ������������ ��� ��������. ���������� �����" << std::endl;
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