#include <iostream>

class Figure {
public:
    Figure() {};
    Figure(int x0, int y0, int x1, int y1) : x0{x0}, y0{y0}, x1{x1}, y1{y1} {}
    
    Figure(const Figure& fig) = delete;
    
    void get_data(int& x0, int& y0, int& x1, int& y1) {
        x0 = this->x0;
        y0 = this->y0;
        x1 = this->x1;
        y1 = this->y1;
    }
    
private:
    int x0{0}, y0{0}, x1{0}, y1{0};
};

int main() {
    Figure fig(-4, 2, 11, 7);
    return 0;
}