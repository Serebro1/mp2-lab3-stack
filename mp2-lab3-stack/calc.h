#pragma once

#include "stack.h"
using namespace std;

class TCalc
{
	string infix;
	string postfix;
	TStack<double> StNum;
	TStack<char> StChar;
public:
	TCalc();
	// set, get для тестов
	void SetInfix(string _infix) { infix = _infix; }
	void SetPostfix(string _postfix) { postfix = _postfix; }
	string GetInfix() { return infix; }
	string GetPostfix() { return postfix; }

	int Prior(char op);
	void ToPostfix();
	double CalcPostfix(); //
	double Calcul(); // вычислить арифм. выражение за 1 проход
};
