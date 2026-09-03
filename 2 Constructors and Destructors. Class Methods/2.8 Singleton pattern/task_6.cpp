#include <string>

class Student {
public:
	Student(const std::string& fio, short old) : m_fio{fio}, m_old{old} {}
	Student(const Student& instance) = delete;
	Student& operator=(const Student& instance) = delete;

	void set_data(const std::string& fio, short old) {
		m_fio = fio;
		m_old = old;
	}

	const std::string& get_fio() const {
		return m_fio;
	}

	short get_old() const {
		return m_old;
	}

private:
	std::string m_fio;
	short m_old{0};
};

int main() {
	Student* ptr_st{new Student{"Pushkin", 21}};
	delete ptr_st;

	return 0;
}