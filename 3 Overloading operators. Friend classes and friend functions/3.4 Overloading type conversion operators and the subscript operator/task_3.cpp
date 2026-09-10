#include <cstddef>
#include <array>

class PointND {
public:
    PointND() = default;

    PointND(short* cds, size_t len) : m_dims{len} {
        m_coords = new short[m_dims];

        for (size_t i{0}; i < m_dims; ++i) {
            m_coords[i] = cds[i];
		}
    }

	PointND(const PointND& other) : m_dims{other.m_dims} {
        m_coords = new short[m_dims];
        
        for (size_t i{0}; i < m_dims; ++i) {
            m_coords[i] = other.m_coords[i];
        }
    }

    ~PointND() { 
		delete[] m_coords; 
	}

	short& operator[](short index) {
		if (index >= m_dims) {
			return m_zero;
		}

		return m_coords[index];
	}

	PointND& operator=(const PointND& other) {
		if (this == &other) {
			return *this;
		}

		delete[] m_coords;
		m_dims = other.m_dims;
		m_coords = new short[m_dims]{0};

		for (size_t i{0}; i < m_dims; ++i) {
			m_coords[i] = other.m_coords[i];
		}

		return *this;
	}

private:
    short* m_coords{nullptr};
    size_t m_dims{0}; 
	short m_zero{0};
};