#include "Complex.h"
#include <cmath>           // Для std::sqrt и std::atan2
#include <stdexcept>       // Для стандартных исключений
#include <iostream>        // Для std::cin, std::cout

// ========================= КОНСТРУКТОРЫ =========================

// Конструктор по умолчанию (создаёт комплексное число 0 + 0i)
Complex::Complex() : real(0), imag(0) {}

// Конструктор, который позволяет задать действительную и мнимую часть
Complex::Complex(double real, double imag) : real(real), imag(imag) {}

// Конструктор копирования (создаёт копию другого комплексного числа)
Complex::Complex(const Complex& other) : real(other.real), imag(other.imag) {}

// ========================= ГЕТТЕРЫ =========================

// Получить действительную часть комплексного числа
double Complex::getReal() const { return real; }

// Получить мнимую часть комплексного числа
double Complex::getImag() const { return imag; }

// Установить новую действительную часть комплексного числа
void Complex::setReal(double r) { real = r; }

// Установить новую мнимую часть комплексного числа
void Complex::setImag(double i) { imag = i; }

// ========================= АРИФМЕТИКА С КОМПЛЕКСНЫМИ ЧИСЛАМИ =========================

// Сложение комплексных чисел: (a + bi) + (x + yi) = (a + x) + (b + y)i
Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

// Вычитание комплексных чисел: (a + bi) - (x + yi) = (a - x) + (b - y)i
Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}

// Умножение комплексных чисел: (a + bi) * (x + yi) = (a*x - b*y) + (a*y + b*x)i
Complex Complex::operator*(const Complex& other) const {
    return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
}

// Деление комплексных чисел: (a + bi) / (x + yi)
// Формула: (a + bi) / (x + yi) = [(a*x + b*y) + (b*x - a*y)i] / (x^2 + y^2)
// Если знаменатель = 0, выбрасываем исключение
Complex Complex::operator/(const Complex& other) const {
    double denominator = other.real * other.real + other.imag * other.imag;
    if (denominator == 0.0) {
        throw std::domain_error("Division by zero in Complex::operator/.");
    }
    return Complex(
        (real * other.real + imag * other.imag) / denominator,
        (imag * other.real - real * other.imag) / denominator
    );
}

// ========================= АРИФМЕТИКА С ВЕЩЕСТВЕННЫМИ ЧИСЛАМИ =========================

// Сложение комплексного числа с вещественным числом
Complex Complex::operator+(double val) const {
    return Complex(real + val, imag);
}

// Вычитание вещественного числа из комплексного числа
Complex Complex::operator-(double val) const {
    return Complex(real - val, imag);
}

// Умножение комплексного числа на вещественное число
Complex Complex::operator*(double val) const {
    return Complex(real * val, imag * val);
}

// Деление комплексного числа на вещественное число
// Если делитель = 0, выбрасываем исключение
Complex Complex::operator/(double val) const {
    if (val == 0.0) {
        throw std::domain_error("Division by zero in Complex::operator/(double).");
    }
    return Complex(real / val, imag / val);
}

// ========================= СМЕНА ЗНАКА =========================

// Изменяет знак комплексного числа: -(a + bi) = -a - bi
Complex Complex::operator-() const {
    return Complex(-real, -imag);
}

// ========================= ПРИСВАИВАНИЕ ОПЕРАЦИЙ =========================

// Прибавление комплексного числа к текущему объекту
Complex& Complex::operator+=(const Complex& other) {
    real += other.real;
    imag += other.imag;
    return *this;
}

// Вычитание комплексного числа из текущего объекта
Complex& Complex::operator-=(const Complex& other) {
    real -= other.real;
    imag -= other.imag;
    return *this;
}

// Умножение текущего объекта на комплексное число
Complex& Complex::operator*=(const Complex& other) {
    double r = real * other.real - imag * other.imag;
    double i = real * other.imag + imag * other.real;
    real = r;
    imag = i;
    return *this;
}

// Деление текущего объекта на комплексное число
// Если делитель = 0, выбрасываем исключение
Complex& Complex::operator/=(const Complex& other) {
    double denominator = other.real * other.real + other.imag * other.imag;
    if (denominator == 0.0) {
        throw std::domain_error("Division by zero in Complex::operator/=.");
    }
    double r = (real * other.real + imag * other.imag) / denominator;
    double i = (imag * other.real - real * other.imag) / denominator;
    real = r;
    imag = i;
    return *this;
}

// ========================= СРАВНЕНИЕ КОМПЛЕКСНЫХ ЧИСЕЛ =========================

// Проверка на равенство двух комплексных чисел
bool Complex::operator==(const Complex& other) const {
    return real == other.real && imag == other.imag;
}

// Проверка на неравенство двух комплексных чисел
bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

// ========================= ДОПОЛНИТЕЛЬНЫЕ МЕТОДЫ =========================

// Абсолютное значение комплексного числа (модуль): |a + bi| = sqrt(a^2 + b^2)
double Complex::abs() const {
    return std::sqrt(real * real + imag * imag);
}

// Аргумент комплексного числа (угол): arg(a + bi) = atan2(b, a)
double Complex::arg() const {
    return std::atan2(imag, real);
}

// Конъюгированное комплексное число: a + bi -> a - bi
Complex Complex::conjugate() const {
    return Complex(real, -imag);
}

// ========================= ОПЕРАЦИИ ВЫВОДА =========================

// Оператор вывода для комплексного числа
// Выводит число в формате a + bi или a - bi
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.real;
    if (c.imag >= 0)
        os << " + " << c.imag << "i";
    else
        os << " - " << -c.imag << "i";
    return os;
}

// ========================= ОПЕРАЦИИ ВВОДА =========================

// Оператор ввода для комплексного числа
// Вводит действительную и мнимую части с консоли
std::istream& operator>>(std::istream& is, Complex& c) {
    std::cout << "Введите действительную часть: ";
    if (!(is >> c.real)) {
        throw std::ios_base::failure("Invalid input for real part.");
    }

    std::cout << "Введите мнимую часть: ";
    if (!(is >> c.imag)) {
        throw std::ios_base::failure("Invalid input for imaginary part.");
    }

    return is;
}