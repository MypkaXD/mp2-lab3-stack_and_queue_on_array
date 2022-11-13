#include "Vector.h"

#ifndef STACK_H
#define STACK_H

template <class T>
class Stack : private Vector<Vector<T>> {
private:
	Vector<T> m_data;
public:
	Stack() {}
	Stack(const Stack<T>& other){
		m_data = other.m_data;
	}
	Stack(Stack<T>&& other) noexcept {
		//std::cout << "Вызван консткуртор перемещения в Stack" << std::endl;
		m_data = std::move(other.m_data);
	}
	/*
	Stack(const std::initializer_list<T>& list) {
		m_data.resize(list.size());
		m_data = list;// пропадает первый элемент у листа

		//size_t count = 0;
		//for (auto it = list.begin(); it < list.end(); ++it) {
		//	m_data[count] = *it;
		//	count++;
		//}
	}
	*/

	Stack& operator=(const Stack<T>& other) {
		if (this != &other)
			(m_data = other.m_data);
		return *this;
	}
	Stack& operator=(Stack<T>&& other) {
		//std::cout << "Вызван операторт перемещения" << std::endl;
		if (this != &other)
			m_data = std::move(other.m_data);
		return *this;
	}
	bool operator==(const Stack<T>& other) const noexcept{
		return (m_data == other.m_data);
	}
	bool operator!=(const Stack<T>& other) const noexcept {
		return !(*this == other);
	}

	bool empty() {
		return (size() == 0);
	}

	size_t size(){
		return m_data.size();
	}

	T top() {
		if (size() == 0)
			throw ("ERROR: stack is empty");
		return m_data[m_data.size() - 1];
	}

	void push(const T& elem) {
		m_data.push_back(elem);
	}

	void pop() {
		if (size() == 0)
			throw ("ERROR: stack is empty");
		m_data.pop_back();
	}

	friend std::ostream& operator<<(std::ostream& out, Stack& other) { // почему нельзя написать const?
		for (size_t count = other.size()-1; count >= 0; count--) {
			out << "|\t" << other.m_data[count] << "\t|\n";
			//out << "|\t" << other.top() << "\t|\n";
			//other.pop();
		}
		out << "|_______________|";
		return out;
	}
};

#endif // !STACK_H
