#pragma once

using namespace std;

class Process
{
private:
	int id;
	int arrivalTime;
	int burstTime;

public:
	int remainingTime;
	int completionTime;
	int turnaroundTime;
	int waitingTime;

	Process() {};
	Process(int id, int arrivalTime, int burstTime);
	int getId() const;
	int getArrivalTime() const;
	int getBurstTime() const;
};
