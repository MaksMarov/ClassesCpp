#pragma once

#include <iostream>
#include <cmath>
#include <stdexcept>

class Vector3D {
private:
    double x, y, z; // ���������� �������

public:
    // ������������
    Vector3D(); // ����������� �� ��������� (������������� ������)
    Vector3D(double x, double y, double z); // ����������� � �������� ���������

    // ������� ��� ���������
    double getX() const; // �������� ���������� X
    double getY() const; // �������� ���������� Y
    double getZ() const; // �������� ���������� Z

    // �������� � ���������
    Vector3D operator+(const Vector3D& other) const; // �������� ��������
    Vector3D operator-(const Vector3D& other) const; // ��������� ��������
    bool operator==(const Vector3D& other) const; // �������� �� ���������
    bool operator!=(const Vector3D& other) const; // �������� �� �����������

    // �������� � ������ (��������)
    Vector3D operator*(double scalar) const; // ��������� ������� �� ������
    Vector3D operator/(double scalar) const; // ������� ������� �� ������

    // ��������� ������������
    double dot(const Vector3D& other) const; // ��������� ������������ ���� ��������

    // ��������� ������������
    Vector3D cross(const Vector3D& other) const; // ��������� ������������ ���� ��������

    // ����� �������
    double length() const; // ���������� ����� �������

    // ���������� ���������� ������/�����
    friend std::ostream& operator<<(std::ostream& os, const Vector3D& v); // �������� ������
    friend std::istream& operator>>(std::istream& is, Vector3D& v); // �������� �����
};