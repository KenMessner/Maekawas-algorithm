//Homework 2 : Maekawas-algorithm
//Author: Kenneth Messner
//Last Modified: 10/12/18

#include <iostream>
#include <string>
#include <unistd.h>
#include <time.h>

#ifndef NODE_H
#define NODE_H

class Node{

public:
    Node();
    Node(int newID, char newState, bool newVoted){ID = newID; state = newState; voted = newVoted;}

    void Process(int taskTime);

private:
    int ID;
    char state;//States: R = Released, H = Held, W = Wanted
    bool voted;
};

void Node::Process(int taskTime){
    time_t my_time = time(NULL);
    printf("%s", ctime(&my_time)); 

    sleep(taskTime / 1000);

    my_time = time(NULL);
    printf("%s", ctime(&my_time)); 
}

#endif