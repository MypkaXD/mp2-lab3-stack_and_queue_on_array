#include <gtest.h>
#include "Stack.h"
#include "Queue.h"
#include "Vector.h"
#include <string>

/////////////////////////////////////////// тесты на queue

TEST(Queue, can_create_queue) {
	ASSERT_NO_THROW(Queue<int> q);
}

TEST(Queue, can_create_copied_queue) {
	Queue<int> q1;

	ASSERT_NO_THROW(Queue<int> q2(q1));
}

TEST(Queue, can_assign_queue_to_itself)
{
	Queue<int> q;

	ASSERT_NO_THROW(q = q);
}

TEST(Queue, can_get_back_element) {
	Queue<int> q;
	
	for (int count = 0; count < 3; count++) {
		q.push(count);
	}

	EXPECT_EQ(2, q.back());
}

TEST(Queue, can_get_front_element) {
	Queue<int> q;

	for (int count = 0; count < 3; count++) {
		q.push(count);
	}

	EXPECT_EQ(0, q.front());
}

TEST(Quque, can_pop_elemnt_from_queue) {
	Queue<int> q;

	for (int count = 0; count < 3; count++) {
		q.push(count);
	}

	q.pop();

	EXPECT_EQ(1, q.front());
}

TEST(Queue, throw_then_get_back_element_from_empty_queue) {
	Queue<int> q;

	ASSERT_ANY_THROW(q.back());
}

TEST(Queue, throw_then_get_front_elememnt_from_empty_queue) {
	Queue<int> q;

	ASSERT_ANY_THROW(q.front());
}

TEST(Queue, throw_then_pop_element_from_empty_queue) {
	Queue<int> q;

	ASSERT_ANY_THROW(q.pop());
}

TEST(Queue, empty_queue_or_not) {
	Queue<int> q;
	
	EXPECT_EQ(true, q.empty());

	q.push(1);

	EXPECT_EQ(false, q.empty());
}

TEST(Queue, can_push_elements) {
	Queue<int> q;

	for (int count = 0; count < 3; count++) {
		q.push(count);
		EXPECT_EQ(q.back(), count);
	}
}

TEST(Queue, can_get_size) {
	Queue<int> q;

	for (int count = 0; count < 3; count++)
		q.push(count);

	EXPECT_EQ(3, q.size());
}

/*
TEST(Queue, can_create_queue_with_move_semantics)
{
	Queue<int> q1;

	ASSERT_NO_THROW(Queue<int> q2 = std::move(q1));
}


TEST(Queue, move_semantics_queue_is_equal_to_source_one)
{
	Queue<int> q1;
	for (int count = 0; count < 3; count++) {
		q1.push(count);
	}
	Queue<int>q2(q1);
	Queue<int>q3 = std::move(q1);

	EXPECT_EQ(q2, q3);
}
*/

/////////////////////////////////////////// тесты на stack

TEST(Stack, can_create_stack) {
	ASSERT_NO_THROW(Stack<int> s);
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



int main(int argc, char** argv)
{
	setlocale(LC_ALL, "rus");

	//Stack<int> s;
	//for (int count = 0; count < 10; count++) {
	//	s.push(count);
	//}
	//std::cout << s;
	//Queue<int> q({1,3,4,5});
	//for (int count = 0; count < 10; count++)
	//	q.push(count);
	//std::cout << q << std::endl;
	//std::cout << q.back() << std::endl;
	//std::cout << q.front() << std::endl;
	//q.pop();
	//std::cout << q << std::endl;
	//if (q.empty())
	//	std::cout << "YES\n";
	//else std::cout << "NO\n";
	
	//Vector<int> v1(3);
	//for (int count = 0; count < v1.size(); count++) {
	//	v1.push_back(count);
	//}
	//Vector<int> v2(v1);
	//if (v1 == v2)
	//	std::cout << "YES\n";
	//else std::cout << "NO\n";
	//
	//Stack<int> s1;
	//for (int count = 0; count < s1.size(); count++) {
	//	s1.push(count);
	//}
	//Stack<int> s2(s1);
	//if (s1 == s2)
	//	std::cout << "YES\n";
	//else std::cout << "NO\n";

	//Queue<int> q1;
	//q1.push(1);
	//std::cout << q1.back() << std::endl;
	//
	//Queue<int> q2;
	//std::cout << q2.back() << std::endl;

	//Vector<int> v1(10);
	//std::cout << &v1 << std::endl;
	//std::cout << *v1 << std::endl;

	//Vector<int> v2 = std::move(v1);
	//std::cout << &v2 << std::endl;
	//std::cout << *v2 << std::endl;
	
	//Vector<int> v1(3);
	//for (int count = 0; count < 3; count++) {
	//	v1.push_back(count);
	//}
	//std::cout << v1 << std::endl;
	//Vector<int> v2 = std::move(v1);
	//std::cout << v2 << std::endl;
	//
	//Stack<int> s1;
	//for (int count = 0; count < 3; count++) {
	//	s1.push(count);
	//}
	//Stack<int> s2 = std::move(s1);
	//std::cout << s2 << std::endl;
	//
	//Stack<int> s3;
	//s3 = std::move(s2);
	//std::cout << s3 << std::endl;

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

	//Vector<int> v(10);
	//for (int count = 0; count < 10;count++)
	//	v.push_back(count);
	//std::cout << v << std::endl;
	//v.erase(5);
	//std::cout << v << std::endl;
	//v.pop_back();
	//std::cout << v << std::endl;
	//v.insert(105,0);
	//std::cout << v << std::endl;

	//Stack<int> s;
	//for (int count = 0; count < 10; count++) {
	//	s.push(count);
	//}
	//std::cout << s << std::endl;
	//Stack<int> s1;
	//std::cout << s1.top() << std::endl;
	//
	//Vector<int> v(1);
	//v.insert(2, 0);
	//v.insert(3, 0);
	//std::cout << v << std::endl;
	//std::cout << s1 << std::endl;


}