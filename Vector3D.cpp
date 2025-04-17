#include "Vector3D.h"

// Конструктор по умолчанию
Vector3D::Vector3D() : x(0), y(0), z(0) {}

// Конструктор с заданием координат
Vector3D::Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

// Геттеры для координат
double Vector3D::getX() const { return x; }
double Vector3D::getY() const { return y; }
double Vector3D::getZ() const { return z; }

// Операции с векторами
Vector3D Vector3D::operator+(const Vector3D& other) const {
    return Vector3D(x + other.x, y + other.y, z + other.z); // Сложение координат
}

Vector3D Vector3D::operator-(const Vector3D& other) const {
    return Vector3D(x - other.x, y - other.y, z - other.z); // Вычитание координат
}

bool Vector3D::operator==(const Vector3D& other) const {
    return x == other.x && y == other.y && z == other.z; // Сравнение координат на равенство
}

bool Vector3D::operator!=(const Vector3D& other) const {
    return !(*this == other); // Неравенство через противоположность равенства
}

// Операции с числом (скаляром)
Vector3D Vector3D::operator*(double scalar) const {
    return Vector3D(x * scalar, y * scalar, z * scalar); // Умножение каждой координаты на скаляр
}

Vector3D Vector3D::operator/(double scalar) const {
    if (scalar == 0) { // Проверка на деление на ноль
        throw std::invalid_argument("Division by zero");
    }
    return Vector3D(x / scalar, y / scalar, z / scalar); // Деление каждой координаты на скаляр
}

// Скалярное произведение
double Vector3D::dot(const Vector3D& other) const {
    return x * other.x + y * other.y + z * other.z; // Скалярное произведение
}

// Векторное произведение
Vector3D Vector3D::cross(const Vector3D& other) const {
    return Vector3D(
        y * other.z - z * other.y, // X-компонента векторного произведения
        z * other.x - x * other.z, // Y-компонента векторного произведения
        x * other.y - y * other.x  // Z-компонента векторного произведения
    );
}

// Длина вектора
double Vector3D::length() const {
    return std::sqrt(x * x + y * y + z * z); // Теорема Пифагора для длины
}

double Vector3D::cos(const Vector3D& other) const {
    return dot(other) / (length() * other.length());
}

// Оператор вывода
std::ostream& operator<<(std::ostream& os, const Vector3D& v) {
    os << "Vector3D(" << v.x << ", " << v.y << ", " << v.z << ")"; // Форматированный вывод вектора
    return os;
}

// Оператор ввода
std::istream& operator>>(std::istream& is, Vector3D& v) {
    double x, y, z;
    std::cout << "Введите координату X: ";
    is >> x; // Ввод X

    std::cout << "Введите координату Y: ";
    is >> y; // Ввод Y

    std::cout << "Введите координату Z: ";
    is >> z; // Ввод Z

    v = Vector3D(x, y, z); // Создание нового вектора с введёнными координатами
    return is;
}