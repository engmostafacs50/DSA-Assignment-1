#pragma once
#include <cctype>
#include <stack>
#include <string>

using namespace std;

class Expression
{
private:
	string expression;
	bool isCalculated;
	long long result;

	long long evaluateWithStack(int idx);
	pair<long long, int> evaluateWithRecursion(int idx);
	
	public:
	Expression(const string &expression);
	void updateExpression(const string &s);
	long long evaluateWithStack();
	long long evaluateWithRecursion();
};
