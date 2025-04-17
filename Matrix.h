#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>

class Matrix {
private:
    std::vector<std::vector<double>> data;  // ������ ������� (��������� ������)
    int rows, cols;  // ���������� ����� � �������� � �������

    // ��������������� ����� ��� ���������� ������������
    double determinantRecursive(const std::vector<std::vector<double>>& mat) const;
    std::vector<std::vector<double>> getMinor(int row, int col) const;

public:
    // ������������
    Matrix(int rows, int cols);  // ����������� � ��������� �������� �������
    Matrix(const std::vector<std::vector<double>>& values);  // ����������� � �������� ������ �������

    // ���������
    Matrix operator+(const Matrix& other) const;  // �������� ��������
    Matrix operator-(const Matrix& other) const;  // �������� ���������
    Matrix operator*(const Matrix& other) const;  // �������� ��������� � ������ ��������
    Matrix operator*(double scalar) const;  // �������� ��������� �� ������
    Matrix operator/(double scalar) const;  // �������� ������� �� ������

    Matrix& operator+=(const Matrix& other);  // �������� +=
    Matrix& operator-=(const Matrix& other);  // �������� -=
    Matrix& operator*=(double scalar);  // �������� *=

    bool operator==(const Matrix& other) const;  // �������� ��������� �� ���������
    bool operator!=(const Matrix& other) const;  // �������� ��������� �� �����������

    // �������� ������� �������
    bool isSquare() const;  // ��������, �������� �� ������� ����������
    bool isDiagonal() const;  // ��������, �������� �� ������� ������������
    bool isIdentity() const;  // ��������, �������� �� ������� ���������
    bool isZero() const;  // ��������, �������� �� ������� �������
    bool isSymmetric() const;  // ��������, �������� �� ������� ������������
    bool isUpperTriangular() const;  // ��������, �������� �� ������� �����������������
    bool isLowerTriangular() const;  // ��������, �������� �� ������� ����������������

    // �������������� ������
    double determinant() const;  // ���������� ������������ �������
    Matrix transpose() const;  // ���������������� �������
    Matrix adjugate() const;  // �������������� ����������
    Matrix inverse() const;  // �������� �������

    // ���������� ��������� ���������� ��� ������ � �����
    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
    friend std::istream& operator>>(std::istream& is, Matrix& m);
};