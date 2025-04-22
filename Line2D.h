#pragma once
#include "Point2D.h"
#include "Vector2D.h"
#include <iostream>
#include <cmath>

class Line2D : public Point2D {
private:
    Point2D p1, p2;       // Две точки на прямой
    Vector2D normal;      // Нормаль к прямой (A, B)
    double C;             // Свободный коэффициент уравнения

    void calculateFromPoints();             // Вычислить нормаль и C по точкам
    void calculatePointsFromEquation();     // Найти точки по уравнению

public:
    // Конструкторы
    Line2D();
    Line2D(const Point2D& a, const Point2D& b);               // По двум точкам
    Line2D(const Point2D& origin, const Vector2D& direction); // По точке и направлению
    Line2D(const Vector2D& normal, double C);                 // По нормали и свободному члену

    // Методы
    double distanceToPoint(const Point2D& pt) const;
    void translate(const Vector2D& direction);                     // Параллельный перенос
    void rotate(double angleDegrees);                         // Поворот по часовой стрелке
    double angleBetween(const Line2D& other) const;           // Угол между прямыми

    // Геттеры
    const Point2D& getP1() const { return p1; }
    const Point2D& getP2() const { return p2; }
    const Vector2D& getNormal() const { return normal; }
    double getC() const { return C; }

    // Перегрузка операторов ввода/вывода
    friend std::ostream& operator<<(std::ostream& os, const Line2D& line);
    friend std::istream& operator>>(std::istream& is, Line2D& line);
};
