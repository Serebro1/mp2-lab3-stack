#include <iostream>
#include <string>
#include "stack.h"
#include "calc.h"

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
	std::string str;
	std::cout << "������� �������������� ���������:" << std::endl;
	std::cin >> str;
	TCalc calc;
	calc.SetInfix(str);
	/*calc.ToPostfix();
	cout << calc.GetPostfix() << endl;*/
	std::cout << calc.Calcul() << std::endl;

}

