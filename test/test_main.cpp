#include <gtest.h>
#include <string>
#include <iostream>
#include <initializer_list>

#include "Stack.h"
#include "Queue.h"
#include "Vector.h"

#include <gtest.h>
#include "Stack.h"


int main(int argc, char** argv)
{
	setlocale(LC_ALL, "rus");

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

	//test for git push

	//Stack<int> s({ 1,3,4,5,6 });
	//std::cout << s << std::endl;
	//
	//Queue<int> q({ 1,2,4,5,21 });
	//std::cout << q << std::endl;
	//
	//Vector<int> v({ 1,2,3,4,5 });
	//std::cout << v << std::endl;

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