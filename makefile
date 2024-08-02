CC = g++
CFLAGS = -Wall -std=c++17

all: cpu_scheduler

cpu_scheduler: main.o FCFS.o RoundRobin.o display.o
	$(CC) $(CFLAGS) -o cpu_scheduler main.o FCFS.o RoundRobin.o display.o

main.o: main.cpp FCFS.h RoundRobin.h display.h
	$(CC) $(CFLAGS) -c main.cpp

FCFS.o: FCFS.cpp FCFS.h
	$(CC) $(CFLAGS) -c FCFS.cpp

RoundRobin.o: RoundRobin.cpp RoundRobin.h
	$(CC) $(CFLAGS) -c RoundRobin.cpp

display.o: display.cpp display.h
	$(CC) $(CFLAGS) -c display.cpp

clean:
	rm -f *.o cpu_scheduler
