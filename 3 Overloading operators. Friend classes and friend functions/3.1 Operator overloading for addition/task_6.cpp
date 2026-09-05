class StudentMarks {
public:
    StudentMarks(short* ms, int total) {
        m_count = (total > m_max_length) ? m_max_length : total;

        for (int i = 0; i < m_count; ++i) {
            m_marks[i] = ms[i];
		}
    }

	StudentMarks operator+(const StudentMarks& student) const {
        int total = m_count + student.m_count;
	
        if (total > m_max_length) {
            total = m_max_length;
		}

        short tmp[m_max_length];

        for (int i = 0; i < m_count; ++i) {
            tmp[i] = m_marks[i];
		}

        int i = m_count;

        for (int j = 0; i < total; ++i, ++j) {
            tmp[i] = student.m_marks[j];
		}

        return StudentMarks{tmp, total};
	}

	StudentMarks operator+(short mark) const {
        int total = (m_count < m_max_length) ? m_count + 1 : m_max_length;

        short tmp[m_max_length];

        for (int i = 0; i < m_count; ++i) {
            tmp[i] = m_marks[i];
		}

        if (m_count < m_max_length) {
            tmp[m_count] = mark;
		}

        return StudentMarks{tmp, total};
    }

    const short* get_marks() const { 
		return m_marks; 
	}

    int get_count() const { 
		return m_count;
	}

private:
    enum {
		m_max_length = 100
	};

    short m_marks[m_max_length]{0}; 
    int m_count{0};
};
