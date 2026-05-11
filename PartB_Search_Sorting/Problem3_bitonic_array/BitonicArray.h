#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class BitonicArray
{
private:
	vector<T> arr;
	void bubbleSort(int left, int right);
	void selectionSort(int left, int right);
	int comparisonsCount;
	int swapsCount;

public:
	BitonicArray(vector<T> inputArray);
	int search(T target) const;
	void printData() const;
};

template <typename T>
inline BitonicArray<T>::BitonicArray(vector<T> inputArray)
{
	arr = inputArray;
	int mid = arr.size() / 2;
	comparisonsCount = swapsCount = 0;
	this->bubbleSort(0, mid);
	this->selectionSort(mid, arr.size());
}

template <typename T>
inline void BitonicArray<T>::bubbleSort(int left, int right) // for the left half
{
	for (int i = left; i < right; i++)
	{
		bool isOrdered = false;
		for (int j = left; j < right - i - 1; j++)
		{
			comparisonsCount++;
			if (arr.at(j) > arr.at(j + 1))
			{
				swapsCount++;
				swap(arr.at(j), arr.at(j + 1));
				isOrdered = true;
			}
		}
		if (!isOrdered)
			break;
	}
}

template <typename T>
inline void BitonicArray<T>::selectionSort(int left, int right) // for the right half
{
	for (int i = left; i < right - 1; i++)
	{
		int j;
		int maxIdex = i;
		for (j = i + 1; j < right; j++)
		{
			comparisonsCount++;
			if (arr.at(maxIdex) < arr.at(j))
			{
				maxIdex = j;
			}
		}
		swapsCount++;
		swap(arr.at(maxIdex), arr.at(i));
	}
	return;
}

template <typename T>
inline int BitonicArray<T>::search(T target) const
{
	int index = 0;
	for (T num : arr)
	{
		if (num == target)
			return index;
		index++;
	}
	return -1;
}

template <typename T>
inline void BitonicArray<T>::printData() const
{
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Total comparisons count = " << comparisonsCount << endl;
	cout << "Total swaps count = " << swapsCount << endl;
}
