#include "Circle.h"
#include <cmath>

// Конструктор по умолчанию
Circle::Circle() : Point2D(0.0, 0.0), radius(1.0) {}

// Конструктор с координатами и радиусом
Circle::Circle(double x, double y, double radius) : Point2D(x, y), radius(radius) {
    if (radius < 0) {
        throw std::invalid_argument("Радиус не может быть отрицательным");
    }
}

// Конструктор из точки
Circle::Circle(const Point2D& center, double radius) : Point2D(center), radius(radius) {
    if (radius < 0) {
        throw std::invalid_argument("Радиус не может быть отрицательным");
    }
}

// Геттер и сеттер
double Circle::getRadius() const {
    return radius;
}

void Circle::setRadius(double radius) {
    if (radius < 0) {
        throw std::invalid_argument("Радиус не может быть отрицательным");
    }
    this->radius = radius;
}

// Площадь круга
double Circle::area() const {
    return 3.1415 * radius * radius;
}

// Периметр (длина окружности)
double Circle::perimeter() const {
    return 2 * 3.1415 * radius;
}

// Проверка попадания точки в окружность
bool Circle::containsPoint(const Point2D& point) const {
    return distanceTo(point) <= radius;
}

// Проверка вложенности другой окружности
bool Circle::containsCircle(const Circle& other) const {
    double centerDistance = distanceTo(other);
    return centerDistance + other.radius <= radius;
}

// Проверка пересечения двух окружностей
bool Circle::intersects(const Circle& other) const {
    double centerDistance = distanceTo(other);
    return centerDistance < (radius + other.radius) &&
        centerDistance > std::abs(radius - other.radius);
}

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& os, const Circle& circle) {
    os << "Центр: (" << circle.getX() << ", " << circle.getY() << "), Радиус: " << circle.radius;
    return os;
}

// Перегрузка оператора ввода
std::istream& operator>>(std::istream& is, Circle& circle) {
    double x, y, r;
    std::cout << "Введите координаты центра (x y): ";
    is >> x >> y;
    std::cout << "Введите радиус: ";
    is >> r;
    if (r < 0) {
        throw std::invalid_argument("Радиус не может быть отрицательным");
    }
    circle.setX(x);
    circle.setY(y);
    circle.setRadius(r);
    return is;
}
