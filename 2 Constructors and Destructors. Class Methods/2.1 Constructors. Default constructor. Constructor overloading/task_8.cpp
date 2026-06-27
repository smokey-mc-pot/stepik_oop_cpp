#include <iostream>

struct Point {
    short x, y;
};

class Line {
public:
    Line() {};
    Line(short x0, short y0, short x1, short y1) : m_x0{x0}, m_y0{y0}, m_x1{x1}, m_y1{y1} {};
    Line(Point sp, Point ep) : m_x0{sp.x}, m_y0{sp.y}, m_x1{ep.x}, m_y1{ep.y} {};

    void set_coords(short a, short b, short c, short d);
    void set_coords(Point sp, Point ep);
    Point get_start();
    Point get_end();

private:
    short m_x0{0}, m_y0{0}, m_x1{0}, m_y1{0};
};

void Line::set_coords(short a, short b, short c, short d) {
    m_x0 = a;
    m_y0 = b;
    m_x1 = c;
    m_y1 = d;
}

void Line::set_coords(Point sp, Point ep) {
    m_x0 = sp.x;
    m_y0 = sp.y;
    m_x1 = ep.x;
    m_y1 = ep.y;
}

Point Line::get_start() {
    return {m_x0, m_y0};
}

Point Line::get_end() {
    return {m_x1, m_y1};
}

int main() {
    Point sp, ep;
    short a, b, c, d;

    std::cin >> a >> b >> c >> d;
    std::cin >> sp.x >> sp.y >> ep.x >> ep.y;

    Line* ptr_ln1{new Line(a, b, c, d)};
    Line* ptr_ln2{new Line(sp, ep)};

    std::cout << ptr_ln1->get_start().x << " " << ptr_ln1->get_start().y << " "
              << ptr_ln1->get_end().x   << " " << ptr_ln1->get_end().y   << " "
              << ptr_ln2->get_start().x << " " << ptr_ln2->get_start().y << " "
              << ptr_ln2->get_end().x   << " " << ptr_ln2->get_end().y   << std::endl;

    delete ptr_ln1;
    delete ptr_ln2;

    return 0;
}