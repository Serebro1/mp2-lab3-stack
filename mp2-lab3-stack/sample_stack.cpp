#include <iostream>
#include <string>
#include "stack.h"
#include "calc.h"

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
	std::string str;
	std::cout << "Введите арифметическое выражение:" << std::endl;
	std::cin >> str;
	TCalc calc;
	calc.SetInfix(str);
	/*calc.ToPostfix();
	cout << calc.GetPostfix() << endl;*/
	std::cout << calc.Calcul() << std::endl;

}

