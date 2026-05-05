#include "Process.h"

using namespace std;

Process::Process(int id, int arrivalTime, int burstTime)
{
	this->id = id;
	this->arrivalTime = arrivalTime;
	this->burstTime = burstTime;
	this->remainingTime = burstTime;
	this->completionTime = this->turnaroundTime = this->waitingTime = 0;
}

int Process::getId() const
{
	return id;
}

int Process::getArrivalTime() const
{
	return arrivalTime;
}

int Process::getBurstTime() const
{
	return burstTime;
}