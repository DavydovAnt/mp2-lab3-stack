#pragma once
#include "Stack.h"
#include <string>
using namespace std;
template <class T>
class TCalculator {
	string expr;
	TStack<char> st_char;
public:
	TCalculator() :st_char(100){}
	void SetExpr(string S) { expr = s; }
	string SetExpr() {
		return string;
	}
	bool check() {
		st_char.clear();
		for (int i = 0; i < expr.size(); i++) {
			if (expr[i] = '(') st_char.push(expr[i]);
			if (st.char.IsEmpty())return 0;
			else st_char.pop();
		}
		return st_char.IsEmpty();
	}
};
