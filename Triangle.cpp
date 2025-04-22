#include "Triangle.h"
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <iostream>
#include <vector>

constexpr double EPSILON = 1e-9; // �������� ��� ��������� � ��������� ������

// ========================= ������������ =========================

// ����������� �� ���������: ������ ����������� � ��������� (0,0), (1,0), (0,1)
Triangle::Triangle() {
    vertices = { { {0, 0}, {1, 0}, {0, 1} } };
}

// ����������� � �����������, ��������� ��� ������� ������������
Triangle::Triangle(const std::pair<double, double>& p1,
    const std::pair<double, double>& p2,
    const std::pair<double, double>& p3) {
    if (p1 == p2 || p2 == p3 || p3 == p1) {
        throw std::invalid_argument("Vertices must be distinct points.");
    }
    vertices = { p1, p2, p3 };
}

// ========================= ������� =========================

// �������� ������� �� ������� (0, 1 ��� 2)
std::pair<double, double> Triangle::getVertex(int index) const {
    if (index < 0 || index > 2) throw std::out_of_range("Vertex index out of range.");
    return vertices[index];
}

// �������� ��� ������� ������������
std::array<std::pair<double, double>, 3> Triangle::getVertices() const {
    return vertices;
}

// ========================= ��������������� ������ =========================

// ���������� ����� ����� �������
double Triangle::distance(const std::pair<double, double>& a, const std::pair<double, double>& b) const {
    return std::hypot(b.first - a.first, b.second - a.second);
}

// ������� �� ������� ������ (������������ ��� ������������)
double Triangle::areaHeron(double a, double b, double c) const {
    double s = (a + b + c) / 2;  // ������������
    return std::sqrt(std::max(s * (s - a) * (s - b) * (s - c), 0.0));
}

// ========================= �������������� �������� =========================

// �������� ������������
double Triangle::perimeter() const {
    return distance(vertices[0], vertices[1]) +
        distance(vertices[1], vertices[2]) +
        distance(vertices[2], vertices[0]);
}

// ������� ������������ �� ������� ������� ����� ����������
// �������: 1/2 * |(x1(y2-y3) + x2(y3-y1) + x3(y1-y2))|
double Triangle::area() const {
    return std::abs(
        (vertices[0].first * (vertices[1].second - vertices[2].second) +
            vertices[1].first * (vertices[2].second - vertices[0].second) +
            vertices[2].first * (vertices[0].second - vertices[1].second)) / 2.0
    );
}

// �������� �� �������������� �����������
bool Triangle::isEquilateral() const {
    double a = distance(vertices[0], vertices[1]);
    double b = distance(vertices[1], vertices[2]);
    double c = distance(vertices[2], vertices[0]);
    return std::abs(a - b) < EPSILON && std::abs(b - c) < EPSILON;
}

// �������� �� �������������� �����������
bool Triangle::isIsosceles() const {
    double a = distance(vertices[0], vertices[1]);
    double b = distance(vertices[1], vertices[2]);
    double c = distance(vertices[2], vertices[0]);
    return std::abs(a - b) < EPSILON || std::abs(b - c) < EPSILON || std::abs(c - a) < EPSILON;
}

// �������� �� ������������� ����������� �� ������� ��������
bool Triangle::isRight() const {
    double a2 = std::pow(distance(vertices[0], vertices[1]), 2);
    double b2 = std::pow(distance(vertices[1], vertices[2]), 2);
    double c2 = std::pow(distance(vertices[2], vertices[0]), 2);
    return std::abs(a2 + b2 - c2) < EPSILON ||
        std::abs(b2 + c2 - a2) < EPSILON ||
        std::abs(c2 + a2 - b2) < EPSILON;
}

// �������� ���������: �����, ���� ������� ��������� (� ��������� �� EPSILON)
bool Triangle::operator==(const Triangle& other) const {
    return std::abs(this->area() - other.area()) < EPSILON;
}

// �������� �� �������: ���� ������� ��������������� (����� ����������)
bool Triangle::isSimilarTo(const Triangle& other) const {
    std::array<double, 3> thisSides = {
        distance(vertices[0], vertices[1]),
        distance(vertices[1], vertices[2]),
        distance(vertices[2], vertices[0])
    };

    std::array<double, 3> otherSides = {
        distance(other.vertices[0], other.vertices[1]),
        distance(other.vertices[1], other.vertices[2]),
        distance(other.vertices[2], other.vertices[0])
    };

    std::sort(thisSides.begin(), thisSides.end());
    std::sort(otherSides.begin(), otherSides.end());

    if (std::any_of(otherSides.begin(), otherSides.end(), [](double side) { return side < EPSILON; })) {
        throw std::domain_error("Degenerate triangle in isSimilarTo.");
    }

    double ratio = thisSides[0] / otherSides[0];
    for (int i = 1; i < 3; ++i) {
        if (std::abs(thisSides[i] / otherSides[i] - ratio) > EPSILON) {
            return false;
        }
    }
    return true;
}

// ��������: �������� �� ����������� ����� (����� ������ ��������)
bool Triangle::containsPoint(const std::pair<double, double>& point) const {
    auto sign = [](const std::pair<double, double>& p1,
        const std::pair<double, double>& p2,
        const std::pair<double, double>& p3) {
            return (p1.first - p3.first) * (p2.second - p3.second) -
                (p2.first - p3.first) * (p1.second - p3.second);
        };

    bool b1 = sign(point, vertices[0], vertices[1]) < 0.0;
    bool b2 = sign(point, vertices[1], vertices[2]) < 0.0;
    bool b3 = sign(point, vertices[2], vertices[0]) < 0.0;

    return (b1 == b2) && (b2 == b3);
}

// ��������: �������� �� ����������� ������ �����������
bool Triangle::containsTriangle(const Triangle& other) const {
    for (const auto& v : other.getVertices()) {
        if (!containsPoint(v)) {
            return false;
        }
    }
    return true;
}

// ========================= ������������� =========================

// ����� ������������ �� dx, dy
void Triangle::translate(double dx, double dy) {
    for (auto& vertex : vertices) {
        vertex.first += dx;
        vertex.second += dy;
    }
}

// ������� ������������ ������ ��������� ������ �� �������� ���� (� ��������)
void Triangle::rotate(double angleDegrees, const std::pair<double, double>& center) {
    double angleRadians = angleDegrees * 3.14159265358979323846 / 180.0;
    for (auto& vertex : vertices) {
        double x = vertex.first - center.first;
        double y = vertex.second - center.second;
        double xNew = x * cos(angleRadians) - y * sin(angleRadians);
        double yNew = x * sin(angleRadians) + y * cos(angleRadians);
        vertex.first = center.first + xNew;
        vertex.second = center.second + yNew;
    }
}

// ��������������� ������������ ������������ ��������� ������
void Triangle::scale(double factor, const std::pair<double, double>& center) {
    if (factor == 0.0) {
        throw std::invalid_argument("Scaling factor cannot be zero.");
    }
    for (auto& vertex : vertices) {
        vertex.first = center.first + factor * (vertex.first - center.first);
        vertex.second = center.second + factor * (vertex.second - center.second);
    }
}

// ========================= ��������� �����/������ =========================

std::ostream& operator<<(std::ostream& os, const Triangle& tri) {
    const auto& v = tri.getVertices();
    os << "�����������:\n";
    os << "  A: (" << v[0].first << ", " << v[0].second << ")\n";
    os << "  B: (" << v[1].first << ", " << v[1].second << ")\n";
    os << "  C: (" << v[2].first << ", " << v[2].second << ")\n";
    return os;
}

std::istream& operator>>(std::istream& is, Triangle& tri) {
    std::vector<std::pair<double, double>> tempVertices(3);
    std::cout << "������� ���������� ������ (x,y ��� ������):\n";

    for (int i = 0; i < 3; ++i) {
        std::cout << "  ������� " << static_cast<char>('A' + i) << ": ";
        if (!(is >> tempVertices[i].first >> tempVertices[i].second)) {
            throw std::runtime_error("Invalid input: expected two numeric values per vertex.");
        }
    }

    tri = Triangle(tempVertices[0], tempVertices[1], tempVertices[2]);  // ���������� ���������� ����������� (����� ���� ������� ����������)
    return is;
}