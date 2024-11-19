/*
* выкинуть исключения при: неправильных скобках, несущ. функциях, при неправильном вводе выражения
* может выполнять все операции и функции и правильно ли
* перевод в постфиксную форму
* вычисление в постфиксной форме
* вычисление в инфиксной форме
* set/get infix, postfix
*/

#include "gtest.h"
#include "calc.cpp"

TEST(TCalc, can_check_the_wrong_brackets_in_expression) {
	string expression = "(1+2*sin())";
	string wrongExpr = "(1+2*sin(3)";
	TCalc calc;
	ASSERT_NO_THROW(calc.Check(expression));
	ASSERT_ANY_THROW(calc.Check(wrongExpr));
}

TEST(TCalc, can_set_infix_expression) {
	string expression = "1.1/(2+3*(4-5)^6)+7/8";
	TCalc calc;
	ASSERT_NO_THROW(calc.SetInfix(expression));
}

TEST(TCalc, can_get_infix_expression) {
	string expression = "1.1/(2+3*(4-5)^6)+7/8";
	TCalc calc;

	calc.SetInfix(expression);
	ASSERT_NO_THROW(calc.GetInfix());
	EXPECT_EQ(calc.GetInfix(), expression);
}

TEST(TCalc, can_set_postfix_expression) {
	string expression = "1 2 3 4 5 - 6 ^ * + / 7 8 / +";
	TCalc calc;
	ASSERT_NO_THROW(calc.SetPostfix(expression));
}

TEST(TCalc, can_get_postfix_expression) {
	string expression = "1 2 3 4 5 - 6 ^ * + / 7 8 / +";
	TCalc calc;

	calc.SetPostfix(expression);
	ASSERT_NO_THROW(calc.GetPostfix());
	EXPECT_EQ(calc.GetPostfix(), expression);
}

TEST(TCalc, can_calculate_infix_expression) {
	string expression = "1.1/(2+3*(4-5)^6)+7/8";

	TCalc calc;

	calc.SetInfix(expression);
	ASSERT_NO_THROW(calc.Calcul());
	EXPECT_EQ(calc.Calcul(), 1.095);
}


TEST(TCalc, can_calculate_postfix_expression) {
	string expression = "1 2 3 4 5 - 6 ^ * + / 7 8 / +";
	TCalc calc;

	calc.SetPostfix(expression);
	ASSERT_NO_THROW(calc.CalcPostfix());
	EXPECT_EQ(calc.CalcPostfix(), 1.075);
}

TEST(TCalc, can_calculate_sin_function) {
	string expression = "1+sin(pi/2)";

	TCalc calc;

	calc.SetInfix(expression);
	EXPECT_EQ(calc.Calcul(), 2);
}

TEST(TCalc, can_calculate_pow_function) {
	string expression = "3+3^(1/2)";

	TCalc calc;

	calc.SetInfix(expression);
	EXPECT_EQ(calc.Calcul(), 3.0+sqrt(3.0)); // 3 + pow(3.0, 0.5)
}

TEST(TCalc, throw_when_expression_with_wrong_function) {
	string expression = "1+sn(p/2)";

	TCalc calc;

	calc.SetInfix(expression);
	ASSERT_ANY_THROW(calc.Calcul());
}