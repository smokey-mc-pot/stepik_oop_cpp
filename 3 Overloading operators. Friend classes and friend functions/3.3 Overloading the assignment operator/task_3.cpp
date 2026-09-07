#include <stddef.h>

class Array {
public:
	Array() = default;

	Array(int* data, size_t size) {
		set_data(data, size);
	}

	~Array() {
		delete[] m_data;
	}

	Array operator+(const Array& other) const {
		int* tmp{new int[m_size + other.m_size]};

		for (size_t i{0}; i < m_size; ++i) {
			tmp[i] = m_data[i];
		}

		for (size_t i{0}; i < other.m_size; ++i) {
			tmp[m_size + i] = other.m_data[i];
		}

		Array res{tmp, m_size + other.m_size};

		delete[] tmp;
		return res;
	}

	Array& operator=(const Array& other) {
		if (this == &other) {
        	return *this;
		}

		delete[] m_data;

		m_size = other.m_size;
    	m_data = new int[m_size];

    	for (size_t i{0}; i < m_size; ++i) {
        	m_data[i] = other.m_data[i];
		}
 
    	return *this;
	}

    void set_data(int* d, size_t length) {
        delete[] m_data;
        m_size = length;
        m_data = new int[m_size];

        for (size_t i{0}; i < m_size; ++i)
		{
            m_data[i] = d[i];
		}
    }

    int* get_data() const { 
		return m_data; 
	}

    size_t get_size() const { 
		return m_size; 
	}

private:
    int* m_data{nullptr};
    size_t m_size{0};
};