#pragma once
#include "Tstack.h"
#include <string>
using namespace std;
class TCalculator {
	std::string expr;
	std::string postfix;
	Tstack<char> st_c;
	Tstack<double> st_d;
public:
	TCalculator() :st_c(100) {}
	void SetExpr(string S) { expr = S; }
	string GetExpr() {
		return expr;
	}
	std::string GetPostfix() {
		return postfix;
	}
	bool check() {
		st_c.clear();
		for (int i = 0; i < expr.size(); i++) {
			if (expr[i] = '(') st_c.push(expr[i]);
			if (expr[i] == ')') {
				if (st_c.IsEmpty())return 0;
				else st_c.pop();
			}
		}
		return st_c.IsEmpty();
	}
	int prior(char c) {
		if (c == '(') return 0;
		if ((c == '+') || (c == '-'))return 1;
		if ((c == '*') || (c == '/'))return 2;
	}
	void ToPostfix() {
		int i = 0;
		string str = "(";
		str += expr;
		str += ")";
		st_c.clear(); postfix = "";
		for (i; i < (str.size()); i++) {
			if (str[i] == '(')st_c.push(str[i]);
			if (((str[i] >= '0') && (str[i] <= '9')) || (str[i] == '.'))postfix += str[i];
			if (str[i] == ')') {
				char tmp = st_c.pop();
				while (tmp != '(') {
					postfix += tmp;
					tmp = st_c.pop();
				}
			}
			if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/')) postfix += " "; {
				char tmp = st_c.pop();
				while (prior(str[i]) <= prior(tmp)) {
					postfix += tmp;
					tmp = st_c.pop();
				}
				st_c.push(tmp);
				st_c.push(str[i]);
			}
		}
	}
	double Calc() {
		st_d.clear();
		char* tmp; double res;
		for (int i = 0; i < postfix.length(); i++) {
			if ((postfix[i] >= '0') && (postfix[i] <= '9')) {
				double d = strtod(&postfix[i], &tmp);
				i = tmp - &postfix[0] - 1;
				st_d.push(d);
			}
			if ((postfix[i] == '+') || (postfix[i] == '-') || (postfix[i] == '*') || (postfix[i] == '/')) {
				double op1, op2;
				op2 = st_d.pop();
				op1 = st_d.pop();
				switch (postfix[i])
				{
				case '+': res = op1 + op2;
					break;
				case '-': res = op1 - op2;
					break;
				case '*': res = op1 * op2;
					break;
				case ('/'): res = op1 / op2;
					break;
				default:
					break;
				}
				st_d.push(res);
			}
		}
		if (st_d.IsEmpty()) throw 1;
		res = st_d.pop();
		if (!st_d.IsEmpty()) throw - 1;
		return res;
	}
};