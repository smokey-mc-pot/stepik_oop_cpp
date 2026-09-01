class Point {
public:
	Point() = default;

	Point(int x, int y) {
		set_coords(x, y);
	};

	static void set_bounds(int left, int right);
	static void get_bounds(int& left, int& right);
	void set_coords(int x, int y);

private:
	int m_x{0}, m_y{0};
	static int MIN_COORD;
	static int MAX_COORD;

	bool check_coord(int coord) const;
};

int Point::MIN_COORD{0};
int Point::MAX_COORD{10}; 

bool Point::check_coord(int coord) const {
	return coord <= MAX_COORD && coord >= MIN_COORD;
}

void Point::set_bounds(int left, int right) {
	MIN_COORD = left;
	MAX_COORD = right;
}

void Point::get_bounds(int& left, int& right) {
	left = MIN_COORD;
	right = MAX_COORD;
}

void Point::set_coords(int x, int y) {
	if (check_coord(x) && check_coord(y)) {
		m_x = x;
		m_y = y;
	}
}

int main() {
	Point::set_bounds(100, 100);
	Point pt{-5, 7};

	return 0;
}