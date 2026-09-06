#include <stddef.h>

class StringChars {
public:
	StringChars(const char* buffer) {
		size_t length{0};

		while (buffer[length] != '\0') {
			++length;
		}

		m_length = length;
		m_buffer = new char[length + 1];

		for (size_t i{0}; i < length; ++i) {
            m_buffer[i] = buffer[i];
		}
	
		m_buffer[length] = '\0';
	}

	StringChars(const StringChars& other) {
        m_length = other.m_length;
        m_buffer = new char[m_length + 1];

        for (size_t i{0}; i < m_length; ++i) {
            m_buffer[i] = other.m_buffer[i];
		}

        m_buffer[m_length] = '\0';
    }

	StringChars operator+(const StringChars& right) const {
		size_t new_len = m_length + right.m_length;

		char* tmp{new char[new_len + 1]};

		for (size_t i{0}; i < m_length; ++i) {
			tmp[i] = m_buffer[i];
		}

		for (size_t i{0}; i < right.m_length; ++i) {
			tmp[m_length + i] = right.m_buffer[i];
		}

		tmp[new_len] = '\0';

		StringChars res{tmp};
		delete[] tmp;

		return res;
	}

	~StringChars() {
        delete[] m_buffer;
    }

	char* to_str() const {
		return m_buffer;
	}

	size_t get_length() const {
		return m_length;
	}

private:
	char* m_buffer{nullptr};
	size_t m_length{0}; 
};

int main() {
	StringChars* ptr_str1{new StringChars{"Language"}};
	StringChars* ptr_str2{new StringChars{"C++"}};

	StringChars res = *ptr_str1 + *ptr_str2;

	delete ptr_str1;
	delete ptr_str2;
	return 0;
}