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
	stack<int> nums; // Didn't actually use it

	pair<long long, int> evaluate(int idx);

public:
	Expression(const string &expression);
	void updateExpression(const string &s);
	long long evaluate();
};
