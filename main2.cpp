//Homework 2.2 : min-min, max-min, sufferage
//Author: Kenneth Messner
//Last Modified: 9/18/2019

#include <iostream>
#include <string>
#include <unistd.h>
#include <math.h>
#include <vector>

void minMin();
void maxMin();
void sufferage();

void process(int task, int machine, int time);
int findMin(int task[7]);
int findMachine(int task, int machine);

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
    std::vector<int> taskMinTimes;

    taskMinTimes.push_back(findMin(task0));
    taskMinTimes.push_back(findMin(task1));
    taskMinTimes.push_back(findMin(task2));
    taskMinTimes.push_back(findMin(task3));
    taskMinTimes.push_back(findMin(task4));
    taskMinTimes.push_back(findMin(task5));
    taskMinTimes.push_back(findMin(task6));
    taskMinTimes.push_back(findMin(task7));

    for(int i = 0; i < 8; ++i){
        std::cout << taskMinTimes[i] << ", ";
    }

    while(!taskMinTimes.empty()){
        int i, min=100, minTime=100;
        for(i = 0; i < taskMinTimes.size(); ++i){
            if(taskMinTimes[i] < min){
                min = i;
                minTime = taskMinTimes[i];
                std::cout << "\n ### Min found: " << min << " with a time of: " << taskMinTimes[i] << ".\n";}
        }
        process(min,findMachine(min, taskMinTimes[min]),minTime);
        taskMinTimes.erase(taskMinTimes.begin()+(i-1));
    }//Continue here and figure out why this for loop never minds a new minimum.**************************************************************************************
}

void maxMin(){

}

void sufferage(){

}

int findMin(int task[7]){
    int min = task[0];

    for(int i = 0; i < 7; ++i){
        if(task[i] < min){min = task[i];}
    }

    return min;
}

int findMachine(int task, int time){
    int machine;

    switch (task)
    {
    case 0:
        for(int i = 0; i < 7; ++i){
            if(task0[i] == time){machine = i;}
        }
        break;
    case 1:
        for(int i = 0; i < 7; ++i){
            if(task1[i] == time){machine = i;}
        }
        break;
    case 2:
        for(int i = 0; i < 7; ++i){
            if(task2[i] == time){machine = i;}
        }
        break;
    case 3:
        for(int i = 0; i < 7; ++i){
            if(task3[i] == time){machine = i;}
        }
        break;
    case 4:
        for(int i = 0; i < 7; ++i){
            if(task4[i] == time){machine = i;}
        }
        break;
    case 5:
        for(int i = 0; i < 7; ++i){
            if(task5[i] == time){machine = i;}
        }
        break;
    case 6:
        for(int i = 0; i < 7; ++i){
            if(task6[i] == time){machine = i;}
        }
        break;
    case 7:
        for(int i = 0; i < 7; ++i){
            if(task7[i] == time){machine = i;}
        }
        break;
    
    default:
        break;
    }
    return machine;
}