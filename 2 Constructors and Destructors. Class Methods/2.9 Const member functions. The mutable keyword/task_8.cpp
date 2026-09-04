#include <cstring>

class GamePole {
public:
	GamePole(int rows, int cols) : m_rows{rows}, m_cols{cols} {
        if (rows > 0 && cols > 0) {
            m_pole = new char[rows * cols];
            std::memset(m_pole, 0, rows * cols * sizeof(char));
        }
	}

	GamePole(const GamePole& other) : m_rows{other.m_rows}, m_cols{other.m_cols} {
        if (other.m_pole) {
            m_pole = new char[m_rows * m_cols];
            std::memcpy(m_pole, other.m_pole, m_rows * m_cols * sizeof(char));
        }
    }

	GamePole(const GamePole&) = delete;
    GamePole& operator=(const GamePole&) = delete;

	~GamePole() {
        delete[] m_pole;
    }

	static GamePole* init(int height, int width) {
		if (!instance) {
            instance = new GamePole(height, width);
        }

        return instance;
	}

	void set_item(int row, int col, char value) const {
		if (row >= 0 && row < m_rows && col >= 0 && col < m_cols && m_pole != nullptr) {
			m_pole[row * m_cols + col] = value;
		}
	}

	char get_item(int row, int col) const {
		if (row >= 0 && row < m_rows && col >= 0 && col < m_cols && m_pole != nullptr) {
			return m_pole[row * m_cols + col];
		}
	}

	const char* get_pole() const {
		return m_pole;
	}

	void get_size(int& rows, int& cols) const {
		rows = m_rows;
		cols = m_cols;
	}

private:
	int m_rows{0}, m_cols{0};
	char* m_pole{nullptr};

	static GamePole* instance;
};

int main() {
	GamePole* ptr_pl = GamePole::init(5, 10);
	ptr_pl->set_item(1, 1, '@');
	ptr_pl->set_item(4, 9, '#');
	ptr_pl->set_item(3, 2, '*');

	return 0;
}