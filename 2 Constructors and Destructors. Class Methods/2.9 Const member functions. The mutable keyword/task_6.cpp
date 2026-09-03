class BoxDims {
public:
	BoxDims(unsigned size_1) : m_dimension{1} {
        m_dims = new unsigned[1];
        m_dims[0] = size_1;
    }

    BoxDims(unsigned size_1, unsigned size_2) : m_dimension{2} {
        m_dims = new unsigned[2];
        m_dims[0] = size_1;
        m_dims[1] = size_2;
    }

    BoxDims(unsigned size_1, unsigned size_2, unsigned size_3) : m_dimension{3} {
        m_dims = new unsigned[3];
        m_dims[0] = size_1;
        m_dims[1] = size_2;
        m_dims[2] = size_3;
    }

    BoxDims(const unsigned* ds, unsigned size_ds) : m_dimension{size_ds} {
        m_dims = new unsigned[size_ds];
	
        for (unsigned i = 0; i < size_ds; ++i) {
            m_dims[i] = ds[i];
        }
    }

	void set_dims(unsigned* ds) {
		for (unsigned short i = 0; i < m_dimension; ++i) {
            m_dims[i] = ds[i];
        }
	}

	unsigned short get_dimension() const {
		return m_dimension;
	}

	const unsigned* get_dims() const {
		return m_dims;
	}

	unsigned get_volume() const {
		unsigned volume = 1;
	
        for (unsigned short i = 0; i < m_dimension; ++i) {
            volume *= m_dims[i];
        }
	
        return volume;
	}

private:
	unsigned short m_dimension{0};
	unsigned* m_dims{nullptr};
};

int main() {
	BoxDims box{3, 10, 5};
	return 0;
}