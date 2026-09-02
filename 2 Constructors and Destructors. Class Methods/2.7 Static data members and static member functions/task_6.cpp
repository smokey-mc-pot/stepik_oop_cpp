class Operator {
public:
	Operator(const Operator& op) = delete;

    void set_state(int t, short o) { 
		type = t; 
		operation = o; 
	}

    void get_state(int& t, short& o) { 
		t = type; 
		o = operation; 
	}

	static Operator* create() {
		return new Operator;
	}

private:
	Operator() = default;

	int type{0};
    short operation{-1};
};