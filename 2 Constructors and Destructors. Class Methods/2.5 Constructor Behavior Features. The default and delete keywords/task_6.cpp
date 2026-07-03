class Operator {
public:
    static Operator* create_obj() {
        Operator * ptr_obj = new Operator();
        return ptr_obj;
    }

private:
	Operator() = default;
	long a{0}, b{0}, c{0};
};