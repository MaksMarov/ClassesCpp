#pragma once

#include <iostream>
#include <cmath>

class Point2D {
private:
    double x;
    double y;

public:
    // ������������
    Point2D();
    Point2D(double x, double y);

    // �������
    double getX() const;
    double getY() const;

    // �������
    void setX(double x);
    void setY(double y);
    void set(double x, double y);

    // �����: ���������� �� ������ �����
    double distanceTo(const Point2D& other) const;

    // ���������� ��������� ����������
    friend std::ostream& operator<<(std::ostream& os, const Point2D& point);
    friend std::istream& operator>>(std::istream& is, Point2D& point);
};