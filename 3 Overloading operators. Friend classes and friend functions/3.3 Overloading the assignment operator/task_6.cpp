#include <string>

class BankAccount {
public:
	BankAccount(const std::string fio, long volume_rub = 0) : m_fio{fio}, m_volume_rub{volume_rub} {}

	BankAccount& operator=(long volume_rub) {
		m_volume_rub = volume_rub;
		return *this;
	}

	const std::string& get_fio() const {
		return m_fio;
	}

	long get_volume_rub() const {
		return m_volume_rub;
	}

private:
	std::string m_fio;
	long m_volume_rub{0}; 
};

int main() {

	return 0;
}