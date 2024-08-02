#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Process {
public:
    std::string name;
    int arrivalTime;
    int serviceTime;
    int remainingTime;
    int finishTime;
    int turnaroundTime;
    float normalizedTurnaroundTime;

    Process(std::string n, int a, int s)
        : name(n), arrivalTime(a), serviceTime(s), remainingTime(s),
          finishTime(0), turnaroundTime(0), normalizedTurnaroundTime(0) {}
};

#endif
