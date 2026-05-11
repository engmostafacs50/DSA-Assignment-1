#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include "Process.h"
#include "Scheduler.h"

using namespace std;

Scheduler::Scheduler(int quantumTime)
{
	this->quantumTime = quantumTime;
	this->currTime = 0;
}

void Scheduler::sortProcessesById()
{
	auto comp = [](const Process &p1, const Process &p2)
	{
		return p1.getId() < p2.getId();
	};

	stable_sort(lastScheduleProcesses.begin(), lastScheduleProcesses.end(), comp);
}

void Scheduler::sortProcessesByArrivalTime()
{
	auto comp = [](const Process &p1, const Process &p2)
	{
		return p1.getArrivalTime() < p2.getArrivalTime();
	};

	stable_sort(lastScheduleProcesses.begin(), lastScheduleProcesses.end(), comp);
}

void Scheduler::scheduleProcesses(const vector<Process> &processes)
{
	currTime = 0;
	lastScheduleProcesses = processes;
	int processPointer = 0;
	sortProcessesByArrivalTime();

	auto addProcesses = [&]()
	{
		while (processPointer < lastScheduleProcesses.size() &&
			   lastScheduleProcesses[processPointer].getArrivalTime() <= currTime)
		{
			processQueue.push(processPointer);
			processPointer++;
		}
	};

	cout << "Queue Updates:" << endl;

	while (!processQueue.empty() || processPointer < lastScheduleProcesses.size())
	{
		if (processQueue.empty())
		{
			currTime = lastScheduleProcesses[processPointer].getArrivalTime();
			addProcesses();
		}
		else
		{
			int frontIdx = processQueue.front();
			processQueue.pop();
			Process &frontProcess = lastScheduleProcesses[frontIdx];

			if (frontProcess.remainingTime <= quantumTime)
			{
				currTime += frontProcess.remainingTime;
				frontProcess.remainingTime = 0;
				frontProcess.completionTime = currTime;
				frontProcess.turnaroundTime = currTime - frontProcess.getArrivalTime();
				frontProcess.waitingTime = frontProcess.turnaroundTime - frontProcess.getBurstTime();
			}
			else
			{
				currTime += quantumTime;
				frontProcess.remainingTime -= quantumTime;
			}

			addProcesses();

			if (frontProcess.remainingTime)
				processQueue.push(frontIdx);
		}

		copy = processQueue;
		cout << "[";
		while (!copy.empty())
		{
			int idx = copy.front();
			copy.pop();
			cout << "P" << lastScheduleProcesses[idx].getId() << (!copy.empty() ? ", " : "");
		}

		if (processQueue.empty())
			cout << "Empty";
		cout << "]" << endl;
	}
}

void Scheduler::showLastScheduleLog()
{
	sortProcessesById();
	float totalWaitingTime = 0;

	cout << left
		 << setw(12) << "Process"
		 << setw(20) << "Completion Time"
		 << setw(20) << "Turnaround Time"
		 << setw(20) << "Waiting Time"
		 << endl
		 << endl;

	for (const auto &p : lastScheduleProcesses)
	{
		cout << left
			 << setw(12) << ("P" + to_string(p.getId()))
			 << setw(20) << p.completionTime
			 << setw(20) << p.turnaroundTime
			 << setw(20) << p.waitingTime
			 << endl
			 << endl;

		totalWaitingTime += p.waitingTime;
	}
	
	cout << "Average Waiting Time : ";
	cout << fixed << setprecision(3) << (totalWaitingTime / lastScheduleProcesses.size()) << endl;
}
