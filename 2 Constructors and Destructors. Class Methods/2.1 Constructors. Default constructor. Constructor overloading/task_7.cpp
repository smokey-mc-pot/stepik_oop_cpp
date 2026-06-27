#include <iostream>

class TriangleChecker {
public:
    TriangleChecker(int a, int b, int c) : m_a{a}, m_b{b}, m_c{c} {}
    int is_triangle();

private:
    int m_a{0}, m_b{0}, m_c{0};
};

int TriangleChecker::is_triangle() {
    if (m_a <= 0 || m_b <= 0 || m_c <= 0) {
        return 1;
    }

    if (m_a + m_b <= m_c || m_a + m_c <= m_b || m_b + m_c <= m_a) {
        return 2;
    }

    return 3;
}

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    TriangleChecker* ptr_tr = new TriangleChecker(a, b, c);
    std::cout << ptr_tr->is_triangle();

    delete ptr_tr;
    return 0;
}