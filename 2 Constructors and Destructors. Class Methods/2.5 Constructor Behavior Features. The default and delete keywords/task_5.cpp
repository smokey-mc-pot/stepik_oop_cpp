class Operator {
public:
	Operator() = default;

    Operator* create_copy() {
        Operator * ptr_obj = new Operator(*this);
        return ptr_obj;
    }

private:
	Operator(const Operator& obj) = default;
	long a{0}, b{0}, c{0};
};