#pragma once
#include <iostream>
#include <vector>
#include <limits>
#include "Complex.h"
#include "Vector3D.h"
#include "Matrix.h"
#include "Polynomial.h"
#include "Triangle.h"

// ������� ��� ���������� ���������� ����
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
        std::cout << "\n������� Enter ��� �����������...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }

    static void printComplexMenuHeader() {
        std::cout << "==============================\n";
        std::cout << "       ����: COMPLEX\n";
        std::cout << "==============================\n";
    }

    static void ComplexMenu();

    static void printVector3DMenuHeader() {
        std::cout << "==============================\n";
        std::cout << "       ����: VECTOR3D\n";
        std::cout << "==============================\n";
    }

    static void Vector3DMenu();

    static void printMatrixMenuHeader() {
        std::cout << "==============================\n";
        std::cout << "       ����: MATRIX\n";
        std::cout << "==============================\n";
    }

    static void MatrixMenu();

    static void printPolynomialMenuHeader() {
        std::cout << "==============================\n";
        std::cout << "       ����: POLYNOMIAL\n";
        std::cout << "==============================\n";
    }

    static void PolynomialMenu();

    static void printTriangleMenuHeader() {
        std::cout << "==============================\n";
        std::cout << "       ����: TRIANGLE\n";
        std::cout << "==============================\n";
    }

    static void TriangleMenu();

    static void printMainMenuHeader() {
        std::cout << "==============================\n";
        std::cout << "          WELCOME\n";
        std::cout << "==============================\n";
    }

    static void MainMenu();
};