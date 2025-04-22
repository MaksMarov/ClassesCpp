#pragma once
#include "Vector3D.h"

class Plane3D {
private:
    Vector3D normal; // нормаль к плоскости
    double D;        // свободный член (Ax + By + Cz + D = 0)

public:
    Plane3D(); // плоскость по умолчанию (нулевая)
    Plane3D(const Vector3D& normal, double D); // по нормали и смещению
    Plane3D(const Vector3D& normal, const Vector3D& point); // по нормали и точке на плоскости

    bool intersectsWith(const Plane3D& other) const; // проверка пересечения
    double angleWith(const Plane3D& other) const;    // угол между плоскостями

    // Геттеры
    Vector3D getNormal() const;
    double getD() const;

    friend std::ostream& operator<<(std::ostream& os, const Plane3D& plane);
    friend std::istream& operator>>(std::istream& is, Plane3D& plane);
};