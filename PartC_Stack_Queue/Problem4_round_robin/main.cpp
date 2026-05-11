#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include "Process.h"
#include "Scheduler.h"

using namespace std;

int main()
{
	int quantumTime, processesCount;
	cin >> quantumTime >> processesCount;

	vector<Process> processes(processesCount);
	for (int p = 0; p < processesCount; p++)
	{
		int id, arrivalTime, burstTime;
		cin >> id >> arrivalTime >> burstTime;
		processes[p] = Process(id, arrivalTime, burstTime);
	}

	Scheduler roundRobinSchedular(quantumTime);
	cout << endl;
	roundRobinSchedular.scheduleProcesses(processes);
	cout << endl;
	roundRobinSchedular.showLastScheduleLog();

	return 0;
}