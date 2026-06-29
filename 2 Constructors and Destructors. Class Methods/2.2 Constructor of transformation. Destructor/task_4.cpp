#include <iostream>

class Vector3D {
public:
	Vector3D(const int* arr) : x{arr[0]}, y{arr[1]}, z{arr[2]} {}
	
	Vector3D(const char* s) {
        if (!s) {
            return;
        }

        int count{0};
        int i{0};

        while (s[i] && count < 3) {
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

            if (count == 0) {
                x = value;
            } 
            else if (count == 1){
                y = value;
            }
            else {
                z = value;
            }
            
            ++count;
        }
    }

    void get_coords(int& a, int& b, int& c) {
    	a = x; 
		b = y; 
		c = z;
    }

private:
	int x{0}, y{0}, z{0};
};

int main() {
	Vector3D v1 = "1 2 -5";                      // x = 1, y = 2, z = -5
	Vector3D v2 = "1.5 2.2 -5.7";                // x = 1, y = 2, z = -5
	Vector3D v3 = "   1.5 a2.2   ---5.7   data"; // x = 1, y = 0, z = 0

	int coords_1[] = {2, 4, 7}, coords_2[] = {5, 3, 1, 0, 20};

	Vector3D v4 = coords_1; // x = 2, y = 4, z = 7
	Vector3D v5 = coords_2; // x = 5, y = 3, z = 1

	int x, y, z;

	v1.get_coords(x, y, z);
	std::cout << "v1: " << x << " " << y << " " << z << std::endl;

	v2.get_coords(x, y, z);
	std::cout << "v2: " << x << " " << y << " " << z << std::endl;

	v3.get_coords(x, y, z);
	std::cout << "v3: " << x << " " << y << " " << z << std::endl;

	v4.get_coords(x, y, z);
	std::cout << "v4: " << x << " " << y << " " << z << std::endl;

	v5.get_coords(x, y, z);
	std::cout << "v5: " << x << " " << y << " " << z << std::endl;

	return 0;
}