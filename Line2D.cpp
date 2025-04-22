#include "Line2D.h"
#include <cmath>
#include <stdexcept>

// Конструктор по двум точкам
Line2D::Line2D() : p1(Point2D()), p2(Point2D()) {
    calculateFromPoints();
}

// Конструктор по двум точкам
Line2D::Line2D(const Point2D& a, const Point2D& b) : p1(a), p2(b) {
    calculateFromPoints();
}

// Конструктор по точке и направлению
Line2D::Line2D(const Point2D& origin, const Vector2D& normal) : normal(normal) {
    C = -(normal.getX() * origin.getX() + normal.getY() * origin.getY());
    calculatePointsFromEquation();
}

// Конструктор по нормали и свободному члену
Line2D::Line2D(const Vector2D& normal, double C) : normal(normal), C(C) {
    calculatePointsFromEquation();
}

// Метод для вычисления нормали и C по двум точкам
void Line2D::calculateFromPoints() {
    Vector2D dir(p2.getX() - p1.getX(), p2.getY() - p1.getY());
    normal = Vector2D(-dir.getY(), dir.getX());  // Перпендикулярный вектор
    C = -(normal.getX() * p1.getX() + normal.getY() * p1.getY());
}

// Метод для вычисления точек пересечения с осями
void Line2D::calculatePointsFromEquation() {
    // Пересечение с осью X: y = 0, подставляем в уравнение прямой
    if (normal.getY() != 0) {
        p1 = Point2D(-C / normal.getX(), 0);
    }
    else {
        p1 = Point2D(0, 0);  // Прямая вертикальна
    }

    // Пересечение с осью Y: x = 0, подставляем в уравнение прямой
    if (normal.getX() != 0) {
        p2 = Point2D(0, -C / normal.getY());
    }
    else {
        p2 = Point2D(0, 0);  // Прямая горизонтальна
    }
}

// Метод для вычисления расстояния от точки до прямой
double Line2D::distanceToPoint(const Point2D& pt) const {
    return std::abs(normal.getX() * pt.getX() + normal.getY() * pt.getY() + C) / normal.length();
}

// Метод для параллельного переноса прямой на заданное расстояние в направлении вектора
void Line2D::translate(const Vector2D& direction) {
    // Проекция направления на нормаль
    double proj = normal.dot(direction) / (normal.length() * normal.length());

    // Пересчитываем C с учетом проекции
    C += proj;

    //пересчитываем точки на прямой
    calculatePointsFromEquation();
}

// Метод для поворота прямой на заданный угол
void Line2D::rotate(double angleDegrees) {
    normal = normal.rotate(angleDegrees);

    double angleRad = angleDegrees * 3.1415 / 180.0;
    double cosAngle = cos(angleRad);
    double sinAngle = sin(angleRad);

    // Поворот точки p1
    double newP1X = p1.getX() * cosAngle - p1.getY() * sinAngle;
    double newP1Y = p1.getX() * sinAngle + p1.getY() * cosAngle;
    p1 = Point2D(newP1X, newP1Y);

    // Пересчитываем C для новой ориентации
    C = -(normal.getX() * p1.getX() + normal.getY() * p1.getY());
}

// Метод для нахождения угла между двумя прямыми
double Line2D::angleBetween(const Line2D& other) const {
    return acos(normal.cos(other.normal)) * 180.0 / 3.1415;// угол в градусах
}

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& os, const Line2D& line) {
    os << "Прямая: " << line.normal.getX() << "x + " << line.normal.getY() << "y + " << line.C;
    return os;
}

// Перегрузка оператора ввода
std::istream& operator>>(std::istream& is, Line2D& line) {
    double nx, ny, c;
    is >> nx >> ny >> c;
    line.normal = Vector2D(nx, ny);
    line.C = c;
    line.calculatePointsFromEquation();

    return is;
}