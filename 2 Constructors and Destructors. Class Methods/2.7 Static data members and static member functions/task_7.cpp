#include <cstddef> 

class Array {
public:
	Array() = default;
	Array(const Array& arr) = delete;

	~Array() {
        delete m_data;
    }

    void set_data(double* d, size_t length)
    {
        delete[] m_data;
        m_size = length;
        m_data = new double[m_size];

        for (size_t i = 0; i < m_size; ++i) {
            m_data[i] = d[i];
		}
    }

    double* get_data() { 
		return m_data; 
	}

    size_t get_size() { 
		return m_size; 
	}

	static Array* create(size_t size);
	static Array* create(double data[], int size);

private:
	double* m_data{nullptr};
    size_t m_size{0};
};

Array* Array::create(size_t size) {
    Array* temp = new Array();
    temp->m_data = new double[size]{0};
    temp->m_size = size;

    return temp;
}

Array* Array::create(double data[], int size) {
    Array* temp = new Array();
    temp->set_data(data, size);

    return temp;
}