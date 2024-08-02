#include "process.h"
#include <algorithm>



vector<Process> shortestJobFirst(vector<Process> processes) {
    int currentTime = 0;
    // Sort processes by service time for SJF
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.serviceTime < b.serviceTime;
    });

    for (auto& p : processes) {
        int startTime = max(currentTime, p.arrivalTime);
        p.finishTime = startTime + p.serviceTime;
        p.turnaroundTime = p.finishTime - p.arrivalTime;
        p.normalizedTurnaroundTime = static_cast<float>(p.turnaroundTime) / p.serviceTime;

        currentTime = p.finishTime;
    }
    return processes;
}

