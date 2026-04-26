#include"RotatedBinarySearch.h"
#include<vector>
#include<iostream>
int main()
{
	vector<double>v1 = { 5 , 6 , 7 ,1 , 2 , 3 }; 
	RotatedBinarySearch obj(v1, 7); 
	obj.binarySearch();
	obj.printResult();
}