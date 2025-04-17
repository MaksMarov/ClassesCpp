#include "Complex.h"

// Конструкторы
Complex::Complex() : real(0), imag(0) {}
Complex::Complex(double real, double imag) : real(real), imag(imag) {}
Complex::Complex(const Complex& other) : real(other.real), imag(other.imag) {}

// Получение и установка значений полей
double Complex::getReal() const { return real; }
double Complex::getImag() const { return imag; }
void Complex::setReal(double r) { real = r; }
void Complex::setImag(double i) { imag = i; }

// Арифметика с комплексными числами
Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}

Complex Complex::operator*(const Complex& other) const {
    return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
}

Complex Complex::operator/(const Complex& other) const {
    double denominator = other.real * other.real + other.imag * other.imag;
    return Complex(
        (real * other.real + imag * other.imag) / denominator,
        (imag * other.real - real * other.imag) / denominator
    );
}

// Арифметика с вещественными числами
Complex Complex::operator+(double val) const {
    return Complex(real + val, imag);
}

Complex Complex::operator-(double val) const {
    return Complex(real - val, imag);
}

Complex Complex::operator*(double val) const {
    return Complex(real * val, imag * val);
}

Complex Complex::operator/(double val) const {
    return Complex(real / val, imag / val);
}

// Смена знака
Complex Complex::operator-() const {
    return Complex(-real, -imag);
}

// Присваивание операций
Complex& Complex::operator+=(const Complex& other) {
    real += other.real;
    imag += other.imag;
    return *this;
}

Complex& Complex::operator-=(const Complex& other) {
    real -= other.real;
    imag -= other.imag;
    return *this;
}

Complex& Complex::operator*=(const Complex& other) {
    double r = real * other.real - imag * other.imag;
    double i = real * other.imag + imag * other.real;
    real = r;
    imag = i;
    return *this;
}

Complex& Complex::operator/=(const Complex& other) {
    double denominator = other.real * other.real + other.imag * other.imag;
    double r = (real * other.real + imag * other.imag) / denominator;
    double i = (imag * other.real - real * other.imag) / denominator;
    real = r;
    imag = i;
    return *this;
}

// Сравнение
bool Complex::operator==(const Complex& other) const {
    return real == other.real && imag == other.imag;
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

// Дополнительные методы
double Complex::abs() const {
    return std::sqrt(real * real + imag * imag);
}

double Complex::arg() const {
    return std::atan2(imag, real);
}

Complex Complex::conjugate() const {
    return Complex(real, -imag);
}

// Операции вывода
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.real;
    if (c.imag >= 0)
        os << " + " << c.imag << "i";
    else
        os << " - " << -c.imag << "i";
    return os;
}

// Операции ввода
std::istream& operator>>(std::istream& is, Complex& c) {
    system("cls");
    std::cout << "Введите действительную часть: ";
    is >> c.real;

    std::cout << "Введите мнимую часть: ";
    is >> c.imag;
    return is;
}