#include "ExpressionEvaluator.h"
#include <iostream>

using namespace std;

int main()
{
	string s = "(1+(4+5+2)-3)+(6+8)";
	// cin >> s;
	Expression expression(s);
	cout << expression.evaluate() << endl;
}