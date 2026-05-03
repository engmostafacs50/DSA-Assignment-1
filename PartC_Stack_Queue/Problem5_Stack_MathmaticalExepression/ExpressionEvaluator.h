#pragma once 
#include<cctype>
#include<stack>
#include<string>
using namespace std;
class Expression {
private :
	string expression; 
	stack<int>nums; 
	stack<char>operators; 
	bool isCalculated = false;
	int res{ 0 };

public :
	Expression(string expression) {
		this->expression = expression;
		getNumsAndOperators();
	};

	void getNumsAndOperators()
	{
		for (char chr : expression)
		{
			if (chr == ' ')
				continue;

			if (isdigit(chr))
				nums.push(chr - '0');
			else
				operators.push(chr);
		}
	}

	void evaluate()
	{
		if (isCalculated)
			return;

		while (!operators.empty())
		{
			if (operators.top() == '(')
				return;

			if (operators.top() == ')')
			{
				operators.pop();
				evaluate();
				operators.pop();
				continue;
			}
			
			int num1 = nums.top(); nums.pop();
			char op = operators.top(); operators.pop();

			if (!operators.empty() && operators.top() == ')')
			{
				operators.pop();
				evaluate();
				operators.pop();
			}

			int num2 = nums.top(); nums.pop();

			if (op == '+')
				nums.push(num1 + num2);
			else if (op == '-')
				nums.push(num2 - num1);
		}

		if (nums.size() == 1)
		{
			res = nums.top();
			nums.pop();
			isCalculated = true;
			return;
		}
	}

	int getResult()
	{
		return res;
	}
};

