#include <algorithm>

class Rectangle {
public:
	Rectangle() = default;
	Rectangle(int x0, int y0, int x1, int y1) : m_x0{x0}, m_y0{y0}, m_x1{x1}, m_y1{y1} {};

	Rectangle operator+(const Rectangle& rect) {
		return Rectangle{std::min(m_x0, rect.m_x0), 
						 std::min(m_y0, rect.m_y0), 
						 std::max(m_x1, rect.m_x1), 
						 std::max(m_y1, rect.m_y1)
		};
	}

	void get_coords(int& x0, int& y0, int& x1, int& y1) const {
		x0 = m_x0;
		y0 = m_y0;
		x1 = m_x1;
		y1 = m_y1;
	}

	void set_coords(int x0, int y0, int x1, int y1) {
		m_x0 = x0;
		m_y0 = y0;
		m_x1 = x1;
		m_y1 = y1;
	}

private:
	int m_x0{0}, m_y0{0}, m_x1{0}, m_y1{0};
};

int main() {
    Rectangle rect_1(-5, 0, 10, 12);
    Rectangle rect_2(1, -2, 7, 14);

	return 0;
}