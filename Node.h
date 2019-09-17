//Homework 2 : Maekawas-algorithm and min-min / min-max / sufferage
//Author: Kenneth Messner
//Last Modified: 9/17/2019

#include <iostream>
#include <string>
#include <unistd.h>
#include <time.h>
#include <vector>
#include <math.h> 

#ifndef NODE_H
#define NODE_H

class Node{

public:
    Node();
    Node(int newID, char newState, char newVoted){ID = newID; state = newState; voted = newVoted;}

    void Process(int taskTime);

    void getID(){std::cout << ID;}
    void getState(){std::cout << state;}
    void getVoted(){std::cout << voted;}

    void setVotingSet(int set){votingSet = set;}
    void getVotingSet(){std::cout << votingSet;}

private:
    int ID;
    char state;//States: R = Released, H = Held, W = Wanted
    char voted;//States: T = True, F = False

    int votingSet;
    std::vector<int> queue;//FIFO Queue for holding request
};

void Node::Process(int taskTime){
    std::cout << "Node " << ID << " processing task in CS; bound to take " << taskTime << " millisecond.\n";
    time_t my_time = time(NULL);
    printf("%s", ctime(&my_time)); 

    sleep(taskTime / 1000);

    my_time = time(NULL);
    printf("%s", ctime(&my_time)); 
}

#endif