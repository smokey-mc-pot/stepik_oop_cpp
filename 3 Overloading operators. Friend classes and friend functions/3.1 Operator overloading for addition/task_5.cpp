class BottleWater {
public:
    BottleWater(unsigned volume = 0) : m_volume{volume > m_max_volume ? m_max_volume : volume} {}

    unsigned get_volume() const { 
		return m_volume; 
	}

	BottleWater operator+(const BottleWater& bottle) const {
		return BottleWater{m_volume + bottle.m_volume};
	}

private:
	enum {
		m_max_volume = 320
	};

    unsigned m_volume{0};
};

int main() {
	BottleWater bw1{40}, bw2{200};
	BottleWater res = bw1 + bw2;

	return 0;
}