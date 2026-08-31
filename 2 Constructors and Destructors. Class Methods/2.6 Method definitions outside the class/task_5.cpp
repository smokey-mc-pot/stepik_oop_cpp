class Wallet {
public:
	Wallet() = delete;
	Wallet(int volume) : m_volume{volume} {};

	void add(int vol);
	int get_volume() const;

private:
	int m_volume{0};
	bool check_volume(int x);
};

bool Wallet::check_volume(int x) {
	return x >= 0;
}

void Wallet::add(int vol) {
	if (check_volume(vol)) {
		m_volume += vol;
	}
}

int Wallet::get_volume() const {
	return m_volume;
}

int main() {
	Wallet wallet{544653}; 
	int vl = wallet.get_volume();
	return 0;
}