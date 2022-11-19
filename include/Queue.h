#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class Queue {
private:
	T* m_data = nullptr;
	size_t m_start = -1;
	size_t m_end = -1;
	size_t m_capacity = 0;
	size_t m_size = 0;
public:
	Queue() {}
	Queue(const Queue<T>& other) {
		m_data = new T[other.m_capacity];
		m_end = other.m_end;
		m_start = other.m_start;
		m_size = other.m_size;
		m_capacity = other.m_capacity;
		for (size_t count = 0; count < m_capacity; count++)
			m_data[count] = other.m_data[count];
	}
	Queue(const std::initializer_list<T>& list) {
		m_data = new T[list.size()];
		size_t count = 0;
		for (auto it = list.begin(); it < list.end(); ++it) {
			m_data[count] = *it;
			count++;
		}
		m_start = 0;
		m_end = list.size();
		m_size = list.size();
		m_capacity = m_size;
	}
	~Queue() {
		delete[] m_data;
		m_data = nullptr;
		size_t m_start = -1;
		size_t m_end = -1;
		size_t m_capacity = 0;
		size_t m_size = 0;
	}
	Queue& operator=(const Queue<T>& other) {
		if (this == &other)
			return *this;
		if (m_capacity == other.m_capacity) {
			for (size_t count = 0; count < other.m_capacity; count++)
				m_data[count] = other.m_data[count];
			m_end = other.m_end;
			m_start = other.m_start;
			m_size = other.m_size;
			return *this;
		}
		else {
			m_data = new T[other.m_capacity];
			for (size_t count = 0; count < other.m_capacity; count++)
				m_data[count] = other.m_data[count];
			m_end = other.m_end;
			m_start = other.m_start;
			m_size = other.m_size;
			m_capacity = other.m_capacity;
			return *this;
		}
	}
	size_t start() {
		return m_start;
	}
	size_t end() {
		return m_end;
	}
	void pop() {// ������� �� �(1)
		/*
		��������� erase �� Vector.h ��������� ����� �(n), � ���� O(1).
			������ �(n), erase ������ ������� �� ������ �������, � ��������� �������� �� - 1
			���� ������� ����� ����������� �����.���� ��� � ��� ������ �� 5 ���������{ 1,4,6,2,10 }.
			���� ������� �������, ��� ��� �������, ������������� ������� 1.
			����� �����, ����� ����������� ������� ���, ��� ����� � ��� ��������� �� 4, ���� ������ ��� ���� �������, �� ����� �������� �� 6.
			����� ������� ����������� �� �����.
		*/

		if (m_size == 0)
			throw "ERROR: queue is empty";

		if (m_start + 1 == m_capacity)
			m_start = 0;
		else
			m_start++;

		m_size--;
	}

	void recomp() {
			T* temp = new T[(m_capacity + 1) * 2];
			if (m_start >= m_end && m_start != -1) {
				size_t iterator = 0;
				for (size_t count = m_start; count < m_capacity; count++) {
					temp[iterator] = m_data[count];
					iterator++;
				}
				for (size_t count = 0; count < m_start; count++) {
					temp[iterator] = m_data[count];
					iterator++;
				}
				m_end = m_capacity - m_start + m_end;
				m_start = 0;
			}
			else if (m_start < m_end || m_end == -1) {
				for (size_t count = 0; count < m_size; count++)
					temp[count] = m_data[count];
			}
			m_capacity = (m_capacity + 1) * 2;
			delete[] m_data;
			m_data = temp;
	}

	void push(const T& elem) {
		/*
			������ ��������� ������ ��� ����. ����� �������:
			1) ���� ������� ������, �� m_start = 0, m_end = 0
			2) ���� ������� �� ������, �� m_start = 0, m_end = ���-�� ��������� � ������� �������
			3) ���� ������� �� ������ � ��� ���, �� m_start > 1.
				���� m_end + 1 > m_capacity, �� m_end = ...
		*/
		if (m_start == -1) {
			recomp();
			m_start++;
			m_end++;
			m_size++;
			m_data[m_end] = elem;
		}
		else if (m_start == 0) {
			if (m_end + 1 == m_capacity)
				recomp();
			m_end++;
			m_size++;
			m_data[m_end] = elem;
		}
		else if (m_start >= 1) {
			if (m_end + 1 == m_capacity)
				m_end == 0;
			else
				m_end++;
			m_size++;
			m_data[m_end] = elem;
		}
		else if (m_start == m_end && m_size == m_capacity) {
			recomp();
			m_end++;
			m_size++;
			m_data[m_end] = elem;
		}
	}

	size_t size() {
		return m_size;
	}

	T back() {
		if (size() == 0)
			throw "ERROR: queue is empty";
		return m_data[m_end];
	}

	T front() {
		if (size() == 0)
			throw "ERROR: queue is empty";
		return m_data[m_start];
	}

	bool empty() {
		return (size() == 0);
	}

	bool operator==(const Queue<T>& other) const noexcept {
		if (this == &other)
			return true;
		if (m_size != other.m_size)
			return false;
		if (other.m_start <= other.m_end) {
			for (size_t count = other.m_start; count <= other.m_end; count++) {
				if (m_data[count] != other.m_data[count])
					return false;
			}
		}
		else if (other.m_start > other.m_end) {
			for (size_t count = other.m_start; count < other.m_capacity; count++) {
				if (m_data[count] != other.m_data[count])
					return false;
			}
			for (size_t count = 0; count < other.m_start; count++) {
				if (m_data[count] != other.m_data[count])
					return false;
			}
		}
		return true;
	}
	bool operator!=(const Queue<T>& other) const noexcept {
		return !(*this == other);
	}

	friend std::ostream& operator<<(std::ostream& out, const Queue& other) {
		out << "\tOUT\t\n _______________\n";
		if (other.m_start <= other.m_end) {
			for (size_t count = other.m_start; count <= other.m_end; count++) {
				out << "|\t" << other.m_data[count] << "\t|\n";
			}
		}
		else if (other.m_start > other.m_end) {
			for (size_t count = other.m_start; count < other.m_capacity; count++) {
				out << "|\t" << other.m_data[count] << "\t|\n";
			}
			for (size_t count = 0; count < other.m_start; count++) {
				out << "|\t" << other.m_data[count] << "\t|\n";
			}
		}
		out << "|_______________|\n\tIN\t\n";
		return out;
	}
};
#endif // !QUEUE_H

