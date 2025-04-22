#pragma once
#include "Vector3D.h"

class Plane3D {
private:
    Vector3D normal; // ������� � ���������
    double D;        // ��������� ���� (Ax + By + Cz + D = 0)

public:
    Plane3D(); // ��������� �� ��������� (�������)
    Plane3D(const Vector3D& normal, double D); // �� ������� � ��������
    Plane3D(const Vector3D& normal, const Vector3D& point); // �� ������� � ����� �� ���������

    bool intersectsWith(const Plane3D& other) const; // �������� �����������
    double angleWith(const Plane3D& other) const;    // ���� ����� �����������

    // �������
    Vector3D getNormal() const;
    double getD() const;

    friend std::ostream& operator<<(std::ostream& os, const Plane3D& plane);
    friend std::istream& operator>>(std::istream& is, Plane3D& plane);
};