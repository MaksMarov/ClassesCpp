#include "Plane3D.h"
#include <cmath>

// ����������� �� ���������
Plane3D::Plane3D() : normal(Vector3D(0, 0, 1)), D(0) {}

// ����������� �� ������� � ���������� �����
Plane3D::Plane3D(const Vector3D& normal, double D) : normal(normal), D(D) {}

// ����������� �� ������� � ����� �� ���������
Plane3D::Plane3D(const Vector3D& normal, const Vector3D& point)
    : normal(normal) {
    // ��������� ���������� ����� � ��������� ���������
    D = -(normal.getX() * point.getX() + normal.getY() * point.getY() + normal.getZ() * point.getZ());
}

// �������� ����������� ���� ����������
bool Plane3D::intersectsWith(const Plane3D& other) const {
    // ��������� �����������, ���� ������� ����������� (��������� ������������ �������)
    Vector3D cross = normal.cross(other.normal);
    return cross.length() != 0;
}

// ���� ����� ����������� = ���� ����� ���������
double Plane3D::angleWith(const Plane3D& other) const {
    double cosTheta = normal.cos(other.normal);
    return acos(cosTheta) * 180.0 / 3.1415;
}

// �������
Vector3D Plane3D::getNormal() const { return normal; }
double Plane3D::getD() const { return D; }

std::ostream& operator<<(std::ostream& os, const Plane3D& plane) {
    Vector3D n = plane.getNormal();
    os << "���������: "
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
