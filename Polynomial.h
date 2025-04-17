#pragma once

#include <vector>
#include <iostream>
#include <initializer_list>
#include <stdexcept>

class Polynomial {
private:
    std::vector<double> coefficients; // Хранение коэффициентов полинома

    void trim(); // Удаляет лишние нули справа в векторе коэффициентов

public:
    // Конструкторы
    Polynomial(); // Нулевой полином
    Polynomial(int degree); // Полином заданной степени, коэффициенты = 0
    Polynomial(int degree, double value); // Полином заданной степени, все коэффициенты = value
    Polynomial(double scalar); // Константный полином (например, 5)
    Polynomial(const std::vector<double>& coeffs); // Полином из вектора коэффициентов
    Polynomial(std::initializer_list<double> list); // Полином из списка инициализации

    // Методы
    int degree() const; // Возвращает степень полинома
    double evaluate(double x) const; // Вычисление значения полинома в точке x
    Polynomial derivative() const; // Возвращает производную полинома
    Polynomial integrate() const; // Возвращает неопределённый интеграл полинома

    Polynomial divide(const Polynomial& divisor) const; // Деление полиномов
    Polynomial mod(const Polynomial& divisor) const; // Остаток от деления полиномов

    // Арифметические операторы
    Polynomial operator+(const Polynomial& other) const; // Оператор сложения
    Polynomial operator-(const Polynomial& other) const; // Оператор вычитания
    Polynomial operator*(const Polynomial& other) const; // Оператор умножения

    Polynomial& operator+=(const Polynomial& other); // Оператор добавления
    Polynomial& operator-=(const Polynomial& other); // Оператор вычитания
    Polynomial& operator*=(const Polynomial& other); // Оператор умножения

    bool operator==(const Polynomial& other) const; // Оператор сравнения на равенство
    bool operator!=(const Polynomial& other) const; // Оператор сравнения на неравенство

    // Преобразование в скаляр
    explicit operator double() const; // Преобразование в скаляр

    // Ввод/вывод
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& poly); // Оператор вывода
    friend std::istream& operator>>(std::istream& is, Polynomial& poly); // Оператор ввода
};
