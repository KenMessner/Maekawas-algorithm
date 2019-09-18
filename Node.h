//Homework 2.1 : Maekawas-algorithm
//Author: Kenneth Messner
//Last Modified: 9/18/2019

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
    void ReleaseAccess();

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
    printf("     -%s", ctime(&my_time)); 

    std::cout << "     Node " << ID << " recieved all responses, processing task in CS; bound to take " << taskTime << " millisecond.\n";
    sleep(taskTime / 1000);//Thread this section

    my_time = time(NULL);
    printf("     -%s", ctime(&my_time));

    std::cout << "\nNode " << ID << " poped from queues of voting set nodes. Continuing on next queued request.";
}

void Node::Request(Node *nodes, int n){
    int k = floor(sqrt(n));
    int m = k;
  
    int matrixIndex = 0;

    for(int i = 0; i < k; i++){
        for(int j = 0; j < m; ++j){
            if(i == votingSet && matrixIndex != ID){
                nodes[matrixIndex].GrantAccess(ID);
                std::cout << matrixIndex << " | ";
                nodes[matrixIndex].ReleaseAccess();
            }
            ++matrixIndex;
        }
    }

    int column;
    column = ID % (m);

    for(int i = 0; i < n; i++){
        if(i%m == column && i != ID){
            nodes[i].GrantAccess(ID);
            std::cout << i << " | ";
            nodes[matrixIndex].ReleaseAccess();
        }
    }
    std::cout << "\n";
}

void Node::GrantAccess(int RequestersID){
    // Push_back and pop_back are both commented out because I was getting this error: 
    // terminate called after throwing an instance of 'std::bad_alloc'
    // what():  std::bad_alloc 
    // Aborted (core dumped)

    //queue.push_back(RequestersID);

    // if(queue[0] != RequestersID){
    //     sleep(100);
    //     std::cout << "Node " << ID << " waiting on another node before responding to node " << RequestersID << ".\n";
    // }

    voted = 'T';
}

void Node::ReleaseAccess(){
    //queue.pop_back();//Commented out for the same reason that Granting Access is commented out.
    voted = 'F';
}

#endif