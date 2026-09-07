# Задачи — 3.2 Дружественные классы и дружественные функции

## Задача 4 — ColorRGB

Продолжите программу, в которой объявлен класс `ColorRGB`:

```cpp
class ColorRGB {
public:
    unsigned get_color() const {
        return m_r + m_g * 256 + m_b * 65536;
    }

private:
    unsigned char m_r{0};
    unsigned char m_g{0};
    unsigned char m_b{0};
};
```

Объявите конструктор или конструкторы так, чтобы объекты класса можно было создавать командами:

```cpp
ColorRGB rgb{};
ColorRGB rgb_with_color{255, 102, 0};  // r = 255, g = 102, b = 0
```

Добавьте в этот класс дружественную функцию `operator+`, чтобы можно было выполнять сложение его объектов следующим образом:

```cpp
ColorRGB color1{100, 100, 100};
ColorRGB color2{255, 0, 80};
ColorRGB result = color1 + color2;  // r = 255, g = 100, b = 180
```

При сложении нужно контролировать максимальное значение `255`, которое можно записать в переменную типа `unsigned char`. Если результат сложения превышает `255`, ограничьте его значением `255`.

## Задача 5 — FilterWater

Продолжите программу, в которой объявлены перечисление и класс `FilterWater`:

```cpp
enum type_filter {
    flt_aragon = 1,
    flt_calcium = 2
};

class FilterWater {
public:
    FilterWater(type_filter type, unsigned date, unsigned short volume) : m_type{type}, m_date{date}, m_volume{volume} {}

private:
    type_filter m_type;       // тип фильтра
    unsigned m_date;          // дата установки фильтра
    unsigned short m_volume;  // объем фильтра
};
```

Добавьте в этот класс следующие дружественные функции, которые не являются методами класса:

```cpp
type_filter get_type_filter(const FilterWater& filter);
unsigned get_date_filter(const FilterWater& filter);
unsigned short get_volume_filter(const FilterWater& filter);
```

Функции должны возвращать значения полей `m_type`, `m_date` и `m_volume` соответственно.

В функции `main` создайте объект класса `FilterWater` с именем `filter` и следующими значениями полей:

```text
type: flt_calcium
date: 153564646
volume: 108
```

С помощью дружественных функций прочитайте эти значения из объекта `filter` и выведите их на экран через пробел в порядке `type date volume`.

## Задача 6 — Distance

Объявите класс `Distance`, содержащий следующие элементы.

Приватное поле:

```cpp
long m_distance{0};  // дистанция в миллиметрах
```

Объявьте конструктор или конструкторы так, чтобы объекты класса можно было создавать командами:

```cpp
Distance distance1{};
Distance distance2{1000};
```

Добавьте в класс следующие дружественные функции, которые не являются методами:

```cpp
void set_distance(Distance& distance, long value);
long get_distance(const Distance& distance);
double distance_to_meters(const Distance& distance);
```

Функции должны выполнять следующие действия:

- `set_distance` записывает значение `value` в поле `m_distance` объекта `distance`;
- `get_distance` возвращает значение поля `m_distance`;
- `distance_to_meters` возвращает значение поля `m_distance` в метрах.

Справка: $1$ м = $1000$ мм.

Добавьте в класс дружественную функцию для сложения двух объектов класса `Distance`:

```cpp
Distance distance1{100};
Distance distance2{543};

Distance result1 = distance1 + distance2;  // distance = 643
Distance result2 = distance1 + 500;        // distance = 600
Distance result3 = 10 + distance2;         // distance = 553
```

В функции `main` создайте объект класса `Distance` в виде обычной переменной с именем `distance` и длиной `783`.

С помощью дружественных функций прочитайте и выведите на экран через пробел:

- значение длины объекта `distance` в миллиметрах как целое число;
- значение длины объекта `distance` в метрах с точностью до сотых.

## Задача 7 — Memory

Продолжите программу, в которой объявлены перечисление и класс `Memory`:

```cpp
enum type_memory {
    mem_none = -1,
    mem_corsair = 1,
    mem_adata = 2,
    mem_kingston = 3
};

class Memory {
public:

private:
    type_memory m_type{mem_none};  // тип (производитель) ОЗУ
    unsigned m_volume{0};          // объем ОЗУ в Мб
};
```

Объявите конструктор или конструкторы так, чтобы объекты класса можно было создавать командами:

```cpp
Memory memory1{};
Memory memory2{1000};                  // volume = 1000, type = mem_none
Memory memory3{8000, mem_corsair};     // volume = 8000, type = mem_corsair
```

Добавьте в класс следующие дружественные функции, которые не являются методами:

```cpp
void set_memory_data(Memory& memory, unsigned volume, type_memory type);
void get_memory_data(const Memory& memory, unsigned& volume, type_memory& type);
```

Функция `set_memory_data` должна записывать переданные значения в поля `m_volume` и `m_type` объекта `memory`.

Функция `get_memory_data` должна возвращать значения полей `m_volume` и `m_type` объекта `memory`.

Добавьте в класс дружественную функцию для сложения двух объектов класса `Memory`:

```cpp
Memory memory1{500, mem_corsair};
Memory memory2{1000, mem_corsair};
Memory memory3{1000, mem_kingston};

Memory result1 = memory1 + memory2;
// volume = 1500, type = mem_corsair

Memory result2 = memory3 + memory2;
// volume = 1000, type = mem_kingston
```

Обратите внимание: складывать объемы памяти разных производителей недопустимо. В этом случае нужно вернуть первый объект, то есть левый операнд.

В функции `main` создайте два объекта класса `Memory` в виде обычных переменных `memory1` и `memory2` со следующими данными:

```text
memory1: 8000, mem_adata
memory2: 4000, mem_adata
```

Выполните сложение этих объектов. Результат сохраните в переменной `result` типа `Memory`.
