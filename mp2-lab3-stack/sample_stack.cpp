#include <iostream>
#include <string>
#include "stack.h"
#include "calc.h"
using namespace std;

bool Check(string str) {
	TStack<char> stack(str.length());
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(') stack.Push('(');
		if (str[i] == ')')
			if (stack.isEmpty()) return false;
			else stack.Pop();
	}
	if (!stack.isEmpty()) return false;
	return true;
}

/*
������ �������� ��������: �����/������������ �����.
� ������� ������ ����������� ����������(�,b,c), � ������� ����� ������������� �����
��������, ���������, ���������,�������, ���������� � �������
����� �������: ������������� ������� (�����, �������, ����������)
������, ������� �� ������ ����. '( )'

������:����� ��������� �������� ���������.

���: ���������� ����������, � ������� �������� ����. ��������� � ������� �����

*/
void main()
{

	setlocale(LC_ALL, "Russian");
	setlocale(LC_NUMERIC, "C");
	string str;
	cout << "������� �������������� ���������:" << endl;
	cin >> str;
	TCalc calc;
	calc.SetInfix(str);
	/*calc.ToPostfix();
	cout << calc.GetPostfix() << endl;*/
	cout << calc.Calcul() << endl;
}

