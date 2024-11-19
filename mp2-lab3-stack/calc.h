#pragma once

#include "stack.h"
using namespace std;

enum Opers {
	openbr, unarMns, pls, mns, mlt, dv, pw, sn, cs, tn
};

class TCalc
{
	string infix;
	string postfix;
	TStack<double> StNum;
	TStack<char> StChar;
	TStack<Opers> StOpers;
public:
	TCalc();
	// set, get для тестов
	void SetInfix(string _infix) { infix = _infix; }
	void SetPostfix(string _postfix) { postfix = _postfix; }
	string GetInfix() { return infix; }
	string GetPostfix() { return postfix; }

	int Prior(const char* op);
	int Prior(const Opers& op);
	void ToPostfix();
	double CalcPostfix(); //
	double Calcul(); // вычислить арифм. выражение за 1 проход
	void Check(string str); // проверка скобок?
	Opers transform(const char* c);

};
