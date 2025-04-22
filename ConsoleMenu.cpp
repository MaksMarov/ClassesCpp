#include "ConsoleMenu.h"

void ConsoleMenu::ComplexMenu() {
    std::vector<Complex> objects;
    int choice;

    do {
        clearConsole();
        printComplexMenuHeader();
        std::cout << "1. ������� ����� ����������� �����\n";
        std::cout << "2. �������� ��� �����\n";
        std::cout << "3. ������������ �������� ����� ����� �������\n";
        std::cout << "4. ������������ �������� � ������������ ������\n";
        std::cout << "5. �������������� ������ (������, ��������, ����������)\n";
        std::cout << "0. �����\n";
        std::cout << "==============================\n";
        std::cout << "�������� �����: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1: {
            clearConsole();
            Complex c;
            std::cin >> c;
            objects.push_back(c);
            std::cout << "�������: " << c << "\n";
            pause();
            break;
        }
        case 2: {
            clearConsole();
            if (objects.empty()) {
                std::cout << "��� ���������� ����������� �����.\n";
            }
            else {
                std::cout << "������ ����������� �����:\n";
                for (size_t i = 0; i < objects.size(); ++i) {
                    std::cout << i + 1 << ": " << objects[i] << "\n";
                }
            }
            pause();
            break;
        }
        case 3: {
            clearConsole();
            if (objects.size() < 2) {
                std::cout << "��� ���������� �������� ���������� ���� �� ��� �����.\n";
            }
            else {
                size_t index1, index2;
                std::cout << "�������� ������ ����� (1 - " << objects.size() << "): ";
                std::cin >> index1;
                std::cout << "�������� ������ ����� (1 - " << objects.size() << "): ";
                std::cin >> index2;

                if (index1 > 0 && index1 <= objects.size() && index2 > 0 && index2 <= objects.size()) {
                    Complex c1 = objects[index1 - 1];
                    Complex c2 = objects[index2 - 1];
                    std::cout << "������ �����: " << c1 << "\n";
                    std::cout << "������ �����: " << c2 << "\n";
                    std::cout << "�������� � ������������ �������:\n";
                    std::cout << "��������: " << c1 + c2 << "\n";
                    std::cout << "���������: " << c1 - c2 << "\n";
                    std::cout << "���������: " << c1 * c2 << "\n";
                    std::cout << "�������: " << c1 / c2 << "\n";
                }
                else {
                    std::cout << "������������ �������. ���������� �����.\n";
                }
            }
            pause();
            break;
        }
        case 4: {
            clearConsole();
            if (objects.empty()) {
                std::cout << "��� ���������� ����������� �����.\n";
            }
            else {
                size_t index;
                double scalar;
                std::cout << "�������� ����� (1 - " << objects.size() << "): ";
                std::cin >> index;
                std::cout << "������� ������������ �����: ";
                std::cin >> scalar;

                if (index > 0 && index <= objects.size()) {
                    Complex c = objects[index - 1];
                    std::cout << "�����: " << c << "\n";
                    std::cout << "������: " << scalar << "\n";
                    std::cout << "�������� � ������������ ������:\n";
                    std::cout << "��������: " << c + scalar << "\n";
                    std::cout << "���������: " << c - scalar << "\n";
                    std::cout << "���������: " << c * scalar << "\n";
                    std::cout << "�������: " << c / scalar << "\n";
                }
                else {
                    std::cout << "������������ ������. ���������� �����.\n";
                }
            }
            pause();
            break;
        }
        case 5: {
            clearConsole();
            if (objects.empty()) {
                std::cout << "��� ���������� ����������� �����.\n";
            }
            else {
                size_t index;
                std::cout << "�������� ����� (1 - " << objects.size() << "): ";
                std::cin >> index;

                if (index > 0 && index <= objects.size()) {
                    Complex c = objects[index - 1];
                    std::cout << "�����: " << c << "\n";
                    std::cout << "������: " << c.abs() << "\n";
                    std::cout << "��������: " << c.arg() << "\n";
                    std::cout << "����������: " << c.conjugate() << "\n";
                }
                else {
                    std::cout << "������������ ������. ���������� �����.\n";
                }
            }
            pause();
            break;
        }
        case 0:
            break;
        default:
            std::cout << "������������ ����, ���������� �����.\n";
            pause();
        }
    } while (choice != 0);
}

void ConsoleMenu::Vector3DMenu() {
    std::vector<Vector3D> vectors; // �������� ��������
    int choice; // ����� ������������

    do {
        clearConsole(); // ������� �������
        printVector3DMenuHeader(); // ������ ��������� ����
        std::cout << "1. ������� ����� ������\n";
        std::cout << "2. �������� ��� �������\n";
        std::cout << "3. ������������ �������� ����� ����� ���������\n";
        std::cout << "4. ������������ �������� � ������\n";
        std::cout << "5. ��������� � ��������� ������������\n";
        std::cout << "6. ����� �������\n";
        std::cout << "7. ������� ���� ����� ���������\n";
        std::cout << "0. �����\n";
        std::cout << "==============================\n";
        std::cout << "�������� �����: ";
        std::cin >> choice;

        // �������� �� ������������ ����
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1: { // �������� ������ �������
            clearConsole();
            Vector3D v;
            std::cin >> v; // ���� �������
            vectors.push_back(v); // ���������� ������� � ������
            std::cout << "�������: " << v << "\n";
            pause(); // ����� ��� ������������
            break;
        }
        case 2: { // �������� ��� �������
            clearConsole();
            if (vectors.empty()) {
                std::cout << "��� ���������� ��������.\n";
            }
            else {
                std::cout << "������ ��������:\n";
                for (size_t i = 0; i < vectors.size(); ++i) {
                    std::cout << i << ": " << vectors[i] << "\n";
                }
            }
            pause(); // ����� ��� ������������
            break;
        }
        case 3: { // �������� ����� ����� ���������
            clearConsole();
            if (vectors.size() < 2) {
                std::cout << "�������� ������� ��� ������� ��� ��������.\n";
            }
            else {
                size_t index1, index2;
                std::cout << "�������� ������ ������ (1 - " << vectors.size() << "): ";
                std::cin >> index1;
                std::cout << "�������� ������ ������ (1 - " << vectors.size() << "): ";
                std::cin >> index2;

                if (index1 > 0 && index1 <= vectors.size() && index2 > 0 && index2 <= vectors.size()) {
                    const Vector3D& a = vectors[index1 - 1];
                    const Vector3D& b = vectors[index2 - 1];
                    std::cout << "������ ������:" << a << "\n";
                    std::cout << "������ ������:" << b << "\n";
                    std::cout << "\n" << a << " + " << b << " = " << (a + b) << "\n";
                    std::cout << a << " - " << b << " = " << (a - b) << "\n";
                    std::cout << a << " == " << b << " ? " << (a == b ? "��" : "���") << "\n";
                }
                else {
                    std::cout << "�������� �������.\n";
                }
            }
            pause();
            break;
        }
        case 4: { // �������� � ������
            clearConsole();
            if (vectors.empty()) {
                std::cout << "��� ��������.\n";
            }
            else {
                size_t index;
                double scalar;
                std::cout << "�������� ������ (1 - " << vectors.size() << "): ";
                std::cin >> index;
                std::cout << "������� ������: ";
                std::cin >> scalar;

                if (index > 0 && index <= vectors.size()) {
                    const Vector3D& v = vectors[index - 1];
                    std::cout << "\n" << v << " * " << scalar << " = " << (v * scalar) << "\n";
                    std::cout << v << " / " << scalar << " = " << (v / scalar) << "\n";
                }
                else {
                    std::cout << "�������� ������.\n";
                }
            }
            pause();
            break;
        }
        case 5: { // ��������� � ��������� ������������
            clearConsole();
            if (vectors.size() < 2) {
                std::cout << "�������� ������� ��� ������� ��� ��������.\n";
            }
            else {
                size_t index1, index2;
                std::cout << "�������� ������ ������ (1 - " << vectors.size() << "): ";
                std::cin >> index1;
                std::cout << "�������� ������ ������ (1 - " << vectors.size() << "): ";
                std::cin >> index2;

                if (index1 > 0 && index1 <= vectors.size() && index2 > 0 && index2 <= vectors.size()) {
                    const Vector3D& a = vectors[index1 - 1];
                    const Vector3D& b = vectors[index2 - 1];
                    std::cout << "������ ������:" << a << "\n";
                    std::cout << "������ ������:" << b << "\n";
                    std::cout << "\n��������� ������������: " << a.dot(b) << "\n";
                    std::cout << "��������� ������������: " << a.cross(b) << "\n";
                }
                else {
                    std::cout << "�������� �������.\n";
                }
            }
            pause();
            break;
        }
        case 6: { // ����� �������
            clearConsole();
            if (vectors.empty()) {
                std::cout << "��� ��������.\n";
            }
            else {
                size_t index;
                std::cout << "�������� ������ (1 - " << vectors.size() << "): ";
                std::cin >> index;

                if (index > 0 && index <= vectors.size()) {
                    const Vector3D& v = vectors[index - 1];
                    std::cout << "������:" << v << "\n";
                    std::cout << "\n����� �������: " << v.length() << "\n";
                }
                else {
                    std::cout << "�������� ������.\n";
                }
            }
            pause();
            break;
        }
        case 7: { // ������� ���� ����� ���������
            clearConsole();
            if (vectors.size() < 2) {
                std::cout << "�������� ������� ��� ������� ��� ��������.\n";
            }
            else {
                size_t index1, index2;
                std::cout << "�������� ������ ������ (1 - " << vectors.size() << "): ";
                std::cin >> index1;
                std::cout << "�������� ������ ������ (1 - " << vectors.size() << "): ";
                std::cin >> index2;

                if (index1 > 0 && index1 <= vectors.size() && index2 > 0 && index2 <= vectors.size()) {
                    const Vector3D& a = vectors[index1 - 1];
                    const Vector3D& b = vectors[index2 - 1];
                    std::cout << "������ ������:" << a << "\n";
                    std::cout << "������ ������:" << b << "\n";
                    std::cout << "\n������� ���� a^b:" << a.cos(b) << "\n";
                }
                else {
                    std::cout << "�������� �������.\n";
                }
            }
            pause();
            break;
        }
        case 0: { // �����
            clearConsole();
            break;
        }
        default:
            std::cout << "�������� �����. ���������� �����.\n";
            pause();
            break;
        }
    } while (choice != 0);
}

// ������� ���� ��� ������ � ���������
void ConsoleMenu::MatrixMenu() {
    std::vector<Matrix> matrices;  // ������ ��� �������� ������
    int choice;  // ���������� ��� ������ ������ ����

    do {
        clearConsole();
        printMatrixMenuHeader();
        std::cout << "1. ������� ����� �������\n";
        std::cout << "2. �������� ��� �������\n";
        std::cout << "3. ������������ �������� ����� ����� ���������\n";
        std::cout << "4. ������������ �������� � ������\n";
        std::cout << "5. ���������������� ������� � ���������� � ������������ � �������� �������\n";
        std::cout << "6. �������� ������� �������\n";
        std::cout << "7. ��������� ������ �� ��������� � �����������\n";
        std::cout << "0. �����\n";
        std::cout << "==============================\n";
        std::cout << "�������� �����: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1: {  // ������� ����� �������
            clearConsole();
            int rows, cols;
            std::cout << "������� ���������� �����: ";
            std::cin >> rows;
            std::cout << "������� ���������� ��������: ";
            std::cin >> cols;

            // ������ ������� � ��������� ���������
            Matrix m(rows, cols);
            std::cout << "������� �������� �������:\n";
            std::cin >> m;  // ���������� ���������� ��������� >> ��� ����� �������

            matrices.push_back(m);
            std::cout << "������� �������!\n";
            pause();
            break;
        }
        case 2: {  // �������� ��� �������
            clearConsole();
            if (matrices.empty()) {
                std::cout << "��� ��������� ������.\n";
            }
            else {
                std::cout << "������ ������:\n";
                for (size_t i = 0; i < matrices.size(); ++i) {
                    std::cout << i + 1 << ". " << "\n" << matrices[i] << "\n";
                }
            }
            pause();
            break;
        }
        case 3: {  // �������� ����� ����� ���������
            clearConsole();
            if (matrices.size() < 2) {
                std::cout << "�������� ������� ��� ������� ��� ��������.\n";
            }
            else {
                size_t index1, index2;
                std::cout << "�������� ������ ������� (1 - " << matrices.size() << "): ";
                std::cin >> index1;
                std::cout << "�������� ������ �������(1 - " << matrices.size() << "): ";
                std::cin >> index2;

                if (index1 > 0 && index1 <= matrices.size() && index2 > 0 && index2 <= matrices.size()) {
                    const Matrix& a = matrices[index1 - 1];
                    const Matrix& b = matrices[index2 - 1];
                    std::cout << "������ �������:" << "\n" << a << "\n";
                    std::cout << "������ �������:" << "\n" << b << "\n";
                    std::cout << "��������:" << "\n";
                    std::cout << a << " + " << "\n" << b << " = " << "\n" << (a + b) << "\n";
                    std::cout << "���������:" << "\n";
                    std::cout << a << " - " << "\n" << b << " = " << "\n" << (a - b) << "\n";
                    std::cout << "���������:" << "\n";
                    std::cout << a << " * " << "\n" << b << " = " << "\n" << (a * b) << "\n";
                }
                else {
                    std::cout << "�������� �������.\n";
                }
            }
            pause();
            break;
        }
        case 4: {  // �������� � ������
            clearConsole();
            if (matrices.empty()) {
                std::cout << "��� ������.\n";
            }
            else {
                size_t index;
                double scalar;
                std::cout << "�������� ������� (1 - " << matrices.size() << "): ";
                std::cin >> index;
                std::cout << "������� ������: ";
                std::cin >> scalar;

                if (index > 0 && index <= matrices.size()) {
                    const Matrix& m = matrices[index - 1];
                    std::cout << "�������:" << "\n" << m << "\n";
                    std::cout << "������:" << scalar << "\n";
                    std::cout << "\n" << m << " * " << scalar << " = " << "\n" << (m * scalar) << "\n";
                }
                else {
                    std::cout << "�������� ������.\n";
                }
            }
            pause();
            break;
        }
        case 5: {  // ���������������� ������� � ���������� � ������������ � �������� �������
            clearConsole();
            if (matrices.empty()) {
                std::cout << "��� ������.\n";
            }
            else {
                size_t index;
                std::cout << "�������� ������� (1 - " << matrices.size() << "): ";
                std::cin >> index;
                if (index > 0 && index <= matrices.size()) {
                    const Matrix& m = matrices[index - 1];
                    std::cout << "�������:" << "\n" << m << "\n";
                    std::cout << "��������� ����������������:\n" << m.transpose() << "\n";
                    std::cout << "������������ �������: " << m.determinant() << "\n";

                    try {
                        std::cout << "�������� �������:\n" << m.inverse() << "\n";
                        std::cout << "������������ �������� � �������� = " << "\n" << (m * m.inverse()) << "\n";

                    }
                    catch (const std::invalid_argument& e) {
                        std::cout << "������: " << e.what() << "\n";
                    }
                }
                else {
                    std::cout << "�������� ������.\n";
                }
            }
            pause();
            break;
        }
        case 6: {  // �������� ������� �������
            clearConsole();
            if (matrices.empty()) {
                std::cout << "��� ������.\n";
            }
            else {
                size_t index;
                std::cout << "�������� ������� (1 - " << matrices.size() << "): ";
                std::cin >> index;

                if (index > 0 && index <= matrices.size()) {
                    const Matrix& m = matrices[index - 1];
                    std::cout << "�������:" << "\n" << m << "\n";
                    std::cout << "�������� �� ������� ����������? " << (m.isSquare() ? "��" : "���") << "\n";
                    std::cout << "�������� �� ������� ������������? " << (m.isDiagonal() ? "��" : "���") << "\n";
                    std::cout << "�������� �� ������� ���������? " << (m.isIdentity() ? "��" : "���") << "\n";
                    std::cout << "�������� �� ������� �������? " << (m.isZero() ? "��" : "���") << "\n";
                    std::cout << "�������� �� ������� ������������? " << (m.isSymmetric() ? "��" : "���") << "\n";
                    std::cout << "�������� �� ������� �����������������? " << (m.isUpperTriangular() ? "��" : "���") << "\n";
                    std::cout << "�������� �� ������� ����������������? " << (m.isLowerTriangular() ? "��" : "���") << "\n";
                }
                else {
                    std::cout << "�������� ������.\n";
                }
            }
            pause();
            break;
        }
        case 7: {  // ��������� ������ �� ��������� � �����������
            clearConsole();
            if (matrices.size() < 2) {
                std::cout << "�������� ������� ��� ������� ��� ���������.\n";
            }
            else {
                size_t index1, index2;
                std::cout << "�������� ������ ������� (1 - " << matrices.size() << "): ";
                std::cin >> index1;
                std::cout << "�������� ������ �������(1 - " << matrices.size() << "): ";
                std::cin >> index2;

                if (index1 > 0 && index1 <= matrices.size() && index2 > 0 && index2 <= matrices.size()) {
                    const Matrix& a = matrices[index1 - 1];
                    const Matrix& b = matrices[index2 - 1];
                    std::cout << "������ �������:" << "\n" << a << "\n";
                    std::cout << "������ �������:" << "\n" << b << "\n";

                    if (a == b) {
                        std::cout << "������� �����.\n";
                    }
                    else {
                        std::cout << "������� �� �����.\n";
                    }
                }
                else {
                    std::cout << "�������� �������.\n";
                }
            }
            pause();
            break;
        }
        case 0:  // �����
            break;
        default:
            std::cout << "�������� �����. ��������� �������.\n";
            pause();
            break;
        }
    } while (choice != 0);
}

void ConsoleMenu::PolynomialMenu() {
    std::vector<Polynomial> polynomials;  // ������ ��� �������� ���������
    int choice;  // ���������� ��� ������ ������ ����

    do {
        clearConsole();
        printPolynomialMenuHeader();
        std::cout << "1. ������� ����� �������\n";
        std::cout << "2. �������� ��� ��������\n";
        std::cout << "3. ������������ �������� ����� ����� ����������\n";
        std::cout << "4. ������������ �������� � ������\n";
        std::cout << "5. ����������� ��������\n";
        std::cout << "6. �������� ��������\n";
        std::cout << "7. ���������� �������� �������� ��� ��������� ���������\n";  // ����� �����
        std::cout << "0. �����\n";
        std::cout << "==============================\n";
        std::cout << "�������� �����: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1: {  // ������� ����� �������
            clearConsole();
            Polynomial p;
            std::cin >> p;  // ���������� ���������� ��������� >> ��� ����� ��������

            polynomials.push_back(p);
            std::cout << "������� ������!\n";
            pause();
            break;
        }
        case 2: {  // �������� ��� ��������
            clearConsole();
            if (polynomials.empty()) {
                std::cout << "��� ��������� ���������.\n";
            }
            else {
                std::cout << "������ ���������:\n";
                for (size_t i = 0; i < polynomials.size(); ++i) {
                    std::cout << i + 1 << ". " << polynomials[i] << "\n";
                }
            }
            pause();
            break;
        }
        case 3: {  // �������� ����� ����� ����������
            clearConsole();
            if (polynomials.size() < 2) {
                std::cout << "�������� ������� ��� �������� ��� ��������.\n";
            }
            else {
                size_t index1, index2;
                std::cout << "�������� ������ ������� (1 - " << polynomials.size() << "): ";
                std::cin >> index1;
                std::cout << "�������� ������ ������� (1 - " << polynomials.size() << "): ";
                std::cin >> index2;

                if (index1 > 0 && index1 <= polynomials.size() && index2 > 0 && index2 <= polynomials.size()) {
                    const Polynomial& a = polynomials[index1 - 1];
                    const Polynomial& b = polynomials[index2 - 1];
                    std::cout << "������ �������:\n" << a << "\n";
                    std::cout << "������ �������:\n" << b << "\n";
                    std::cout << "��������:\n" << a << " + " << b << " = " << (a + b) << "\n";
                    std::cout << "���������:\n" << a << " - " << b << " = " << (a - b) << "\n";
                    std::cout << "���������:\n" << a << " * " << b << " = " << (a * b) << "\n";
                }
                else {
                    std::cout << "�������� �������.\n";
                }
            }
            pause();
            break;
        }
        case 4: {  // �������� � ������
            clearConsole();
            if (polynomials.empty()) {
                std::cout << "��� ���������.\n";
            }
            else {
                size_t index;
                double scalar;
                std::cout << "�������� ������� (1 - " << polynomials.size() << "): ";
                std::cin >> index;
                std::cout << "������� ������: ";
                std::cin >> scalar;

                if (index > 0 && index <= polynomials.size()) {
                    const Polynomial& p = polynomials[index - 1];
                    std::cout << "�������:\n" << p << "\n";
                    std::cout << "������: " << scalar << "\n";
                    std::cout << p << " * " << scalar << " = " << (p * scalar) << "\n";
                }
                else {
                    std::cout << "�������� ������.\n";
                }
            }
            pause();
            break;
        }
        case 5: {  // ����������� ��������
            clearConsole();
            if (polynomials.empty()) {
                std::cout << "��� ���������.\n";
            }
            else {
                size_t index;
                std::cout << "�������� ������� (1 - " << polynomials.size() << "): ";
                std::cin >> index;
                if (index > 0 && index <= polynomials.size()) {
                    const Polynomial& p = polynomials[index - 1];
                    std::cout << "����������� ��������:\n" << p.derivative() << "\n";
                }
                else {
                    std::cout << "�������� ������.\n";
                }
            }
            pause();
            break;
        }
        case 6: {  // �������� ��������
            clearConsole();
            if (polynomials.empty()) {
                std::cout << "��� ���������.\n";
            }
            else {
                size_t index;
                std::cout << "�������� ������� (1 - " << polynomials.size() << "): ";
                std::cin >> index;
                if (index > 0 && index <= polynomials.size()) {
                    const Polynomial& p = polynomials[index - 1];
                    std::cout << "�������� ��������:\n" << p.integrate() << "\n";
                }
                else {
                    std::cout << "�������� ������.\n";
                }
            }
            pause();
            break;
        }
        case 7: {  // ���������� �������� �������� ��� ��������� ���������
            clearConsole();
            if (polynomials.empty()) {
                std::cout << "��� ���������.\n";
            }
            else {
                size_t index;
                double arg;
                std::cout << "�������� ������� (1 - " << polynomials.size() << "): ";
                std::cin >> index;
                std::cout << "������� �������� ���������: ";
                std::cin >> arg;

                if (index > 0 && index <= polynomials.size()) {
                    const Polynomial& p = polynomials[index - 1];
                    double result = p.evaluate(arg);
                    std::cout << "�������� �������� " << p << " ��� x = " << arg << " ����� " << result << "\n";
                }
                else {
                    std::cout << "�������� ������.\n";
                }
            }
            pause();
            break;
        }
        case 0:  // �����
            break;
        default:
            std::cout << "�������� �����. ��������� �������.\n";
            pause();
            break;
        }
    } while (choice != 0);
}

void ConsoleMenu::TriangleMenu() {
    std::vector<Triangle> triangles;  // Vector to store triangles
    int choice;  // Variable for menu selection

    do {
        clearConsole();
        printTriangleMenuHeader();
        std::cout << "1. ������� ����� �����������\n";
        std::cout << "2. �������� ��� ������������\n";
        std::cout << "3. ������ ��������� ������������\n";
        std::cout << "4. ������ ������� ������������\n";
        std::cout << "5. �������� ���� ������������\n";
        std::cout << "6. �������� �� ������� �������������\n";
        std::cout << "7. ����������� � ������������ ��������\n";
        std::cout << "8. ����� ������������\n";
        std::cout << "0. �����\n";
        std::cout << "==============================\n";
        std::cout << "�������� �����: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1: {  // Create a new triangle
            clearConsole();
            Triangle t;
            std::cin >> t;
            triangles.push_back(t);
            std::cout << "����������� ������!\n";
            pause();
            break;
        }
        case 2: {  // Show all triangles
            clearConsole();
            if (triangles.empty()) {
                std::cout << "��� ��������� �������������.\n";
            }
            else {
                std::cout << "������ �������������:\n";
                for (size_t i = 0; i < triangles.size(); ++i) {
                    std::cout << i + 1 << ". ����������� " << i + 1 << ": " << triangles[i] << "\n";
                }
            }
            pause();
            break;
        }
        case 3: {  // Calculate perimeter
            clearConsole();
            if (triangles.empty()) {
                std::cout << "��� �������������.\n";
            }
            else {
                size_t idx;
                std::cout << "�������� ����������� (1 - " << triangles.size() << "): ";
                std::cin >> idx;
                if (idx > 0 && idx <= triangles.size()) {
                    Triangle t = triangles[idx - 1];
                    std::cout << t << "\n";
                    std::cout << "��������: " << t.perimeter() << "\n";
                }
                else {
                    std::cout << "�������� ������.\n";
                }
            }
            pause();
            break;
        }
        case 4: {  // Calculate area
            clearConsole();
            if (triangles.empty()) {
                std::cout << "��� �������������.\n";
            }
            else {
                size_t idx;
                std::cout << "�������� ����������� (1 - " << triangles.size() << "): ";
                std::cin >> idx;
                if (idx > 0 && idx <= triangles.size()) {
                    Triangle t = triangles[idx - 1];
                    std::cout << t << "\n";
                    std::cout << "�������: " << t.area() << "\n";
                }
                else {
                    std::cout << "�������� ������.\n";
                }
            }
            pause();
            break;
        }
        case 5: {  // Check triangle type
            clearConsole();
            if (triangles.empty()) {
                std::cout << "��� �������������.\n";
            }
            else {
                size_t idx;
                std::cout << "�������� ����������� (1 - " << triangles.size() << "): ";
                std::cin >> idx;
                if (idx > 0 && idx <= triangles.size()) {
                    Triangle t = triangles[idx - 1];
                    std::cout << t << "\n";
                    if (t.isEquilateral()) {
                        std::cout << "��� �������������� �����������.\n";
                    }
                    else {
                        std::cout << "��� �� �������������� �����������.\n";
                    }
                    if (t.isIsosceles()) {
                        std::cout << "��� �������������� �����������.\n";
                    }
                    else {
                        std::cout << "��� �� �������������� �����������.\n";
                    }
                    if (t.isRight()) {
                        std::cout << "��� ������������� �����������.\n";
                    }
                    else {
                        std::cout << "��� �� ������������� �����������.\n";
                    }
                }
                else {
                    std::cout << "�������� ������.\n";
                }
            }
            pause();
            break;
        }
        case 6: {  // Check for similarity of triangles
            clearConsole();
            if (triangles.empty()) {
                std::cout << "��� �������������.\n";
            }
            else {
                size_t idx1, idx2;
                std::cout << "�������� ������ ����������� (1 - " << triangles.size() << "): ";
                std::cin >> idx1;
                std::cout << "�������� ������ ����������� (1 - " << triangles.size() << "): ";
                std::cin >> idx2;
                if (idx1 > 0 && idx1 <= triangles.size() && idx2 > 0 && idx2 <= triangles.size()) {
                    Triangle t1 = triangles[idx1 - 1];
                    Triangle t2 = triangles[idx2 - 1];
                    std::cout << t1 << "\n";
                    std::cout << t2 << "\n";
                    if (t1.isSimilarTo(t2)) {
                        std::cout << "������������ �������.\n";
                    }
                    else {
                        std::cout << "������������ �� �������.\n";
                    }
                }
                else {
                    std::cout << "�������� �������.\n";
                }
            }
            pause();
            break;
        }
        case 7: {
            clearConsole();
            if (triangles.empty()) {
                std::cout << "��� �������������.\n";
            }
            else {
                size_t maxIndex = 0;
                double maxArea = triangles[0].area();

                for (size_t i = 1; i < triangles.size(); ++i) {
                    double area = triangles[i].area();
                    if (area > maxArea) {
                        maxArea = area;
                        maxIndex = i;
                    }
                }

                std::cout << "����������� � ���������� ��������:\n";
                std::cout << maxIndex + 1 << ". " << triangles[maxIndex] << " � �������: " << maxArea << "\n\n";
                std::cout << "������� ���� �������������:\n";
                for (size_t i = 0; i < triangles.size(); ++i) {
                    std::cout << i + 1 << ". " << triangles[i] << " � �������: " << triangles[i].area() << "\n";
                }
            }
            pause();
            break;
        }
        case 8: {  // Translate triangle
            clearConsole();
            if (triangles.empty()) {
                std::cout << "��� �������������.\n";
            }
            else {
                size_t idx;
                std::pair<double, double> shift;
                std::cout << "�������� ����������� (1 - " << triangles.size() << "): ";
                std::cin >> idx;
                if (idx > 0 && idx <= triangles.size()) {
                    Triangle t = triangles[idx - 1];
                    std::cout << t << "\n";
                    std::cout << "������� ����� �� ���� (dx dy): ";
                    std::cin >> shift.first >> shift.second;
                    t.translate(shift.first, shift.second);
                    std::cout << "����������� �������.\n";
                }
                else {
                    std::cout << "�������� ������.\n";
                }
            }
            pause();
            break;
        }
        case 0: {
            break;
        }
        default: {
            std::cout << "�������� �����. ���������� �����.\n";
            pause();
            break;
        }
        }
    } while (choice != 0);
}

// ������� ��� �������� ����, ������� �������� ��� ������ ����
void ConsoleMenu::MainMenu() {
    int choice;
    do {
        ConsoleMenu::clearConsole();
        printMainMenuHeader();
        std::cout << "1. ���� ����������� �����\n";
        std::cout << "2. ���� �������� 3D\n";
        std::cout << "3. ���� ������\n";
        std::cout << "4. ���� �����������\n";
        std::cout << "5. ���� �������������\n";
        std::cout << "0. �����\n";
        std::cout << "��� �����: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            ConsoleMenu::ComplexMenu();
            break;
        case 2:
            ConsoleMenu::Vector3DMenu();
            break;
        case 3:
            ConsoleMenu::MatrixMenu();
            break;
        case 4:
            ConsoleMenu::PolynomialMenu();
            break;
        case 5:
            ConsoleMenu::TriangleMenu();
            break;
        case 0:
            std::cout << "����� �� ���������...\n";
            break;
        default:
            std::cout << "�������� �����. ����������, ���������� �����.\n";
            ConsoleMenu::pause();
            break;
        }
    } while (choice != 0);
}