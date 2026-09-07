#include <iostream>

enum type_filter {
	flt_aragon = 1, 
	flt_calcium = 2
};

class FilterWater {
public:
    FilterWater(type_filter t, unsigned d, unsigned short v) : m_type{t}, m_date{d}, m_volume{v} {}

	friend type_filter get_type_filter(const FilterWater& flt);
	friend unsigned get_date_filter(const FilterWater& flt);
	friend unsigned short get_volume_filter(const FilterWater& flt);

private: 
    type_filter m_type;
    unsigned m_date; 
    unsigned short m_volume; 
};

type_filter get_type_filter(const FilterWater& flt) {
	return flt.m_type;
}

unsigned get_date_filter(const FilterWater& flt) {
	return flt.m_date;
}

unsigned short get_volume_filter(const FilterWater& flt) {
	return flt.m_volume;
}

int main() {
	FilterWater filter{flt_calcium, 153564646, 108};
	std::cout << get_type_filter(filter) << " " << get_date_filter(filter) << " " << get_volume_filter(filter) << std::endl;
	return 0;
}