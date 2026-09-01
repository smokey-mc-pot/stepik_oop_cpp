class Window {
public:
	Window() = delete;

	Window(int width, int height, int color) : m_width{width}, m_height{height}, m_color{color} {
		++total;
	}

	static long get_total() {
		return total;
	}

	void set_size(int w, int h) {
		m_width = w;
		m_height = h;
	}

	void get_size(int& w, int& h) const {
		w = m_width;
		h = m_height;
	}

	int get_color() {
		return m_color;
	}

private:
	static inline unsigned long total{0};
	int m_width{0}, m_height{0}, m_color{0};
};

int main() {
	Window* ptr_wnd{new Window{200, 100, 255}};

	delete ptr_wnd;
	return 0;
}