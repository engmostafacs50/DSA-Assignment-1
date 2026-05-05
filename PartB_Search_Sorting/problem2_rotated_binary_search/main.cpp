#include <iostream>
#include <vector>
#include "RotatedBinarySearch.h"

int main()
{
	vector<double> v1 = {5, 6, 7, 1, 2, 3, 4};
	RotatedBinarySearch obj(v1, 7);
	obj.printResult();
}