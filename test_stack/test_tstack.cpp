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

//пустой ли стек?
//полный ли стек?
//не полный ли стек и не пустой?
// проверка pop у последнего элемента
// проверка pop у элемента и ожидаем что остаётся другой элемент
// проверить очищение стека


/*
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
		for (int j = i; j < 10; j++)
		{
			a[i][j] = i + i;
		}
	}
	TStack<int> b(a);
	EXPECT_EQ(a, b);
}

TEST(TStack, copied_stack_has_its_own_memory)
{
	TStack<int> a(10);
	for (int i = 0; i < 10; i++)
	{
		for (int j = i; j < 10; j++)
		{
			a[i][j] = i + i;
		}
	}
	TStack<int> b(a);
	for (int i = 0; i < 10; i++)
	{
		for (int j = i; j < 10; j++)
		{
			a[i][j] += i;
		}
	}
	EXPECT_NE(a, b);
}

TEST(TStack, can_get_size)
{
	TStack<int> a(10);
	ASSERT_NO_THROW(a.GetSize());
	EXPECT_EQ(10, a.GetSize());
}

TEST(TStack, can_set_and_get_element)
{
	TStack<int> a(10);
	ASSERT_NO_THROW(a[0][0] = 10);
	ASSERT_NO_THROW(a[0][0]);
	a[4][5] = 5;
	EXPECT_EQ(5, a[4][5]);
}

TEST(TStack, throws_when_set_element_with_negative_index)
{
	TStack<int> a(10);
	ASSERT_ANY_THROW(a[4][-1] = 10);
}

TEST(TStack, throws_when_set_element_with_too_large_index)
{
	TStack<int> a(10);
	ASSERT_ANY_THROW(a[11][12] = 10);
}

TEST(TStack, can_assign_stack_to_itself)
{
	const int size = 5;
	TStack<int> v1(size), v2(size), testv(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			v1[i][j] = i;
		}
	}
	ASSERT_NO_THROW(v1 = v1);

}

TEST(TStack, can_assign_matrices_of_equal_size)
{
	const int size = 5;
	TStack<int> v1(size), v2(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			v1[i][j] = i;
		}
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
		for (int j = i; j < size1; j++)
		{
			v1[i][j] = i;
		}
	}
	ASSERT_NO_THROW(v2 = v1);

	EXPECT_EQ(size1, v2.GetSize());
	EXPECT_EQ(v1, v2);
}

TEST(TStack, can_assign_matrices_of_different_size)
{
	const int size1 = 5, size2 = 6;
	TStack<int> v1(size1), v2(size2);
	for (int i = 0; i < size1; i++)
	{
		for (int j = i; j < size1; j++)
		{
			v1[i][j] = i;
		}
	}
	ASSERT_NO_THROW(v2 = v1);

}

TEST(TStack, compare_equal_matrices_return_true)
{
	const int size = 5;
	TStack<int> v1(size), v2(size);
	v2 = v1;
	ASSERT_TRUE(v2 == v1);
	EXPECT_EQ(v1, v2);
}

TEST(TStack, compare_stack_with_itself_return_true)
{
	const int size = 2;
	TStack<int> v1(size);
	EXPECT_EQ(v1, v1);
}

TEST(TStack, matrices_with_different_size_are_not_equal)
{
	const int size1 = 2, size2 = 5;
	TStack<int> v1(size1), v2(size2);
	EXPECT_NE(v1, v2);

}

TEST(TStack, can_add_stack_with_equal_size)
{
	const int size = 5;
	TStack<int> v1(size), v2(size), testv(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			v1[i][j] = j;
			v2[i][j] = j + 5;
			testv[i][j] = v1[i][j] + v2[i][j];
		}
		
	}
	ASSERT_NO_THROW(v1 + v2);
	EXPECT_EQ(v1 + v2, testv);
	//ADD_FAILURE();
}

TEST(TStack, cant_add_matrices_with_not_equal_size)
{
	const int size1 = 5, size2 = 2;
	TStack<int> v1(size1), v2(size2);
	ASSERT_ANY_THROW(v1 + v2);
	//ADD_FAILURE();
}

TEST(TStack, can_subtract_matrices_with_equal_size)
{
	const int size = 5;
	TStack<int> v1(size), v2(size), testv(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			v1[i][j] = i;
			v2[i][j] = i + i;
			testv[i][j] = v2[i][j] - v1[i][j];
		}
	}
	ASSERT_NO_THROW(v2 - v1);
	EXPECT_EQ(v2 - v1, testv);
	//ADD_FAILURE();
}

TEST(TStack, cant_subtract_stackes_with_not_equal_size)
{
	const int size1 = 5, size2 = 2;
	TStack<int> v1(size1), v2(size2);
	ASSERT_ANY_THROW(v1 - v2);
	//ADD_FAILURE();
}

*/