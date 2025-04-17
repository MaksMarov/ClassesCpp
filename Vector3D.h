#pragma once

#include <iostream>
#include <cmath>
#include <stdexcept>

class Vector3D {
private:
    double x, y, z; // Координаты вектора

public:
    // Конструкторы
    Vector3D(); // Конструктор по умолчанию (инициализация нулями)
    Vector3D(double x, double y, double z); // Конструктор с заданием координат

    // Геттеры для координат
    double getX() const; // Получить координату X
    double getY() const; // Получить координату Y
    double getZ() const; // Получить координату Z

    // Операции с векторами
    Vector3D operator+(const Vector3D& other) const; // Сложение векторов
    Vector3D operator-(const Vector3D& other) const; // Вычитание векторов
    bool operator==(const Vector3D& other) const; // Проверка на равенство
    bool operator!=(const Vector3D& other) const; // Проверка на неравенство

    // Операции с числом (скаляром)
    Vector3D operator*(double scalar) const; // Умножение вектора на скаляр
    Vector3D operator/(double scalar) const; // Деление вектора на скаляр

    // Скалярное произведение
    double dot(const Vector3D& other) const; // Скалярное произведение двух векторов

    // Векторное произведение
    Vector3D cross(const Vector3D& other) const; // Векторное произведение двух векторов

    // Длина вектора
    double length() const; // Вычисление длины вектора

    // Перегрузка операторов вывода/ввода
    friend std::ostream& operator<<(std::ostream& os, const Vector3D& v); // Оператор вывода
    friend std::istream& operator>>(std::istream& is, Vector3D& v); // Оператор ввода
};