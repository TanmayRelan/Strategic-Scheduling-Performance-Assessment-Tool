// FCFS.cpp

#include "process.h"



vector<Process> firstComeFirstServe(vector<Process> processes) {
    int currentTime = 0;
    
    for (auto& p : processes) {
        int startTime = max(currentTime, p.arrivalTime);
        p.finishTime = startTime + p.serviceTime;
        p.turnaroundTime = p.finishTime - p.arrivalTime;
        p.normalizedTurnaroundTime = static_cast<float>(p.turnaroundTime) / p.serviceTime;

        currentTime = p.finishTime;
    }
    return processes;
}



