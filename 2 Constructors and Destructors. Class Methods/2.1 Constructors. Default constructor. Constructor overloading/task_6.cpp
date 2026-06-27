#include <iostream>

class Wallet {
public:
    Wallet(long volume = 0) : volume{volume} {}
    void set_volume(long volume);
    long get_volume();

private:
    long volume{0};
};

void Wallet::set_volume(long volume) {
    this->volume = volume;
}

long Wallet::get_volume() {
    return volume;
}

int main() {
    Wallet wt1{1000}, wt2;

    return 0;
}
