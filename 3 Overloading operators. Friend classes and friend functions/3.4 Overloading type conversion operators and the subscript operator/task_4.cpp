class Box3D {
private:
    class DimProxy;

public:
	Box3D() = default;
	Box3D(short a, short b, short c) : m_a{a}, m_b{b}, m_c{c} {}

	void get_dims(short& a, short& b, short& c) const {
		a = m_a;
		b = m_b;
		c = m_c;
	}

	void set_dims(short a, short b, short c) {
		if (a > 0) { 
			m_a = a;
		}

        if (b > 0) {
			m_b = b;
		}

        if (c > 0) {
			m_c = c;
		}
	}

    operator int() const {
        return m_a*m_b*m_c;
    }

    DimProxy operator[](int index) {
        switch (index) {
            case 0: 
				return DimProxy{m_a};
            case 1: 
				return DimProxy{m_b};
            case 2: 
				return DimProxy{m_c};
        }

        static short dummy{0};

        return DimProxy{dummy};
    }

    short operator[](int index) const {
        switch (index) {
            case 0: 
				return m_a;
            case 1: 
				return m_b;
            case 2: 
				return m_c;
        }

        return 0;
    }

private:
	class DimProxy { 
    public:
        DimProxy(short& r) : ref{r} {}

        DimProxy& operator=(short val) {
            if (val > 0) {
                ref = val;
            }
            
            return *this;
        }

        operator short() const {
            return ref;
        }

	private :
		short& ref;
    };

	short m_a{0}, m_b{0}, m_c{0};
};