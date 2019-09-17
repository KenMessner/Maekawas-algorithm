//Homework 2 : Maekawas-algorithm and min-min / min-max / sufferage
//Author: Kenneth Messner
//Last Modified: 9/17/2019

#include "Node.h"

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


    std::vector<std::vector<int>> VotingSets;
    std::vector<int> set;

    int votingIndex = 0;//Once this index reaches m, coming nodes will be allocated to the next voting set
    for(int i = 0; i < n; i++){//assigning voting sets
        if(i%m == 0 && i != 0){++votingIndex; VotingSets.push_back(set); set.clear();}//if m nodes have been put in a set, add one to the votingIndex
        nodes[i]->setVotingSet(votingIndex);
        // std::cout << "   #$#$ Node " << i << " voting set is being set to " << votingIndex << ".\n";//Test
        set.push_back(i);
    }
    VotingSets.push_back(set);//Pushes back the last set to the vector of sets

    std::cout << "Voting Sets\n";
    for(int i = 0; i < k; i++){//Printing out voting vectors
        for(int j = 0; j < m; j++){
            std::cout << "|  ID: " << VotingSets[i][j] << " ";//outputting matrix
            if(VotingSets[i][j] < 10){std::cout << " ";}//Fixing the visual
        }
        std::cout << " |\n";
    }

    // Testing inti of nodes and printing out values inside each node
    // for(int i = 0; i < n; i++){
    //     std::cout << "ID: ";
    //     nodes[i]->getID();
    //     std::cout << ", State: " << nodes[i]->getState();
    //     std::cout << ", Voted: " << nodes[i]->getVoted();
    //     std::cout << ", Voting Set: " << nodes[i]->getVotingSet();
    //     std::cout << "\n";
    // }


    // std::cout << "\n";//Break line for styling


    int process, time = 1;
    
    while(time != 0){
        std::cout << "\nWhich process do you want to try to gain access to the CS: ";
        std::cin >> process;
        if(process < 0 || process > n){process = 0; std::cout << "     ***Process DNE, process 0 chosen instead***\n";}

        std::cout << "How many milliseconds do you wan that process to be in the CS (enter 0 to stop homework 2.1): ";
        std::cin >> time;

        if(time != 0){
            std::cout << "\n";
            nodes[process]->setState('W');
            std::cout << "Node " << process << " state set to Wanted. Requests to enter CS sent to Voting Set.\n";
             nodes[process]->Request(*nodes, n);

            nodes[process]->setState('H');
            std::cout << "\n     Process " << process << " entering CS, state changed to Held.\n";
            nodes[process]->Process(time);
        }
    }
}