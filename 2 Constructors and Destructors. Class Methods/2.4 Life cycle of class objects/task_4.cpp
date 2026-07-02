#include <iostream>

class Graph {
public:
    Graph() = default;
    Graph(const double* ar, int size) {
        set_data(ar, size);    
    }

    ~Graph() {
        delete[] data;
    }

    void set_data(const double* ar, int size) {
        if (ar == nullptr || size <= 0){
            return;
        }
        
        delete[] data;
        
        data = new double[size];
        length = size;

        for (int i = 0; i < size; ++i) {
           data[i] = ar[i];   
        }
    }

    double* get_data() {
        return data;
    }

    int get_length() {
        return length;  
    }
    
private:
    double* data{nullptr};
    int length{0};
};

int main() {
    double coords[] = {5, 0.4, 2.7, -3.2};
    Graph gr;

    gr.set_data(coords, sizeof(coords)/sizeof(*coords)); 
    return 0;
}