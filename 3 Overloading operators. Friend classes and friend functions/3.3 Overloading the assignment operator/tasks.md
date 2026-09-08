# Задачи — 3.3 Перегрузка оператора присваивания

## Задача 3 — Array

В программе объявлен класс `Array`:

```cpp
class Array {
public:
    Array() = default;

    Array(int* data, size_t size) : m_size{size} {
        m_data = new int[m_size];

        for (size_t i{0}; i < m_size; ++i) {
            m_data[i] = data[i];
        }
    }

    ~Array() {
        delete[] m_data;
    }

    void set_data(int* data, size_t size) {
        delete[] m_data;

        m_size = size;
        m_data = new int[m_size];

        for (size_t i{0}; i < m_size; ++i) {
            m_data[i] = data[i];
        }
    }

    int* get_data() {
        return m_data;
    }

    size_t get_size() const {
        return m_size;
    }

private:
    int* m_data{nullptr};
    size_t m_size{0};
};
```

Настройте конструктор или конструкторы так, чтобы объекты класса `Array` можно было создавать командами:

```cpp
Array array1{};
Array array2{data, std::size(data)};
```

При создании `array2` в массив `m_data` должны скопироваться данные из массива `data`, а поле `m_size` должно быть равно `std::size(data)`.

Не забудьте добавить в класс деструктор для освобождения памяти, выделенной под массив `m_data`.

Переопределите операции сложения и присваивания, чтобы с объектами класса `Array` можно было выполнять следующие команды:

```cpp
Array result1{};
result1 = array1 + array2;
```

При сложении значения массивов `m_data` должны объединяться по порядку в единый массив. Поле `m_size` должно содержать итоговую длину результирующего массива.

Также должна работать цепочка сложений:

```cpp
Array result2 = array1 + array2 + array3;
```

## Задача 4 — AbsoluteValue

Объявите класс `AbsoluteValue`, содержащий следующий публичный атрибут:

```cpp
unsigned long m_value{0};  // абсолютное значение
```

Объявите конструктор или конструкторы так, чтобы объекты класса можно было создавать командами:

```cpp
AbsoluteValue value1{};        // value = 0
AbsoluteValue value2{100};     // value = 100
AbsoluteValue value3{-50};     // value = 50
```

Отрицательные значения должны преобразовываться в положительные, то есть должны браться по модулю.

Переопределите операцию присваивания так, чтобы с объектами класса можно было выполнять команды:

```cpp
value1 = -123;  // value = 123
value2 = 10;    // value = 10
```

В функции `main` создайте объект класса `AbsoluteValue` с помощью оператора `new` и указателя `ptr_value`:

```cpp
AbsoluteValue* ptr_value = new AbsoluteValue{};
```

С помощью операции присваивания присвойте объекту `ptr_value` значение `-512`. В конце функции `main` освободите выделенную память.

## Задача 5 — Rectangle

Объявите класс `Rectangle`, содержащий следующие приватные поля:

```cpp
short m_x0{0};
short m_y0{0};
short m_x1{0};
short m_y1{0};
int m_border_color{0};
int m_fill_color{255};
```

Поля `m_x0`, `m_y0`, `m_x1`, `m_y1` задают координаты прямоугольника.

Добавьте публичные методы:

```cpp
int get_border_color() const;
int get_fill_color() const;
void get_coords(short& x0, short& y0, short& x1, short& y1) const;
void set_coords(short x0, short y0, short x1, short y1);
void set_border_color(int color);
void set_fill_color(int color);
```

Методы, которые не изменяют состояние объекта `Rectangle`, сделайте константными.

Объявите конструктор или конструкторы так, чтобы объекты класса можно было создавать командами:

```cpp
Rectangle rectangle1{};
Rectangle rectangle2{1, 2, 10, 20};
```

Переопределите операцию присваивания так, чтобы можно было выполнить команду:

```cpp
Rectangle rectangle{};
rectangle = rectangle2;
```

При присваивании должны копироваться только координаты `m_x0`, `m_y0`, `m_x1`, `m_y1`. Поля `m_border_color` и `m_fill_color` копироваться не должны.

## Задача 6 — BankAccount

Объявите класс `BankAccount`, содержащий следующие приватные поля:

```cpp
std::string m_fio;       // владелец счета
long m_volume_rub{0};    // объем средств в рублях
```

Добавьте публичные методы:

```cpp
const std::string& get_fio() const;
long get_volume_rub() const;
```

Методы, которые не изменяют состояние объекта `BankAccount`, сделайте константными.

Объявите конструктор или конструкторы так, чтобы объекты класса можно было создавать командами:

```cpp
BankAccount account1{"Balakirev"};
BankAccount account2{"Pushkin", 10000};
```

Для объектов должны выполняться следующие условия:

```text
account1: fio = "Balakirev", volume_rub = 0
account2: fio = "Pushkin", volume_rub = 10000
```

Переопределите операцию присваивания так, чтобы с объектами класса можно было выполнять команду:

```cpp
account1 = 512000;
```

После присваивания поле `m_volume_rub` должно быть равно `512000`, а поле `m_fio` не должно измениться.

## Задача 7 — PhoneBook

Продолжите программу, в которой объявлены структура `PhoneBookItem` и класс `PhoneBook`:

```cpp
struct PhoneBookItem {
    PhoneBookItem() = default;
    PhoneBookItem(std::string fio, std::string phone_number) : m_fio{fio}, m_phone_number{phone_number} {}
    
    std::string m_fio;          // ФИО контакта
    std::string m_phone_number; // номер телефона
};

class PhoneBook {
public:
    PhoneBook() {
        m_phone_book = new PhoneBookItem[max_phone_book];
    }

    PhoneBook(PhoneBookItem* items, size_t size) {
        m_count = size > max_phone_book ? max_phone_book : size;
        m_phone_book = new PhoneBookItem[max_phone_book];

        for (size_t i{0}; i < m_count; ++i) {
            m_phone_book[i] = items[i];
        }
    }

    ~PhoneBook() {
        delete[] m_phone_book;
    }

    const PhoneBookItem* get_phone_book() const;
    size_t get_count() const;
    bool append(const PhoneBookItem& item);

private:
    enum { 
        max_phone_book = 100 
    };

    PhoneBookItem* m_phone_book{nullptr}; // массив записей
    size_t m_count{0};                    // количество записей
};
```

Метод `append` должен добавлять переданный контакт `item` в конец телефонной книги. Если контакт добавлен успешно, метод должен вернуть `true` и увеличить счетчик `m_count` на единицу. Если телефонная книга заполнена, метод должен вернуть `false`.

Методы, которые не изменяют состояние объекта `PhoneBook`, сделайте константными.

Переопределите в классе `PhoneBook` операции присваивания и сложения, чтобы реализовать следующую логику:

```cpp
PhoneBook phone_book{};
PhoneBookItem item{"Sergey", "+79041704034"};

phone_book = phone_book + item;
```

Операция сложения должна добавлять контакт в конец телефонной книги, если максимальное количество записей `max_phone_book` еще не достигнуто.

Также должна работать операция присваивания телефонной книги:

```cpp
PhoneBook phone_book2{};
phone_book2 = phone_book;
```

В объекте `phone_book2` должен создаваться собственный массив `m_phone_book` с поэлементным копированием значений из массива объекта `phone_book`.

В функции `main` создайте объект класса `PhoneBook` с именем `phone_list`. Добавьте в телефонную книгу следующие контакты в указанном порядке:

```text
"А. Дзюба", "+71237694401"
"П. Гагарина", "+79234694105"
"О. Бузова", "+79041563055"
"Тимати", "+79121000000"
```
