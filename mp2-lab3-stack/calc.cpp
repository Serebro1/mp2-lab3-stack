#include "calc.h"
#include <string>
TCalc::TCalc()
{
	StNum = TStack<double>(MAX_STACK_SIZE);
	StChar = TStack<char>(MAX_STACK_SIZE);
}
// ������� ��� �������� � �������� ��������� ��������
// ������� ��� � ������ ������ �����
double TCalc::CalcPostfix()
{
	// ������� ���� �� ���������� ��������
	StNum.Clear();
	for (int i = 0; i < postfix.size(); i++)
	{

		char c = postfix[i];
		if (c >= '0' && c <= '9' || c == '.') {
			size_t idx;
			double num = stod(&postfix[i], &idx);
			StNum.Push(num);
			i += idx - 1;
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
			double leftOp, rightOp;
			rightOp = StNum.Pop();
			leftOp = StNum.Pop();
			switch (c)
			{
			case '+':
				StNum.Push(leftOp + rightOp);
				break;
			case '-':
				StNum.Push(leftOp - rightOp);
				break;
			case '*':
				StNum.Push(leftOp * rightOp);
				break;
			case '/':
				if (rightOp == 0.0) throw - 2;
				StNum.Push(leftOp / rightOp);
				break;
			case '^':
				StNum.Push(pow(leftOp, rightOp));
				break;
			}
		}
	}
	double res = StNum.Pop();
	if (!StNum.isEmpty()) throw - 3;
	return res;
}

int TCalc::Prior(char op)
{
	// �� switch-case ����������
	if (op == '+' || op == '-') return 1;
	else if (op == '*' || op == '/') return 2;
	else if (op == '^') return 3;
	return 0;
}

void TCalc::ToPostfix()
{
	postfix = "";
	StChar.Clear();
	string tmpStr = '(' + infix + ')';
	for (int i = 0; i < tmpStr.size(); i++)
	{
		char tmp = tmpStr[i];
		if (tmp == '(') StChar.Push(tmp);
		else if (tmp == ')') {
			char top = StChar.Pop();
			while (top != '(') {
				postfix += ' ';
				postfix += top;
				postfix += ' ';
				top = StChar.Pop();
				
			}
		}
		else if (tmp >= '0' && tmp <= '9' || tmp == '.' || tmp == ',') {
			if (tmp == ',') tmp = '.';
			postfix += tmp;
		}
		else
		{
			postfix += ' ';
			while (Prior(StChar.Top()) >= Prior(tmp))
			{
				postfix += StChar.Pop();
				postfix += ' ';
			}

			StChar.Push(tmp);
			
		}
	}
}

double TCalc::Calcul()
{
/*
* ����� ������� � ��������� �����
* ������: 1.1/(2+3*(4-5)^6)+7/8
* ����������� ������: 1.1 2 3 4 5 - 6 ^ * + / 7 8 / +
* ������
* 1) ���� ������ �����, ������� � ���� �����
* 2) � ����� �������� � ��� ���������� � �������� �������.
* 3) �������� - � ���� �� ����������
* 4) ')' - ����������� ��� �������� �� ')' � �������
* 5) �� ���������� ���������� ���� �������� ������ ���� �����, � � ����� ����� ������ ���� 1 �����
* 6) ���������� ������� ����� ����� ��� �����
* 7) ������� ����� ���������� 2+(-3) ��������� ��� (-3+4)
* 8) ����������� �������. ��� ������� ����� enum
* ������� � ����������� ������� ����������� � ����
* ��� ����������� ������, ���� ���������� �������, �� ��������������� ������� ���� ���������
* � �������� ������� ���������� �������. � ����� ������� ������������ ���(enum) � ���������� ���������� ������������� ����, �� ���� openBrace - '(', plus, minus, mul, div� �.�.
* ��������� ����������� �� �������� � ���� ����� enum
* 
*/
	StNum.Clear();
	StChar.Clear();
	string str = '(' + infix + ')';
	for (int i = 0; i < str.size(); i++)
	{
		char tmp = str[i];
		if (tmp == '(') StChar.Push(tmp);
		else if (tmp >= '0' && tmp <= '9' || tmp == '.' || tmp == ',') {
			if (tmp == ',') tmp = '.';
			size_t idx;
			double num = stod(&str[i], &idx);
			StNum.Push(num);
			i += idx - 1;
		}
		else if (tmp == '+' || tmp == '-' || tmp == '*' || tmp == '/' || tmp == '^') {
			while (Prior(StChar.Top()) >= Prior(str[i])) {
				double leftOp = StNum.Pop();
				double rightOp = StNum.Pop();
				switch (tmp)
				{
				case '+':
					StNum.Push(leftOp + rightOp);
					break;
				case '-':
					StNum.Push(leftOp - rightOp);
					break;
				case '*':
					StNum.Push(leftOp * rightOp);
					break;
				case '/':
					if (rightOp == 0.0) throw - 2;
					StNum.Push(leftOp / rightOp);
					break;
				case '^':
					StNum.Push(pow(leftOp, rightOp));
					break;
				}
			}
			StChar.Push(tmp);
		}
		else if (tmp == ')') {
			char top = StChar.Pop();
			while (top != '(') {
				double rightOp = StNum.Pop();
				double leftOp = StNum.Pop();
				switch (top)
				{
				case '+':
					StNum.Push(leftOp + rightOp);
					break;
				case '-':
					StNum.Push(leftOp - rightOp);
					break;
				case '*':
					StNum.Push(leftOp * rightOp);
					break;
				case '/':
					if (rightOp == 0.0) throw - 2;
					StNum.Push(leftOp / rightOp);
					break;
				case '^':
					StNum.Push(pow(leftOp, rightOp));
					break;
				}
				top = StChar.Pop();
			}
		}
	}
	if (StNum.isEmpty()) throw - 1;
	double res = StNum.Pop();
	if (!StNum.isEmpty()) throw - 2;
	return res;
}