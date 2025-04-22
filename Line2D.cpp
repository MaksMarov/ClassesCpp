#include "Line2D.h"
#include <cmath>
#include <stdexcept>

// ����������� �� ���� ������
Line2D::Line2D() : p1(Point2D()), p2(Point2D()) {
    calculateFromPoints();
}

// ����������� �� ���� ������
Line2D::Line2D(const Point2D& a, const Point2D& b) : p1(a), p2(b) {
    calculateFromPoints();
}

// ����������� �� ����� � �����������
Line2D::Line2D(const Point2D& origin, const Vector2D& normal) : normal(normal) {
    C = -(normal.getX() * origin.getX() + normal.getY() * origin.getY());
    calculatePointsFromEquation();
}

// ����������� �� ������� � ���������� �����
Line2D::Line2D(const Vector2D& normal, double C) : normal(normal), C(C) {
    calculatePointsFromEquation();
}

// ����� ��� ���������� ������� � C �� ���� ������
void Line2D::calculateFromPoints() {
    Vector2D dir(p2.getX() - p1.getX(), p2.getY() - p1.getY());
    normal = Vector2D(-dir.getY(), dir.getX());  // ���������������� ������
    C = -(normal.getX() * p1.getX() + normal.getY() * p1.getY());
}

// ����� ��� ���������� ����� ����������� � �����
void Line2D::calculatePointsFromEquation() {
    // ����������� � ���� X: y = 0, ����������� � ��������� ������
    if (normal.getY() != 0) {
        p1 = Point2D(-C / normal.getX(), 0);
    }
    else {
        p1 = Point2D(0, 0);  // ������ �����������
    }

    // ����������� � ���� Y: x = 0, ����������� � ��������� ������
    if (normal.getX() != 0) {
        p2 = Point2D(0, -C / normal.getY());
    }
    else {
        p2 = Point2D(0, 0);  // ������ �������������
    }
}

// ����� ��� ���������� ���������� �� ����� �� ������
double Line2D::distanceToPoint(const Point2D& pt) const {
    return std::abs(normal.getX() * pt.getX() + normal.getY() * pt.getY() + C) / normal.length();
}

// ����� ��� ������������� �������� ������ �� �������� ���������� � ����������� �������
void Line2D::translate(const Vector2D& direction) {
    // �������� ����������� �� �������
    double proj = normal.dot(direction) / (normal.length() * normal.length());

    // ������������� C � ������ ��������
    C += proj;

    //������������� ����� �� ������
    calculatePointsFromEquation();
}

// ����� ��� �������� ������ �� �������� ����
void Line2D::rotate(double angleDegrees) {
    normal = normal.rotate(angleDegrees);

    double angleRad = angleDegrees * 3.1415 / 180.0;
    double cosAngle = cos(angleRad);
    double sinAngle = sin(angleRad);

    // ������� ����� p1
    double newP1X = p1.getX() * cosAngle - p1.getY() * sinAngle;
    double newP1Y = p1.getX() * sinAngle + p1.getY() * cosAngle;
    p1 = Point2D(newP1X, newP1Y);

    // ������������� C ��� ����� ����������
    C = -(normal.getX() * p1.getX() + normal.getY() * p1.getY());
}

// ����� ��� ���������� ���� ����� ����� �������
double Line2D::angleBetween(const Line2D& other) const {
    return acos(normal.cos(other.normal)) * 180.0 / 3.1415;// ���� � ��������
}

// ���������� ��������� ������
std::ostream& operator<<(std::ostream& os, const Line2D& line) {
    os << "������: " << line.normal.getX() << "x + " << line.normal.getY() << "y + " << line.C;
    return os;
}

// ���������� ��������� �����
std::istream& operator>>(std::istream& is, Line2D& line) {
    double nx, ny, c;
    is >> nx >> ny >> c;
    line.normal = Vector2D(nx, ny);
    line.C = c;
    line.calculatePointsFromEquation();

    return is;
}