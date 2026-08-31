class Complex {
public:
    Complex(double real, double imag) : re{real}, im{imag} {}
    double get_real() const;
    double get_imag() const;

private:
    double re{0}, im{0};
};

double Complex::get_real() const {
	return re;
}

double Complex::get_imag() const {
	return im;
}