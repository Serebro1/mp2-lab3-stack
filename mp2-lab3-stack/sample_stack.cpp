#include <iostream>
#include <string>
#include "stack.h"
#include "calc.h"
using namespace std;
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

