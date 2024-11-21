#include "stack.h"

#include "gtest.h"

TEST(TStack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(TStack<int> m(5));
}
TEST(TStack, throws_when_create_stack_with_negative_length)
{
  ASSERT_ANY_THROW(TStack<int> m(-5));
}
TEST(TStack, can_create_copied_stack)
{
	TStack<int> m(5);

	ASSERT_NO_THROW(TStack<int> m1(m));
}

TEST(TStack, copied_stack_is_equal_to_source_one)
{
	TStack<int> a(10);
	for (int i = 0; i < 10; i++)
	{
		a.Push(i + i);
	}
	TStack<int> b(a);
	EXPECT_EQ(a, b);
}

TEST(TStack, compare_equal_stacks_return_true)
{
	const int size = 5;
	TStack<int> v1(size), v2(size);
	v2 = v1;
	ASSERT_TRUE(v2 == v1);
	EXPECT_EQ(v1, v2);
}

TEST(TStack, compare_matrix_with_itself_return_true)
{
	const int size = 2;
	TStack<int> v1(size);
	EXPECT_EQ(v1, v1);
}


TEST(TStack, stacks_with_different_size_are_not_equal)
{
	TStack<int> a(10);
	for (int i = 0; i < 10; i++)
	{
		a.Push(i + i);
	}
	TStack<int> b(9);
	EXPECT_NE(a, b);
	TStack<int> c(a);
	c.Clear();
	for (int i = 0; i < 9; i++)
	{
		c.Push(i + i);
	}
	c.Push(10);
	EXPECT_NE(a, c);
}
TEST(TStack, copied_stack_has_its_own_memory)
{
	TStack<int> a(10);
	for (int i = 0; i < 10; i++)
	{
		a.Push(i + i);
	}
	TStack<int> b(a);
	a.Clear();
	for (int i = 0; i < 10; i++)
	{
		a.Push(i);
	}
	EXPECT_NE(a, b);
}
TEST(TStack, can_assign_stack_to_itself)
{
	const int size = 5;
	TStack<int> v1(size);
	for (int i = 0; i < size; i++)
	{
		v1.Push(i);
	}
	ASSERT_NO_THROW(v1 = v1);
}
TEST(TStack, can_assign_stacks_of_equal_size)
{
	const int size = 5;
	TStack<int> v1(size), v2(size);
	for (int i = 0; i < size; i++)
	{
		v1.Push(i);
	}
	ASSERT_NO_THROW(v2 = v1);
	EXPECT_EQ(v1, v2);
}
TEST(TStack, assign_operator_change_stack_size)
{
	const int size1 = 4, size2 = 6;
	TStack<int> v1(size1), v2(size2);
	for (int i = 0; i < size1; i++)
	{
		v1.Push(i);
	}
	ASSERT_NO_THROW(v2 = v1);

	EXPECT_EQ(size1, v2.GetSize());
	EXPECT_EQ(v1, v2);
}

TEST(TStack, can_get_stack_max_size) {
	TStack<int> m(5);
	m.Push(0);
	m.Push(1);
	EXPECT_EQ(5, m.GetSize());
}
TEST(TStack, can_get_stack_top_num) {
	TStack<int> m(5);
	m.Push(0);
	m.Push(1);
	EXPECT_EQ(1, m.GetTopNum());
	m.Pop();
	EXPECT_EQ(0, m.GetTopNum());
}
TEST(TStack, can_push_element_in_stack) {
	TStack<int> m(5);
	m.Push(5);
	EXPECT_EQ(5, m.Top());
}
TEST(TStack, can_pop_element_in_stack) {
	TStack<int> m(5);
	m.Push(5);
	m.Push(2);
	EXPECT_EQ(2, m.Pop());
	EXPECT_EQ(5, m.Pop());
}
TEST(TStack, check_if_stack_empty)
{
	TStack<int> m(5);
	EXPECT_TRUE(m.isEmpty());
	m.Push(5);
	EXPECT_FALSE(m.isEmpty());
	m.Pop();
	EXPECT_TRUE(m.isEmpty());
}
TEST(TStack, throws_when_pop_element_in_empty_stack) {
	TStack<int> m(5);
	ASSERT_ANY_THROW(m.Pop());
	m.Push(2);
	m.Pop();
	ASSERT_ANY_THROW(m.Pop());
}
TEST(TStack, throws_when_push_in_full_stack)
{
	TStack<int> m(5);
	for (int i = 0; i < m.GetSize(); i++)
	{
		m.Push(i);
	}
	ASSERT_ANY_THROW(m.Push(1));
	EXPECT_TRUE(m.isFull());
}
TEST(TStack, can_clear_stack) {
	TStack<int> m(5);
	m.Push(2);
	ASSERT_NO_THROW(m.Clear());
	EXPECT_EQ(-1, m.GetTopNum());
}