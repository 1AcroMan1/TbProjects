#include <fstream>
#include <iostream>
#include "List.h"
void Save1(List* l, std::string fileName)
{
    std::ofstream f(fileName, std::ios::out | std::ios::binary);
    if (!f.is_open()) {
        std::cout << "Не получается отрыть файл " << fileName << std::endl;
        return;
    }
    Node* ar = l->begin;
    while (ar != nullptr) {
        f.write((char*)(ar->data), sizeof(AirRace));
        ar = ar->next;
    }
    f.close();
}

void Save2(List* l, std::string filename) {
    std::ofstream f(filename);
    if (!f.is_open()) {
        std::cout << "Не получается отрыть файл " << filename << std::endl;
        return;
    }
    Node* ar = l->begin;
    for(int i = 0;i<l->count;i++)
    {
        f << ar->data->path1 << " "
            << ar->data->path2 << " "
            << ar->data->planeMark << " "
            << ar->data->onePassageerCost << " "
            << ar->data->raceNum << " "
            << ar->data->totalRaceCost << " "
            << ar->data->passageersAmmount << std::endl;
        ar = ar->next;
    }
    f.close();
}