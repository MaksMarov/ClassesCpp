#pragma once

#include <iostream>
#include <array>
#include <cmath>

// Класс для представления треугольника
class Triangle {
private:
    // Массив из 3 вершин (каждая вершина — это пара координат (x, y))
    std::array<std::pair<double, double>, 3> vertices;

    // Вспомогательные методы для расчёта расстояния и площади по формуле Герона
    double distance(const std::pair<double, double>& a, const std::pair<double, double>& b) const;
    double areaHeron(double a, double b, double c) const;

public:
    // Конструкторы для треугольника
    Triangle(); // Конструктор по умолчанию, создающий треугольник с заданными вершинами
    Triangle(const std::pair<double, double>& p1,
        const std::pair<double, double>& p2,
        const std::pair<double, double>& p3);

    // Геттеры для получения вершин
    std::pair<double, double> getVertex(int index) const;
    std::array<std::pair<double, double>, 3> getVertices() const;

    // Методы для расчёта свойств треугольника
    double perimeter() const;  // Периметр треугольника
    double area() const;       // Площадь треугольника
    bool isEquilateral() const; // Проверка на равносторонний треугольник
    bool isIsosceles() const;  // Проверка на равнобедренный треугольник
    bool isRight() const;      // Проверка на прямоугольный треугольник

    // Дополнительные методы для манипуляций с треугольником
    bool operator==(const Triangle& other) const; // Проверка на равенство по площади
    bool isSimilarTo(const Triangle& other) const; // Проверка на подобие
    bool containsPoint(const std::pair<double, double>& point) const; // Проверка, содержит ли треугольник точку
    bool containsTriangle(const Triangle& other) const; // Проверка, содержит ли треугольник другой треугольник
    void translate(double dx, double dy); // Сдвиг треугольника
    void rotate(double angleDegrees, const std::pair<double, double>& center); // Поворот треугольника
    void scale(double factor, const std::pair<double, double>& center); // Масштабирование треугольника

    // Операторы ввода и вывода для треугольника
    friend std::ostream& operator<<(std::ostream& os, const Triangle& tri);
    friend std::istream& operator>>(std::istream& is, Triangle& tri);
};