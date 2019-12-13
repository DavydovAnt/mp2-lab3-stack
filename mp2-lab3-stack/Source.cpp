#include <iostream> 
#include "Tstack.h"
#include "Calculator.h"
using namespace std;
int main()
{
	TCalculator c;
	string expr;
	cin >> expr;
	c.SetExpr(expr);
	c.ToPostfix();
	cout << c.Calc();
}