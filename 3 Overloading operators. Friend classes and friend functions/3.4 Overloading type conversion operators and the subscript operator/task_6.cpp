class TicTacToe {
public:
    class Proxy {
    public:
        Proxy(char* pole, int row, int size) : m_pole{pole}, m_row{row}, m_size{size} {}

        char& operator[](int col) {
            if (col < 0 || col >= m_size) {
                return m_dummy;
            }

            return m_pole[m_row * m_size + col];
        }

    private:
        char* m_pole;
        int m_row;
        int m_size;
        char m_dummy{0};
    };

    Proxy operator[](int row) {
        if (row < 0 || row >= m_size_pole) {
            return Proxy{m_pole, 0, m_size_pole}; 
        }

        return Proxy{m_pole, row, m_size_pole};
    }

    const char* get_pole() const { 
		return m_pole; 
	}

    int get_size() const { 
		return m_size_pole; 
	}

private:
    enum { 
		m_size_pole = 3 
	};

    char m_pole[m_size_pole * m_size_pole]{0};
};

int main() {
    TicTacToe* ptr_game{new TicTacToe{}};

    (*ptr_game)[0][0] = 'x';
    (*ptr_game)[1][1] = 'x';
    (*ptr_game)[2][2] = 'x';

    delete ptr_game;
    return 0;
}
