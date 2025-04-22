#include "Vector2D.h"
#include <iostream>
#include <cmath>
#include <stdexcept>

// ========================= КОНСТРУКТОРЫ =========================

// Конструктор по умолчанию (создаёт нулевой вектор: (0, 0))
Vector2D::Vector2D() : x(0), y(0) {}

// Конструктор, который позволяет сразу задать координаты
Vector2D::Vector2D(double x, double y) : x(x), y(y){}

// ========================= ГЕТТЕРЫ =========================

// Получить X-координату
double Vector2D::getX() const {
    return x;
}

// Получить Y-координату
double Vector2D::getY() const {
    return y;
}

// ========================= АРИФМЕТИКА С ВЕКТОРАМИ =========================

// Сложение векторов: (a, b) + (x, y) = (a+x, b+y)
Vector2D Vector2D::operator+(const Vector2D& other) const {
    return Vector2D(x + other.x, y + other.y);
}

// Вычитание векторов: (a, b) - (x, y) = (a−x, b−y)
Vector2D Vector2D::operator-(const Vector2D& other) const {
    return Vector2D(x - other.x, y - other.y);
}

// Проверка на равенство
bool Vector2D::operator==(const Vector2D& other) const {
    return x == other.x && y == other.y;
}

// Проверка на неравенство
bool Vector2D::operator!=(const Vector2D& other) const {
    return !(*this == other);
}

// ========================= АРИФМЕТИКА СО СКАЛЯРОМ =========================

// Умножение вектора на скаляр
Vector2D Vector2D::operator*(double scalar) const {
    return Vector2D(x * scalar, y * scalar);
}

// Деление вектора на скаляр
Vector2D Vector2D::operator/(double scalar) const {
    if (scalar == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return Vector2D(x / scalar, y / scalar);
}

// ========================= СКАЛЯРНОЕ ПРОИЗВЕДЕНИЕ =========================

// Возвращает скалярное произведение двух векторов:
// (x1*x2 + y1*y2)
double Vector2D::dot(const Vector2D& other) const {
    return x * other.x + y * other.y;
}

// ========================= ДЛИНА ВЕКТОРА =========================

// Возвращает длину вектора (модуль): √(x² + y²)
double Vector2D::length() const {
    return std::sqrt(x * x + y * y);
}

// ========================= КОСИНУС УГЛА МЕЖДУ ВЕКТОРАМИ =========================

// Возвращает cos(угла) между двумя векторами по формуле:
// cos(θ) = (A·B) / (|A|·|B|)
double Vector2D::cos(const Vector2D& other) const {
    double lenA = length();
    double lenB = other.length();

    if (lenA == 0 || lenB == 0) {
        // Если хотя бы один вектор — нулевой, угол не определён
        throw std::domain_error("Cannot compute angle with zero-length vector");
    }

    return dot(other) / (lenA * lenB);
}

// ========================= ПОВОРОТ ВЕКТОРА =========================

// Метод поворота вектора на угол (в градусах)
Vector2D Vector2D::rotate(double angle) const {
    double angleRad = angle * 3.1415 / 180.0;
    // Расчёт новых координат после поворота
    double newX = x * std::cos(angleRad) - y * std::sin(angleRad);
    double newY = x * std::sin(angleRad) + y * std::cos(angleRad);

    return Vector2D(newX, newY);
}

// ========================= ВВОД/ВЫВОД =========================

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
    os << "Vector2D(" << v.x << ", " << v.y << ")";
    return os;
}

// Перегрузка оператора ввода
std::istream& operator>>(std::istream& is, Vector2D& v) {
    double x, y;
    std::cout << "Введите координату X: ";
    if (!(is >> x)) throw std::invalid_argument("Invalid input X");

    std::cout << "Введите координату Y: ";
    if (!(is >> y)) throw std::invalid_argument("Invalid input Y");

    v = Vector2D(x, y);
    return is;
}