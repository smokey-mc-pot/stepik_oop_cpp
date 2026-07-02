#include <iostream>
#include <string>

struct CPU {
    CPU() = default;
    CPU(std::string model, double fr) : m_model{model}, m_fr{fr}{}
    
    std::string m_model; 
    double m_fr;
};

struct Memory {
    Memory() = default;
    Memory(std::string name, unsigned long long volume) : m_name{name}, m_volume{volume} {}
    
    std::string m_name; 
    unsigned long long m_volume; 
};

class MotherBoard {
public:
    MotherBoard(const CPU& cpu, const Memory& mem_1, const Memory& mem_2) : cpu(cpu), mems {mem_1, mem_2} {}
    
    CPU& get_cpu() { 
        return cpu; 
    }
    
    Memory* get_mems() { 
        return mems; 
    }

private:
    CPU cpu;
    Memory mems[2];
};

int main() {
    MotherBoard* ptr_mb = new MotherBoard{{"CORE i5", 1.7}, {"Samsung", 4000000000}, {"Kingston", 8000000000}}; 
    delete ptr_mb;
 
    return 0;
}