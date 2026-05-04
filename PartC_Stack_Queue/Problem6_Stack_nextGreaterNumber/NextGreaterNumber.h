#pragma once 
#include<iostream>
#include<stack>
#include<vector>
using namespace std; 

class NextGreaterNumber {
private : 
	vector<int>nums; 
	stack<int>st; 

public:
	NextGreaterNumber(vector<int>nums)
	{
		this->nums = nums; 
	}

	vector<int>solve()
	{
		vector<int>result(nums.size(), -1);
		for (int i = 0; i <   nums.size(); i++)
		{
			int current = nums.at(i % nums.size());

			while (!st.empty() && nums.at(st.top()) < current)
			{
				result.at(st.top()) = current; 
				st.pop();
			}

			if (i < nums.size())
				st.push(i); 
		}
		return result; 
	}

	void printResult(int index , vector<int>result)
	{
		if (index == result.size())
			return;
		cout << result.at(index) << " " ;
		printResult(index + 1, result); 
	}
};