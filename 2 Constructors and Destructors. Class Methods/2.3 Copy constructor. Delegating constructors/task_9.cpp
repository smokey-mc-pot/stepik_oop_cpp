#include <iostream>

class Vector3D {
public:
    Vector3D() = default;
    Vector3D(int x) : m_x{x} {} 
    Vector3D(int x, int y, int z) : m_x{x}, m_y{y}, m_z{z} {}

    void set_coords(int a, int b, int c) {
        if (a < -100 || a > 100 || b < -100 || b > 100 || c < -100 || c > 100){
            return;
        }
        
        m_x = a;
        m_y = b;
        m_z = c;
    }
    
    void get_coords(int& x, int& y, int& z) {
        x = m_x;
        y = m_y;
        z = m_z;
    }

private:
    int m_x{0}, m_y{0}, m_z{0};
};


int main() {
    auto ptr_v1 = new Vector3D{10, -5, 7};
    auto ptr_v2 = new Vector3D{0, 12, -56};

    delete ptr_v1;
    ptr_v1 = nullptr;
    
    delete ptr_v2;
    ptr_v2 = nullptr;
    
    return 0;
}