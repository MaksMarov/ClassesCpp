#pragma once

#include <iostream>
#include <array>
#include <cmath>

// ����� ��� ������������� ������������
class Triangle {
private:
    // ������ �� 3 ������ (������ ������� � ��� ���� ��������� (x, y))
    std::array<std::pair<double, double>, 3> vertices;

    // ��������������� ������ ��� ������� ���������� � ������� �� ������� ������
    double distance(const std::pair<double, double>& a, const std::pair<double, double>& b) const;
    double areaHeron(double a, double b, double c) const;

public:
    // ������������ ��� ������������
    Triangle(); // ����������� �� ���������, ��������� ����������� � ��������� ���������
    Triangle(const std::pair<double, double>& p1,
        const std::pair<double, double>& p2,
        const std::pair<double, double>& p3);

    // ������� ��� ��������� ������
    std::pair<double, double> getVertex(int index) const;
    std::array<std::pair<double, double>, 3> getVertices() const;

    // ������ ��� ������� ������� ������������
    double perimeter() const;  // �������� ������������
    double area() const;       // ������� ������������
    bool isEquilateral() const; // �������� �� �������������� �����������
    bool isIsosceles() const;  // �������� �� �������������� �����������
    bool isRight() const;      // �������� �� ������������� �����������

    // �������������� ������ ��� ����������� � �������������
    bool operator==(const Triangle& other) const; // �������� �� ��������� �� �������
    bool isSimilarTo(const Triangle& other) const; // �������� �� �������
    bool containsPoint(const std::pair<double, double>& point) const; // ��������, �������� �� ����������� �����
    bool containsTriangle(const Triangle& other) const; // ��������, �������� �� ����������� ������ �����������
    void translate(double dx, double dy); // ����� ������������
    void rotate(double angleDegrees, const std::pair<double, double>& center); // ������� ������������
    void scale(double factor, const std::pair<double, double>& center); // ��������������� ������������

    // ��������� ����� � ������ ��� ������������
    friend std::ostream& operator<<(std::ostream& os, const Triangle& tri);
    friend std::istream& operator>>(std::istream& is, Triangle& tri);
};