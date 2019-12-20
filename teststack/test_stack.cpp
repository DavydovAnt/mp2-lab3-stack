#include "gtest.h"

#include "../mp2-lab3-stack/Tstack.h"

TEST(TStack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(Tstack<int> st(3));
}

TEST(TStack, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(Tstack<int> st(-3));
}

TEST(TStack, can_create_copied_stack)
{
	Tstack<int> st(3);

	ASSERT_NO_THROW(Tstack<int> st1(st));
}

TEST(TStack, can_add_element)
{
	Tstack<int> st(1);
	st.push(1);
	EXPECT_EQ(1, st.top());
}

TEST(TStack, can_pop_an_element)
{
	Tstack<int> st(4);
	st.push(1);
	st.push(2);
	int a = st.pop();
	EXPECT_EQ(2, a);
}

TEST(TStack, copied_stack_is_equal_to_source_one)
{
	Tstack <int> st(3);
	for (int i = 0; i < 3; i++) {
		st.push(i);
	}
	Tstack <int> st1(st);
	for (int i = 2; i >= 0; i--) {
		EXPECT_EQ(i, st1.pop());
	}
}

TEST(TStack, copied_stack_has_its_own_memory)
{
	int size = 2;
	Tstack <int> st(size);
	for (int i = 0; i < size; i++) {
		st.push(i);
	}
	Tstack <int> st1(st);
	st.clear();
	for (int i = 0; i < size; i++) {
		st.push(i + 3);
	}
	for (int i = 0; i < size; i++) {
		EXPECT_NE(st1.pop(), st.pop());
	}
}

TEST(TStack, can_check_for_emptiness)
{
	int size = 2;
	Tstack<int> st(size);
	EXPECT_EQ(true, st.IsEmpty());
	st.push(1);
	st.push(2);
	EXPECT_EQ(true,st.IsFull());
}

TEST(TStack, throws_when_try_to_extract_from_the_empty)
{
	Tstack<int> st;
	ASSERT_ANY_THROW(st.pop());
}

TEST(TStack, throws_when_try_to_add_to_the_full)
{
	Tstack<int> st(1);
	st.push(1);
	ASSERT_ANY_THROW(st.push(2));
}