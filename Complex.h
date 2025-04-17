#pragma once
#include <iostream>
#include <cmath>
#include <string>

class Complex {
private:
    double real; // �������������� �����
    double imag; // ������ �����

public:
    // ������������
    Complex();  // ����������� �� ��������� (���� = 0, ���� = 0)
    Complex(double real, double imag = 0.0); // ����������� � �����������
    Complex(const Complex& other); // ����������� �����������

    // ��������� � ��������� �������� �����
    double getReal() const; // ��������� �������������� �����
    double getImag() const; // ��������� ������ �����
    void setReal(double r); // ��������� �������������� �����
    void setImag(double i); // ��������� ������ �����

    // �������������� �������� � ������������ �������
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;

    // �������������� �������� � ������������� �������
    Complex operator+(double val) const;
    Complex operator-(double val) const;
    Complex operator*(double val) const;
    Complex operator/(double val) const;

    // �������� ��� ������������ �������
    Complex operator-() const; // ����� �����

    // �������� ������������
    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex& operator*=(const Complex& other);
    Complex& operator/=(const Complex& other);

    // ���������
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;

    // �������������� ������
    double abs() const;       // ������
    double arg() const;       // ��������
    Complex conjugate() const; // ���������� �����

    // �������� �����/������
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);
};
