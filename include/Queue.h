#include "Vector.h"

#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class Queue : private Vector<Vector<T>> {
private:
	Vector<T> m_data;
public:
	Queue() {}
	Queue(const Queue<T>& other) {
		m_data = other.m_data;
	}
	Queue(const std::initializer_list<T>& list) {
		m_data.resize(list.size());
		m_data = list;
	}
	Queue(Queue<T>&& other) noexcept {
		//std::cout << "Вызван консткуртор перемещения в Stack" << std::endl;
		m_data = std::move(other.m_data);
	}


	Queue& operator=(const Queue& other) {
		if (this != &other)
			m_data = other.m_data;
		return *this;
	}
	Queue& operator=(Queue<T>&& other) {
		//std::cout << "Вызван операторт перемещения" << std::endl;
		if (this != &other)
			m_data = std::move(other.m_data);
		return *this;
	}

	T& back() {
		if (size() == 0)
			throw "ERROR: queue is empty";
		return m_data[m_data.size() - 1];
	}

	bool empty() {
		return (m_data.size() == 0);
	}
	bool operator==(const Queue<T>& other) const noexcept {
		return (m_data == other.m_data);
	}
	bool operator!=(const Queue<T>& other) const noexcept {
		return !(*this == other);
	}

	T& front() {
		if (size() == 0)
			throw "ERROR: queue is empty";
		return m_data[0];
	}

	void pop() {
		if (size() == 0)
			throw "ERROR: queue is empty";
		m_data.erase(1);
	}

	void push(const T& elem) {
		m_data.push_back(elem);
	}

	size_t size() {
		return m_data.size();
	}

	friend std::ostream& operator<<(std::ostream& out, const Queue& other) {
		out << "\tOUT\t\n _______________\n";
		for (size_t count = 0; count < other.m_data.size(); count++) {
			out << "|\t" << other.m_data[count] << "\t|\n";
		}
		out << "|_______________|\n\tIN\t\n";
		return out;
	}

};
#endif // !QUEUE_H

