#include"ExpressionEvaluator.h"
#include<iostream>
using namespace std; 
int main()
{
	Expression expression("2-1+2");
	expression.evaluate();
	cout << expression.getResult() << endl;
}