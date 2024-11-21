#pragma once

#include "stack.h"
//using namespace std;

enum Opers {
	openbr, unarMns, pls, mns, mlt, dv, pw, sn, cs, tn
};

class TCalc
{
	std::string infix;
	std::string postfix;
	TStack<double> StNum;
	TStack<char> StChar;
	TStack<Opers> StOpers;
public:
	TCalc();
	// set, get ��� ������
	void SetInfix(std::string _infix) { infix = _infix; }
	void SetPostfix(std::string _postfix) { postfix = _postfix; }
	std::string GetInfix() { return infix; }
	std::string GetPostfix() { return postfix; }

	int Prior(const char* op);
	int Prior(const Opers& op);
	void ToPostfix();
	double CalcPostfix(); //
	double Calcul(); // ��������� �����. ��������� �� 1 ������
	void Check(std::string str); // �������� ������?
	Opers transform(const char* c);

};
