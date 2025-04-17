#include "ConsoleMenu.h"

void ConsoleMenu::ComplexMenu() {
    std::vector<Complex> objects;
    int choice;

    do {
        clearConsole();
        printComplexMenuHeader();
        std::cout << "1. Создать новое комплексное число\n";
        std::cout << "2. Показать все числа\n";
        std::cout << "3. Демонстрация операций между двумя числами\n";
        std::cout << "4. Демонстрация операций с вещественным числом\n";
        std::cout << "5. Дополнительные методы (модуль, аргумент, сопряжённое)\n";
        std::cout << "0. Назад\n";
        std::cout << "==============================\n";
        std::cout << "Выберите пункт: ";
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
            std::cout << "Создано: " << c << "\n";
            pause();
            break;
        }
        case 2: {
            clearConsole();
            if (objects.empty()) {
                std::cout << "Нет сохранённых комплексных чисел.\n";
            }
            else {
                std::cout << "Список комплексных чисел:\n";
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
                std::cout << "Для выполнения операции необходимо хотя бы два числа.\n";
            }
            else {
                size_t index1, index2;
                std::cout << "Выберите первое число (1 - " << objects.size() << "): ";
                std::cin >> index1;
                std::cout << "Выберите второе число (1 - " << objects.size() << "): ";
                std::cin >> index2;

                if (index1 > 0 && index1 <= objects.size() && index2 > 0 && index2 <= objects.size()) {
                    Complex c1 = objects[index1 - 1];
                    Complex c2 = objects[index2 - 1];
                    std::cout << "Первое число: " << c1 << "\n";
                    std::cout << "Второе число: " << c2 << "\n";
                    std::cout << "Операции с комплексными числами:\n";
                    std::cout << "Сложение: " << c1 + c2 << "\n";
                    std::cout << "Вычитание: " << c1 - c2 << "\n";
                    std::cout << "Умножение: " << c1 * c2 << "\n";
                    std::cout << "Деление: " << c1 / c2 << "\n";
                }
                else {
                    std::cout << "Некорректные индексы. Попробуйте снова.\n";
                }
            }
            pause();
            break;
        }
        case 4: {
            clearConsole();
            if (objects.empty()) {
                std::cout << "Нет сохранённых комплексных чисел.\n";
            }
            else {
                size_t index;
                double scalar;
                std::cout << "Выберите число (1 - " << objects.size() << "): ";
                std::cin >> index;
                std::cout << "Введите вещественное число: ";
                std::cin >> scalar;

                if (index > 0 && index <= objects.size()) {
                    Complex c = objects[index - 1];
                    std::cout << "Число: " << c << "\n";
                    std::cout << "Скаляр: " << scalar << "\n";
                    std::cout << "Операции с вещественным числом:\n";
                    std::cout << "Сложение: " << c + scalar << "\n";
                    std::cout << "Вычитание: " << c - scalar << "\n";
                    std::cout << "Умножение: " << c * scalar << "\n";
                    std::cout << "Деление: " << c / scalar << "\n";
                }
                else {
                    std::cout << "Некорректный индекс. Попробуйте снова.\n";
                }
            }
            pause();
            break;
        }
        case 5: {
            clearConsole();
            if (objects.empty()) {
                std::cout << "Нет сохранённых комплексных чисел.\n";
            }
            else {
                size_t index;
                std::cout << "Выберите число (1 - " << objects.size() << "): ";
                std::cin >> index;

                if (index > 0 && index <= objects.size()) {
                    Complex c = objects[index - 1];
                    std::cout << "Число: " << c << "\n";
                    std::cout << "Модуль: " << c.abs() << "\n";
                    std::cout << "Аргумент: " << c.arg() << "\n";
                    std::cout << "Сопряжённое: " << c.conjugate() << "\n";
                }
                else {
                    std::cout << "Некорректный индекс. Попробуйте снова.\n";
                }
            }
            pause();
            break;
        }
        case 0:
            break;
        default:
            std::cout << "Некорректный ввод, попробуйте снова.\n";
            pause();
        }
    } while (choice != 0);
}

void ConsoleMenu::Vector3DMenu() {
    std::vector<Vector3D> vectors; // Хранение векторов
    int choice; // Выбор пользователя

    do {
        clearConsole(); // Очистка консоли
        printVector3DMenuHeader(); // Печать заголовка меню
        std::cout << "1. Создать новый вектор\n";
        std::cout << "2. Показать все векторы\n";
        std::cout << "3. Демонстрация операций между двумя векторами\n";
        std::cout << "4. Демонстрация операций с числом\n";
        std::cout << "5. Скалярное и векторное произведение\n";
        std::cout << "6. Длина вектора\n";
        std::cout << "7. Косинус угла между векторами\n";
        std::cout << "0. Назад\n";
        std::cout << "==============================\n";
        std::cout << "Выберите пункт: ";
        std::cin >> choice;

        // Проверка на неправильный ввод
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1: { // Создание нового вектора
            clearConsole();
            Vector3D v;
            std::cin >> v; // Ввод вектора
            vectors.push_back(v); // Добавление вектора в список
            std::cout << "Создано: " << v << "\n";
            pause(); // Пауза для пользователя
            break;
        }
        case 2: { // Показать все векторы
            clearConsole();
            if (vectors.empty()) {
                std::cout << "Нет сохранённых векторов.\n";
            }
            else {
                std::cout << "Список векторов:\n";
                for (size_t i = 0; i < vectors.size(); ++i) {
                    std::cout << i << ": " << vectors[i] << "\n";
                }
            }
            pause(); // Пауза для пользователя
            break;
        }
        case 3: { // Операции между двумя векторами
            clearConsole();
            if (vectors.size() < 2) {
                std::cout << "Создайте минимум два вектора для операций.\n";
            }
            else {
                size_t index1, index2;
                std::cout << "Выберите первый вектор (1 - " << vectors.size() << "): ";
                std::cin >> index1;
                std::cout << "Выберите второй вектор (1 - " << vectors.size() << "): ";
                std::cin >> index2;

                if (index1 > 0 && index1 <= vectors.size() && index2 > 0 && index2 <= vectors.size()) {
                    const Vector3D& a = vectors[index1 - 1];
                    const Vector3D& b = vectors[index2 - 1];
                    std::cout << "Первый вектор:" << a << "\n";
                    std::cout << "Второй вектор:" << b << "\n";
                    std::cout << "\n" << a << " + " << b << " = " << (a + b) << "\n";
                    std::cout << a << " - " << b << " = " << (a - b) << "\n";
                    std::cout << a << " == " << b << " ? " << (a == b ? "Да" : "Нет") << "\n";
                }
                else {
                    std::cout << "Неверные индексы.\n";
                }
            }
            pause();
            break;
        }
        case 4: { // Операции с числом
            clearConsole();
            if (vectors.empty()) {
                std::cout << "Нет векторов.\n";
            }
            else {
                size_t index;
                double scalar;
                std::cout << "Выберите вектор (1 - " << vectors.size() << "): ";
                std::cin >> index;
                std::cout << "Введите скаляр: ";
                std::cin >> scalar;

                if (index > 0 && index <= vectors.size()) {
                    const Vector3D& v = vectors[index - 1];
                    std::cout << "\n" << v << " * " << scalar << " = " << (v * scalar) << "\n";
                    std::cout << v << " / " << scalar << " = " << (v / scalar) << "\n";
                }
                else {
                    std::cout << "Неверный индекс.\n";
                }
            }
            pause();
            break;
        }
        case 5: { // Скалярное и векторное произведение
            clearConsole();
            if (vectors.size() < 2) {
                std::cout << "Создайте минимум два вектора для операций.\n";
            }
            else {
                size_t index1, index2;
                std::cout << "Выберите первый вектор (1 - " << vectors.size() << "): ";
                std::cin >> index1;
                std::cout << "Выберите второй вектор (1 - " << vectors.size() << "): ";
                std::cin >> index2;

                if (index1 > 0 && index1 <= vectors.size() && index2 > 0 && index2 <= vectors.size()) {
                    const Vector3D& a = vectors[index1 - 1];
                    const Vector3D& b = vectors[index2 - 1];
                    std::cout << "Первый вектор:" << a << "\n";
                    std::cout << "Второй вектор:" << b << "\n";
                    std::cout << "\nСкалярное произведение: " << a.dot(b) << "\n";
                    std::cout << "Векторное произведение: " << a.cross(b) << "\n";
                }
                else {
                    std::cout << "Неверные индексы.\n";
                }
            }
            pause();
            break;
        }
        case 6: { // Длина вектора
            clearConsole();
            if (vectors.empty()) {
                std::cout << "Нет векторов.\n";
            }
            else {
                size_t index;
                std::cout << "Выберите вектор (1 - " << vectors.size() << "): ";
                std::cin >> index;

                if (index > 0 && index <= vectors.size()) {
                    const Vector3D& v = vectors[index - 1];
                    std::cout << "Вектор:" << v << "\n";
                    std::cout << "\nДлина вектора: " << v.length() << "\n";
                }
                else {
                    std::cout << "Неверный индекс.\n";
                }
            }
            pause();
            break;
        }
        case 7: { // Косинус угла между векторами
            clearConsole();
            if (vectors.size() < 2) {
                std::cout << "Создайте минимум два вектора для операций.\n";
            }
            else {
                size_t index1, index2;
                std::cout << "Выберите первый вектор (1 - " << vectors.size() << "): ";
                std::cin >> index1;
                std::cout << "Выберите второй вектор (1 - " << vectors.size() << "): ";
                std::cin >> index2;

                if (index1 > 0 && index1 <= vectors.size() && index2 > 0 && index2 <= vectors.size()) {
                    const Vector3D& a = vectors[index1 - 1];
                    const Vector3D& b = vectors[index2 - 1];
                    std::cout << "Первый вектор:" << a << "\n";
                    std::cout << "Второй вектор:" << b << "\n";
                    std::cout << "\nКосинус угла a^b:" << a.cos(b) << "\n";
                }
                else {
                    std::cout << "Неверные индексы.\n";
                }
            }
            pause();
            break;
        }
        case 0: { // Выход
            clearConsole();
            break;
        }
        default:
            std::cout << "Неверный выбор. Попробуйте снова.\n";
            pause();
            break;
        }
    } while (choice != 0);
}

// Главное меню для работы с матрицами
void ConsoleMenu::MatrixMenu() {
    std::vector<Matrix> matrices;  // Вектор для хранения матриц
    int choice;  // Переменная для выбора пункта меню

    do {
        clearConsole();
        printMatrixMenuHeader();
        std::cout << "1. Создать новую матрицу\n";
        std::cout << "2. Показать все матрицы\n";
        std::cout << "3. Демонстрация операций между двумя матрицами\n";
        std::cout << "4. Демонстрация операций с числом\n";
        std::cout << "5. Транспонирование матрицы\n";
        std::cout << "0. Назад\n";
        std::cout << "==============================\n";
        std::cout << "Выберите пункт: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1: {  // Создать новую матрицу
            clearConsole();
            int rows, cols;
            std::cout << "Введите количество строк: ";
            std::cin >> rows;
            std::cout << "Введите количество столбцов: ";
            std::cin >> cols;

            // Создаём матрицу с введёнными размерами
            Matrix m(rows, cols);
            std::cout << "Введите элементы матрицы:\n";
            std::cin >> m;  // Используем перегрузку оператора >> для ввода матрицы

            matrices.push_back(m);
            std::cout << "Матрица создана!\n";
            pause();
            break;
        }
        case 2: {  // Показать все матрицы
            clearConsole();
            if (matrices.empty()) {
                std::cout << "Нет созданных матриц.\n";
            }
            else {
                std::cout << "Список матриц:\n";
                for (size_t i = 0; i < matrices.size(); ++i) {
                    std::cout << i + 1 << ". " << matrices[i] << "\n";
                }
            }
            pause();
            break;
        }
        case 3: {  // Операции между двумя матрицами
            clearConsole();
            if (matrices.size() < 2) {
                std::cout << "Создайте минимум две матрицы для операций.\n";
            }
            else {
                size_t i1, i2;
                std::cout << "Выберите индекс первой матрицы: ";
                std::cin >> i1;
                std::cout << "Выберите индекс второй матрицы: ";
                std::cin >> i2;

                if (i1 < matrices.size() && i2 < matrices.size()) {
                    const Matrix& a = matrices[i1];
                    const Matrix& b = matrices[i2];
                    std::cout << "\n" << a << " + " << b << " = " << (a + b) << "\n";
                    std::cout << a << " - " << b << " = " << (a - b) << "\n";
                    std::cout << a << " * " << b << " = " << (a * b) << "\n";
                }
                else {
                    std::cout << "Неверные индексы.\n";
                }
            }
            pause();
            break;
        }
        case 4: {  // Операции с числом
            clearConsole();
            if (matrices.empty()) {
                std::cout << "Нет матриц.\n";
            }
            else {
                size_t idx;
                double scalar;
                std::cout << "Выберите индекс матрицы: ";
                std::cin >> idx;
                std::cout << "Введите скаляр: ";
                std::cin >> scalar;

                if (idx < matrices.size()) {
                    const Matrix& m = matrices[idx];
                    std::cout << "\n" << m << " * " << scalar << " = " << (m * scalar) << "\n";
                }
                else {
                    std::cout << "Неверный индекс.\n";
                }
            }
            pause();
            break;
        }
        case 5: {  // Транспонирование матрицы
            clearConsole();
            if (matrices.empty()) {
                std::cout << "Нет матриц.\n";
            }
            else {
                size_t idx;
                std::cout << "Выберите индекс матрицы: ";
                std::cin >> idx;
                if (idx < matrices.size()) {
                    std::cout << "Результат транспонирования:\n" << matrices[idx].transpose() << "\n";
                }
                else {
                    std::cout << "Неверный индекс.\n";
                }
            }
            pause();
            break;
        }
        case 0:  // Назад
            break;
        default:
            std::cout << "Неверный выбор. Повторите попытку.\n";
            pause();
            break;
        }
    } while (choice != 0);
}

void ConsoleMenu::PolynomialMenu() {
    std::vector<Polynomial> polynomials;  // Вектор для хранения полиномов
    int choice;  // Переменная для выбора пункта меню

    do {
        clearConsole();
        printPolynomialMenuHeader();
        std::cout << "1. Создать новый полином\n";
        std::cout << "2. Показать все полиномы\n";
        std::cout << "3. Демонстрация операций между двумя полиномами\n";
        std::cout << "4. Демонстрация операций с числом\n";
        std::cout << "5. Производная полинома\n";
        std::cout << "6. Интеграл полинома\n";
        std::cout << "0. Назад\n";
        std::cout << "==============================\n";
        std::cout << "Выберите пункт: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1: {  // Создать новый полином
            clearConsole();
            Polynomial p;
            std::cin >> p;  // Ввод полинома через перегрузку оператора >>
            polynomials.push_back(p);
            std::cout << "Полином создан!\n";
            pause();
            break;
        }
        case 2: {  // Показать все полиномы
            clearConsole();
            if (polynomials.empty()) {
                std::cout << "Нет созданных полиномов.\n";
            }
            else {
                std::cout << "Список полиномов:\n";
                for (size_t i = 0; i < polynomials.size(); ++i) {
                    std::cout << i + 1 << ". " << polynomials[i] << "\n";
                }
            }
            pause();
            break;
        }
        case 3: {  // Операции между двумя полиномами
            clearConsole();
            if (polynomials.size() < 2) {
                std::cout << "Создайте минимум два полинома для операций.\n";
            }
            else {
                size_t i1, i2;
                std::cout << "Выберите индекс первого полинома: ";
                std::cin >> i1;
                std::cout << "Выберите индекс второго полинома: ";
                std::cin >> i2;

                if (i1 < polynomials.size() && i2 < polynomials.size()) {
                    const Polynomial& a = polynomials[i1];
                    const Polynomial& b = polynomials[i2];
                    std::cout << "\n" << a << " + " << b << " = " << (a + b) << "\n";
                    std::cout << a << " - " << b << " = " << (a - b) << "\n";
                    std::cout << a << " * " << b << " = " << (a * b) << "\n";
                }
                else {
                    std::cout << "Неверные индексы.\n";
                }
            }
            pause();
            break;
        }
        case 4: {  // Операции с числом
            clearConsole();
            if (polynomials.empty()) {
                std::cout << "Нет полиномов.\n";
            }
            else {
                size_t idx;
                double scalar;
                std::cout << "Выберите индекс полинома: ";
                std::cin >> idx;
                std::cout << "Введите скаляр: ";
                std::cin >> scalar;

                if (idx < polynomials.size()) {
                    const Polynomial& p = polynomials[idx];
                    std::cout << "\n" << p << " * " << scalar << " = " << (p * scalar) << "\n";
                    std::cout << p << " + " << scalar << " = " << (p + scalar) << "\n";
                }
                else {
                    std::cout << "Неверный индекс.\n";
                }
            }
            pause();
            break;
        }
        case 5: {  // Производная полинома
            clearConsole();
            if (polynomials.empty()) {
                std::cout << "Нет полиномов.\n";
            }
            else {
                size_t idx;
                std::cout << "Выберите индекс полинома: ";
                std::cin >> idx;
                if (idx < polynomials.size()) {
                    std::cout << "Производная полинома:\n" << polynomials[idx].derivative() << "\n";
                }
                else {
                    std::cout << "Неверный индекс.\n";
                }
            }
            pause();
            break;
        }
        case 6: {  // Интеграл полинома
            clearConsole();
            if (polynomials.empty()) {
                std::cout << "Нет полиномов.\n";
            }
            else {
                size_t idx;
                std::cout << "Выберите индекс полинома: ";
                std::cin >> idx;
                if (idx < polynomials.size()) {
                    std::cout << "Интеграл полинома:\n" << polynomials[idx].integrate() << "\n";
                }
                else {
                    std::cout << "Неверный индекс.\n";
                }
            }
            pause();
            break;
        }
        case 0:  // Назад
            break;
        default:
            std::cout << "Неверный выбор. Повторите попытку.\n";
            pause();
            break;
        }
    } while (choice != 0);
}

void ConsoleMenu::TriangleMenu() {
    std::vector<Triangle> triangles;  // Вектор для хранения треугольников
    int choice;  // Переменная для выбора пункта меню

    do {
        clearConsole();
        printTriangleMenuHeader();
        std::cout << "1. Создать новый треугольник\n";
        std::cout << "2. Показать все треугольники\n";
        std::cout << "3. Расчёт периметра треугольника\n";
        std::cout << "4. Расчёт площади треугольника\n";
        std::cout << "5. Проверка на равносторонний треугольник\n";
        std::cout << "6. Проверка на равнобедренный треугольник\n";
        std::cout << "7. Проверка на прямоугольный треугольник\n";
        std::cout << "8. Проверка на равенство треугольников\n";
        std::cout << "9. Проверка на подобие треугольников\n";
        std::cout << "10. Проверка, содержит ли треугольник точку\n";
        std::cout << "11. Сдвиг треугольника\n";
        std::cout << "12. Поворот треугольника\n";
        std::cout << "13. Масштабирование треугольника\n";
        std::cout << "0. Назад\n";
        std::cout << "==============================\n";
        std::cout << "Выберите пункт: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1: {  // Создать новый треугольник
            clearConsole();
            std::pair<double, double> p1, p2, p3;
            std::cout << "Введите координаты первой вершины (x1 y1): ";
            std::cin >> p1.first >> p1.second;
            std::cout << "Введите координаты второй вершины (x2 y2): ";
            std::cin >> p2.first >> p2.second;
            std::cout << "Введите координаты третьей вершины (x3 y3): ";
            std::cin >> p3.first >> p3.second;

            Triangle t(p1, p2, p3);
            triangles.push_back(t);
            std::cout << "Треугольник создан!\n";
            pause();
            break;
        }
        case 2: {  // Показать все треугольники
            clearConsole();
            if (triangles.empty()) {
                std::cout << "Нет созданных треугольников.\n";
            }
            else {
                std::cout << "Список треугольников:\n";
                for (size_t i = 0; i < triangles.size(); ++i) {
                    std::cout << i + 1 << ". " << triangles[i] << "\n";
                }
            }
            pause();
            break;
        }
        case 3: {  // Расчёт периметра
            clearConsole();
            if (triangles.empty()) {
                std::cout << "Нет треугольников.\n";
            }
            else {
                size_t idx;
                std::cout << "Выберите индекс треугольника: ";
                std::cin >> idx;
                if (idx < triangles.size()) {
                    std::cout << "Периметр: " << triangles[idx].perimeter() << "\n";
                }
                else {
                    std::cout << "Неверный индекс.\n";
                }
            }
            pause();
            break;
        }
        case 4: {  // Расчёт площади
            clearConsole();
            if (triangles.empty()) {
                std::cout << "Нет треугольников.\n";
            }
            else {
                size_t idx;
                std::cout << "Выберите индекс треугольника: ";
                std::cin >> idx;
                if (idx < triangles.size()) {
                    std::cout << "Площадь: " << triangles[idx].area() << "\n";
                }
                else {
                    std::cout << "Неверный индекс.\n";
                }
            }
            pause();
            break;
        }
        case 5: {  // Проверка на равносторонний треугольник
            clearConsole();
            if (triangles.empty()) {
                std::cout << "Нет треугольников.\n";
            }
            else {
                size_t idx;
                std::cout << "Выберите индекс треугольника: ";
                std::cin >> idx;
                if (idx < triangles.size()) {
                    if (triangles[idx].isEquilateral()) {
                        std::cout << "Это равносторонний треугольник.\n";
                    }
                    else {
                        std::cout << "Это не равносторонний треугольник.\n";
                    }
                }
                else {
                    std::cout << "Неверный индекс.\n";
                }
            }
            pause();
            break;
        }
        case 6: {  // Проверка на равнобедренный треугольник
            clearConsole();
            if (triangles.empty()) {
                std::cout << "Нет треугольников.\n";
            }
            else {
                size_t idx;
                std::cout << "Выберите индекс треугольника: ";
                std::cin >> idx;
                if (idx < triangles.size()) {
                    if (triangles[idx].isIsosceles()) {
                        std::cout << "Это равнобедренный треугольник.\n";
                    }
                    else {
                        std::cout << "Это не равнобедренный треугольник.\n";
                    }
                }
                else {
                    std::cout << "Неверный индекс.\n";
                }
            }
            pause();
            break;
        }
        case 7: {  // Проверка на прямоугольный треугольник
            clearConsole();
            if (triangles.empty()) {
                std::cout << "Нет треугольников.\n";
            }
            else {
                size_t idx;
                std::cout << "Выберите индекс треугольника: ";
                std::cin >> idx;
                if (idx < triangles.size()) {
                    if (triangles[idx].isRight()) {
                        std::cout << "Это прямоугольный треугольник.\n";
                    }
                    else {
                        std::cout << "Это не прямоугольный треугольник.\n";
                    }
                }
                else {
                    std::cout << "Неверный индекс.\n";
                }
            }
            pause();
            break;
        }
        case 8: {  // Проверка на равенство треугольников
            clearConsole();
            if (triangles.empty()) {
                std::cout << "Нет треугольников.\n";
            }
            else {
                size_t idx1, idx2;
                std::cout << "Выберите индексы двух треугольников для сравнения: ";
                std::cin >> idx1 >> idx2;
                if (idx1 < triangles.size() && idx2 < triangles.size()) {
                    if (triangles[idx1] == triangles[idx2]) {
                        std::cout << "Треугольники равны по площади.\n";
                    }
                    else {
                        std::cout << "Треугольники не равны.\n";
                    }
                }
                else {
                    std::cout << "Неверные индексы.\n";
                }
            }
            pause();
            break;
        }
        case 9: {  // Проверка на подобие
            clearConsole();
            if (triangles.empty()) {
                std::cout << "Нет треугольников.\n";
            }
            else {
                size_t idx1, idx2;
                std::cout << "Выберите индексы двух треугольников для проверки на подобие: ";
                std::cin >> idx1 >> idx2;
                if (idx1 < triangles.size() && idx2 < triangles.size()) {
                    if (triangles[idx1].isSimilarTo(triangles[idx2])) {
                        std::cout << "Треугольники подобны.\n";
                    }
                    else {
                        std::cout << "Треугольники не подобны.\n";
                    }
                }
                else {
                    std::cout << "Неверные индексы.\n";
                }
            }
            pause();
            break;
        }
        case 10: {  // Проверка, содержит ли треугольник точку
            clearConsole();
            if (triangles.empty()) {
                std::cout << "Нет треугольников.\n";
            }
            else {
                size_t idx;
                std::pair<double, double> point;
                std::cout << "Выберите индекс треугольника: ";
                std::cin >> idx;
                std::cout << "Введите координаты точки (x y): ";
                std::cin >> point.first >> point.second;

                if (idx < triangles.size()) {
                    if (triangles[idx].containsPoint(point)) {
                        std::cout << "Треугольник содержит эту точку.\n";
                    }
                    else {
                        std::cout << "Треугольник не содержит эту точку.\n";
                    }
                }
                else {
                    std::cout << "Неверный индекс.\n";
                }
            }
            pause();
            break;
        }
        case 11: {  // Сдвиг треугольника
            clearConsole();
            if (triangles.empty()) {
                std::cout << "Нет треугольников.\n";
            }
            else {
                size_t idx;
                double dx, dy;
                std::cout << "Выберите индекс треугольника: ";
                std::cin >> idx;
                std::cout << "Введите сдвиг по X и Y: ";
                std::cin >> dx >> dy;

                if (idx < triangles.size()) {
                    triangles[idx].translate(dx, dy);
                    std::cout << "Треугольник сдвинут.\n";
                }
                else {
                    std::cout << "Неверный индекс.\n";
                }
            }
            pause();
            break;
        }
        case 12: {  // Поворот треугольника
            clearConsole();
            if (triangles.empty()) {
                std::cout << "Нет треугольников.\n";
            }
            else {
                size_t idx;
                double angle;
                std::pair<double, double> center;
                std::cout << "Выберите индекс треугольника: ";
                std::cin >> idx;
                std::cout << "Введите угол поворота и точку вращения (x, y): ";
                std::cin >> angle >> center.first >> center.second;

                if (idx < triangles.size()) {
                    triangles[idx].rotate(angle, center);
                    std::cout << "Треугольник повёрнут.\n";
                }
                else {
                    std::cout << "Неверный индекс.\n";
                }
            }
            pause();
            break;
        }
        case 13: {  // Масштабирование треугольника
            clearConsole();
            if (triangles.empty()) {
                std::cout << "Нет треугольников.\n";
            }
            else {
                size_t idx;
                double scale;
                std::pair<double, double> center;
                std::cout << "Выберите индекс треугольника: ";
                std::cin >> idx;
                std::cout << "Введите угол поворота и центр (x, y): ";
                std::cin >> scale >> center.first >> center.second;

                if (idx < triangles.size()) {
                    triangles[idx].scale(scale, center);
                    std::cout << "Треугольник масштабирован.\n";
                }
                else {
                    std::cout << "Неверный индекс.\n";
                }
            }
            pause();
            break;
        }
        case 0: {  // Назад
            clearConsole();
            break;
        }
        default:
            std::cout << "Неверный выбор, попробуйте снова.\n";
            pause();
            break;
        }
    } while (choice != 0);
}

// Функция для главного меню, которое вызывает все другие меню
void ConsoleMenu::MainMenu() {
    int choice;
    do {
        ConsoleMenu::clearConsole();
        printMainMenuHeader();
        std::cout << "1. Меню комплексных чисел\n";
        std::cout << "2. Меню векторов 3D\n";
        std::cout << "3. Меню матриц\n";
        std::cout << "4. Меню многочленов\n";
        std::cout << "5. Меню треугольников\n";
        std::cout << "0. Выход\n";
        std::cout << "Ваш выбор: ";
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
            std::cout << "Выход из программы...\n";
            break;
        default:
            std::cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
            ConsoleMenu::pause();
            break;
        }
    } while (choice != 0);
}