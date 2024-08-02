# Strategic-Scheduling-Performance-Assessment-Tool


This project implements and compares four process scheduling algorithms:
- **First-Come-First-Serve (FCFS)**
- **Shortest Job First (SJF)**
- **Priority Scheduling**
- **Round Robin (RR)**

## Project Overview

The project reads a list of processes and their attributes (name, arrival time, and service time) from user input and applies one or more scheduling algorithms to these processes. The user can choose between FCFS, SJF, Priority Scheduling, and Round Robin. The project then computes and displays various performance metrics for each scheduling algorithm and identifies the best algorithm based on average turnaround time and completion time.

## Scheduling Algorithms

### 1. First-Come-First-Serve (FCFS)
- **Description**: Processes are executed in the order of their arrival times. Once a process starts execution, it runs until completion.
- **Best Used When**: Simplicity is preferred and processes have similar lengths. FCFS is straightforward but may lead to the "convoy effect" where shorter processes wait behind longer ones.
- **Advantages**:
  - Easy to implement and understand.
  - No starvation (all processes eventually get executed).
- **Disadvantages**:
  - Can lead to high average waiting time and turnaround time, especially with processes of varying lengths.
  - Not optimal for all types of workloads.

### 2. Shortest Job First (SJF)
- **Description**: Processes with the shortest service times are executed first. This is a non-preemptive algorithm.
- **Best Used When**: The process lengths are known beforehand and the system can prioritize shorter jobs to improve turnaround times.
- **Advantages**:
  - Minimizes average waiting time and turnaround time.
  - More efficient for processes with varying lengths.
- **Disadvantages**:
  - Not feasible if process lengths are not known in advance.
  - Can cause starvation for longer processes.

### 3. Priority Scheduling
- **Description**: Each process is assigned a priority, and processes are executed based on priority. Lower service time means higher priority in this implementation.
- **Best Used When**: The system requires prioritization of processes based on certain criteria (e.g., importance).
- **Advantages**:
  - Allows for prioritization of important processes.
  - Flexible based on priority values.
- **Disadvantages**:
  - Can lead to starvation of low-priority processes.
  - Requires careful consideration of priority values.

### 4. Round Robin (RR)
- **Description**: Each process is assigned a fixed time slice (quantum). Processes are executed in a cyclic order, with each process getting its turn for a time slice.
- **Best Used When**: Fair allocation of CPU time is needed, and processes are of varying lengths.
- **Advantages**:
  - Fair allocation of CPU time, preventing any single process from monopolizing the CPU.
  - Suitable for time-sharing systems.
- **Disadvantages**:
  - Higher average turnaround time compared to SJF and Priority if quantum is not well-tuned.
  - Context switching overhead can be high.

## Files and Functions

### Files

- **`process.h`**: Defines the `Process` class which includes process attributes like name, arrival time, service time, finish time, turnaround time, and normalized turnaround time.
- **`FCFS.cpp`**: Contains the implementation of the FCFS scheduling algorithm.
- **`SJF.cpp`**: Contains the implementation of the Shortest Job First scheduling algorithm.
- **`Priority.cpp`**: Contains the implementation of Priority Scheduling.
- **`RoundRobin.cpp`**: Contains the implementation of the Round Robin scheduling algorithm.
- **`display.cpp`**: Provides functions to display the results of scheduling algorithms.
- **`Makefile`**: Provides rules to compile the project and run multiple test cases.

### Main Function

- **`main.cpp`**: The main function reads input processes, applies the chosen scheduling algorithm, and displays the results. It also compares the performance metrics (average turnaround time, average wait time, and completion time) of all algorithms and identifies the best one based on these metrics.
## Evaluating Scheduling Algorithms

When comparing scheduling algorithms, **average turnaround time** and **average waiting time** are crucial metrics to determine their efficiency and effectiveness. Here’s how these metrics can indicate the optimization of an algorithm:

### Average Turnaround Time

- **Definition**: The average turnaround time is the mean time taken for a process to complete, from its arrival in the queue to its finish.
- **Indicator**: A lower average turnaround time signifies that processes are completing faster, which generally improves system responsiveness and user experience. An optimized algorithm will have a lower average turnaround time, indicating effective management of process execution and minimal delays.

### Average Waiting Time

- **Definition**: The average waiting time is the mean time a process spends waiting in the ready queue before it begins execution.
- **Indicator**: A lower average waiting time means that processes experience less delay before starting execution, which reduces idle time and enhances system throughput. An optimized algorithm will minimize the average waiting time, ensuring that processes are started sooner.

### Summary

- **Lower Average Turnaround Time**: Indicates better overall performance for completing processes quickly.
- **Lower Average Waiting Time**: Indicates better performance in terms of how quickly processes start execution.

