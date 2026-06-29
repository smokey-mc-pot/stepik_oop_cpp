#include <iostream>
#include <limits>

class IntOperator {
public:
    IntOperator() = default;
    IntOperator(int* arr, int sz) : data{arr}, size{sz} {}

    ~IntOperator() {
        for (int i = 0; i < size; ++i) {
            data[i] = 0;
        }
    }

    int sum() {
        if (!size) {
            return 0;
        }

        int sum = 0;

        for (int i = 0; i < size; ++i) {
            sum += data[i];
        }

        return sum;
    }

    double average() {
        if (!size) {
            return 0.0;
        }

        return static_cast<double>(sum()) / size;
    }

    int max() {
        if (!size) {
            return 0;
        }

        int max = std::numeric_limits<int>::min();

        for (int i = 0; i < size; ++i) {
            if (data[i] > max) {
                max = data[i];
            }
        }

        return max;
    }

    int min() {
        if (!size) {
            return 0;
        }

        int min = std::numeric_limits<int>::max();

        for (int i = 0; i < size; ++i) {
            if (data[i] < min) {
                min = data[i];
            }
        }

        return min;
    }

private:
    int* data{nullptr};
    int size{0};
};

int main() {
    int dt[] = {0, -5, 2, 10, 7, 22};

    IntOperator op_1;
    IntOperator op2(dt, std::size(dt));

	std::cout << op2.sum() << " " << op2.average() << " " << op2.max() << " " << op2.min() << std::endl;

    return 0;
}
