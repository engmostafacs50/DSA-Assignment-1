#include"NextGreaterNumber.h"
#include<iostream>
using namespace std; 
int main()
{
	cout << "\nTest case one ===\n"; 
	vector<int>nums1 = {1 , 2 , 1};
	NextGreaterNumber obj1(nums1); 
	vector<int> res1 = obj1.solve(); 
	obj1.printResult(0, res1); 

	cout << "\nTest case two ===\n";
	vector<int>nums2 = { 1 , 2 , 3 , 4 , 3};
	NextGreaterNumber obj2(nums2);
	vector<int> res2 = obj2.solve();
	obj2.printResult(0, res2);
}