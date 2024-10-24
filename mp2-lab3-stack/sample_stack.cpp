#include <iostream>
#include <string>
#include "stack.h"

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

void main()
{
	
	setlocale(LC_ALL, "Russian");
	cout << "“естирование программ проверки правильности расстановки скобок" << endl;


}