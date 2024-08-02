#ifndef ROUNDRROBIN_H
#define ROUNDRROBIN_H

#include "process.h"
#include <vector>

std::vector<Process> roundRobin(std::vector<Process> processes, int quantum);

#endif
