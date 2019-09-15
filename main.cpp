//Main function where IO and BUS functions will be placed

//MESI Project, The goal in this project is to implement the MESI cache coherence protocol

//Author: Kenneth Messner

//Last Modified: 10/21/18



#include "Core.h"



char initalPrompt();

void parseRequest(std::string request);

void bus(const int coreNumber, const char action, const int blockNumber, const int blockLocation, const int writeValue);

bool checkForState(const int blockNumber, const char state);

void coreStatusUpdate();

void invalidate(const int blockNumber);

void switchToShared(const int blockNumber);



//GLOBAL - Array of Four CPU Cores

Core* cores[4];



int main(){

}
