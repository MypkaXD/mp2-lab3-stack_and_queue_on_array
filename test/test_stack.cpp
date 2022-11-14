#include <gtest.h>
#include "Stack.h"

TEST(Stack, can_create_stack) {
	ASSERT_NO_THROW(Stack<int> s);
}

TEST(Stack, can_create_stack_with_initializer_list) {
	ASSERT_NO_THROW(Stack<int> s({ 1,2,3,4,5 }));
}

TEST(Stack, can_create_copied_stack) {
	Stack<int> s1;

	ASSERT_NO_THROW(Stack<int> s2(s1));
}

//TEST(Stack, throw_when_create_copied_stack_with_diffrent_types) {
//	Stack<int> s1;
//	s1.push(1);
//	Stack<std::string> s2;
//	s2.push("1");
//	ASSERT_NO_THROW(Stack<int> s2(s1));
//}

TEST(Stack, copied_vector_is_equal_to_source_one)
{
	Stack<int> s1;
	for (int count = 0; count < 3; count++) {
		s1.push(count);
	}
	Stack<int>s2(s1);

	EXPECT_EQ(s1, s2);
}

TEST(Stack, can_assign_stack_to_itself)
{
	Stack<int> s;

	ASSERT_NO_THROW(s = s);
}

TEST(Stack, compare_equal_stack_return_true)
{
	const int size = 3;

	Stack<int> s1;
	Stack<int> s2;

	for (int count = 0; count < size; count++) {
		s1.push(count);
		s2.push(count);
	}

	EXPECT_EQ(true, s1 == s2);
}

TEST(Stack, compare_stack_with_itself_return_true)
{
	Stack<int> s;

	for (int count = 0; count < 3; count++) {
		s.push(count);
	}

	EXPECT_EQ(true, s == s);
}

TEST(Stack, can_get_size) {
	Stack<int> s;

	for (int count = 0; count < 3; count++)
		s.push(count);

	EXPECT_EQ(3, s.size());
}

TEST(Stack, can_push_elements) {
	Stack<int> s;

	s.push(0);
	EXPECT_EQ(s.top(), 0);

	s.push(1);
	EXPECT_EQ(s.top(), 1);

	s.push(2);
	EXPECT_EQ(s.top(), 2);
}

TEST(Stack, can_pop_elements) {
	Stack<int> s;

	s.push(1);
	EXPECT_EQ(1, s.size());

	s.pop();
	EXPECT_EQ(0, s.size());
}

TEST(Stack, throws_when_pop_element_from_empty_stack) {
	Stack<int> s;

	ASSERT_ANY_THROW(s.pop());
}

TEST(Stack, can_get_top_element) {
	Stack<int> s;

	for (int count = 0; count < 3; count++)
		s.push(count);

	EXPECT_EQ(2, s.top());
}

TEST(Stack, throws_when_top_element_from_empty_stack) {
	Stack<int> s;

	ASSERT_ANY_THROW(s.top());
}

TEST(Stack, can_create_stack_with_move_semantics)
{
	Stack<int> s1;

	ASSERT_NO_THROW(Stack<int> s2 = std::move(s1));
}


TEST(Stack, move_semantics_stack_is_equal_to_source_one)
{
	Stack<int> s1;

	for (int count = 0; count < 3; count++) {
		s1.push(count);
	}
	Stack<int> s2(s1);
	Stack<int> s3 = std::move(s1);

	EXPECT_EQ(s2, s3);
}