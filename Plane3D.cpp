#include "Plane3D.h"
#include <cmath>

// Конструктор по умолчанию
Plane3D::Plane3D() : normal(Vector3D(0, 0, 1)), D(0) {}

// Конструктор по нормали и свободному члену
Plane3D::Plane3D(const Vector3D& normal, double D) : normal(normal), D(D) {}

// Конструктор по нормали и точке на плоскости
Plane3D::Plane3D(const Vector3D& normal, const Vector3D& point)
    : normal(normal) {
    // Подставим координаты точки в уравнение плоскости
    D = -(normal.getX() * point.getX() + normal.getY() * point.getY() + normal.getZ() * point.getZ());
}

// Проверка пересечения двух плоскостей
bool Plane3D::intersectsWith(const Plane3D& other) const {
    // Плоскости параллельны, если нормали коллинеарны (векторное произведение нулевое)
    Vector3D cross = normal.cross(other.normal);
    return cross.length() != 0;
}

// Угол между плоскостями = угол между нормалями
double Plane3D::angleWith(const Plane3D& other) const {
    double cosTheta = normal.cos(other.normal);
    return acos(cosTheta) * 180.0 / 3.1415;
}

// Геттеры
Vector3D Plane3D::getNormal() const { return normal; }
double Plane3D::getD() const { return D; }

std::ostream& operator<<(std::ostream& os, const Plane3D& plane) {
    Vector3D n = plane.getNormal();
    os << "Плоскость: "
        << n.getX() << "x + "
        << n.getY() << "y + "
        << n.getZ() << "z + "
        << plane.getD() << " = 0";
    return os;
}

std::istream& operator>>(std::istream& is, Plane3D& plane) {
    double a, b, c, d;
    is >> a >> b >> c >> d;
    plane = Plane3D(Vector3D(a, b, c), d);
    return is;
}
