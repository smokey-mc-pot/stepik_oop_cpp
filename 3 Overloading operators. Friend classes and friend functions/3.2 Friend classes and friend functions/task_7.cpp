enum type_memory {
	mem_none = -1, 
	mem_corsair = 1, 
	mem_adata = 2, 
	mem_kingston = 3
};

class Memory { 
public:
	Memory() = default;
	Memory(unsigned volume, type_memory = mem_none) : m_volume{volume} {}
	Memory(unsigned volume, type_memory type) : m_volume{volume}, m_type{type} {}

	friend void set_memory_data(Memory& mem, unsigned vol, type_memory tp);
	friend void get_memory_data(const Memory& mem, unsigned& vol, type_memory& tp);
	friend Memory operator+(const Memory& first, const Memory& second);

private:
    type_memory m_type{mem_none}; 
    unsigned m_volume;
};

void set_memory_data(Memory& mem, unsigned vol, type_memory tp) {
	mem.m_volume = vol;
	mem.m_type = tp;
}

void get_memory_data(const Memory& mem, unsigned& vol, type_memory& tp) {
	vol = mem.m_volume;
	tp = mem.m_type;
}

Memory operator+(const Memory& first, const Memory& second) {
    return first.m_type == second.m_type ? Memory{first.m_volume + second.m_volume, first.m_type} : Memory{first.m_volume, first.m_type};
}

int main() {
	Memory mem_1{8000, mem_adata};
	Memory mem_2{4000, mem_adata};

	Memory res = mem_1 + mem_2;
	return 0;
}