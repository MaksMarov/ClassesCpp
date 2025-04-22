#pragma once
#include <iostream>
#include <vector>
#include <limits>
#include "Complex.h"
#include "Vector3D.h"
#include "Matrix.h"
#include "Polynomial.h"
#include "Triangle.h"
#include "Point2D.h"
#include "Line2D.h"
#include "Vector2D.h"
#include "Plane3D.h"
#include "Circle.h"

// Функции для управления консольным меню
class ConsoleMenu {
public:
    static void clearConsole() {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }

    static void pause() {
        std::cout << "\nНажмите Enter для продолжения...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }

    static void printComplexMenuHeader() {
        std::cout << "==============================\n";
        std::cout << "       МЕНЮ: COMPLEX\n";
        std::cout << "==============================\n";
    }

    static void ComplexMenu();

    static void printVector3DMenuHeader() {
        std::cout << "==============================\n";
        std::cout << "       МЕНЮ: VECTOR3D\n";
        std::cout << "==============================\n";
    }

    static void Vector3DMenu();

    static void printMatrixMenuHeader() {
        std::cout << "==============================\n";
        std::cout << "       МЕНЮ: MATRIX\n";
        std::cout << "==============================\n";
    }

    static void MatrixMenu();

    static void printPolynomialMenuHeader() {
        std::cout << "==============================\n";
        std::cout << "       МЕНЮ: POLYNOMIAL\n";
        std::cout << "==============================\n";
    }

    static void PolynomialMenu();

    static void printTriangleMenuHeader() {
        std::cout << "==============================\n";
        std::cout << "       МЕНЮ: TRIANGLE\n";
        std::cout << "==============================\n";
    }

    static void TriangleMenu();

    static void printGeometryHeader() {
        std::cout << "==============================\n";
        std::cout << "       МЕНЮ: Классы 2\n";
        std::cout << "==============================\n";
    }

    static void GeometryMenu();

    static void CirclePointDemo();
    static void PointLineDistanceDemo();
    static void Vector2DRotationDemo();
    static void Line2DOperationsDemo();
    static void PlaneIntersectionDemo();

    static void printMainMenuHeader() {
        std::cout << "==============================\n";
        std::cout << "          WELCOME\n";
        std::cout << "==============================\n";
    }

    static void MainMenu();
};