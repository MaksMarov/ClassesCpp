#include "Vector3D.h"
#include <iostream>        // Для std::cin, std::cout
#include <cmath>           // Для sqrt (длина вектора)
#include <stdexcept>       // Для стандартных исключений

// ========================= КОНСТРУКТОРЫ =========================

// Конструктор по умолчанию (создаёт нулевой вектор: (0, 0, 0))
Vector3D::Vector3D() : x(0), y(0), z(0) {}

// Конструктор, который позволяет сразу задать координаты
Vector3D::Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

// ========================= ГЕТТЕРЫ =========================

// Получить X-координату
double Vector3D::getX() const { return x; }

// Получить Y-координату
double Vector3D::getY() const { return y; }

// Получить Z-координату
double Vector3D::getZ() const { return z; }

// ========================= АРИФМЕТИКА С ВЕКТОРАМИ =========================

// Сложение векторов: (a, b, c) + (x, y, z) = (a+x, b+y, c+z)
Vector3D Vector3D::operator+(const Vector3D& other) const {
    return Vector3D(x + other.x, y + other.y, z + other.z);
}

// Вычитание векторов: (a, b, c) - (x, y, z) = (a−x, b−y, c−z)
Vector3D Vector3D::operator-(const Vector3D& other) const {
    return Vector3D(x - other.x, y - other.y, z - other.z);
}

// Проверка на равенство координат векторов
bool Vector3D::operator==(const Vector3D& other) const {
    return x == other.x && y == other.y && z == other.z;
}

// Проверка на неравенство (через отрицание оператора ==)
bool Vector3D::operator!=(const Vector3D& other) const {
    return !(*this == other);
}

// ========================= АРИФМЕТИКА СО СКАЛЯРОМ =========================

// Умножение вектора на число (масштабирование)
Vector3D Vector3D::operator*(double scalar) const {
    return Vector3D(x * scalar, y * scalar, z * scalar);
}

// Деление вектора на число (масштабирование в меньшую сторону)
Vector3D Vector3D::operator/(double scalar) const {
    if (scalar == 0) {
        // Нельзя делить на ноль — кидаем исключение
        throw std::invalid_argument("Division by zero");
    }
    return Vector3D(x / scalar, y / scalar, z / scalar);
}

// ========================= СКАЛЯРНОЕ ПРОИЗВЕДЕНИЕ =========================

// Возвращает скалярное произведение (dot product) двух векторов:
// (x1*x2 + y1*y2 + z1*z2)
double Vector3D::dot(const Vector3D& other) const {
    return x * other.x + y * other.y + z * other.z;
}

// ========================= ВЕКТОРНОЕ ПРОИЗВЕДЕНИЕ =========================

// Возвращает новый вектор — результат векторного произведения
// Работает по формуле векторного произведения в ℝ³
Vector3D Vector3D::cross(const Vector3D& other) const {
    return Vector3D(
        y * other.z - z * other.y, // Новая X-компонента
        z * other.x - x * other.z, // Новая Y-компонента
        x * other.y - y * other.x  // Новая Z-компонента
    );
}

// ========================= СМЕШАННОЕ ПРОИЗВЕДЕНИЕ =========================

// Метод для вычисления смешанного произведения: a . (b × c)
double Vector3D::mixedProduct(const Vector3D& b, const Vector3D& c) const {
    // Сначала вычисляем векторное произведение b × c
    Vector3D crossProduct = b.cross(c);

    // Теперь возвращаем скалярное произведение a . (b × c)
    return this->dot(crossProduct);
}

// ========================= МЕТОД ДЛЯ ПРОВЕРКИ, МОГУТ ЛИ ВЕКТОРЫ ОБРАЗОВАТЬ БАЗИС =========================

// Метод для проверки, могут ли три вектора образовывать базис
bool Vector3D::canFormBasis(const Vector3D& b, const Vector3D& c) const {
    // Проверяем, что смешанное произведение не равно нулю
    return std::abs(this->mixedProduct(b, c)) > 1e-9;  // Если результат не ноль, вектора образуют базис
}

// ========================= ДЛИНА ВЕКТОРА =========================

// Возвращает длину вектора (модуль): √(x² + y² + z²)
double Vector3D::length() const {
    return std::sqrt(x * x + y * y + z * z);
}

// ========================= КОСИНУС УГЛА МЕЖДУ ВЕКТОРАМИ =========================

// Возвращает cos(угла) между двумя векторами по формуле:
// cos(θ) = (A·B) / (|A|·|B|)
double Vector3D::cos(const Vector3D& other) const {
    double lenA = length();
    double lenB = other.length();

    if (lenA == 0 || lenB == 0) {
        // Если хотя бы один вектор — нулевой, угол не определён
        throw std::domain_error("Cannot compute angle with zero-length vector");
    }

    return dot(other) / (lenA * lenB);
}

// ========================= ВВОД/ВЫВОД =========================

// Оператор вывода: делает возможным std::cout << v;
std::ostream& operator<<(std::ostream& os, const Vector3D& v) {
    os << "Vector3D(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}

// Оператор ввода: читает вектор с консоли
std::istream& operator>>(std::istream& is, Vector3D& v) {
    double x, y, z;
    std::cout << "Введите координату X: ";
    if (!(is >> x)) throw std::invalid_argument("Invalid input X");

    std::cout << "Введите координату Y: ";
    if (!(is >> y)) throw std::invalid_argument("Invalid input Y");

    std::cout << "Введите координату Z: ";
    if (!(is >> z)) throw std::invalid_argument("Invalid input Z");

    v = Vector3D(x, y, z); // Присваиваем считанные значения в объект
    return is;
}
