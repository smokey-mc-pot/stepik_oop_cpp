#include <string>

class Notebook {
public:
    Notebook() = default;
    Notebook(const char* model) : model{model} {}
    Notebook(const char* model, const char* cpu) : model{model}, cpu_model{cpu} {}
    Notebook(const char* model, const char* cpu, unsigned memory) : model{model}, cpu_model{cpu}, memory{memory} {}
    Notebook(const char* model, const char* cpu, unsigned memory, unsigned disk) : model{model}, cpu_model{cpu}, memory{memory}, disk_volume{disk} {}

    void set_data(const std::string& model, const std::string& cpu, unsigned memory, unsigned disk) {
        this->model = model;
        this->cpu_model = cpu;
        this->memory = memory;
        this->disk_volume = disk;
    }

    const std::string& get_model() const {
        return model;
    }

    const std::string& get_cpu() const {
        return cpu_model;
    }

    void get_info(unsigned& memory, unsigned& disk_volume) const {
        memory = this->memory;
        disk_volume = this->disk_volume;
    }

private:
    std::string model;
    std::string cpu_model;
    unsigned memory{0};
    unsigned disk_volume{0};
};

int main() {
    Notebook note{"HP", "Core i7", 16000, 512};
    return 0;
}