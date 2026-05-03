#include"ExpressionEvaluator.h"
#include<iostream>
using namespace std; 
int main()
{
	Expression expression("(1+(4+5+2)-3)+(6+8)");
	expression.evaluate();
	cout << expression.getResult() << endl;
}