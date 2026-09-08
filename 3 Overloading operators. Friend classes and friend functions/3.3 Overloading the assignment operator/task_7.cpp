#include <string>

struct PhoneBookItem {
	PhoneBookItem() = default;
    PhoneBookItem(std::string fio, std::string phone_number) : m_fio{fio}, m_phone_number{phone_number} {}

    std::string m_fio; 
    std::string m_phone_number;
};

class PhoneBook { 
public:
    PhoneBook() {
        m_phone_book = new PhoneBookItem[max_phone_book];
    }

    PhoneBook(PhoneBookItem* lst, size_t size) {
        m_count = (size > max_phone_book) ? max_phone_book : size;
        m_phone_book = new PhoneBookItem[max_phone_book];
	
        for (int i{0}; i < m_count; ++i) {
            m_phone_book[i] = lst[i];
		}
    }

    ~PhoneBook() { 
		delete[] m_phone_book; 
	}

	PhoneBook operator+(const PhoneBookItem& other) const {
		PhoneBook result = *this;
		result.append(other);
		return result;
	}

	PhoneBook& operator=(const PhoneBook& other) {
		if (this == &other) {
			return *this;
		}

		delete[] m_phone_book;
		m_count = other.m_count;
		m_phone_book = new PhoneBookItem[max_phone_book];

        for (size_t i{0}; i < m_count; ++i) {
            m_phone_book[i] = other.m_phone_book[i];
        }

		return *this;
	}

	const PhoneBookItem* get_phone_book() const {
		return m_phone_book;
	}

	size_t get_count() const {
		return m_count;
	}

	bool append(const PhoneBookItem& item) {
		if (m_count >= max_phone_book) {
			return false;
		}

		m_phone_book[m_count] = item;
		++m_count;

		return true;
	}

private:
    enum { 
		max_phone_book = 100 
	}; 

    PhoneBookItem* m_phone_book{nullptr};
    size_t m_count{0};
};

int main() {
	PhoneBook phone_lst;
	phone_lst.append({"А. Дзюба", "+71237694401"});
	phone_lst.append({"П. Гагарина", "+79234694105"});
	phone_lst.append({"О. Бузова", "+79041563055"});
	phone_lst.append({"Тимати", "+79121000000"});

	return 0;
}