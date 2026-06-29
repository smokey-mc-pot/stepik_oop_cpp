#include <cctype>
#include <string>
#include <iostream>

class Point {
public:
    Point(const char* s) {
        if (!s) {
            return;
        }

        int count{0};
        int i{0};

        while (s[i] && count < 2) {
            while (s[i] == ' ') { 
                ++i;
            }
            
            if (!s[i]) {
                break;
            }

            int start = i;
            
            while (s[i] && s[i] != ' ') {
                ++i;
            }
            
            int end = i; 

            int pos = start;
            int sign = 1;
            bool numeric = false;
            int num = 0;

            if (s[pos] == '-') {
                sign = -1;
                ++pos;
            }

            if (pos < end && std::isdigit(s[pos])) {
                numeric = true;

                while (pos < end && std::isdigit(s[pos])) {
                    num = num * 10 + (s[pos] - '0');
                    ++pos;
                }

                if (pos < end && s[pos] == '.') {
                    ++pos;
                    
                    while (pos < end && std::isdigit(s[pos])) { 
                        ++pos;
                    }
                }
            }

            int value = numeric ? num * sign : 0;

            if (!count) {
                x = value;
            } 
            else {
                y = value;
            }
            
            ++count;
        }
    }

    int get_x() { 
        return x; 
    }
    
    int get_y() { 
        return y;
    }
    
private:
    int x{0}, y{0};
};

int main() {
	Point p1 = "104332ads 5";          // x = 104332, y = 5
	Point p2 = "-8.7 2.3";             // x = -8, y = 2
	Point p3 = "14.2 -5.8 point data"; // x = 14, y = -5
	Point p4 = "ab8 2.3";              // x = 0, y = 2
	Point p5 = "ab8 2cd";              // x = 0, y = 2

	std::cout << "p1: (" << p1.get_x() << ", " << p1.get_y() << ")\n";
	std::cout << "p2: (" << p2.get_x() << ", " << p2.get_y() << ")\n";
	std::cout << "p3: (" << p3.get_x() << ", " << p3.get_y() << ")\n";
	std::cout << "p4: (" << p4.get_x() << ", " << p4.get_y() << ")\n";
	std::cout << "p5: (" << p5.get_x() << ", " << p5.get_y() << ")\n";

	return 0;
}