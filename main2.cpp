//Homework 2.2 : min-min, max-min, sufferage
//Author: Kenneth Messner
//Last Modified: 9/18/2019

#include <iostream>
#include <string>
#include <unistd.h>
#include <math.h>

void minMin();
void maxMin();
void sufferage();

//The below arrays list the computation times for machines [0-7] that type of task.
//All 100's in the below arrays are actually computationally infeasible
int task0[7]{13,79,23,71,60,27,2};
int task1[7]{31,13,14,94,60,61,57};
int task2[7]{17,1,100,23,36,8,86};
int task3[7]{19,28,10,4,58,73,40};
int task4[7]{94,75,100,58,100,68,46};
int task5[7]{8,24,3,32,4,94,89};
int task6[7]{10,57,13,1,92,75,29};
int task7[7]{80,17,38,40,66,25,88};

int main(){
    std::cout << "Homework 2.2 | Ken Messner | min-min, max-min, sufferage.\n\n";

    std::cout << "Executing Algorithm Min-Min:\n";
    minMin();

    std::cout << "\nExecuting Algorithm Max-Min:";
    maxMin();

    std::cout << "\nExecuting Algorithm Sufferage:";
    sufferage();
}

void process(int task, int machine, int time){
    std::cout << "Task " << task << " executed on machine " << machine << " had a durration of " << time << " milliseconds.\n";
}

void minMin(){

}

void maxMin(){

}

void sufferage(){

}