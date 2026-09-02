#include <array>

class DataThree {
public:
	static DataThree* get_new_data();

private:
	DataThree() = default;
	DataThree(const DataThree& obj) = delete;
	~DataThree() = default;

	static inline DataThree* m_ptr[3]{nullptr};
	static inline int m_count{0};
};

DataThree* DataThree::get_new_data() {
	if (m_count < 3) {
		m_ptr[m_count] = new DataThree;
        return m_ptr[m_count++];
    } 
    else {
        return m_ptr[std::size(m_ptr) - 1];
    }	
}

int main() {
	std::array<DataThree*, 5> ptr_dates;
    
    for (auto& elem : ptr_dates) {
        elem = DataThree::get_new_data();
    }

	return 0;
}