#include <iostream>

template<typename T>

class Array {
    T* m_data = nullptr;
    int m_size = 0;
    int m_count = 0;
    int m_grow = 1;

    void checkIndex(int index) const {
        if (index < 0 || index >= m_count) {
            std::cout << "Index out of range";
            return;
        }
    }

    void reallocate(int newSize) {
        if (newSize == m_size) {
            return;
        }

        if (newSize == 0) {
            delete[] m_data;
            m_data = nullptr;
            m_size = 0;
            m_count = 0;
            return;
        }

        T* newData = new T[newSize];

        if (m_data) {
            int copycount = (m_count < newSize) ? m_count : newSize;

            for (int i = 0; i < copycount; i++) {
                newData[i] = m_data[i];
            }

            delete[] m_data;

            if (copycount < m_count) {
                m_count = copycount;
            }
        }

        m_data = newData;
        m_size = newSize;

    }

public:
    Array& operator= (const Array other) {
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

    int getSize() const {
        return m_size;
    }

    int GetUpperBound() {
        return (m_count > 0) ? (m_count - 1) : -1;
    }

    bool isEmpty() {
        return m_count == 0;
    }

    void removeAll() {
        delete[] m_data;
        m_data = nullptr;
        m_size = 0;
        m_count = 0;
    }

    T* getData() {
        return m_data;
    }

    T& getAt(int index) {
        checkIndex(index);
        return m_data[index];
    }

    T& operator[] (int index) {
        return getAt(index);
    }

    void setAt(int index, const T& value) {
        checkIndex(index);
        m_data[index] = value;
    }

    void SetSize(int size, int grow = 1) {
        if (size < 0) {
            std::cout << "Size cannot be negative" << std::endl;
            return;
        }

        if (grow <= 0) {
            grow = 1;
        }

        m_grow = grow;
        reallocate(size);
    }

    void FreeExtra() {
        if (m_size > m_count) {
            reallocate(m_count);
        }
    }

    void RemoveAt(int index, int count = 1) {
        if (index < 0 || index >= m_count) {
            std::cout << "Index out of range fro RemoveAt";
            return;
        }

        if (count <= 0) {
            return;
        }

        if (index + count > m_count) {
            count = m_count - index;
        }

        for (int i = count + index; i < m_count; i++) {
            m_data[i - count] = m_data[i];
        }

        m_count -= count;
    }

    void Add(const T& element) {
        if (m_count > m_size) {
            int newSize = m_size + m_grow;

            if (newSize <= m_size) {
                newSize = m_size + 1;
            }

            reallocate(newSize);
        }

        m_data[m_count] = element;
        m_count++;
    }

};

int main()
{
    Array<int> arr;
    arr.SetSize(5, 5);

    arr.Add(10);
    arr.Add(20);
    arr.Add(30);

    std::cout << "Size: " << arr.getSize() << std::endl;

    arr.FreeExtra();

    std::cout << "Size: " << arr.getSize() << std::endl;

    arr.RemoveAt(0, 2);
    std::cout << "Size: " << arr.getSize() << std::endl;

    arr.removeAll();

    std::cout << (arr.isEmpty() ? "yes" : "no");
}