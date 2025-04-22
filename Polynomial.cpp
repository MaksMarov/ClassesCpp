#include "Polynomial.h"
#include <cmath>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>

// ========================= ВСПОМОГАТЕЛЬНЫЕ МЕТОДЫ =========================

// Удаляет лишние нули справа от коэффициентов
void Polynomial::trim() {
    while (!coefficients.empty() && std::abs(coefficients.back()) < 1e-10) {
        coefficients.pop_back(); // Убираем нулевой коэффициент с конца
    }
}

// ========================= КОНСТРУКТОРЫ =========================

// Конструктор по умолчанию (инициализирует полином с нулевым коэффициентом)
Polynomial::Polynomial() : coefficients{ 0.0 } {}

// Конструктор, который создаёт полином заданной степени с нулевыми коэффициентами
Polynomial::Polynomial(int degree) {
    if (degree < 0) throw std::invalid_argument("Degree must be non-negative");
    coefficients.resize(degree + 1, 0.0); // Инициализация полинома с нулями
}

// Конструктор, который инициализирует полином с заданной степенью и значением для всех коэффициентов
Polynomial::Polynomial(int degree, double value) {
    if (degree < 0) throw std::invalid_argument("Degree must be non-negative");
    coefficients.resize(degree + 1, value); // Инициализация полинома с одним значением для всех коэффициентов
    trim(); // Обрезаем лишние нули
}

// Конструктор для создания полинома из одного скалярного значения
Polynomial::Polynomial(double scalar) {
    coefficients.push_back(scalar); // Константный полином
}

// Конструктор, который инициализирует полином из списка коэффициентов
Polynomial::Polynomial(const std::vector<double>& coeffs) : coefficients(coeffs) {
    trim(); // Обрезаем лишние нули
}

// Конструктор, который инициализирует полином из инициализирующего списка
Polynomial::Polynomial(std::initializer_list<double> list) : coefficients(list) {
    trim(); // Обрезаем лишние нули
}

// ========================= МЕТОДЫ =========================

// Получение степени полинома
int Polynomial::degree() const {
    return static_cast<int>(coefficients.size()) - 1; // Возвращаем степень полинома
}

// Оценка полинома в точке x (подсчитываем значение полинома)
double Polynomial::evaluate(double x) const {
    double result = 0;
    double power = 1;
    for (double coef : coefficients) {
        result += coef * power;
        power *= x; // Умножаем на x для следующей степени
    }
    return result;
}

// Вычисление производной полинома
Polynomial Polynomial::derivative() const {
    if (coefficients.size() <= 1) return Polynomial(0.0); // Если полином константный, его производная равна нулю
    std::vector<double> deriv(coefficients.size() - 1); // Массив для производной
    for (size_t i = 1; i < coefficients.size(); ++i) {
        deriv[i - 1] = i * coefficients[i]; // Производная от x^n = n*x^(n-1)
    }
    return Polynomial(deriv);
}

// Интегрирование полинома (неопределённый интеграл)
Polynomial Polynomial::integrate() const {
    std::vector<double> integ(coefficients.size() + 1, 0.0); // Массив для интеграла
    for (size_t i = 0; i < coefficients.size(); ++i) {
        integ[i + 1] = coefficients[i] / (i + 1); // Интеграл от x^n = x^(n+1)/(n+1)
    }
    return Polynomial(integ);
}

// ========================= ДЕЛЕНИЕ ПОЛИНОМОВ =========================

// Деление полиномов (возвращает частное)
Polynomial Polynomial::divide(const Polynomial& divisor) const {
    if (divisor.coefficients.empty() || divisor.degree() < 0)
        throw std::runtime_error("Division by zero polynomial");

    Polynomial dividend = *this;
    std::vector<double> result(dividend.degree() - divisor.degree() + 1, 0.0);

    while (dividend.degree() >= divisor.degree()) {
        int deg = dividend.degree() - divisor.degree();
        double coef = dividend.coefficients.back() / divisor.coefficients.back();  // Вычисляем коэффициент

        result[deg] = coef;  // Записываем его в результат

        std::vector<double> sub(deg + divisor.coefficients.size(), 0.0);
        for (size_t i = 0; i < divisor.coefficients.size(); ++i)
            sub[deg + i] = coef * divisor.coefficients[i];

        dividend = dividend - Polynomial(sub);  // Создаём новый полином для делимого
        dividend.trim();  // Обрезаем лишние нули
    }

    return Polynomial(result);  // Возвращаем частное
}

// Остаток от деления полиномов
Polynomial Polynomial::mod(const Polynomial& divisor) const {
    if (divisor.coefficients.empty() || divisor.degree() < 0)
        throw std::runtime_error("Division by zero polynomial");

    Polynomial dividend = *this;

    while (dividend.degree() >= divisor.degree()) {
        int deg = dividend.degree() - divisor.degree();
        double coef = dividend.coefficients.back() / divisor.coefficients.back(); // Коэффициент

        std::vector<double> sub(deg + divisor.coefficients.size(), 0.0);
        for (size_t i = 0; i < divisor.coefficients.size(); ++i)
            sub[deg + i] = coef * divisor.coefficients[i];

        dividend = dividend - Polynomial(sub);  // Вычитаем
        dividend.trim();  // Обрезаем лишние нули
    }

    return dividend;  // Возвращаем остаток
}

// ========================= ОПЕРАЦИИ С ПОЛИНОМАМИ =========================

// Операция сложения полиномов
Polynomial Polynomial::operator+(const Polynomial& other) const {
    size_t max_size = std::max(coefficients.size(), other.coefficients.size());
    std::vector<double> result(max_size, 0.0);
    for (size_t i = 0; i < max_size; ++i) {
        if (i < coefficients.size()) result[i] += coefficients[i];
        if (i < other.coefficients.size()) result[i] += other.coefficients[i];
    }
    return Polynomial(result);
}

// Операция вычитания полиномов
Polynomial Polynomial::operator-(const Polynomial& other) const {
    size_t max_size = std::max(coefficients.size(), other.coefficients.size());
    std::vector<double> result(max_size, 0.0);
    for (size_t i = 0; i < max_size; ++i) {
        if (i < coefficients.size()) result[i] += coefficients[i];
        if (i < other.coefficients.size()) result[i] -= other.coefficients[i];
    }
    return Polynomial(result);
}

// Операция умножения полиномов
Polynomial Polynomial::operator*(const Polynomial& other) const {
    std::vector<double> result(coefficients.size() + other.coefficients.size() - 1, 0.0);
    for (size_t i = 0; i < coefficients.size(); ++i)
        for (size_t j = 0; j < other.coefficients.size(); ++j)
            result[i + j] += coefficients[i] * other.coefficients[j];
    return Polynomial(result);
}

// ========================= ОПЕРАЦИИ С ПРИСВАИВАНИЯМИ =========================

// Операция присваивания для сложения
Polynomial& Polynomial::operator+=(const Polynomial& other) {
    *this = *this + other;
    return *this;
}

// Операция присваивания для вычитания
Polynomial& Polynomial::operator-=(const Polynomial& other) {
    *this = *this - other;
    return *this;
}

// Операция присваивания для умножения
Polynomial& Polynomial::operator*=(const Polynomial& other) {
    *this = *this * other;
    return *this;
}

// ========================= СРАВНЕНИЕ ПОЛИНОМОВ =========================

// Операция сравнения на равенство
bool Polynomial::operator==(const Polynomial& other) const {
    return coefficients == other.coefficients;
}

// Операция сравнения на неравенство
bool Polynomial::operator!=(const Polynomial& other) const {
    return !(*this == other);
}

// ========================= ПРЕОБРАЗОВАНИЕ В SCALAR =========================

// Преобразование полинома в скаляр (если полином константный)
Polynomial::operator double() const {
    if (coefficients.size() == 1) return coefficients[0];
    throw std::runtime_error("Cannot convert polynomial to double");
}

// ========================= ВВОД И ВЫВОД =========================

// Операция вывода полинома в поток
std::ostream& operator<<(std::ostream& os, const Polynomial& poly) {
    for (size_t i = poly.coefficients.size(); i-- > 0;) {
        if (i != poly.coefficients.size() - 1) os << (poly.coefficients[i] >= 0 ? " + " : " - ");
        os << std::abs(poly.coefficients[i]);
        if (i > 0) os << "x^" << i;
    }
    return os;
}

// Операция ввода полинома из потока (однострочный ввод через пробел)
std::istream& operator>>(std::istream& is, Polynomial& poly) {
    std::vector<double> coeffs;
    double coef;

    std::cout << "Введите коэффициенты полинома, разделенные пробелами: ";

    // Чтение коэффициентов из потока
    while (is >> coef) {
        coeffs.push_back(coef);  // Добавляем коэффициент в вектор
        if (is.peek() == '\n') break;  // Если встретили конец строки, выходим из цикла
    }

    if (coeffs.empty()) {
        throw std::invalid_argument("A polynomial cannot be empty. Enter at least one coefficient.");
    }

    // Создаем полином из полученных коэффициентов
    poly = Polynomial(coeffs);
    return is;
}