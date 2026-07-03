#include <iostream>
#include <string>

class Item {
public:
	Item() = default;
    Item(const char* name, unsigned short duration) : name{name}, duration{duration} {}

    std::string& get_name() { 
		return name; 
	}

    unsigned short get_duration() { 
		return duration; 
	}

private:
	std::string name;
    unsigned short duration{0};
};

class TVProg {
public:
    TVProg() = default;
    
    TVProg(const TVProg& other) {
        for (int i = 0; i < other.count; ++i) {
            items[i] = other.items[i];
        }

        count = other.count;
    }
    
    TVProg(const Item& it) {
        append(it);
    }
    
    TVProg(const Item lst[], int length) {
        append(lst, length);
    }
    
    TVProg(std::initializer_list<Item> init) {
        for (const auto& item : init) {
            append(item);
        }
    }
    
    ~TVProg() = default;
    
    void append(const Item& it) {
        if (count < max_length) {
            items[count++] = it;
        }
    }
    
    void append(const Item lst[], int length) {
        for (int i = 0; i < length && count < max_length; ++i) {
            append(lst[i]);
        }
    }
    
    Item* get_list() { 
		return items; 
	}

    int get_count() { 
		return count; 
	}

private:
    enum { 
		max_length = 100 
	};

    Item items[max_length];
    int count{0};
};

int main() {
    Item* ptr_it = new Item;
    Item it("Поле чудес", 120);
    TVProg pr;
    Item lst[3] = {{"Доброе утро", 40}, {"Новости", 15}, {"Модный приговор", 60}};
    TVProg pr2(lst, 3);

    // Работает благодаря конструктору со списком инициализации
    TVProg tv = {{"Новости", 20}, {"Модный приговор", 50}, {"Жить здорово!", 60}, {"Информационный канал", 15}, {"Новости", 15}, {"Давай поженимся!", 70}};

    delete ptr_it;

    return 0;
}