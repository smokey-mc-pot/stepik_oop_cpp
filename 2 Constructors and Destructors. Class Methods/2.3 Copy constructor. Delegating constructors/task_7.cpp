#include <iostream>
#include <cmath>

class Complex {
public:
	Complex() {};
	Complex(short re) : m_re{re} {};
    Complex(short re, short im) : m_re{re}, m_im{im} {}
	Complex(const Complex& num) : Complex(abs(num.real()), abs(num.imag())) {}

	short imag() const {
		return m_im;
	}

	short real() const {
		return m_re;
	}

private:
	short m_re{0}, m_im{0};
};

int main() {
	Complex d;        // re = 0, im = 0
	Complex d = 5;    // re = 5, im = 0
	Complex d(1, -6); // re = 1, im = -6

	Complex digit{-4, 7};
	Complex res{digit};
	return 0;
}