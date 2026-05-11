#pragma once

#include <vector>
#include <queue>
#include "Process.h"

using namespace std;

class Scheduler
{
private:
	int quantumTime;
	int currTime;
	vector<Process> lastScheduleProcesses;
	queue<int> processQueue, copy; // ProcessQueue stores the index of the process in lastScheduleProcess

public:
	Scheduler(int quantumTime);
	void sortProcessesById();
	void sortProcessesByArrivalTime();
	void scheduleProcesses(const vector<Process> &processes);
	void showLastScheduleLog();
};
