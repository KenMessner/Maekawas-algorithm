//Homework 2 : Maekawas-algorithm and min-min / min-max / sufferage
//Author: Kenneth Messner
//Last Modified: 9/17/2019

#include <iostream>
#include <string>
#include <unistd.h>
#include <time.h>
#include <vector>
#include <thread>
#include <math.h> 

#ifndef NODE_H
#define NODE_H

class Node{

public:
    Node();
    Node(int newID, char newState, char newVoted){ID = newID; state = newState; voted = newVoted;}

    void Process(int taskTime);
    void Request(Node *nodes, int n);
    void GrantAccess(int requestersID);

    void getID(){std::cout << ID;}

    void setState(char newState){state = newState;}
    char getState(){return state;}

    char getVoted(){return voted;}

    void setVotingSet(int set){votingSet = set;}
    int getVotingSet(){return votingSet;}

private:
    int ID;
    char state;//States: R = Released, H = Held, W = Wanted
    char voted;//States: T = True, F = False

    int votingSet;
    std::vector<int> queue;//FIFO Queue for holding request
};

void Node::Process(int taskTime){
    time_t my_time = time(NULL);
    printf("     %s", ctime(&my_time)); 

    std::cout << "     Node " << ID << " processing task in CS; bound to take " << taskTime << " millisecond.\n";
    sleep(taskTime / 1000);//Thread this section

    my_time = time(NULL);
    printf("     %s", ctime(&my_time)); 
}

void Node::Request(Node *nodes, int n){
    int k = floor(sqrt(n));
    int m = k;
  
    int row = n / ID;
    std::cout << "Rowwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww " << row;
    //Continue here and figure out a way to get this for loop to only grantAccess when it's in the same row
    for(int i = 0; i < n; i++){
        if(i/n == row && i != ID){
            nodes[i].GrantAccess(ID);
            std::cout << " $$ Requesting node " << i << ".\n";
        }
    }

    int column;
    column = ID % (m);

    for(int i = 0; i < n; i++){
        if(i%m == column && i != ID){
            nodes[i].GrantAccess(ID);
            std::cout << " && Requesting node " << i << ".\n";
        }
    }
}

void Node::GrantAccess(int RequestersID){

}

#endif