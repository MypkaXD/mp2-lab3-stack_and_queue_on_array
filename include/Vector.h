#include <initializer_list>
#include <iostream>

#define size_t int

#ifndef VECTOR_H
#define VECTOR_H

template <class T>
class Vector {
private:
	size_t m_size = 0;
	size_t m_capacity = 0;
	T* m_data = nullptr;
public:
	Vector(){}
	Vector(size_t size){
		if (size <= 0)
			throw ("ERROR: size should be greater than zero");
		m_capacity = size;
		m_data = new T[size];
		m_size = 0;
	}
	Vector(const Vector& other) {
		//if (sizeof(m_data[0]) != sizeof(other.m_data[0]))
		//	throw ("ERROR: diffrent type");
		resize(other.m_size);
		m_data = new T[m_capacity];

		for (size_t count = 0; count < m_size; count++)
			m_data[count] = other.m_data[count];
	}
	Vector(const std::initializer_list<T>& list) {
		resize(list.size());
		m_data = new T[m_capacity];
		size_t count = 0;
		for (auto it = list.begin(); it < list.end(); ++it) {
			m_data[count] = *it;
			count++;
		}
	}
	Vector(Vector&& other) noexcept {
		//std::cout << "Вызван консткуртор перемещения в Vector" << std::endl;
		if (this != &other) {
			delete[] m_data;
			m_capacity = other.m_capacity;
			m_size = other.m_size;
			m_data = other.m_data;//move
			other.m_data = nullptr;
			other.m_capacity = 0;
			other.m_size = 0;
		}
		//std::swap(other.m_data, this->m_data);
		//std::swap(other.m_n, this->m_n);
	}
	~Vector() {
		delete[] m_data;
		m_data = nullptr;
		m_capacity = 0;
		m_size = 0;
	}

	Vector& operator=(const Vector& other) {
		if (&other == this)
			return *this;

		if (m_capacity == other.m_capacity) {
			for (size_t count = 0; count < other.m_size; count++)
				m_data[count] = other.m_data[count];
			return *this;
		}
		else {
			m_data = new T[other.m_capacity];
			for (size_t count = 0; count < other.m_size; count++)
				m_data[count] = other.m_data[count];
			m_size = other.m_size;
			m_capacity = other.m_capacity;
			return *this;
		}
	}
	Vector& operator=(Vector&& other) {// операторт перемещения
		if (this == &other) {
			return *this;
		}
		delete[] m_data;
		m_data = other.m_data;
		m_capacity = other.m_capacity;
		m_size = other.m_size;
		other.m_data = nullptr;
		other.m_capacity = 0;
		other.m_size = 0;
		return *this;
	}
	bool operator==(const Vector<T>& other) const noexcept {
		if (this == &other)
			return true;
		if (m_size != other.m_size)
			return false;
		for (size_t count = 0; count < m_size; count++) {
			if (m_data[count] != other.m_data[count])
				return false;
		}
		return true;
	}
	bool operator!=(const Vector<T>& other) const noexcept {
		return !(other == *this);
	}

	T& operator[](size_t index){
		if (index >= m_size)
			throw ("ERROR: index is out of range");
		return m_data[index];
	}
	const T& operator[](size_t index) const{
		if (index >= m_size)
			throw ("ERROR: index is out of range");
		return m_data[index];
	}

	void resize(const size_t newSize){
		if (m_capacity > newSize) m_size = newSize;
		else {
			m_capacity = (newSize + 1) * 2;
			T* temp = new T[m_capacity];
			for (size_t count = 0; count < m_size; count++)
				temp[count] = m_data[count];
			m_size = newSize;
			delete[] m_data;
			m_data = temp;
		}
	}

	void push_back(const T elem) { //положить элемент в конец вектора
		if (m_capacity < m_size + 1) resize(m_size + 1);
		else m_size++;
		m_data[m_size - 1] = elem;
	}
	
	void pop_back() { //удалить последний элемент из вектора
		if (size() == 0)
			throw ("ERROR: vector is empty");
		m_size--;
	}

	void erase(size_t index) { //Удаляет элемент или диапазон элементов в векторе из заданных позиций.
		if (index > m_size)
			throw "ERROR: index is out of range";
		for (size_t count = index - 1; count < m_size; count++)
			m_data[count] = m_data[count + 1];
		m_size--;
	}

	void insert(T elem, size_t index) { //Вставляет элемент, множество элементов или диапазон элементов в вектор по заданной позиции.
		/*
			тут проблема, если создать вектор, например, из 10 элементов. То при обращении к insert(elem,9) будет ошибка, так как в моих методов нет присваивания 0 дургим элементам
			так как я не знаю как сделать 0 шаблонным, если я вызову Vector<std::string> то будет ошибка
		*/
		resize(m_size + 1);
		for (size_t count = m_size - 1; count > index; count--)
			m_data[count] = m_data[count - 1];
		m_data[index] = elem;
	}


	const size_t size() const noexcept{
		return m_size;
	}
	size_t size() noexcept{
		return m_size;
	}

	friend std::ostream& operator<<(std::ostream& out, const Vector& other) {
		out << "[\t";
		for (size_t count = 0; count < other.m_size; count++) {
			out << other.m_data[count] << "\t";
		}
		out << "]";
		return out;
	}
	friend std::istream& operator>>(std::istream& in, Vector& other) {
		for (size_t count = 0; count < m_size; count++) {
			std::cout << "[" << count << "] = "; in >> m_data[count];
		}
		return in;
	}
};

#endif // !VECTOR_H
