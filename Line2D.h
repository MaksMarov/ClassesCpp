#pragma once
#include "Point2D.h"
#include "Vector2D.h"
#include <iostream>
#include <cmath>

class Line2D : public Point2D {
private:
    Point2D p1, p2;       // ��� ����� �� ������
    Vector2D normal;      // ������� � ������ (A, B)
    double C;             // ��������� ����������� ���������

    void calculateFromPoints();             // ��������� ������� � C �� ������
    void calculatePointsFromEquation();     // ����� ����� �� ���������

public:
    // ������������
    Line2D();
    Line2D(const Point2D& a, const Point2D& b);               // �� ���� ������
    Line2D(const Point2D& origin, const Vector2D& direction); // �� ����� � �����������
    Line2D(const Vector2D& normal, double C);                 // �� ������� � ���������� �����

    // ������
    double distanceToPoint(const Point2D& pt) const;
    void translate(const Vector2D& direction);                     // ������������ �������
    void rotate(double angleDegrees);                         // ������� �� ������� �������
    double angleBetween(const Line2D& other) const;           // ���� ����� �������

    // �������
    const Point2D& getP1() const { return p1; }
    const Point2D& getP2() const { return p2; }
    const Vector2D& getNormal() const { return normal; }
    double getC() const { return C; }

    // ���������� ���������� �����/������
    friend std::ostream& operator<<(std::ostream& os, const Line2D& line);
    friend std::istream& operator>>(std::istream& is, Line2D& line);
};
