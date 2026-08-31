class Thing {
public:
	Thing() = default;

	Thing(long id, int price, double weight) : m_id{id} {
		if (check_price(price)) {
			m_price = price;
		}

		if (check_weight(weight)) {
			m_weight = weight;
		}
	};

	void get_info(long& id, int& price, double& weight);

private:
	long m_id{0};
	int m_price{0};
	double m_weight{0.0};

	bool check_price(int x);
	bool check_weight(double x);
};

bool Thing::check_price(int x) {
	return x >= 0;	
}

bool Thing::check_weight(double x) {
	return x >= 0.0;
}

void Thing::get_info(long& id, int& price, double& weight) {
	m_id = id;
	m_price = price;
	m_weight = weight;
}

int main() {
	Thing th{5, 53403, 87.4};  
	return 0;
}