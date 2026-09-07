#include <iostream>

class Distance {
public:
	Distance() = default;
	Distance(long dist) : m_dist{dist} {}

	friend void set_distance(Distance& dst, long value);
	friend long get_distance(const Distance& dst);
	friend double distance_to_meters(const Distance& dst);

	friend Distance operator+(const Distance& first, const Distance& second);

private:
	long m_dist{0};
};

void set_distance(Distance& dst, long value) {
	dst.m_dist = value;
}

long get_distance(const Distance& dst) {
	return dst.m_dist;
}

double distance_to_meters(const Distance& dst) {
	return dst.m_dist / 1000.0;
}

Distance operator+(const Distance& first, const Distance& second) {
	Distance dst; 
	dst.m_dist = first.m_dist + second.m_dist;

	return dst;
}

int main() {
	Distance d{783};
	std::cout << get_distance(d) << " " << distance_to_meters(d) << std::endl;
	return 0;
}