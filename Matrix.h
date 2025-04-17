#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>

class Matrix {
private:
    std::vector<std::vector<double>> data;  // Данные матрицы (двумерный вектор)
    int rows, cols;  // Количество строк и столбцов в матрице

    // Вспомогательные метод для вычисления определителя
    double determinantRecursive(const std::vector<std::vector<double>>& mat) const;
    std::vector<std::vector<double>> getMinor(int row, int col) const;

public:
    // Конструкторы
    Matrix(int rows, int cols);  // Конструктор с указанием размеров матрицы
    Matrix(const std::vector<std::vector<double>>& values);  // Конструктор с заданием данных матрицы

    // Операторы
    Matrix operator+(const Matrix& other) const;  // Оператор сложения
    Matrix operator-(const Matrix& other) const;  // Оператор вычитания
    Matrix operator*(const Matrix& other) const;  // Оператор умножения с другой матрицей
    Matrix operator*(double scalar) const;  // Оператор умножения на скаляр
    Matrix operator/(double scalar) const;  // Оператор деления на скаляр

    Matrix& operator+=(const Matrix& other);  // Оператор +=
    Matrix& operator-=(const Matrix& other);  // Оператор -=
    Matrix& operator*=(double scalar);  // Оператор *=

    bool operator==(const Matrix& other) const;  // Оператор сравнения на равенство
    bool operator!=(const Matrix& other) const;  // Оператор сравнения на неравенство

    // Проверки свойств матрицы
    bool isSquare() const;  // Проверка, является ли матрица квадратной
    bool isDiagonal() const;  // Проверка, является ли матрица диагональной
    bool isIdentity() const;  // Проверка, является ли матрица единичной
    bool isZero() const;  // Проверка, является ли матрица нулевой
    bool isSymmetric() const;  // Проверка, является ли матрица симметричной
    bool isUpperTriangular() const;  // Проверка, является ли матрица верхнетреугольной
    bool isLowerTriangular() const;  // Проверка, является ли матрица нижнетреугольной

    // Функциональные методы
    double determinant() const;  // Вычисление определителя матрицы
    Matrix transpose() const;  // Транспонирование матрицы
    Matrix adjugate() const;  // Алгебраическое дополнение
    Matrix inverse() const;  // Обратная матрица

    // Перегрузка потоковых операторов для вывода и ввода
    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
    friend std::istream& operator>>(std::istream& is, Matrix& m);
};