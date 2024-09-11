#include <fstream>
#include <iostream>
#include "List.h"
#include "Delete.h"
#include "AddElement.h"
#include "Sort.h"
void Load1(List* l, std::string fileName) {
    Clear(l);
    std::ifstream f(fileName, std::ios::in | std::ios::binary);
    if (!f.is_open())
    {
        std::cerr << "Не получается открыть файл: " << std::endl;
        return;
    }
    while (true) {
        AirRace* ar = new AirRace;
        f.read((char*)(ar), sizeof(AirRace));
        if (!f)
        {
            delete ar;
            break;
        }
        Node* node = new Node();
        node->data = ar;
        AddIntoBegin2(l, node);
    }
    Sort(l, 1, 0);
    f.close();
}
void Load2(List* l, std::string filename) {
    std::ifstream f(filename);
    if (!f.is_open()) {
        std::cerr << "Не получается отрыть файл " << filename << std::endl;
        return;
    }
    Clear(l);
    while (!f.eof()) {
        std::string path1, path2, planeMark;
        float onePassageerCost, totalRaceCost;
        int raceNum, passageersAmmount;
        f >> path1 >> path2 >> planeMark >> onePassageerCost >> raceNum >> totalRaceCost >> passageersAmmount;
        if (!f.fail()) {
            Node* ar = new Node();
            ar->data = new AirRace();
                ar->data->path1 = path1;
                ar->data->path2 = path2;
                ar->data->planeMark = planeMark;
                ar->data->onePassageerCost = onePassageerCost;
                ar->data->raceNum = raceNum;
                ar->data->totalRaceCost = totalRaceCost;
                ar->data->passageersAmmount = passageersAmmount;
                AddIntoBegin2(l, ar);
        }
    }
    Sort(l, 1, 0);
    f.close();
}
