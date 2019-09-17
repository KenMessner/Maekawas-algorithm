//Homework 2 : Maekawas-algorithm and min-min / min-max / sufferage
//Author: Kenneth Messner
//Last Modified: 9/17/2019

#include "Node.h"

int CS = 100;//Critical Section Data

int main(){
    std::cout << "This program will execute homework 2 directly after homework 1 has been executed.\n";
    std::cout << "Please enter the number of node you'd like to execute in the Maekawa’s algorithm: ";
    
    int n = 0;//number of nodes
    std::cin >> n;

    Node *nodes[n];//Node pointer array

    //Init nodes and add them to the node array called nodes
    for(int i = 0; i < n; i++){
        Node *P = new Node(i,'R','F');
        nodes[i]=P;
    }

    std::cout << "\n";//Break line for styling

    int k = floor(sqrt(n));//k = number of voting sets and floored as there will not always be a perfect sqrt
    std::cout << "The K value is " << k << " (number of voting sets, floor(sqrt(n))).\n";

    int m = k;//m = number of nodes in each voting set
    std::cout << "The M value is " << k << " (Number of nodes in each voting set).\n";

    std::cout << "\n";//Break line for styling

    int votingIndex = 0;//Once this index reaches m, coming nodes will be allocated to the next voting set
    for(int i = 0; i < n; i++){//assigning voting sets
        if(i%m == 0){++votingIndex;}//if m nodes have been put in a set, add one to the votingIndex
        nodes[i]->setVotingSet(votingIndex);
    }

    //Testing inti of nodes and printing out values inside each node
    for(int i = 0; i < n; i++){
        std::cout << "ID: ";
        nodes[i]->getID();
        std::cout << ", State: ";
        nodes[i]->getState();
        std::cout << ", Voted: ";
        nodes[i]->getVoted();
        std::cout << ", Voting Set: ";
        nodes[i]->getVotingSet();
        std::cout << "\n";
    }
}