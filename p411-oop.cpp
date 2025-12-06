#include <iostream>

template <typename T>

class Array {
private:
	T* m_data = nullptr;
	int m_size = 0;
	int m_count = 0;
	int m_grow = 0;

	void checkIndex(int index) const {
		if (index < 0 || index >= m_count) {
			std::cout << "Index out of range";
		}
	}

public:
	Array& operator=(const Array& other) {
		if (this != &other) {
			delete[] m_data;
			m_size = other.m_size;
			m_count = other.m_count;
			m_grow = other.m_grow;
			m_data = nullptr;

			if (m_size > 0) {
				m_data = new T[m_size];

				for (int i = 0; i < m_count; i++) {
					m_data[i] = other.m_data[i];
				}
			}
		}

		return *this;
	}

	~Array() {
		delete[] m_data;
	}
	
	int GetSize() const {
		return m_size;
	}

	int GetUpperBound() const {
		return (m_count > 0) ? (m_count - 1) : -1;
	}

	bool IsEmpty() const {
		return m_count == 0;
	}

	void RemoveAll() {
		delete[] m_data;
		m_data = nullptr;
		m_size = 0;
		m_count = 0;
	}

	T* GetData() {
		return m_data;
	}

	void SetAt(int index, const T& value) {
		checktIndex(index);
		m_data[index] = value;
	}

	T& GetAt(int index) {
		checkIndex(index);
		return m_data[index];
	}

	T& operator[] (int index) {
		return GetAt(index);
	}

	// array[0]
};

int main()
{
	Array<int> arr1;
	Array<int> arr2;
}
