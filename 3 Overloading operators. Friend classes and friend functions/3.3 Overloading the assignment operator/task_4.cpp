#include <cmath>

class AbsoluteValue {
public:
	AbsoluteValue() = default;
	AbsoluteValue(int value) : m_value{std::abs(value)} {};

	AbsoluteValue& operator=(int value) {
		m_value = std::abs(value);
		return *this;
	}

	unsigned long m_value{0};
};

int main() {
	AbsoluteValue* ptr_abv{new AbsoluteValue{}};
	*ptr_abv = -512;
	return 0;
}