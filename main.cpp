#include "process.h"
#include "FCFS.h"
#include "RoundRobin.h"
#include "SJF.h"
#include "Priority.h"
#include "display.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;

// Function to compute average turnaround time
float averageTurnaroundTime(const vector<Process>& processes) {
    float totalTurnaroundTime = 0;
    for (const auto& p : processes) {
        totalTurnaroundTime += p.turnaroundTime;
    }
    return totalTurnaroundTime / processes.size();
}

// Function to compute average wait time
float averageWaitTime(const vector<Process>& processes) {
    float totalWaitTime = 0;
    for (const auto& p : processes) {
        totalWaitTime += (p.turnaroundTime - p.serviceTime);
    }
    return totalWaitTime / processes.size();
}

int main() {
    vector<Process> processes;
    string name;
    int arrivalTime, serviceTime;

    // Read input
    cout << "Enter processes (format: name arrivalTime serviceTime), type 'done' to finish:" << endl;
    while (cin >> name) {
        if (name == "done") break;
        cin >> arrivalTime >> serviceTime;
        processes.emplace_back(name, arrivalTime, serviceTime);
    }

    // FCFS Scheduling
    vector<Process> processesFCFS = processes;
    processesFCFS = firstComeFirstServe(processesFCFS);
    float avgTurnaroundFCFS = averageTurnaroundTime(processesFCFS);
    float avgWaitFCFS = averageWaitTime(processesFCFS);
    int completionTimeFCFS = processesFCFS.back().finishTime;

    // SJF Scheduling
    vector<Process> processesSJF = processes;
    processesSJF = shortestJobFirst(processesSJF);
    float avgTurnaroundSJF = averageTurnaroundTime(processesSJF);
    float avgWaitSJF = averageWaitTime(processesSJF);
    int completionTimeSJF = processesSJF.back().finishTime;

    // Priority Scheduling
    vector<Process> processesPriority = processes;
    processesPriority = priorityScheduling(processesPriority);
    float avgTurnaroundPriority = averageTurnaroundTime(processesPriority);
    float avgWaitPriority = averageWaitTime(processesPriority);
    int completionTimePriority = processesPriority.back().finishTime;

    // RR Scheduling
    string algorithm;
    int quantum = 0;

    cout << "Enter scheduling algorithm (FCFS, SJF, Priority, or RR-<quantum>): ";
    cin >> algorithm;

    vector<Process> processesRR = processes;

    if (algorithm == "FCFS") {
        processesRR = firstComeFirstServe(processesRR);
        displayResults(processesRR);
    } else if (algorithm.find("RR-") == 0) {
        try {
            quantum = stoi(algorithm.substr(3));
            processesRR = roundRobin(processesRR, quantum);
            displayResults(processesRR);
        } catch (const invalid_argument& e) {
            cout << "Invalid quantum value!" << endl;
            return 1;
        }
    } else if (algorithm == "SJF") {
        processesRR = shortestJobFirst(processesRR);
        displayResults(processesRR);
    } else if (algorithm == "Priority") {
        processesRR = priorityScheduling(processesRR);
        displayResults(processesRR);
    } else {
        cout << "Invalid algorithm!" << endl;
        return 1;
    }

    // Compute metrics for Round Robin
    float avgTurnaroundRR = averageTurnaroundTime(processesRR);
    float avgWaitRR = averageWaitTime(processesRR);
    int completionTimeRR = processesRR.back().finishTime;

    // Output comparison results
    cout << endl;
    cout << "FCFS Metrics:" << endl;
    cout << "Average Turnaround Time: " << avgTurnaroundFCFS << endl;
    cout << "Average Wait Time: " << avgWaitFCFS << endl;
    cout << "Completion Time: " << completionTimeFCFS << endl;

    cout << endl;
    cout << "SJF Metrics:" << endl;
    cout << "Average Turnaround Time: " << avgTurnaroundSJF << endl;
    cout << "Average Wait Time: " << avgWaitSJF << endl;
    cout << "Completion Time: " << completionTimeSJF << endl;

    cout << endl;
    cout << "Priority Metrics:" << endl;
    cout << "Average Turnaround Time: " << avgTurnaroundPriority << endl;
    cout << "Average Wait Time: " << avgWaitPriority << endl;
    cout << "Completion Time: " << completionTimePriority << endl;

    cout << endl;
    cout << "RR Metrics:" << endl;
    cout << "Average Turnaround Time: " << avgTurnaroundRR << endl;
    cout << "Average Wait Time: " << avgWaitRR << endl;
    cout << "Completion Time: " << completionTimeRR << endl;

    // Determine the best algorithm
    string bestAlgorithm = "FCFS";
    float minTurnaround = avgTurnaroundFCFS;
    float minWait = avgWaitFCFS;
    int minCompletionTime = completionTimeFCFS;

    if (avgTurnaroundRR < minTurnaround && avgWaitRR < minWait && completionTimeRR < minCompletionTime) {
        bestAlgorithm = "RR";
        minTurnaround = avgTurnaroundRR;
        minWait = avgWaitRR;
        minCompletionTime = completionTimeRR;
    }
    if (avgTurnaroundSJF < minTurnaround && avgWaitSJF < minWait && completionTimeSJF < minCompletionTime) {
        bestAlgorithm = "SJF";
        minTurnaround = avgTurnaroundSJF;
        minWait = avgWaitSJF;
        minCompletionTime = completionTimeSJF;
    }
    if (avgTurnaroundPriority < minTurnaround && avgWaitPriority < minWait && completionTimePriority < minCompletionTime) {
        bestAlgorithm = "Priority";
        minTurnaround = avgTurnaroundPriority;
        minWait = avgWaitPriority;
        minCompletionTime = completionTimePriority;
    }

    cout << endl;
    cout << "Best Algorithm: " << bestAlgorithm << endl;
    cout << "Average Turnaround Time: " << minTurnaround << endl;
    cout << "Average Wait Time: " << minWait << endl;
    cout << "Completion Time: " << minCompletionTime << endl;

    return 0;
}
