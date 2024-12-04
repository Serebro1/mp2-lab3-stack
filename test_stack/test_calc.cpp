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
	std::string expression = "(1+2*sin())";
	std::string wrongExpr = "(1+2*sin(3)";
	TCalc calc;
	ASSERT_NO_THROW(calc.Check(expression));
	ASSERT_ANY_THROW(calc.Check(wrongExpr));
}

TEST(TCalc, can_set_infix_expression) {
	std::string expression = "1.1/(2+3*(4-5)^6)+7/8";
	TCalc calc;
	ASSERT_NO_THROW(calc.SetInfix(expression));
}

TEST(TCalc, can_get_infix_expression) {
	std::string expression = "1.1/(2+3*(4-5)^6)+7/8";
	TCalc calc;

	calc.SetInfix(expression);
	ASSERT_NO_THROW(calc.GetInfix());
	EXPECT_EQ(calc.GetInfix(), expression);
}

TEST(TCalc, can_set_postfix_expression) {
	std::string expression = "1 2 3 4 5 - 6 ^ * + / 7 8 / +";
	TCalc calc;
	ASSERT_NO_THROW(calc.SetPostfix(expression));
}

TEST(TCalc, can_get_postfix_expression) {
	std::string expression = "1 2 3 4 5 - 6 ^ * + / 7 8 / +";
	TCalc calc;

	calc.SetPostfix(expression);
	ASSERT_NO_THROW(calc.GetPostfix());
	EXPECT_EQ(calc.GetPostfix(), expression);
}

TEST(TCalc, can_calculate_infix_expression) {
	std::string expression = "1.1/(2.0+3.0*(4.0-5.0)^6.0)+7.0/8.0";

	TCalc calc;

	calc.SetInfix(expression);
	ASSERT_NO_THROW(calc.Calcul());
	EXPECT_EQ(calc.Calcul(), 1.095);
}


TEST(TCalc, can_calculate_postfix_expression) {
	std::string expression = "1 2 3 4 5 - 6 ^ * + / 7 8 / +";
	TCalc calc;

	calc.SetPostfix(expression);
	ASSERT_NO_THROW(calc.CalcPostfix());
	EXPECT_EQ(calc.CalcPostfix(), 1.075);
}

TEST(TCalc, can_calculate_sin_function) {
	std::string expression = "1.0+sin(pi/2.0)";

	TCalc calc;

	calc.SetInfix(expression);
	EXPECT_EQ(calc.Calcul(), 2);
}
TEST(TCalc, can_calculate_cos_function) {
	std::string expression = "1.0+cos(pi/2.0)";

	TCalc calc;

	calc.SetInfix(expression);
	EXPECT_EQ(calc.Calcul(), 1);
}
TEST(TCalc, can_calculate_tan_function) {
	std::string expression = "1.0+tan(0)";

	TCalc calc;

	calc.SetInfix(expression);
	EXPECT_EQ(calc.Calcul(), 1);
}

TEST(TCalc, can_calculate_pow_function) {
	std::string expression = "3+3^(1/2)";

	TCalc calc;

	calc.SetInfix(expression);
	EXPECT_EQ(calc.Calcul(), 3.0+sqrt(3.0)); // 3 + pow(3.0, 0.5)
}

TEST(TCalc, throw_when_expression_with_wrong_function) {
	std::string expression = "1+sin(p/2)";

	TCalc calc;

	calc.SetInfix(expression);
	ASSERT_ANY_THROW(calc.Calcul());
}

TEST(TCalc, throw_when_divide_zero) {
	std::string expression = "1/0";

	TCalc calc;

	calc.SetInfix(expression);
	ASSERT_ANY_THROW(calc.Calcul());
}