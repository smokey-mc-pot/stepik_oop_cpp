#include <iostream>

class Clock {
public:
    Clock() = default;
	Clock(unsigned int tm) : m_tm{tm} {};

	unsigned int get_time() const;

private:
	unsigned int m_tm{0};
};

unsigned Clock::get_time() const {
	return m_tm;
}

int main() {
	Clock* ptr_cl = new Clock{12643};
	unsigned int res = ptr_cl->get_time();

	std::cout << res;

	delete ptr_cl;
	return 0;
}