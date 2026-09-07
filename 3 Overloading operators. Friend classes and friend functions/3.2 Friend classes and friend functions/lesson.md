# 3.2 Дружественные классы и дружественные функции

## Дружественная функция

На прошлом занятии мы получили класс для представления времени:

```cpp
class TimeDay {
public:
    TimeDay() : m_time{0} {}

    TimeDay(unsigned char hours,
            unsigned char minutes,
            unsigned char seconds,
            unsigned int days = 0)
        : m_time{seconds + minutes * 60 + hours * 3600 + days * 86400} {}

    TimeDay(unsigned long time) : m_time{time} {}

    void get_time(unsigned int& days,
                  unsigned char& hours,
                  unsigned char& minutes,
                  unsigned char& seconds) const {
        seconds = m_time % 60;
        minutes = m_time / 60 % 60;
        hours = m_time / 3600 % 24;
        days = m_time / 86400;
    }

    unsigned long get_time() const {
        return m_time;
    }

private:
    unsigned long m_time{0};
};
```

И определили операцию сложения для его объектов с помощью внешней функции:

```cpp
unsigned long operator+(const TimeDay& left, const TimeDay& right) {
    return left.get_time() + right.get_time();
}
```

Эта функция обращается к публичному методу `get_time` переданных объектов, чтобы получить доступ к значению поля `m_time`.

Было бы удобно расширить область видимости класса `TimeDay` на эту внешнюю функцию, чтобы в ее теле можно было напрямую обращаться к приватным данным объектов. Язык C++ предоставляет такой механизм обхода ограничения доступа: дружественные функции.

Объявим функцию `operator+` дружественной по отношению к классу `TimeDay`:

```cpp
class TimeDay {
public:
    TimeDay() : m_time{0} {}

    TimeDay(unsigned char hours,
            unsigned char minutes,
            unsigned char seconds,
            unsigned int days = 0)
        : m_time{seconds + minutes * 60 + hours * 3600 + days * 86400} {}

    TimeDay(unsigned long time) : m_time{time} {}

    friend unsigned long operator+(const TimeDay& left, const TimeDay& right);

private:
    unsigned long m_time{0};
};
```

После этого в теле дружественной функции можно напрямую обращаться к полю `m_time` объектов `left` и `right`:

```cpp
unsigned long operator+(const TimeDay& left, const TimeDay& right) {
    return left.m_time + right.m_time;
}
```

Для объявления дружественной функции используется ключевое слово `friend`, после которого записывается прототип функции.

Дружественная функция не является методом класса, но получает доступ к его приватным и защищенным полям и методам.

## Особенности дружественных функций

Концепция дружественных функций является спорной в языке C++. Одни считают ее приемлемой, поскольку иногда необходимо расширить область видимости класса на внешние функции. Другие полагают, что это может привести к путанице и неочевидным проблемам.

Дружественные функции могут изменять состояние объектов напрямую через приватные переменные, минуя публичные методы класса. Поэтому использовать такой механизм следует осторожно и только тогда, когда без него невозможно обойтись или решение действительно становится понятнее.

## Дружественные классы

Помимо дружественных функций можно объявлять дружественные классы. Это делается похожим образом.

Объявим класс `Clock` дружественным для класса `TimeDay`:

```cpp
class TimeDay {
public:
    TimeDay() : m_time{0} {}

    TimeDay(unsigned char hours,
            unsigned char minutes,
            unsigned char seconds,
            unsigned int days = 0)
        : m_time{seconds + minutes * 60 + hours * 3600 + days * 86400} {}

    TimeDay(unsigned long time) : m_time{time} {}

    friend class Clock;

private:
    unsigned long m_time{0};
};
```

Обратите внимание: дружественность можно объявлять в любой секции класса. На доступ к приватным полям это не влияет.

После класса `TimeDay` объявим класс `Clock`:

```cpp
#include <cstdio>

class Clock {
public:
    void show_time(const TimeDay& time) const {
        unsigned char seconds = time.m_time % 60;
        unsigned char minutes = time.m_time / 60 % 60;
        unsigned char hours = time.m_time / 3600 % 24;

        std::printf("%02u:%02u:%02u", hours, minutes, seconds);
    }
};
```

Благодаря дружественности с классом `TimeDay` метод `show_time` класса `Clock` может напрямую обращаться к приватной переменной `m_time` объекта `time`.

Используем эти классы в функции `main`:

```cpp
int main() {
    TimeDay time1{10, 45, 13};
    TimeDay time2{4, 11, 50};
    TimeDay result = time1 + 10;

    Clock clock;
    clock.show_time(result);

    return 0;
}
```

Это учебный пример. Тот же функционал можно реализовать без дружественности, например с помощью публичного метода `get_time`. На практике следует сначала проверить, можно ли изменить структуру программы так, чтобы дружественная функция или дружественный класс не понадобились.

Если после этого использование дружественности все еще оправдано, можно применить ключевое слово `friend`.

---

## Тест

### Вопрос 1

Выберите все верные утверждения, касающиеся дружественных классов и функций.

- [x] дружественные функции и классы можно объявлять в любых секциях класса (публичной, приватной); это никак не скажется на их функциональности
- [x] если в классе имеется дружественная функция `operator+` и аналогичный метод, то возникает неопределенность приоритета их вызова
- [x] дружественные функции имеют доступ к приватным полям объектов класса
- [x] в практике программирования следует избегать объявления дружественных функций и классов
- [ ] дружественные функции и классы нужно объявлять только в публичной секции класса

### Вопрос 2

Выберите все верные варианты объявления дружественной функции с сигнатурой:

```cpp
int get_value();
```

для класса `Value`.

- [ ] `class friend Value { int get_value(); };`
- [ ] `class Value { int get_value() friend; };`
- [ ] `friend class Value { int get_value(); };`
- [x] `class Value { friend int get_value(); };`
- [x] `class Value { int friend get_value(); };`

### Вопрос 3

Выберите все верные варианты объявления дружественного класса `Frnd` для класса `Geom`.

- [ ] `friend class Frnd { class Geom; };`
- [ ] `class Frnd { friend class Geom; };`
- [ ] `friend class Geom { class Frnd; };`
- [x] `class Geom { friend class Frnd; };`

### Вопрос 8

Пусть имеется следующий класс:

```cpp
class Vector {
public:
    int get_x();
    int get_y();

private:
    int m_x{0};
    int m_y{0};
};
```

Выберите верный вариант определения метода `get_x` вне класса.

- [ ] `Vector::int get_x() { return m_x; }`
- [x] `int Vector::get_x() { return m_x; }`
- [ ] `Vector.int get_x() { return m_x; }`
- [ ] `Vector::get_x() { return m_x; }`
- [ ] `int Vector.get_x() { return m_x; }`

### Вопрос 9

Отметьте все методы, которые компилятор языка C++ стандарта C++11 автоматически добавляет в класс при необходимости.

- [x] операция присваивания копированием
- [x] конструктор копирования
- [x] конструктор перемещения
- [x] деструктор в виде заглушки
- [ ] конструктор преобразования
- [x] конструктор по умолчанию
- [x] операция присваивания перемещением
