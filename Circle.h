#pragma once

#include "Point2D.h"
#include <iostream>

class Circle : public Point2D {
private:
    double radius;

public:
    // Конструкторы
    Circle();
    Circle(double x, double y, double radius);
    Circle(const Point2D& center, double radius);

    // Геттер и сеттер
    double getRadius() const;
    void setRadius(double radius);

    // Методы
    double area() const;
    double perimeter() const;

    bool containsPoint(const Point2D& point) const;
    bool containsCircle(const Circle& other) const;
    bool intersects(const Circle& other) const;

    // Перегрузка операторов
    friend std::ostream& operator<<(std::ostream& os, const Circle& circle);
    friend std::istream& operator>>(std::istream& is, Circle& circle);
};