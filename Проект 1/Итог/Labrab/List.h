#ifndef LIST
#define LIST
#include <string>
struct AirRace
{
	std::string path1;
	std::string path2;
	std::string planeMark;//6 symb
	float onePassageerCost;
	int raceNum;
	int totalRaceCost;
	int passageersAmmount;
};
struct Node
{
	Node* next;
	Node* prev;
	AirRace* data;
};
struct List
{
	Node* begin = nullptr;
	Node* end = nullptr;
	int count = 0;
};
int ClientCode();
#endif