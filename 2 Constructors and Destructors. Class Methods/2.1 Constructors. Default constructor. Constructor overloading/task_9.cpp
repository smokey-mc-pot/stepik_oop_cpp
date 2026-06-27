#include <iostream>

struct Point {
    short x, y;
};

class PolyLine {
public:
    PolyLine() {};
    PolyLine(const Point* ar, int size_ar) { 
        set_coords(ar, size_ar); 
    };

    void set_coords(const Point* ar, int size);
    void append_coord(Point pt);
    const Point* get_coords();
    int get_total(); 

private:
    enum { 
        max_coords = 10 
    };

    Point coords[max_coords];
    int total{0};
};

void PolyLine::set_coords(const Point* ar, int size) {
    for (int i = 0; i < size && i < max_coords; ++i) {
        coords[i] = ar[i];
    }

    total = (size < max_coords) ? size : max_coords;
}

void PolyLine::append_coord(Point pt) {
    if (total < max_coords) {
        coords[total++] = pt;
    }
}

const Point* PolyLine::get_coords() {
    return coords;
}

int PolyLine::get_total() {
    return total;
}

int main() {
    Point coords[20];
    
    for (int i = 0; i < 20; ++i) {
        coords[i].x = i + 1;
        coords[i].y = i + 2;
    }

    PolyLine poly(coords, 20), pl;
    pl.append_coord(coords[19]);

    return 0;
}