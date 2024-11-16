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
строка содержит операнды: целые/вещественные числа.
В крайнем случае обозначения переменных(а,b,c), в которых позже подставляется число
Сложение, вычитание, умножение,деление, возведение в степень
Более сложное: использование функций (синус, косинус, экспонента)
скобки, считаем их одного вида. '( )'

Задача:Нужно посчитать значение выражения.

Вид: консольное приложение, в котором вводится ариф. выражение и выдаётся ответ

*/
void main()
{

	setlocale(LC_ALL, "Russian");
	setlocale(LC_NUMERIC, "C");
	string str;
	cout << "Введите арифметическое выражение:" << endl;
	cin >> str;
	TCalc calc;
	calc.SetInfix(str);
	/*calc.ToPostfix();
	cout << calc.GetPostfix() << endl;*/
	cout << calc.Calcul() << endl;
}

