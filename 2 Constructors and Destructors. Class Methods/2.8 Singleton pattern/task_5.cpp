class DeskTop {
public:
	int get_width() {
		return m_width;
	}

	int get_height() {
		return m_height;
	}

	static inline DeskTop* get_instance(int width, int height) {
		if (!instance) {
			DeskTop* instance{new DeskTop()};
			instance->m_width = width;
			instance->m_height = height;
			return instance;
		}

		return instance;
	}

private:
	DeskTop() = default;
	DeskTop(const DeskTop& obj) = delete;

	int m_width{0}, m_height{0};
	static inline DeskTop* instance{nullptr};
};

int main() {
	DeskTop* ptr_desk = DeskTop::get_instance(500, 200);
	return 0;
}