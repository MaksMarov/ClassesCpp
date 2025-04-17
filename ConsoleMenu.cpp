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
        std::cout << "5. ���������������� �������\n";
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
                    std::cout << i + 1 << ". " << matrices[i] << "\n";
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
                size_t i1, i2;
                std::cout << "�������� ������ ������ �������: ";
                std::cin >> i1;
                std::cout << "�������� ������ ������ �������: ";
                std::cin >> i2;

                if (i1 < matrices.size() && i2 < matrices.size()) {
                    const Matrix& a = matrices[i1];
                    const Matrix& b = matrices[i2];
                    std::cout << "\n" << a << " + " << b << " = " << (a + b) << "\n";
                    std::cout << a << " - " << b << " = " << (a - b) << "\n";
                    std::cout << a << " * " << b << " = " << (a * b) << "\n";
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
                size_t idx;
                double scalar;
                std::cout << "�������� ������ �������: ";
                std::cin >> idx;
                std::cout << "������� ������: ";
                std::cin >> scalar;

                if (idx < matrices.size()) {
                    const Matrix& m = matrices[idx];
                    std::cout << "\n" << m << " * " << scalar << " = " << (m * scalar) << "\n";
                }
                else {
                    std::cout << "�������� ������.\n";
                }
            }
            pause();
            break;
        }
        case 5: {  // ���������������� �������
            clearConsole();
            if (matrices.empty()) {
                std::cout << "��� ������.\n";
            }
            else {
                size_t idx;
                std::cout << "�������� ������ �������: ";
                std::cin >> idx;
                if (idx < matrices.size()) {
                    std::cout << "��������� ����������������:\n" << matrices[idx].transpose() << "\n";
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
            std::cin >> p;  // ���� �������� ����� ���������� ��������� >>
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
                size_t i1, i2;
                std::cout << "�������� ������ ������� ��������: ";
                std::cin >> i1;
                std::cout << "�������� ������ ������� ��������: ";
                std::cin >> i2;

                if (i1 < polynomials.size() && i2 < polynomials.size()) {
                    const Polynomial& a = polynomials[i1];
                    const Polynomial& b = polynomials[i2];
                    std::cout << "\n" << a << " + " << b << " = " << (a + b) << "\n";
                    std::cout << a << " - " << b << " = " << (a - b) << "\n";
                    std::cout << a << " * " << b << " = " << (a * b) << "\n";
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
                size_t idx;
                double scalar;
                std::cout << "�������� ������ ��������: ";
                std::cin >> idx;
                std::cout << "������� ������: ";
                std::cin >> scalar;

                if (idx < polynomials.size()) {
                    const Polynomial& p = polynomials[idx];
                    std::cout << "\n" << p << " * " << scalar << " = " << (p * scalar) << "\n";
                    std::cout << p << " + " << scalar << " = " << (p + scalar) << "\n";
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
                size_t idx;
                std::cout << "�������� ������ ��������: ";
                std::cin >> idx;
                if (idx < polynomials.size()) {
                    std::cout << "����������� ��������:\n" << polynomials[idx].derivative() << "\n";
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
                size_t idx;
                std::cout << "�������� ������ ��������: ";
                std::cin >> idx;
                if (idx < polynomials.size()) {
                    std::cout << "�������� ��������:\n" << polynomials[idx].integrate() << "\n";
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
    std::vector<Triangle> triangles;  // ������ ��� �������� �������������
    int choice;  // ���������� ��� ������ ������ ����

    do {
        clearConsole();
        printTriangleMenuHeader();
        std::cout << "1. ������� ����� �����������\n";
        std::cout << "2. �������� ��� ������������\n";
        std::cout << "3. ������ ��������� ������������\n";
        std::cout << "4. ������ ������� ������������\n";
        std::cout << "5. �������� �� �������������� �����������\n";
        std::cout << "6. �������� �� �������������� �����������\n";
        std::cout << "7. �������� �� ������������� �����������\n";
        std::cout << "8. �������� �� ��������� �������������\n";
        std::cout << "9. �������� �� ������� �������������\n";
        std::cout << "10. ��������, �������� �� ����������� �����\n";
        std::cout << "11. ����� ������������\n";
        std::cout << "12. ������� ������������\n";
        std::cout << "13. ��������������� ������������\n";
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
        case 1: {  // ������� ����� �����������
            clearConsole();
            std::pair<double, double> p1, p2, p3;
            std::cout << "������� ���������� ������ ������� (x1 y1): ";
            std::cin >> p1.first >> p1.second;
            std::cout << "������� ���������� ������ ������� (x2 y2): ";
            std::cin >> p2.first >> p2.second;
            std::cout << "������� ���������� ������� ������� (x3 y3): ";
            std::cin >> p3.first >> p3.second;

            Triangle t(p1, p2, p3);
            triangles.push_back(t);
            std::cout << "����������� ������!\n";
            pause();
            break;
        }
        case 2: {  // �������� ��� ������������
            clearConsole();
            if (triangles.empty()) {
                std::cout << "��� ��������� �������������.\n";
            }
            else {
                std::cout << "������ �������������:\n";
                for (size_t i = 0; i < triangles.size(); ++i) {
                    std::cout << i + 1 << ". " << triangles[i] << "\n";
                }
            }
            pause();
            break;
        }
        case 3: {  // ������ ���������
            clearConsole();
            if (triangles.empty()) {
                std::cout << "��� �������������.\n";
            }
            else {
                size_t idx;
                std::cout << "�������� ������ ������������: ";
                std::cin >> idx;
                if (idx < triangles.size()) {
                    std::cout << "��������: " << triangles[idx].perimeter() << "\n";
                }
                else {
                    std::cout << "�������� ������.\n";
                }
            }
            pause();
            break;
        }
        case 4: {  // ������ �������
            clearConsole();
            if (triangles.empty()) {
                std::cout << "��� �������������.\n";
            }
            else {
                size_t idx;
                std::cout << "�������� ������ ������������: ";
                std::cin >> idx;
                if (idx < triangles.size()) {
                    std::cout << "�������: " << triangles[idx].area() << "\n";
                }
                else {
                    std::cout << "�������� ������.\n";
                }
            }
            pause();
            break;
        }
        case 5: {  // �������� �� �������������� �����������
            clearConsole();
            if (triangles.empty()) {
                std::cout << "��� �������������.\n";
            }
            else {
                size_t idx;
                std::cout << "�������� ������ ������������: ";
                std::cin >> idx;
                if (idx < triangles.size()) {
                    if (triangles[idx].isEquilateral()) {
                        std::cout << "��� �������������� �����������.\n";
                    }
                    else {
                        std::cout << "��� �� �������������� �����������.\n";
                    }
                }
                else {
                    std::cout << "�������� ������.\n";
                }
            }
            pause();
            break;
        }
        case 6: {  // �������� �� �������������� �����������
            clearConsole();
            if (triangles.empty()) {
                std::cout << "��� �������������.\n";
            }
            else {
                size_t idx;
                std::cout << "�������� ������ ������������: ";
                std::cin >> idx;
                if (idx < triangles.size()) {
                    if (triangles[idx].isIsosceles()) {
                        std::cout << "��� �������������� �����������.\n";
                    }
                    else {
                        std::cout << "��� �� �������������� �����������.\n";
                    }
                }
                else {
                    std::cout << "�������� ������.\n";
                }
            }
            pause();
            break;
        }
        case 7: {  // �������� �� ������������� �����������
            clearConsole();
            if (triangles.empty()) {
                std::cout << "��� �������������.\n";
            }
            else {
                size_t idx;
                std::cout << "�������� ������ ������������: ";
                std::cin >> idx;
                if (idx < triangles.size()) {
                    if (triangles[idx].isRight()) {
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
        case 8: {  // �������� �� ��������� �������������
            clearConsole();
            if (triangles.empty()) {
                std::cout << "��� �������������.\n";
            }
            else {
                size_t idx1, idx2;
                std::cout << "�������� ������� ���� ������������� ��� ���������: ";
                std::cin >> idx1 >> idx2;
                if (idx1 < triangles.size() && idx2 < triangles.size()) {
                    if (triangles[idx1] == triangles[idx2]) {
                        std::cout << "������������ ����� �� �������.\n";
                    }
                    else {
                        std::cout << "������������ �� �����.\n";
                    }
                }
                else {
                    std::cout << "�������� �������.\n";
                }
            }
            pause();
            break;
        }
        case 9: {  // �������� �� �������
            clearConsole();
            if (triangles.empty()) {
                std::cout << "��� �������������.\n";
            }
            else {
                size_t idx1, idx2;
                std::cout << "�������� ������� ���� ������������� ��� �������� �� �������: ";
                std::cin >> idx1 >> idx2;
                if (idx1 < triangles.size() && idx2 < triangles.size()) {
                    if (triangles[idx1].isSimilarTo(triangles[idx2])) {
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
        case 10: {  // ��������, �������� �� ����������� �����
            clearConsole();
            if (triangles.empty()) {
                std::cout << "��� �������������.\n";
            }
            else {
                size_t idx;
                std::pair<double, double> point;
                std::cout << "�������� ������ ������������: ";
                std::cin >> idx;
                std::cout << "������� ���������� ����� (x y): ";
                std::cin >> point.first >> point.second;

                if (idx < triangles.size()) {
                    if (triangles[idx].containsPoint(point)) {
                        std::cout << "����������� �������� ��� �����.\n";
                    }
                    else {
                        std::cout << "����������� �� �������� ��� �����.\n";
                    }
                }
                else {
                    std::cout << "�������� ������.\n";
                }
            }
            pause();
            break;
        }
        case 11: {  // ����� ������������
            clearConsole();
            if (triangles.empty()) {
                std::cout << "��� �������������.\n";
            }
            else {
                size_t idx;
                double dx, dy;
                std::cout << "�������� ������ ������������: ";
                std::cin >> idx;
                std::cout << "������� ����� �� X � Y: ";
                std::cin >> dx >> dy;

                if (idx < triangles.size()) {
                    triangles[idx].translate(dx, dy);
                    std::cout << "����������� �������.\n";
                }
                else {
                    std::cout << "�������� ������.\n";
                }
            }
            pause();
            break;
        }
        case 12: {  // ������� ������������
            clearConsole();
            if (triangles.empty()) {
                std::cout << "��� �������������.\n";
            }
            else {
                size_t idx;
                double angle;
                std::pair<double, double> center;
                std::cout << "�������� ������ ������������: ";
                std::cin >> idx;
                std::cout << "������� ���� �������� � ����� �������� (x, y): ";
                std::cin >> angle >> center.first >> center.second;

                if (idx < triangles.size()) {
                    triangles[idx].rotate(angle, center);
                    std::cout << "����������� �������.\n";
                }
                else {
                    std::cout << "�������� ������.\n";
                }
            }
            pause();
            break;
        }
        case 13: {  // ��������������� ������������
            clearConsole();
            if (triangles.empty()) {
                std::cout << "��� �������������.\n";
            }
            else {
                size_t idx;
                double scale;
                std::pair<double, double> center;
                std::cout << "�������� ������ ������������: ";
                std::cin >> idx;
                std::cout << "������� ���� �������� � ����� (x, y): ";
                std::cin >> scale >> center.first >> center.second;

                if (idx < triangles.size()) {
                    triangles[idx].scale(scale, center);
                    std::cout << "����������� �������������.\n";
                }
                else {
                    std::cout << "�������� ������.\n";
                }
            }
            pause();
            break;
        }
        case 0: {  // �����
            clearConsole();
            break;
        }
        default:
            std::cout << "�������� �����, ���������� �����.\n";
            pause();
            break;
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