#include "Point2D.h"

// Конструктор по умолчанию
Point2D::Point2D() : x(0), y(0) {}

// Конструктор с параметрами
Point2D::Point2D(double x, double y) : x(x), y(y) {}

// Геттеры
double Point2D::getX() const {
    return x;
}

double Point2D::getY() const {
    return y;
}

// Сеттеры
void Point2D::setX(double x) {
    this->x = x;
}

void Point2D::setY(double y) {
    this->y = y;
}

void Point2D::set(double x, double y) {
    this->x = x;
    this->y = y;
}

// Расстояние между двумя точками
double Point2D::distanceTo(const Point2D& other) const {
    double dx = x - other.x;
    double dy = y - other.y;
    return std::sqrt(dx * dx + dy * dy);
}

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& os, const Point2D& point) {
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}

// Перегрузка оператора ввода
std::istream& operator>>(std::istream& is, Point2D& point) {
    is >> point.x >> point.y;
    return is;
}