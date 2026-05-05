#include "RotatedBinarySearch.h"
#include <iostream>
using namespace std;

RotatedBinarySearch::RotatedBinarySearch(vector<double> v, double t)
{
	vec = v;
	target = t;
	comparisonsCount = 0;
}

int RotatedBinarySearch::binarySearch()
{
	int left = 0, right = vec.size() - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		comparisonsCount++;
		if (vec[mid] == target)
			return mid;

		if (vec[left] == vec[mid] && vec[mid] == vec[right])
		{
			comparisonsCount += 2;
			left++;
			right--;
		}
		else if (vec[left] <= vec[mid])
		{
			comparisonsCount += 5;
			if (vec[left] <= target && target < vec[mid])
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		else
		{
			comparisonsCount += 5;
			if (vec[mid] < target && target <= vec[right])
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
	}

	return -1;
}

void RotatedBinarySearch::printResult()
{
	int result = binarySearch();
	if (result == -1)
	{
		cout << "Target doesn't exist\n";
	}
	else
	{
		cout << "Found at " << result << endl;
	}
	cout << "Total comparisons count = " << comparisonsCount << endl;
}

int RotatedBinarySearch::getTotalComparisons() const
{
	return comparisonsCount;
}