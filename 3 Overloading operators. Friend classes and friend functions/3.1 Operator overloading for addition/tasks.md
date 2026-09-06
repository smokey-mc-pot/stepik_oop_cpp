# Задачи — 3.1 Перегрузка оператора сложения

## Задача 5 — BottleWater

Продолжите программу, в которой уже объявлен класс `BottleWater`:

```cpp
class BottleWater {
public:
    BottleWater(unsigned volume = 0) : m_volume{volume > max_volume ? max_volume : volume} {}

    unsigned get_volume() const {
        return m_volume;
    }

private:
    enum { 
        max_volume = 320 
    };

    unsigned m_volume{0};
};
```

Внесите изменения в конструктор этого класса, чтобы при передаче объема выше значения `max_volume` поле `m_volume` было равно `max_volume`.

Добавьте в этот класс метод или методы `operator+`, чтобы можно было выполнять сложение его объектов следующим образом:

```cpp
BottleWater bottle1{10};
BottleWater bottle2{100};

BottleWater result1 = bottle1 + bottle2;  // result1: volume = 110
BottleWater result2 = bottle2 + 300;      // result2: volume = 320
```

При сложении объемов воды бутылок нужно контролировать превышение максимального уровня `max_volume`. Если максимальный уровень превышен, результирующее значение `m_volume` должно быть равно `max_volume`.

В функции `main` создайте два объекта класса `BottleWater` в виде переменных `bw1` и `bw2` с объемами воды `40` и `200` соответственно. Выполните сложение этих двух объектов и сохраните результат в переменной `result` типа `BottleWater`.

## Задача 6 — StudentMarks

Продолжите программу, в которой уже объявлен класс `StudentMarks`:

```cpp
class StudentMarks {
public:
    StudentMarks(short* marks, int total) {
        m_count = total > max_length ? max_length : total;

        for (int i{0}; i < m_count; ++i) {
            m_marks[i] = marks[i];
        }
    }

    const short* get_marks() const {
        return m_marks;
    }

    int get_count() const {
        return m_count;
    }

private:
    enum { 
        max_length = 100
    };

    short m_marks[max_length]{0}; 
    int m_count{0};             
};
```

Добавьте в этот класс метод или методы `operator+`, чтобы можно было выполнять сложение его объектов следующим образом:

```cpp
short marks1[] = {2, 2, 3, 2, 3};
short marks2[] = {5, 4, 2};

StudentMarks student_marks1{marks1, sizeof(marks1) / sizeof(*marks1)};
StudentMarks student_marks2{marks2, sizeof(marks2) / sizeof(*marks2)};

StudentMarks result1 = student_marks1 + student_marks2;
// result1: marks = {2, 2, 3, 2, 3, 5, 4, 2}, count = 8

StudentMarks result2 = student_marks1 + 4;
// result2: marks = {2, 2, 3, 2, 3, 4}, count = 6
```

При сложении оценки должны объединяться по порядку. Значение поля `m_count` должно быть равно общему числу оценок. Результат сложения должен возвращаться в виде объекта класса `StudentMarks`.

Объекты `student_marks1` и `student_marks2`, участвующие в сложении, изменяться не должны.

Новые конструкторы в класс `StudentMarks` добавлять нельзя. Все реализуйте путем добавления метода или методов `operator+`.

## Задача 7 — Rectangle

Объявите класс `Rectangle`, содержащий следующие элементы.

Приватные поля:

```cpp
int m_x0{0};
int m_y0{0};
int m_x1{0};
int m_y1{0};
```

`m_x0`, `m_y0` - координаты верхнего левого угла, а `m_x1`, `m_y1` - координаты правого нижнего угла.

Публичные методы:

```cpp
void get_coords(int& x0, int& y0, int& x1, int& y1) const;
void set_coords(int x0, int y0, int x1, int y1);
```

Методы, которые не изменяют состояние объектов класса `Rectangle`, сделайте константными.

Объявите конструктор или конструкторы так, чтобы объекты класса можно было создавать командами:

```cpp
Rectangle rectangle1{};
Rectangle rectangle2{1, 2, 10, 20};
```

Для объекта `rectangle2` должны выполняться условия:

```cpp
m_x0 = 1;
m_y0 = 2;
m_x1 = 10;
m_y1 = 20;
```

Добавьте в этот класс метод или методы `operator+`, чтобы можно было выполнять сложение его объектов следующим образом:

```cpp
Rectangle rectangle1{1, 2, 3, 4};
Rectangle rectangle2{5, 6, 7, 8};
Rectangle result = rectangle1 + rectangle2;
```

Для вычисления координат объекта `result` должны использоваться минимальные значения для `m_x0`, `m_y0` и максимальные значения для `m_x1`, `m_y1`:

```cpp
m_x0 = min(1, 5);
m_y0 = min(2, 6);
m_x1 = max(3, 7);
m_y1 = max(4, 8);
```

В функции `main` создайте два объекта класса `Rectangle` в виде обычных переменных `rect1` и `rect2` со следующими данными:

```text
rect1: -5, 0, 10, 12
rect2: 1, -2, 7, 14
```

Выполните сложение этих объектов и сохраните результат в обычной переменной `result` типа `Rectangle`.

## Задача 8 — StringChars

Объявите класс `StringChars`, содержащий следующие элементы.

Приватные поля:

```cpp
char* m_buffer{nullptr};  
size_t m_length{0};      
```

Публичные методы:

```cpp
char* to_str() const;
size_t get_length() const;
```

Методы, которые не изменяют состояние объектов класса `StringChars`, сделайте константными.

Объявите конструктор или конструкторы так, чтобы объекты класса можно было создавать командами:

```cpp
StringChars string1{"Hello"};
StringChars string2 = string1;
```

Для объектов `string1` и `string2` должны выполняться условия:

```text
m_buffer = "Hello"
m_length = 5
```

Не забудьте добавить в класс `StringChars`:

- деструктор для освобождения ранее выделенной памяти;
- конструктор копирования для глубокого копирования строки.

Добавьте в этот класс метод или методы `operator+`, чтобы можно было выполнять сложение его объектов следующим образом:

```cpp
StringChars string1{"Hello, "};
StringChars string2{"C++"};
StringChars result = string1 + string2;
```

После сложения должны выполняться условия:

```text
m_buffer = "Hello, C++"
m_length = 10
```

При сложении объекты, записанные в левом и правом операндах, изменяться не должны.

В функции `main` создайте два объекта класса `StringChars` с помощью оператора `new` и указателей `ptr_string1`, `ptr_string2` на них. Объекты должны хранить следующие строки:

```text
ptr_string1: "Language"
ptr_string2: " C++"
```

Выполните сложение этих объектов и сохраните результат в обычной переменной `result` типа `StringChars`.

Помните, что корректная C++-строка должна заканчиваться символом `\0`.

Не забудьте в конце функции `main` освободить ранее выделенную память:

```cpp
delete ptr_string1;
delete ptr_string2;
```
