class Rectangle {
public:
	Rectangle() = default;
	Rectangle(short x0, short y0, short x1, short y1) : m_x0{x0}, m_y0{y0}, m_x1{x1}, m_y1{y1} {}

	Rectangle& operator=(const Rectangle& rect) {
		set_coords(rect.m_x0, rect.m_y0, rect.m_x1, rect.m_y1);
		return *this;
	}

	int get_border_color() const {
		return m_border_color;
	} 

	int get_fill_color() const {
		return m_fill_color;
	}

	void get_coords(short& x0, short& y0, short& x1, short& y1) const {
		x0 = m_x0;
		y0 = m_y0;
		x1 = m_x1;
		y1 = m_y1;
	}

	void set_coords(short x0, short y0, short x1, short y1) {
		m_x0 = x0;
		m_y0 = y0;
		m_x1 = x1;
		m_y1 = y1;
	}

	void set_border_color(int color) {
		m_border_color = color;
	}

	void set_fill_color(int color) {
		m_fill_color = color;
	}

private:
	short m_x0{0}, m_y0{0}, m_x1{0}, m_y1{0};
	int m_border_color{0};
	int m_fill_color{255};
};