

#include "process.h"



void displayResults(const vector<Process>& processes) {
    cout << "Finish time for each process: ";
    for (const auto& p : processes) {
        cout << endl<<p.name<< "-"<< p.finishTime << endl;
    }
    cout << endl;

    cout << "Process sequence in which they will finish: ";
    for (const auto& p : processes) {
        cout << endl<<p.name <<" ";
    }
    cout << endl;

    cout << "Turnaround time for each process: ";
    for (const auto& p : processes) {
        cout <<endl<< p.name<< ": " << p.turnaroundTime <<endl;
    }
    cout << endl;
}

