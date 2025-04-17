#include "Matrix.h"
#include <iomanip>  // Для форматирования вывода с setprecision

// Конструктор для создания матрицы заданного размера
Matrix::Matrix(int r, int c) : rows(r), cols(c), data(r, std::vector<double>(c, 0.0)) {}

// Конструктор для создания матрицы из данных
Matrix::Matrix(const std::vector<std::vector<double>>& values)
    : rows(values.size()), cols(values[0].size()), data(values) {
}

// Оператор сложения матриц
Matrix Matrix::operator+(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols)  // Проверка на совпадение размеров
        throw std::invalid_argument("Matrix sizes must match for addition.");

    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = data[i][j] + other.data[i][j];  // Сложение элементов матриц
    return result;
}

// Оператор вычитания матриц
Matrix Matrix::operator-(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols)  // Проверка на совпадение размеров
        throw std::invalid_argument("Matrix sizes must match for subtraction.");

    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = data[i][j] - other.data[i][j];  // Вычитание элементов матриц
    return result;
}

// Оператор умножения матриц
Matrix Matrix::operator*(const Matrix& other) const {
    if (cols != other.rows)  // Проверка на возможность умножения
        throw std::invalid_argument("Matrix multiplication dimension mismatch.");

    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < other.cols; ++j)
            for (int k = 0; k < cols; ++k)
                result.data[i][j] += data[i][k] * other.data[k][j];  // Умножение матриц
    return result;
}

// Оператор умножения матрицы на скаляр
Matrix Matrix::operator*(double scalar) const {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = data[i][j] * scalar;  // Умножение каждого элемента на скаляр
    return result;
}

// Оператор деления матрицы на скаляр
Matrix Matrix::operator/(double scalar) const {
    if (scalar == 0)  // Проверка на деление на ноль
        throw std::invalid_argument("Zero division.");
    return *this * (1.0 / scalar);  // Деление через умножение на обратное значение
}

// Оператор сложения и присваивания
Matrix& Matrix::operator+=(const Matrix& other) {
    return *this = *this + other;  // Сложение и присваивание
}

// Оператор вычитания и присваивания
Matrix& Matrix::operator-=(const Matrix& other) {
    return *this = *this - other;  // Вычитание и присваивание
}

// Оператор умножения и присваивания
Matrix& Matrix::operator*=(double scalar) {
    return *this = *this * scalar;  // Умножение и присваивание
}

// Оператор сравнения на равенство
bool Matrix::operator==(const Matrix& other) const {
    return data == other.data;  // Сравнение данных матриц
}

// Оператор сравнения на неравенство
bool Matrix::operator!=(const Matrix& other) const {
    return !(*this == other);  // Отрицание оператора равенства
}

// Проверка на квадратность матрицы
bool Matrix::isSquare() const {
    return rows == cols;  // Квадратная матрица имеет одинаковое количество строк и столбцов
}

// Проверка на диагональность
bool Matrix::isDiagonal() const {
    if (!isSquare()) return false;  // Диагональная матрица должна быть квадратной
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if (i != j && std::abs(data[i][j]) > 1e-9)  // Если на не диагональных позициях есть элементы, отличные от 0
                return false;
    return true;
}

// Проверка на единичность
bool Matrix::isIdentity() const {
    if (!isSquare()) return false;  // Единичная матрица должна быть квадратной
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j) {
            if (i == j && std::abs(data[i][j] - 1) > 1e-9)  // Единичная матрица имеет 1 на главной диагонали
                return false;
            if (i != j && std::abs(data[i][j]) > 1e-9)  // Все остальные элементы должны быть 0
                return false;
        }
    return true;
}

// Проверка на нулевую матрицу
bool Matrix::isZero() const {
    for (auto& row : data)
        for (auto& val : row)
            if (std::abs(val) > 1e-9)  // Если найден элемент, отличный от 0
                return false;
    return true;
}

// Проверка на симметричность
bool Matrix::isSymmetric() const {
    if (!isSquare()) return false;  // Симметричная матрица должна быть квадратной
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < i; ++j)
            if (std::abs(data[i][j] - data[j][i]) > 1e-9)  // Если элементы на симметричных позициях не равны
                return false;
    return true;
}

// Проверка на верхнюю треугольную матрицу
bool Matrix::isUpperTriangular() const {
    if (!isSquare()) return false;  // Верхняя треугольная матрица должна быть квадратной
    for (int i = 1; i < rows; ++i)
        for (int j = 0; j < i; ++j)
            if (std::abs(data[i][j]) > 1e-9)  // Если элементы ниже главной диагонали не равны 0
                return false;
    return true;
}

// Проверка на нижнюю треугольную матрицу
bool Matrix::isLowerTriangular() const {
    if (!isSquare()) return false;  // Нижняя треугольная матрица должна быть квадратной
    for (int i = 0; i < rows - 1; ++i)
        for (int j = i + 1; j < cols; ++j)
            if (std::abs(data[i][j]) > 1e-9)  // Если элементы выше главной диагонали не равны 0
                return false;
    return true;
}

// Вычисление определителя матрицы (рекурсивно)
double Matrix::determinantRecursive(const std::vector<std::vector<double>>& mat) const {
    int n = mat.size();
    if (n == 1) return mat[0][0];  // Определитель 1x1 - просто элемент
    if (n == 2) return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];  // Определитель 2x2

    double det = 0.0;
    for (int i = 0; i < n; ++i) {
        std::vector<std::vector<double>> submat(n - 1, std::vector<double>(n - 1));
        for (int j = 1; j < n; ++j) {
            int colIdx = 0;
            for (int k = 0; k < n; ++k) {
                if (k == i) continue;
                submat[j - 1][colIdx++] = mat[j][k];
            }
        }
        det += (i % 2 == 0 ? 1 : -1) * mat[0][i] * determinantRecursive(submat);  // Рекурсивное вычисление
    }
    return det;
}

// Вычисление определителя матрицы
double Matrix::determinant() const {
    if (!isSquare())  // Определитель можно вычислить только для квадратных матриц
        throw std::invalid_argument("Matrix must be square to compute determinant.");
    return determinantRecursive(data);  // Рекурсивный метод
}

// Транспонирование матрицы
Matrix Matrix::transpose() const {
    Matrix result(cols, rows);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[j][i] = data[i][j];  // Перемещение элементов по диагонали
    return result;
}

// Алгебраическое дополнение (матрица миноров)
Matrix Matrix::adjugate() const {
    if (!isSquare())  // Алгебраическое дополнение только для квадратных матриц
        throw std::invalid_argument("Matrix must be square for adjugate.");
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = std::pow(-1, i + j) * determinantRecursive(getMinor(i, j));  // Алгебраическое дополнение
    return result;
}

// Получение минора (матрица без i-й строки и j-го столбца)
std::vector<std::vector<double>> Matrix::getMinor(int row, int col) const {
    std::vector<std::vector<double>> minor(rows - 1, std::vector<double>(cols - 1));

    int minorRow = 0, minorCol = 0;
    for (int i = 0; i < rows; ++i) {
        if (i == row) continue;  // Пропускаем строку, из которой удаляем элемент
        minorCol = 0;
        for (int j = 0; j < cols; ++j) {
            if (j == col) continue;  // Пропускаем столбец, из которого удаляем элемент
            minor[minorRow][minorCol++] = data[i][j];
        }
        ++minorRow;
    }

    return minor;
}


// Обратная матрица
Matrix Matrix::inverse() const {
    double det = determinant();
    if (std::abs(det) < 1e-9)  // Если определитель равен 0, обратной матрицы не существует
        throw std::invalid_argument("Matrix is singular and cannot be inverted.");
    return adjugate() / det;  // Обратная матрица = (алгебраическое дополнение) / определитель
}

// Оператор вывода матрицы
std::ostream& operator<<(std::ostream& os, const Matrix& m) {
    for (const auto& row : m.data) {
        for (const auto& val : row)
            os << std::setw(10) << std::fixed << std::setprecision(2) << val << " ";  // Форматированный вывод
        os << std::endl;
    }
    return os;
}

// Оператор ввода матрицы
std::istream& operator>>(std::istream& is, Matrix& m) {
    for (int i = 0; i < m.rows; ++i)
        for (int j = 0; j < m.cols; ++j)
            is >> m.data[i][j];  // Ввод элементов матрицы
    return is;
}