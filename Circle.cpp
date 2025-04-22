#include "Circle.h"
#include <cmath>

// ����������� �� ���������
Circle::Circle() : Point2D(0.0, 0.0), radius(1.0) {}

// ����������� � ������������ � ��������
Circle::Circle(double x, double y, double radius) : Point2D(x, y), radius(radius) {
    if (radius < 0) {
        throw std::invalid_argument("������ �� ����� ���� �������������");
    }
}

// ����������� �� �����
Circle::Circle(const Point2D& center, double radius) : Point2D(center), radius(radius) {
    if (radius < 0) {
        throw std::invalid_argument("������ �� ����� ���� �������������");
    }
}

// ������ � ������
double Circle::getRadius() const {
    return radius;
}

void Circle::setRadius(double radius) {
    if (radius < 0) {
        throw std::invalid_argument("������ �� ����� ���� �������������");
    }
    this->radius = radius;
}

// ������� �����
double Circle::area() const {
    return 3.1415 * radius * radius;
}

// �������� (����� ����������)
double Circle::perimeter() const {
    return 2 * 3.1415 * radius;
}

// �������� ��������� ����� � ����������
bool Circle::containsPoint(const Point2D& point) const {
    return distanceTo(point) <= radius;
}

// �������� ����������� ������ ����������
bool Circle::containsCircle(const Circle& other) const {
    double centerDistance = distanceTo(other);
    return centerDistance + other.radius <= radius;
}

// �������� ����������� ���� �����������
bool Circle::intersects(const Circle& other) const {
    double centerDistance = distanceTo(other);
    return centerDistance < (radius + other.radius) &&
        centerDistance > std::abs(radius - other.radius);
}

// ���������� ��������� ������
std::ostream& operator<<(std::ostream& os, const Circle& circle) {
    os << "�����: (" << circle.getX() << ", " << circle.getY() << "), ������: " << circle.radius;
    return os;
}

// ���������� ��������� �����
std::istream& operator>>(std::istream& is, Circle& circle) {
    double x, y, r;
    std::cout << "������� ���������� ������ (x y): ";
    is >> x >> y;
    std::cout << "������� ������: ";
    is >> r;
    if (r < 0) {
        throw std::invalid_argument("������ �� ����� ���� �������������");
    }
    circle.setX(x);
    circle.setY(y);
    circle.setRadius(r);
    return is;
}
