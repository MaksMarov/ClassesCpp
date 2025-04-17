#include "Triangle.h"
#include <algorithm>

constexpr double EPSILON = 1e-9; // Точность для сравнений с плавающей точкой

// Конструктор по умолчанию, создаёт треугольник с заданными вершинами
Triangle::Triangle() {
    vertices = { { {0, 0}, {1, 0}, {0, 1} } }; // Создаём треугольник с вершинами в (0,0), (1,0), (0,1)
}

// Конструктор с параметрами, задающими три вершины треугольника
Triangle::Triangle(const std::pair<double, double>& p1,
    const std::pair<double, double>& p2,
    const std::pair<double, double>& p3) {
    vertices = { p1, p2, p3 };
}

// Метод для получения вершины по индексу
std::pair<double, double> Triangle::getVertex(int index) const {
    if (index < 0 || index > 2) throw std::out_of_range("Vertex index out of range.");
    return vertices[index];
}

// Метод для получения всех трёх вершин
std::array<std::pair<double, double>, 3> Triangle::getVertices() const {
    return vertices;
}

// Вспомогательный метод для вычисления расстояния между двумя точками
double Triangle::distance(const std::pair<double, double>& a, const std::pair<double, double>& b) const {
    return std::hypot(b.first - a.first, b.second - a.second); // Используется std::hypot для вычисления гипотенузы
}

// Метод для вычисления площади треугольника по формуле Герона
double Triangle::areaHeron(double a, double b, double c) const {
    double s = (a + b + c) / 2;  // Полупериметр
    return std::sqrt(std::max(s * (s - a) * (s - b) * (s - c), 0.0)); // Геронова формула
}

// Метод для вычисления периметра треугольника
double Triangle::perimeter() const {
    return distance(vertices[0], vertices[1]) +
        distance(vertices[1], vertices[2]) +
        distance(vertices[2], vertices[0]);
}

// Метод для вычисления площади треугольника
double Triangle::area() const {
    return std::abs(
        (vertices[0].first * (vertices[1].second - vertices[2].second) +
            vertices[1].first * (vertices[2].second - vertices[0].second) +
            vertices[2].first * (vertices[0].second - vertices[1].second)) / 2.0
    );
}

// Проверка на равносторонний треугольник
bool Triangle::isEquilateral() const {
    double a = distance(vertices[0], vertices[1]);
    double b = distance(vertices[1], vertices[2]);
    double c = distance(vertices[2], vertices[0]);
    return std::abs(a - b) < EPSILON && std::abs(b - c) < EPSILON;
}

// Проверка на равнобедренный треугольник
bool Triangle::isIsosceles() const {
    double a = distance(vertices[0], vertices[1]);
    double b = distance(vertices[1], vertices[2]);
    double c = distance(vertices[2], vertices[0]);
    return std::abs(a - b) < EPSILON || std::abs(b - c) < EPSILON || std::abs(c - a) < EPSILON;
}

// Проверка на прямоугольный треугольник
bool Triangle::isRight() const {
    double a2 = std::pow(distance(vertices[0], vertices[1]), 2);
    double b2 = std::pow(distance(vertices[1], vertices[2]), 2);
    double c2 = std::pow(distance(vertices[2], vertices[0]), 2);
    return std::abs(a2 + b2 - c2) < EPSILON ||
        std::abs(b2 + c2 - a2) < EPSILON ||
        std::abs(c2 + a2 - b2) < EPSILON;
}

// Оператор равенства: два треугольника считаются равными, если их площади равны
bool Triangle::operator==(const Triangle& other) const {
    return std::abs(this->area() - other.area()) < EPSILON;
}

// Проверка на подобие треугольников: если стороны пропорциональны
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

    double ratio = thisSides[0] / otherSides[0];
    for (int i = 1; i < 3; ++i) {
        if (std::abs(thisSides[i] / otherSides[i] - ratio) > EPSILON) {
            return false;
        }
    }
    return true;
}

// Проверка, содержит ли треугольник точку
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

// Проверка, содержит ли треугольник другой треугольник (по методу containsPoint)
bool Triangle::containsTriangle(const Triangle& other) const {
    for (const auto& v : other.getVertices()) {
        if (!containsPoint(v)) {
            return false;
        }
    }
    return true;
}

// Сдвиг треугольника
void Triangle::translate(double dx, double dy) {
    for (auto& vertex : vertices) {
        vertex.first += dx;
        vertex.second += dy;
    }
}

// Поворот треугольника относительно центра
void Triangle::rotate(double angleDegrees, const std::pair<double, double>& center) {
    double angleRadians = angleDegrees * 3.1415 / 180.0;
    for (auto& vertex : vertices) {
        double xNew = center.first + (vertex.first - center.first) * cos(angleRadians) - (vertex.second - center.second) * sin(angleRadians);
        double yNew = center.second + (vertex.first - center.first) * sin(angleRadians) + (vertex.second - center.second) * cos(angleRadians);
        vertex.first = xNew;
        vertex.second = yNew;
    }
}

// Масштабирование треугольника относительно центра
void Triangle::scale(double factor, const std::pair<double, double>& center) {
    for (auto& vertex : vertices) {
        vertex.first = center.first + factor * (vertex.first - center.first);
        vertex.second = center.second + factor * (vertex.second - center.second);
    }
}

// Оператор вывода: выводит вершины треугольника
std::ostream& operator<<(std::ostream& os, const Triangle& tri) {
    os << "Vertices of Triangle: ";
    for (const auto& vertex : tri.getVertices()) {
        os << "(" << vertex.first << ", " << vertex.second << ") ";
    }
    return os;
}

// Оператор ввода: вводит вершины треугольника
std::istream& operator>>(std::istream& is, Triangle& tri) {
    std::cout << "Enter coordinates of the 3 vertices of the triangle:" << std::endl;
    for (auto& vertex : tri.vertices) {
        std::cout << "Enter x and y: ";
        is >> vertex.first >> vertex.second;
    }
    return is;
}
