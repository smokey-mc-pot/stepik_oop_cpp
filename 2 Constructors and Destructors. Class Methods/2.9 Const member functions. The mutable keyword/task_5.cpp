class CellItem {
public:
	CellItem(int row, int col) : m_row{row}, m_col{col} {}
	CellItem(int row, int col, double d) : m_row{row}, m_col{col}, m_data{d} {}

	double get_data() const {
		return m_data;
	}

	int get_row() const {
		return m_row;
	}

	int get_col() const {
		return m_col;
	}

	void set_data(double d) {
		m_data = d;
	}

private:
	int m_row{0}, m_col{0};
	double m_data{0.0};
};

int main() {
	CellItem cell{5, 7, 0.79};
	return 0;
}