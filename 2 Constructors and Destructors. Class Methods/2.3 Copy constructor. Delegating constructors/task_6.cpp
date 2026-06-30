#include <iostream>

class Thing {
public:
	Thing() {
		std::cout << "default constructor" << std::endl;
	}

	Thing(const std::string& name) : m_name{name} {
		std::cout << "constructor 1" << std::endl;
	}

	Thing(const std::string& name, double weight, int price) : Thing{name} {
		m_weight = weight;
		m_price = price;
		std::cout << "constructor 3" << std::endl;
	}

	std::string get_name() {
		return m_name;
	}

	double get_weight() {
		return m_weight;
	}

	int get_price() {
		return m_price;
	}

private:
	std::string m_name;
	double m_weight{0};
	int m_price{0};
};

int main() {
	Thing th1;
	Thing th2("Book");
	Thing th3("Mouse", 0.1, 13200);

	Thing* ptr_th = new Thing{"HP Omen", 2.3, 120000};

	delete ptr_th;
	return 0;
}