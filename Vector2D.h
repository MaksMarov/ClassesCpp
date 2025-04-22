#pragma once

#include <iostream>
#include <cmath>
#include <stdexcept>

class Vector2D {
private:
    double x, y;

public:
    // ������������
    Vector2D(); // ����������� �� ��������� (������������� ������)
    Vector2D(double x, double y); // ����������� � �������� ���������

    // ������� ��� ���������
    double getX() const; // �������� ���������� X
    double getY() const; // �������� ���������� Y

    // �������� � ���������
    Vector2D operator+(const Vector2D& other) const; // �������� ��������
    Vector2D operator-(const Vector2D& other) const; // ��������� ��������
    bool operator==(const Vector2D& other) const; // �������� �� ���������
    bool operator!=(const Vector2D& other) const; // �������� �� �����������

    // �������� � ������ (��������)
    Vector2D operator*(double scalar) const; // ��������� ������� �� ������
    Vector2D operator/(double scalar) const; // ������� ������� �� ������

    // ��������� ������������
    double dot(const Vector2D& other) const; // ��������� ������������ ���� ��������

    // ����� �������
    double length() const; // ���������� ����� �������

    double cos(const Vector2D& other) const; //������� ���� ����� ���������

    // ����� �������� ������� �� ����
    Vector2D rotate(double angle) const;  // ������� ������� �� ���� � ��������

    // ���������� ���������� ������/�����
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& v); // �������� ������
    friend std::istream& operator>>(std::istream& is, Vector2D& v); // �������� �����
};



