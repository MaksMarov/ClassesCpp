#pragma once

#include <iostream>
#include <cmath>

class Point2D {
private:
    double x;
    double y;

public:
    // Конструкторы
    Point2D();
    Point2D(double x, double y);

    // Геттеры
    double getX() const;
    double getY() const;

    // Сеттеры
    void setX(double x);
    void setY(double y);
    void set(double x, double y);

    // Метод: расстояние до другой точки
    double distanceTo(const Point2D& other) const;

    // Перегрузка потоковых операторов
    friend std::ostream& operator<<(std::ostream& os, const Point2D& point);
    friend std::istream& operator>>(std::istream& is, Point2D& point);
};