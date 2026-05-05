#pragma once

#include <vector>

using namespace std;

class RotatedBinarySearch
{
private:
	vector<double> vec;
	double target;
	int comparisonsCount;

public:
	RotatedBinarySearch(vector<double> v, double t);
	int binarySearch();
	void printResult();
	int getTotalComparisons() const;
};