#pragma once

#include <iostream>
#include <cmath>
#include <stdexcept>

class Vector2D {
private:
    double x, y;

public:
    // Конструкторы
    Vector2D(); // Конструктор по умолчанию (инициализация нулями)
    Vector2D(double x, double y); // Конструктор с заданием координат

    // Геттеры для координат
    double getX() const; // Получить координату X
    double getY() const; // Получить координату Y

    // Операции с векторами
    Vector2D operator+(const Vector2D& other) const; // Сложение векторов
    Vector2D operator-(const Vector2D& other) const; // Вычитание векторов
    bool operator==(const Vector2D& other) const; // Проверка на равенство
    bool operator!=(const Vector2D& other) const; // Проверка на неравенство

    // Операции с числом (скаляром)
    Vector2D operator*(double scalar) const; // Умножение вектора на скаляр
    Vector2D operator/(double scalar) const; // Деление вектора на скаляр

    // Скалярное произведение
    double dot(const Vector2D& other) const; // Скалярное произведение двух векторов

    // Длина вектора
    double length() const; // Вычисление длины вектора

    double cos(const Vector2D& other) const; //Косинус угла между векторами

    // Метод поворота вектора на угол
    Vector2D rotate(double angle) const;  // Поворот вектора на угол в радианах

    // Перегрузка операторов вывода/ввода
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& v); // Оператор вывода
    friend std::istream& operator>>(std::istream& is, Vector2D& v); // Оператор ввода
};



