// roundrobin.cpp
#include "process.h"




vector<Process> roundRobin(vector<Process> processes, int quantum) {
    queue<Process*> q;
    int currentTime = 0;
    int index = 0;

    while (index < processes.size() || !q.empty()) {
        while (index < processes.size() && processes[index].arrivalTime <= currentTime) {
            q.push(&processes[index]);
            index++;
        }

        if (!q.empty()) {
            Process* currentProcess = q.front();
            q.pop();

            int executionTime = min(quantum, currentProcess->remainingTime);
            currentProcess->remainingTime -= executionTime;
            currentTime += executionTime;

            if (currentProcess->remainingTime == 0) {
                currentProcess->finishTime = currentTime;
                currentProcess->turnaroundTime = currentProcess->finishTime - currentProcess->arrivalTime;
                currentProcess->normalizedTurnaroundTime = static_cast<float>(currentProcess->turnaroundTime) / currentProcess->serviceTime;
            } else {
                q.push(currentProcess);
            }
        } else {
            currentTime++;
        }
    }
    return processes;
}



