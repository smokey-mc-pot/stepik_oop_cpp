#include <iostream>

class StringBuffer {
public:
    StringBuffer(const char* str) {
        size = 0;

        while (str[size] != '\0' && size < max_size - 1) {
            ++size;
		}

        buffer = new char[size + 1];

        for (int i = 0; i < size; ++i) {
            buffer[i] = str[i];
		}

        buffer[size] = '\0';
    }

	StringBuffer(const StringBuffer& copy) : StringBuffer{copy.buffer} {}

	~StringBuffer() {
		delete[] buffer;
	}

    const char* get_data() { 
		return buffer; 
	}

    int get_size() { 
		return size; 
	}

private:
    enum {
		max_size = 1024
	};

    char* buffer{nullptr};
    int size{0};
};

int main() {
	StringBuffer str("Hello");
	StringBuffer data{str};

	std::cout << data.get_data() << std::endl;
	return 0;
}