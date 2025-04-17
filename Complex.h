#pragma once
#include <iostream>
#include <cmath>
#include <string>

class Complex {
private:
    double real; // Действительная часть
    double imag; // Мнимая часть

public:
    // Конструкторы
    Complex();  // Конструктор по умолчанию (реал = 0, имаг = 0)
    Complex(double real, double imag = 0.0); // Конструктор с параметрами
    Complex(const Complex& other); // Конструктор копирования

    // Получение и установка значений полей
    double getReal() const; // Получение действительной части
    double getImag() const; // Получение мнимой части
    void setReal(double r); // Установка действительной части
    void setImag(double i); // Установка мнимой части

    // Арифметические операции с комплексными числами
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;

    // Арифметические операции с вещественными числами
    Complex operator+(double val) const;
    Complex operator-(double val) const;
    Complex operator*(double val) const;
    Complex operator/(double val) const;

    // Операции над комплексными числами
    Complex operator-() const; // Смена знака

    // Операции присваивания
    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex& operator*=(const Complex& other);
    Complex& operator/=(const Complex& other);

    // Сравнение
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;

    // Дополнительные методы
    double abs() const;       // Модуль
    double arg() const;       // Аргумент
    Complex conjugate() const; // Сопряжённое число

    // Операции ввода/вывода
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);
};
