# Задачи — 2.3 Конструктор копирования. Делегирующие конструкторы

## Задача 4 — Person (делегирующий конструктор)

Продолжите программу, в которой объявлен класс Person:

```cpp
class Person {
public:
    Person(const std::string& fio) : fio{fio} {
        std::cout << "Person(string)" << std::endl;
    }

    void get_data(std::string& fio, short& age, long& salary) {
        fio = this->fio;
        age = this->age;
        salary = this->salary;
    }

private:
    std::string fio;
    short age{0};
    long salary{0};
};
```

Добавьте в класс делегирующий конструктор, принимающий три параметра:

- std::string fio
- short age
- long salary

И инициализирующий fio вызовом уже имеющегося конструктора.

В main создайте объект класса Person через new и передайте в конструктор значения:

```cpp
"Рахманинов С.В.", 75, 13204
```

Не забудьте освободить память в конце main.

## Задача 5 — StringBuffer (деструктор и конструктор копирования)

Дан класс StringBuffer:

```cpp
class StringBuffer {
public:
    StringBuffer(const char* str) {
        size = 0;
        
        while (str[size] != '\0' && size < max_size - 1) {
            size++;
        }

        buffer = new char[size + 1];
    
        for (int i = 0; i < size; ++i) {
            buffer[i] = str[i];
        }

        buffer[size] = '\0';
    }

    const char* get_data() {
        return buffer;
    }

    int get_size() {
        return size;
    }

private:
    enum { 
        max_size = 1024 
    };

    char* buffer{nullptr};
    int size{0};
};
```

Добавьте в класс:

- деструктор для освобождения buffer;
- конструктор копирования, выполняющий глубокое копирование содержимого buffer.

Пример ожидаемого поведения:

```cpp
StringBuffer s("Hello");
StringBuffer t{s};  // t имеет свой собственный буфер, независимый от s
```

В ответе достаточно объявить и реализовать класс StringBuffer.

## Задача 6 — Thing (делегирование конструктора)

Объявите класс Thing:

- приватные поля:

```cpp
std::string name;    // наименование предмета
double weight{0.0};  // вес предмета
int price{0};        // цена предмета
```

- публичные методы: геттеры get_name, get_weight, get_price.

Конструкторы должны позволять создавать объекты командами:

```cpp
Thing th1;                       // default constructor
Thing th2("Book");               // constructor 1
Thing th3("Mouse", 0.1, 13200);  // constructor 3 (делегирующий)
```

Каждый конструктор должен выводить в консоль соответствующую строку (с переводом строки):

- default constructor
- constructor 1
- constructor 3

Реализуйте конструктор с тремя параметрами как делегирующий (вызывать конструктор с одним параметром для инициализации name).

В main создайте объект через new:

```cpp
ptr_th = new Thing("HP Omen", 2.3, 120000);
```

И затем освободите память.

## Задача 7 — Complex (конструктор копирования)

Объявите класс Complex:

- приватные поля:

```cpp
short re{0};
short im{0};
```

- публичные методы: геттеры real() и imag().

Конструкторы должны позволять создавать объекты:

```cpp
Complex d;         // re=0, im=0
Complex d = 5;     // re=5, im=0
Complex d(1, -6);  // re=1, im=-6
```

Реализуйте конструктор копирования, который при копировании заносит в поля re и im модули значений из копируемого объекта.

В main создайте digit с re=-4, im=7 и res как копию digit (должен быть вызван конструктор копирования).

## Задача 9 — Vector3D (повторение)

Объявите класс Vector3D:

- приватные поля:

```cpp
int x;
int y;
int z;
```

- публичные методы:

```cpp
void set_coords(int a, int b, int c);  // проверка диапазона [-100, 100]
void get_coords(int& x, int& y, int& z);
```

Конструкторы должны позволять создавать объекты:

```cpp
Vector3D v;           // x=0, y=0, z=0
Vector3D v = 5;       // x=5, y=0, z=0
Vector3D v(1, 2, 3);  // x=1, y=2, z=3
```

В main создайте через new два объекта ptr_v1 и ptr_v2 с координатами:

- ptr_v1: 10, -5, 7
- ptr_v2: 0, 12, -56

И освободите память в конце main.
