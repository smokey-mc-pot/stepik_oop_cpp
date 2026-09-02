class Operator {
public:
	Operator(const Operator& op) = delete;

    void set_state(int t, short o) { 
		m_type = t; 
		m_operation = o; 
	}

    void get_state(int& t, short& o) { 
		t = m_type; 
		o = m_operation; 
	}

	static Operator* create() {
		return new Operator;
	}

private:
	Operator() = default;

	int m_type{0};
    short m_operation{-1};
};