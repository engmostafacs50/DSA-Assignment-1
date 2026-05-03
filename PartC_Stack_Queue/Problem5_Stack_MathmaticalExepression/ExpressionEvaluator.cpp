#include <cctype>
#include <stack>
#include <string>
#include "ExpressionEvaluator.h"

using namespace std;

Expression::Expression(const string &s)
{
	this->expression = s;
	this->isCalculated = false;
	this->result = 0;
}

void Expression::updateExpression(const string &s)
{
	this->expression = s;
	this->isCalculated = false;
	this->result = 0;
}

pair<long long, int> Expression::evaluate(int idx)
{
	long long evalRes = 0;
	int sign = 1;
	while (idx < expression.size())
	{
		const auto &ch = expression[idx];
		if (ch == ' ')
		{
			idx++;
			continue;
		}

		if (!isdigit(ch))
		{
			switch (ch)
			{
			case '+':
			{
				sign = 1;
				break;
			}
			case '-':
			{
				sign = -1;
				break;
			}
			case '(':
			{
				pair<long long, int> bracketRes = evaluate(idx + 1);
				evalRes += sign * bracketRes.first;
				idx = bracketRes.second;
				break;
			}
			case ')':
			{
				return {evalRes, idx};
				break;
			}
			}
		}
		else
			evalRes += sign * (ch - '0');

		idx++;
	}

	return {evalRes, idx - 1};
}

long long Expression::evaluate()
{
	if (isCalculated)
		return result;
	return result = evaluate(0).first;
}
