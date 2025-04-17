#include "Vector3D.h"

// ����������� �� ���������
Vector3D::Vector3D() : x(0), y(0), z(0) {}

// ����������� � �������� ���������
Vector3D::Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

// ������� ��� ���������
double Vector3D::getX() const { return x; }
double Vector3D::getY() const { return y; }
double Vector3D::getZ() const { return z; }

// �������� � ���������
Vector3D Vector3D::operator+(const Vector3D& other) const {
    return Vector3D(x + other.x, y + other.y, z + other.z); // �������� ���������
}

Vector3D Vector3D::operator-(const Vector3D& other) const {
    return Vector3D(x - other.x, y - other.y, z - other.z); // ��������� ���������
}

bool Vector3D::operator==(const Vector3D& other) const {
    return x == other.x && y == other.y && z == other.z; // ��������� ��������� �� ���������
}

bool Vector3D::operator!=(const Vector3D& other) const {
    return !(*this == other); // ����������� ����� ����������������� ���������
}

// �������� � ������ (��������)
Vector3D Vector3D::operator*(double scalar) const {
    return Vector3D(x * scalar, y * scalar, z * scalar); // ��������� ������ ���������� �� ������
}

Vector3D Vector3D::operator/(double scalar) const {
    if (scalar == 0) { // �������� �� ������� �� ����
        throw std::invalid_argument("Division by zero");
    }
    return Vector3D(x / scalar, y / scalar, z / scalar); // ������� ������ ���������� �� ������
}

// ��������� ������������
double Vector3D::dot(const Vector3D& other) const {
    return x * other.x + y * other.y + z * other.z; // ��������� ������������
}

// ��������� ������������
Vector3D Vector3D::cross(const Vector3D& other) const {
    return Vector3D(
        y * other.z - z * other.y, // X-���������� ���������� ������������
        z * other.x - x * other.z, // Y-���������� ���������� ������������
        x * other.y - y * other.x  // Z-���������� ���������� ������������
    );
}

// ����� �������
double Vector3D::length() const {
    return std::sqrt(x * x + y * y + z * z); // ������� �������� ��� �����
}

double Vector3D::cos(const Vector3D& other) const {
    return dot(other) / (length() * other.length());
}

// �������� ������
std::ostream& operator<<(std::ostream& os, const Vector3D& v) {
    os << "Vector3D(" << v.x << ", " << v.y << ", " << v.z << ")"; // ��������������� ����� �������
    return os;
}

// �������� �����
std::istream& operator>>(std::istream& is, Vector3D& v) {
    double x, y, z;
    std::cout << "������� ���������� X: ";
    is >> x; // ���� X

    std::cout << "������� ���������� Y: ";
    is >> y; // ���� Y

    std::cout << "������� ���������� Z: ";
    is >> z; // ���� Z

    v = Vector3D(x, y, z); // �������� ������ ������� � ��������� ������������
    return is;
}