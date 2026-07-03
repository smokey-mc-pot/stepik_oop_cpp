#include <iostream>
#include <string.h>

class Flower {
public:
    Flower() = delete;
    Flower(const Flower& flower) = delete;
    
    Flower(const char* str, int price) : price{price} {
        if (name != nullptr) { 
            strcpy(name, str);
        }
    }
    
    void get_data(char* name, int& price) {
        if (this->name != nullptr) {     
            strcpy(name, this->name);
        }
        
        price = this->price;
    }
    
private:
    char name[100]{0};
    int price{0}; 
};

int main() {
    Flower flower("Тюльпан", 120); 
    return 0;
}