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

pair<long long, int> Expression::evaluateWithRecursion(int idx)
{
	long long evalRes = 0;
	int sign = 1;

	while (idx < expression.size())
	{
		const auto &ch = expression[idx];
		if (ch == ' ' || isdigit(ch))
		{
			long long digit = 0;
			while (idx < expression.size() && isdigit(expression[idx]))
			{
				digit = digit * 10 + (expression[idx] - '0');
				idx++;
			}
			evalRes += sign * digit;

			if (ch == ' ')
				idx++;

			continue;
		}

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
			pair<long long, int> bracketRes = evaluateWithRecursion(idx + 1);
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

		idx++;
	}

	return {evalRes, idx - 1};
}

long long Expression::evaluateWithStack(int idx)
{
	stack<pair<long long, int>> stk; // Stores {evalRes (computed before the bracket), sign (of the bracket)};
	long long evalRes = 0;
	int sign = 1;

	while (idx < expression.size())
	{
		const auto &ch = expression[idx];
		if (ch == ' ' || isdigit(ch))
		{
			long long digit = 0;
			while (idx < expression.size() && isdigit(expression[idx]))
			{
				digit = digit * 10 + (expression[idx] - '0');
				idx++;
			}
			evalRes += sign * digit;

			if (ch == ' ')
				idx++;

			continue;
		}

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
			stk.push({evalRes, sign});
			evalRes = 0;
			sign = 1;
			break;
		}
		case ')':
		{
			auto [prevRes, bracketSign] = stk.top();
			stk.pop();
			evalRes = prevRes + bracketSign * evalRes;
			break;
		}
		}

		idx++;
	}

	return evalRes;
}

long long Expression::evaluateWithRecursion()
{
	if (isCalculated)
		return result;
	return result = evaluateWithRecursion(0).first;
}

long long Expression::evaluateWithStack()
{
	if (isCalculated)
		return result;
	return result = evaluateWithStack(0);
}
