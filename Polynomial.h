#pragma once

#include <vector>
#include <iostream>
#include <initializer_list>
#include <stdexcept>

class Polynomial {
private:
    std::vector<double> coefficients; // �������� ������������� ��������

    void trim(); // ������� ������ ���� ������ � ������� �������������

public:
    // ������������
    Polynomial(); // ������� �������
    Polynomial(int degree); // ������� �������� �������, ������������ = 0
    Polynomial(int degree, double value); // ������� �������� �������, ��� ������������ = value
    Polynomial(double scalar); // ����������� ������� (��������, 5)
    Polynomial(const std::vector<double>& coeffs); // ������� �� ������� �������������
    Polynomial(std::initializer_list<double> list); // ������� �� ������ �������������

    // ������
    int degree() const; // ���������� ������� ��������
    double evaluate(double x) const; // ���������� �������� �������� � ����� x
    Polynomial derivative() const; // ���������� ����������� ��������
    Polynomial integrate() const; // ���������� ������������� �������� ��������

    Polynomial divide(const Polynomial& divisor) const; // ������� ���������
    Polynomial mod(const Polynomial& divisor) const; // ������� �� ������� ���������

    // �������������� ���������
    Polynomial operator+(const Polynomial& other) const; // �������� ��������
    Polynomial operator-(const Polynomial& other) const; // �������� ���������
    Polynomial operator*(const Polynomial& other) const; // �������� ���������

    Polynomial& operator+=(const Polynomial& other); // �������� ����������
    Polynomial& operator-=(const Polynomial& other); // �������� ���������
    Polynomial& operator*=(const Polynomial& other); // �������� ���������

    bool operator==(const Polynomial& other) const; // �������� ��������� �� ���������
    bool operator!=(const Polynomial& other) const; // �������� ��������� �� �����������

    // �������������� � ������
    explicit operator double() const; // �������������� � ������

    // ����/�����
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& poly); // �������� ������
    friend std::istream& operator>>(std::istream& is, Polynomial& poly); // �������� �����
};
