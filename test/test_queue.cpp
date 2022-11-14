#include <gtest.h>
#include "Queue.h"

TEST(Queue, can_create_queue) {
	ASSERT_NO_THROW(Queue<int> q);
}

TEST(Queue, can_create_queue_with_initializer_list) {
	ASSERT_NO_THROW(Queue<int> q({ 1,2,3,4,5 }));
}

TEST(Queue, can_create_copied_queue) {
	Queue<int> q1;

	ASSERT_NO_THROW(Queue<int> q2(q1));
}

TEST(Queue, can_assign_queue_to_itself) {
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
