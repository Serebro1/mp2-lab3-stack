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

int TCalc::Prior(const char* op)
{
	// �� switch-case ����������
	char oper = *op;
	if (oper == '+' || oper == '-') return 1;
	else if (oper == '*' || oper == '/') return 2;
	else if (oper == '^') return 3;
	else if (*(op - 1) == '(' || *(op + 1) == '(')
		return 4;
	return 0;
}

int TCalc::Prior(const Opers& op)
{
	switch (op)
	{
	case pls: case mns:
		return 1;
	case mlt: case dv:
		return 2;
	case pw:
		return 3;
	case sn: case unarMns: case cs:
		return 4;
	default:
		return 0;
	}
}
Opers TCalc::transform(const char* c)
{
	switch (*c)
	{
	case '+':
		return pls;
	case '-':
		if (*(c-1) == '(')
			return unarMns;
		return mns;
	case '*':
		return mlt;
	case '/':
		return dv;
	case '^':
		return pw;
	case 'S':
		return sn;
	case 'C':
		return cs;
	default:
		break;
	}
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
			const char tmp2 = StChar.Top();
			while (Prior(&tmp2) >= Prior(&tmp))
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
	StOpers.Clear();
	string str = '(' + infix + ')';
	for (int i = 0; i < str.size(); i++)
	{
		char tmp = str[i];
		if (tmp == '(') StOpers.Push(openbr);
		else if (tmp == 'p') StNum.Push(2 * acos(0.0));
		else if (tmp >= '0' && tmp <= '9' || tmp == '.' || tmp == ',') {
			if (tmp == ',') tmp = '.';
			size_t idx;
			double num = stod(&str[i], &idx);
			StNum.Push(num);
			i += idx - 1;
		}
		else if (tmp == '+' || tmp == '-' || tmp == '*' || tmp == '/' || tmp == '^' || tmp == 'S' || tmp == 'C') {
			while (Prior(StOpers.Top()) >= Prior(&str[i])) {
				double leftOp, rightOp;
				switch (StOpers.Pop())
				{
				case pls:
					rightOp = StNum.Pop(), leftOp = StNum.Pop();
					StNum.Push(leftOp + rightOp);
					break;
				case mns:
					rightOp = StNum.Pop(), leftOp = StNum.Pop();
					StNum.Push(leftOp - rightOp);
					break;
				case mlt:
					rightOp = StNum.Pop(), leftOp = StNum.Pop();
					StNum.Push(leftOp * rightOp);
					break;
				case dv:
					rightOp = StNum.Pop(), leftOp = StNum.Pop();;
					if (rightOp == 0.0) throw - 2;
					StNum.Push(leftOp / rightOp);
					break;
				case pw:
					rightOp = StNum.Pop(), leftOp = StNum.Pop();
					StNum.Push(pow(leftOp, rightOp));
					break;
				case unarMns:
					StNum.Push(0.0 - StNum.Pop());
					break;
				case sn:
					StNum.Push(sin(StNum.Pop()));
					break;
				case cs:
					StNum.Push(cos(StNum.Pop()));
					break;
				}
			}
			StOpers.Push(transform(&str[i]));
		}
		else if (tmp == ')') {
			Opers top = StOpers.Pop();
			while (top != openbr) {
				double rightOp;
				double leftOp;
				switch (top)
				{
				case pls:
					rightOp = StNum.Pop(), leftOp = StNum.Pop();
					StNum.Push(leftOp + rightOp);
					break;
				case mns:
					rightOp = StNum.Pop(), leftOp = StNum.Pop();
					StNum.Push(leftOp - rightOp);
					break;
				case mlt:
					rightOp = StNum.Pop(), leftOp = StNum.Pop();
					StNum.Push(leftOp * rightOp);
					break;
				case dv:
					rightOp = StNum.Pop(), leftOp = StNum.Pop();
					if (rightOp == 0.0) throw - 2;
					StNum.Push(leftOp / rightOp);
					break;
				case pw:
					rightOp = StNum.Pop(), leftOp = StNum.Pop();

					StNum.Push(pow(leftOp, rightOp));
					break;
				case unarMns:
					StNum.Push(0.0 - StNum.Pop());
					break;
				case sn:
					StNum.Push(sin(StNum.Pop()));
					break;
				case cs:
					StNum.Push(cos(StNum.Pop()));
					break;
				}
				top = StOpers.Pop();
			}
		}
	}
	if (StNum.isEmpty()) throw - 1;
	double res = StNum.Pop();
	if (!StNum.isEmpty()) throw - 2;
	return res;
}


