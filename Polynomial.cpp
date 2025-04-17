#include "Polynomial.h"
#include <cmath>
#include <algorithm>

// Удаляет лишние нули справа
void Polynomial::trim() {
    while (!coefficients.empty() && std::abs(coefficients.back()) < 1e-10) {
        coefficients.pop_back(); // Убираем нулевой коэффициент
    }
}

// Конструкторы
Polynomial::Polynomial() : coefficients{ 0.0 } {}  // Инициализация полинома нулём

Polynomial::Polynomial(int degree) {
    if (degree < 0) throw std::invalid_argument("Degree must be non-negative");
    coefficients.resize(degree + 1, 0.0); // Инициализируем полином с нулями
}

Polynomial::Polynomial(int degree, double value) {
    if (degree < 0) throw std::invalid_argument("Degree must be non-negative");
    coefficients.resize(degree + 1, value); // Инициализация полинома с одним значением для всех коэффициентов
    trim(); // Убираем лишние нули
}

Polynomial::Polynomial(double scalar) {
    coefficients.push_back(scalar); // Константный полином
}

Polynomial::Polynomial(const std::vector<double>& coeffs) : coefficients(coeffs) {
    trim(); // Обрезаем лишние нули
}

Polynomial::Polynomial(std::initializer_list<double> list) : coefficients(list) {
    trim(); // Обрезаем лишние нули
}

// Методы
int Polynomial::degree() const {
    return static_cast<int>(coefficients.size()) - 1; // Возвращаем степень полинома
}

double Polynomial::evaluate(double x) const {
    double result = 0;
    double power = 1;
    for (double coef : coefficients) {
        result += coef * power;
        power *= x; // Умножаем на x для следующей степени
    }
    return result;
}

Polynomial Polynomial::derivative() const {
    if (coefficients.size() <= 1) return Polynomial(0.0); // Если полином константный, его производная равна нулю
    std::vector<double> deriv(coefficients.size() - 1); // Массив для производной
    for (size_t i = 1; i < coefficients.size(); ++i) {
        deriv[i - 1] = i * coefficients[i]; // Производная от x^n = n*x^(n-1)
    }
    return Polynomial(deriv);
}

Polynomial Polynomial::integrate() const {
    std::vector<double> integ(coefficients.size() + 1, 0.0); // Массив для интеграла
    for (size_t i = 0; i < coefficients.size(); ++i) {
        integ[i + 1] = coefficients[i] / (i + 1); // Интеграл от x^n = x^(n+1)/(n+1)
    }
    return Polynomial(integ);
}

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

        dividend = dividend - Polynomial(sub);  // Создаем новый полином для делимого
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

// Арифметика
Polynomial Polynomial::operator+(const Polynomial& other) const {
    size_t max_size = std::max(coefficients.size(), other.coefficients.size());
    std::vector<double> result(max_size, 0.0);
    for (size_t i = 0; i < max_size; ++i) {
        if (i < coefficients.size()) result[i] += coefficients[i];
        if (i < other.coefficients.size()) result[i] += other.coefficients[i];
    }
    return Polynomial(result);
}

Polynomial Polynomial::operator-(const Polynomial& other) const {
    size_t max_size = std::max(coefficients.size(), other.coefficients.size());
    std::vector<double> result(max_size, 0.0);
    for (size_t i = 0; i < max_size; ++i) {
        if (i < coefficients.size()) result[i] += coefficients[i];
        if (i < other.coefficients.size()) result[i] -= other.coefficients[i];
    }
    return Polynomial(result);
}

Polynomial Polynomial::operator*(const Polynomial& other) const {
    std::vector<double> result(coefficients.size() + other.coefficients.size() - 1, 0.0);
    for (size_t i = 0; i < coefficients.size(); ++i)
        for (size_t j = 0; j < other.coefficients.size(); ++j)
            result[i + j] += coefficients[i] * other.coefficients[j];
    return Polynomial(result);
}

// Операторы присваивания
Polynomial& Polynomial::operator+=(const Polynomial& other) {
    *this = *this + other;
    return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial& other) {
    *this = *this - other;
    return *this;
}

Polynomial& Polynomial::operator*=(const Polynomial& other) {
    *this = *this * other;
    return *this;
}

// Сравнение полиномов
bool Polynomial::operator==(const Polynomial& other) const {
    return coefficients == other.coefficients;
}

bool Polynomial::operator!=(const Polynomial& other) const {
    return !(*this == other);
}

// Преобразование в double
Polynomial::operator double() const {
    if (coefficients.size() == 1) return coefficients[0];
    throw std::runtime_error("Cannot convert polynomial to double");
}

// Ввод/вывод
std::ostream& operator<<(std::ostream& os, const Polynomial& poly) {
    for (size_t i = poly.coefficients.size(); i-- > 0;) {
        if (i != poly.coefficients.size() - 1) os << (poly.coefficients[i] >= 0 ? " + " : " - ");
        os << std::abs(poly.coefficients[i]);
        if (i > 0) os << "x^" << i;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Polynomial& poly) {
    // Пример простой реализации для ввода
    std::vector<double> coeffs;
    double coef;
    while (is >> coef) {
        coeffs.push_back(coef);
    }
    poly = Polynomial(coeffs);
    return is;
}