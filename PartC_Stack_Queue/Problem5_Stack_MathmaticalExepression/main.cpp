#include "ExpressionEvaluator.h"
#include <iostream>

using namespace std;

int main()
{
	string s = "10 + 11 + 12 - 11 - (1 + 1)"; // cin >> s;
	Expression expression(s);
	cout << expression.evaluateWithRecursion() << endl;
	cout << expression.evaluateWithStack() << endl;
}