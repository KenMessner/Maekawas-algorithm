//Homework 2 : Maekawas-algorithm
//Author: Kenneth Messner
//Last Modified: 10/12/18

#include <fstream>
#include <iostream>
#include <iostream>
#include <string>

#ifndef CORE_H
#define CORE_H

int systemMemory[10][4] = {0};

class Core{

public:
    Core();
    Core(int ID){coreID = ID; coreState = 'I';}
    Core(int ID, char state){coreID = ID; coreState = state;}

private:
    int coreID;
    char coreState;//States: I = Invalid, S = Shared, E = Exclusive, M = Modified
    int casheBlockID = -1;
    int cashe[4] = {-1};
};

void Core::requestMemory(int blockID, int memoryID){

}

#endif