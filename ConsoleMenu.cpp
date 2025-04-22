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
        std::cout << "5. Транспонирование матрицы и вычисление её определителя и обратной матрицы\n";
        std::cout << "6. Проверка свойств матрицы\n";
        std::cout << "7. Сравнение матриц на равенство и неравенство\n";
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
                    std::cout << i + 1 << ". " << "\n" << matrices[i] << "\n";
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
                size_t index1, index2;
                std::cout << "Выберите первую матрицу (1 - " << matrices.size() << "): ";
                std::cin >> index1;
                std::cout << "Выберите вторую матрицу(1 - " << matrices.size() << "): ";
                std::cin >> index2;

                if (index1 > 0 && index1 <= matrices.size() && index2 > 0 && index2 <= matrices.size()) {
                    const Matrix& a = matrices[index1 - 1];
                    const Matrix& b = matrices[index2 - 1];
                    std::cout << "Первая матрица:" << "\n" << a << "\n";
                    std::cout << "Вторая матрица:" << "\n" << b << "\n";
                    std::cout << "Сложение:" << "\n";
                    std::cout << a << " + " << "\n" << b << " = " << "\n" << (a + b) << "\n";
                    std::cout << "Вычитание:" << "\n";
                    std::cout << a << " - " << "\n" << b << " = " << "\n" << (a - b) << "\n";
                    std::cout << "Умножение:" << "\n";
                    std::cout << a << " * " << "\n" << b << " = " << "\n" << (a * b) << "\n";
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
                size_t index;
                double scalar;
                std::cout << "Выберите матрицу (1 - " << matrices.size() << "): ";
                std::cin >> index;
                std::cout << "Введите скаляр: ";
                std::cin >> scalar;

                if (index > 0 && index <= matrices.size()) {
                    const Matrix& m = matrices[index - 1];
                    std::cout << "Матрица:" << "\n" << m << "\n";
                    std::cout << "Скаляр:" << scalar << "\n";
                    std::cout << "\n" << m << " * " << scalar << " = " << "\n" << (m * scalar) << "\n";
                }
                else {
                    std::cout << "Неверный индекс.\n";
                }
            }
            pause();
            break;
        }
        case 5: {  // Транспонирование матрицы и вычисление её определителя и обратной матрицы
            clearConsole();
            if (matrices.empty()) {
                std::cout << "Нет матриц.\n";
            }
            else {
                size_t index;
                std::cout << "Выберите матрицу (1 - " << matrices.size() << "): ";
                std::cin >> index;
                if (index > 0 && index <= matrices.size()) {
                    const Matrix& m = matrices[index - 1];
                    std::cout << "Матрица:" << "\n" << m << "\n";
                    std::cout << "Результат транспонирования:\n" << m.transpose() << "\n";
                    std::cout << "Определитель матрицы: " << m.determinant() << "\n";

                    try {
                        std::cout << "Обратная матрица:\n" << m.inverse() << "\n";
                        std::cout << "Произведение исходной и обратной = " << "\n" << (m * m.inverse()) << "\n";

                    }
                    catch (const std::invalid_argument& e) {
                        std::cout << "Ошибка: " << e.what() << "\n";
                    }
                }
                else {
                    std::cout << "Неверный индекс.\n";
                }
            }
            pause();
            break;
        }
        case 6: {  // Проверка свойств матрицы
            clearConsole();
            if (matrices.empty()) {
                std::cout << "Нет матриц.\n";
            }
            else {
                size_t index;
                std::cout << "Выберите матрицу (1 - " << matrices.size() << "): ";
                std::cin >> index;

                if (index > 0 && index <= matrices.size()) {
                    const Matrix& m = matrices[index - 1];
                    std::cout << "Матрица:" << "\n" << m << "\n";
                    std::cout << "Является ли матрица квадратной? " << (m.isSquare() ? "Да" : "Нет") << "\n";
                    std::cout << "Является ли матрица диагональной? " << (m.isDiagonal() ? "Да" : "Нет") << "\n";
                    std::cout << "Является ли матрица единичной? " << (m.isIdentity() ? "Да" : "Нет") << "\n";
                    std::cout << "Является ли матрица нулевой? " << (m.isZero() ? "Да" : "Нет") << "\n";
                    std::cout << "Является ли матрица симметричной? " << (m.isSymmetric() ? "Да" : "Нет") << "\n";
                    std::cout << "Является ли матрица верхнетреугольной? " << (m.isUpperTriangular() ? "Да" : "Нет") << "\n";
                    std::cout << "Является ли матрица нижнетреугольной? " << (m.isLowerTriangular() ? "Да" : "Нет") << "\n";
                }
                else {
                    std::cout << "Неверный индекс.\n";
                }
            }
            pause();
            break;
        }
        case 7: {  // Сравнение матриц на равенство и неравенство
            clearConsole();
            if (matrices.size() < 2) {
                std::cout << "Создайте минимум две матрицы для сравнения.\n";
            }
            else {
                size_t index1, index2;
                std::cout << "Выберите первую матрицу (1 - " << matrices.size() << "): ";
                std::cin >> index1;
                std::cout << "Выберите вторую матрицу(1 - " << matrices.size() << "): ";
                std::cin >> index2;

                if (index1 > 0 && index1 <= matrices.size() && index2 > 0 && index2 <= matrices.size()) {
                    const Matrix& a = matrices[index1 - 1];
                    const Matrix& b = matrices[index2 - 1];
                    std::cout << "Первая матрица:" << "\n" << a << "\n";
                    std::cout << "Вторая матрица:" << "\n" << b << "\n";

                    if (a == b) {
                        std::cout << "Матрицы равны.\n";
                    }
                    else {
                        std::cout << "Матрицы не равны.\n";
                    }
                }
                else {
                    std::cout << "Неверные индексы.\n";
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
        std::cout << "7. Вычисление значения полинома для заданного аргумента\n";  // Новый пункт
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
            std::cin >> p;  // Используем перегрузку оператора >> для ввода полинома

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
                size_t index1, index2;
                std::cout << "Выберите первый полином (1 - " << polynomials.size() << "): ";
                std::cin >> index1;
                std::cout << "Выберите второй полином (1 - " << polynomials.size() << "): ";
                std::cin >> index2;

                if (index1 > 0 && index1 <= polynomials.size() && index2 > 0 && index2 <= polynomials.size()) {
                    const Polynomial& a = polynomials[index1 - 1];
                    const Polynomial& b = polynomials[index2 - 1];
                    std::cout << "Первый полином:\n" << a << "\n";
                    std::cout << "Второй полином:\n" << b << "\n";
                    std::cout << "Сложение:\n" << a << " + " << b << " = " << (a + b) << "\n";
                    std::cout << "Вычитание:\n" << a << " - " << b << " = " << (a - b) << "\n";
                    std::cout << "Умножение:\n" << a << " * " << b << " = " << (a * b) << "\n";
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
                size_t index;
                double scalar;
                std::cout << "Выберите полином (1 - " << polynomials.size() << "): ";
                std::cin >> index;
                std::cout << "Введите скаляр: ";
                std::cin >> scalar;

                if (index > 0 && index <= polynomials.size()) {
                    const Polynomial& p = polynomials[index - 1];
                    std::cout << "Полином:\n" << p << "\n";
                    std::cout << "Скаляр: " << scalar << "\n";
                    std::cout << p << " * " << scalar << " = " << (p * scalar) << "\n";
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
                size_t index;
                std::cout << "Выберите полином (1 - " << polynomials.size() << "): ";
                std::cin >> index;
                if (index > 0 && index <= polynomials.size()) {
                    const Polynomial& p = polynomials[index - 1];
                    std::cout << "Производная полинома:\n" << p.derivative() << "\n";
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
                size_t index;
                std::cout << "Выберите полином (1 - " << polynomials.size() << "): ";
                std::cin >> index;
                if (index > 0 && index <= polynomials.size()) {
                    const Polynomial& p = polynomials[index - 1];
                    std::cout << "Интеграл полинома:\n" << p.integrate() << "\n";
                }
                else {
                    std::cout << "Неверный индекс.\n";
                }
            }
            pause();
            break;
        }
        case 7: {  // Вычисление значения полинома для заданного аргумента
            clearConsole();
            if (polynomials.empty()) {
                std::cout << "Нет полиномов.\n";
            }
            else {
                size_t index;
                double arg;
                std::cout << "Выберите полином (1 - " << polynomials.size() << "): ";
                std::cin >> index;
                std::cout << "Введите значение аргумента: ";
                std::cin >> arg;

                if (index > 0 && index <= polynomials.size()) {
                    const Polynomial& p = polynomials[index - 1];
                    double result = p.evaluate(arg);
                    std::cout << "Значение полинома " << p << " при x = " << arg << " равно " << result << "\n";
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
    std::vector<Triangle> triangles;  // Vector to store triangles
    int choice;  // Variable for menu selection

    do {
        clearConsole();
        printTriangleMenuHeader();
        std::cout << "1. Создать новый треугольник\n";
        std::cout << "2. Показать все треугольники\n";
        std::cout << "3. Расчёт периметра треугольника\n";
        std::cout << "4. Расчёт площади треугольника\n";
        std::cout << "5. Проверка типа треугольника\n";
        std::cout << "6. Проверка на подобие треугольников\n";
        std::cout << "7. Треугольник с максимальной площадью\n";
        std::cout << "8. Сдвиг треугольника\n";
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
        case 1: {  // Create a new triangle
            clearConsole();
            Triangle t;
            std::cin >> t;
            triangles.push_back(t);
            std::cout << "Треугольник создан!\n";
            pause();
            break;
        }
        case 2: {  // Show all triangles
            clearConsole();
            if (triangles.empty()) {
                std::cout << "Нет созданных треугольников.\n";
            }
            else {
                std::cout << "Список треугольников:\n";
                for (size_t i = 0; i < triangles.size(); ++i) {
                    std::cout << i + 1 << ". Треугольник " << i + 1 << ": " << triangles[i] << "\n";
                }
            }
            pause();
            break;
        }
        case 3: {  // Calculate perimeter
            clearConsole();
            if (triangles.empty()) {
                std::cout << "Нет треугольников.\n";
            }
            else {
                size_t idx;
                std::cout << "Выберите треугольник (1 - " << triangles.size() << "): ";
                std::cin >> idx;
                if (idx > 0 && idx <= triangles.size()) {
                    Triangle t = triangles[idx - 1];
                    std::cout << t << "\n";
                    std::cout << "Периметр: " << t.perimeter() << "\n";
                }
                else {
                    std::cout << "Неверный индекс.\n";
                }
            }
            pause();
            break;
        }
        case 4: {  // Calculate area
            clearConsole();
            if (triangles.empty()) {
                std::cout << "Нет треугольников.\n";
            }
            else {
                size_t idx;
                std::cout << "Выберите треугольник (1 - " << triangles.size() << "): ";
                std::cin >> idx;
                if (idx > 0 && idx <= triangles.size()) {
                    Triangle t = triangles[idx - 1];
                    std::cout << t << "\n";
                    std::cout << "Площадь: " << t.area() << "\n";
                }
                else {
                    std::cout << "Неверный индекс.\n";
                }
            }
            pause();
            break;
        }
        case 5: {  // Check triangle type
            clearConsole();
            if (triangles.empty()) {
                std::cout << "Нет треугольников.\n";
            }
            else {
                size_t idx;
                std::cout << "Выберите треугольник (1 - " << triangles.size() << "): ";
                std::cin >> idx;
                if (idx > 0 && idx <= triangles.size()) {
                    Triangle t = triangles[idx - 1];
                    std::cout << t << "\n";
                    if (t.isEquilateral()) {
                        std::cout << "Это равносторонний треугольник.\n";
                    }
                    else {
                        std::cout << "Это не равносторонний треугольник.\n";
                    }
                    if (t.isIsosceles()) {
                        std::cout << "Это равнобедренный треугольник.\n";
                    }
                    else {
                        std::cout << "Это не равнобедренный треугольник.\n";
                    }
                    if (t.isRight()) {
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
        case 6: {  // Check for similarity of triangles
            clearConsole();
            if (triangles.empty()) {
                std::cout << "Нет треугольников.\n";
            }
            else {
                size_t idx1, idx2;
                std::cout << "Выберите первый треугольник (1 - " << triangles.size() << "): ";
                std::cin >> idx1;
                std::cout << "Выберите второй треугольник (1 - " << triangles.size() << "): ";
                std::cin >> idx2;
                if (idx1 > 0 && idx1 <= triangles.size() && idx2 > 0 && idx2 <= triangles.size()) {
                    Triangle t1 = triangles[idx1 - 1];
                    Triangle t2 = triangles[idx2 - 1];
                    std::cout << t1 << "\n";
                    std::cout << t2 << "\n";
                    if (t1.isSimilarTo(t2)) {
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
        case 7: {
            clearConsole();
            if (triangles.empty()) {
                std::cout << "Нет треугольников.\n";
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

                std::cout << "Треугольник с наибольшей площадью:\n";
                std::cout << maxIndex + 1 << ". " << triangles[maxIndex] << " — Площадь: " << maxArea << "\n\n";
                std::cout << "Площади всех треугольников:\n";
                for (size_t i = 0; i < triangles.size(); ++i) {
                    std::cout << i + 1 << ". " << triangles[i] << " — Площадь: " << triangles[i].area() << "\n";
                }
            }
            pause();
            break;
        }
        case 8: {  // Translate triangle
            clearConsole();
            if (triangles.empty()) {
                std::cout << "Нет треугольников.\n";
            }
            else {
                size_t idx;
                std::pair<double, double> shift;
                std::cout << "Выберите треугольник (1 - " << triangles.size() << "): ";
                std::cin >> idx;
                if (idx > 0 && idx <= triangles.size()) {
                    Triangle t = triangles[idx - 1];
                    std::cout << t << "\n";
                    std::cout << "Введите сдвиг по осям (dx dy): ";
                    std::cin >> shift.first >> shift.second;
                    t.translate(shift.first, shift.second);
                    std::cout << "Треугольник сдвинут.\n";
                }
                else {
                    std::cout << "Неверный индекс.\n";
                }
            }
            pause();
            break;
        }
        case 0: {
            break;
        }
        default: {
            std::cout << "Неверный выбор. Попробуйте снова.\n";
            pause();
            break;
        }
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