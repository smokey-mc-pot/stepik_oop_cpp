#include <iostream>
#include <cstddef>

class VectorN {
public:
    VectorN() = default;

    VectorN(int size) : dims{size} {
        coords = new short[dims]{};
    }

    VectorN(short first, short second) : dims{2} {
        coords = new short[2];
        coords[0] = first;
        coords[1] = second;
    }

    VectorN(const short* data, std::size_t size) : dims{static_cast<int>(size)} {
        if (data == nullptr || size == 0) {
            coords = nullptr;
            dims = 0;
            return;
        }

        coords = new short[dims];

        for (int i = 0; i < dims; ++i) {
            coords[i] = data[i];
        }
    }

    ~VectorN() {
        if (coords == nullptr) {
            return;
        }

        std::cout << "delete coords: ";

        for (int i = 0; i < dims; ++i) {
            std::cout << coords[i];

            if (i < dims - 1) {
                std::cout << ' ';
            }
        }

        std::cout << '\n';

        delete[] coords;
    }

    const short* get_coords() {
        return coords;
    }

    int get_dims() {
        return dims;
    }

private:
    int dims{0};
    short* coords{nullptr};
};

int main() {
	short data[] = {4, 2, 10, 0, -5};
	VectorN v1 = 5; 
	VectorN v2(1, 2); 
	VectorN v3(data, std::size(data)); 

	std::cout << v1.get_dims() << '\n';
    std::cout << "v2 dims: " << v2.get_dims() << ". " << "coord1: " << v2.get_coords()[0] << ", " << "coord2: " << v2.get_coords()[1] << '\n';

	return 0;
}