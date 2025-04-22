#include "Matrix.h"
#include <iomanip>      // Для форматирования вывода (setw, setprecision)
#include <stdexcept>    // Для стандартных исключений (invalid_argument и др.)
#include <limits>
#include <string>

// ========================= КОНСТРУКТОРЫ =========================

// Конструктор: создаёт матрицу заданного размера (r × c), инициализированную нулями
Matrix::Matrix(int r, int c) : rows(r), cols(c), data(r, std::vector<double>(c, 0.0)) {
    if (r <= 0 || c <= 0)
        throw std::invalid_argument("Matrix dimensions must be positive.");  // Размеры должны быть положительными
}

// Конструктор: инициализация матрицы из двумерного вектора
Matrix::Matrix(const std::vector<std::vector<double>>& values)
    : rows(values.size()), cols(values[0].size()), data(values) {
    if (rows <= 0 || cols <= 0)
        throw std::invalid_argument("Matrix dimensions must be positive.");

    // Проверка: все строки должны иметь одинаковое количество столбцов
    for (size_t i = 1; i < values.size(); ++i)
        if (values[i].size() != cols)
            throw std::invalid_argument("All rows must have the same number of columns.");
}

// ========================= АРИФМЕТИКА С МАТРИЦАМИ =========================

// Оператор сложения: A + B
Matrix Matrix::operator+(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols)
        throw std::invalid_argument("Matrix sizes must match for addition.");

    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = data[i][j] + other.data[i][j];

    return result;
}

// Оператор вычитания: A - B
Matrix Matrix::operator-(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols)
        throw std::invalid_argument("Matrix sizes must match for subtraction.");

    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = data[i][j] - other.data[i][j];

    return result;
}

// Оператор умножения: A * B (по правилу умножения матриц)
Matrix Matrix::operator*(const Matrix& other) const {
    if (cols != other.rows)
        throw std::invalid_argument("Matrix multiplication dimension mismatch.");

    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < other.cols; ++j)
            for (int k = 0; k < cols; ++k)
                result.data[i][j] += data[i][k] * other.data[k][j];

    return result;
}

// ========================= АРИФМЕТИКА СО СКАЛЯРОМ =========================

// Оператор умножения на скаляр: A * λ
Matrix Matrix::operator*(double scalar) const {
    if (std::isnan(scalar))
        throw std::invalid_argument("Scalar value cannot be NaN.");

    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = data[i][j] * scalar;

    return result;
}

// Оператор деления на скаляр: A / λ
Matrix Matrix::operator/(double scalar) const {
    if (scalar == 0.0)
        throw std::invalid_argument("Zero division.");
    if (std::isnan(scalar))
        throw std::invalid_argument("Scalar value cannot be NaN.");

    return *this * (1.0 / scalar);
}

// ========================= ПРИСВАИВАНИЕ =========================
Matrix& Matrix::operator+=(const Matrix& other) {
    *this = *this + other;
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {
    *this = *this - other;
    return *this;
}

Matrix& Matrix::operator*=(double scalar) {
    *this = *this * scalar;
    return *this;
}

// ========================= СРАВНЕНИЯ =========================

bool Matrix::operator==(const Matrix& other) const {
    return data == other.data;
}

bool Matrix::operator!=(const Matrix& other) const {
    return !(*this == other);
}

// ========================= ТИП МАТРИЦЫ =========================

// Квадратная ли матрица?
bool Matrix::isSquare() const {
    return rows == cols;
}

// Диагональная ли матрица?
bool Matrix::isDiagonal() const {
    if (!isSquare()) return false;

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if (i != j && std::abs(data[i][j]) > 1e-9)
                return false;

    return true;
}

// Единичная ли матрица?
bool Matrix::isIdentity() const {
    if (!isSquare()) return false;

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j) {
            if ((i == j && std::abs(data[i][j] - 1.0) > 1e-9) ||
                (i != j && std::abs(data[i][j]) > 1e-9))
                return false;
        }

    return true;
}

// Нулевая ли матрица?
bool Matrix::isZero() const {
    for (const auto& row : data)
        for (double val : row)
            if (std::abs(val) > 1e-9)
                return false;

    return true;
}

// Симметричная ли матрица (Aᵀ = A)?
bool Matrix::isSymmetric() const {
    if (!isSquare()) return false;

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < i; ++j)
            if (std::abs(data[i][j] - data[j][i]) > 1e-9)
                return false;

    return true;
}

// Верхняя треугольная матрица (все элементы ниже главной диагонали равны 0)
bool Matrix::isUpperTriangular() const {
    if (!isSquare()) return false;

    for (int i = 1; i < rows; ++i)
        for (int j = 0; j < i; ++j)
            if (std::abs(data[i][j]) > 1e-9)
                return false;

    return true;
}

// Нижняя треугольная матрица (все элементы выше главной диагонали равны 0)
bool Matrix::isLowerTriangular() const {
    if (!isSquare()) return false;

    for (int i = 0; i < rows - 1; ++i)
        for (int j = i + 1; j < cols; ++j)
            if (std::abs(data[i][j]) > 1e-9)
                return false;

    return true;
}

// ========================= ДОПОЛНИТЕЛЬНЫЕ СВОЙСТВА =========================

// Рекурсивное вычисление определителя (разложение по первой строке)
double Matrix::determinantRecursive(const std::vector<std::vector<double>>& mat) const {
    int n = mat.size();
    if (n == 1) return mat[0][0];  // Базовый случай для матрицы 1x1
    if (n == 2)                    // Базовый случай для матрицы 2x2
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];

    double det = 0.0;
    for (int i = 0; i < n; ++i) {
        // Получаем минор текущего элемента первой строки
        auto minor = getMinorFromMatrix(mat, 0, i);

        // Разложение определителя по элементам первой строки
        double sign = (i % 2 == 0) ? 1.0 : -1.0;
        det += sign * mat[0][i] * determinantRecursive(minor);
    }
    return det;
}

// Получение минора текущей матрицы по индексу строки и столбца
std::vector<std::vector<double>> Matrix::getMinor(int row, int col) const {
    return getMinorFromMatrix(data, row, col);
}

// Получение минора произвольной матрицы (удаление строки и столбца)
std::vector<std::vector<double>> Matrix::getMinorFromMatrix(const std::vector<std::vector<double>>& mat, int row, int col) const {
    int n = mat.size();
    std::vector<std::vector<double>> minor;
    minor.reserve(n - 1);

    for (int i = 0; i < n; ++i) {
        if (i == row) continue;
        std::vector<double> minorRow;
        minorRow.reserve(n - 1);
        for (int j = 0; j < n; ++j) {
            if (j == col) continue;
            minorRow.push_back(mat[i][j]);
        }
        minor.push_back(std::move(minorRow));
    }

    return minor;
}

// Вычисление определителя текущей матрицы
double Matrix::determinant() const {
    if (!isSquare())
        throw std::invalid_argument("Matrix must be square to compute determinant.");

    return determinantRecursive(data);
}

// Получение транспонированной матрицы (Aᵀ)
Matrix Matrix::transpose() const {
    Matrix result(cols, rows);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[j][i] = data[i][j];

    return result;
}

// Алгебраическое дополнение (матрица кофакторов)
Matrix Matrix::adjugate() const {
    if (!isSquare())
        throw std::invalid_argument("Matrix must be square for adjugate.");

    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = std::pow(-1, i + j) * determinantRecursive(getMinor(i, j));

    return result.transpose();
}

// Получение обратной матрицы: A⁻¹ = A* / det(A)
Matrix Matrix::inverse() const {
    double det = determinant();
    if (std::abs(det) < 1e-9)
        throw std::invalid_argument("Matrix is singular and cannot be inverted.");

    return adjugate() / det;
}

// ========================= ВВОД/ВЫВОД =========================

// Форматированный вывод матрицы в поток
std::ostream& operator<<(std::ostream& os, const Matrix& m) {
    os << std::fixed << std::setprecision(2);
    for (const auto& row : m.data) {
        os << "| ";
        for (const auto& val : row) {
            os << std::setw(8) << val << " ";
        }
        os << "|\n";
    }
    return os;
}

// Ввод матрицы из потока
std::istream& operator>>(std::istream& is, Matrix& m) {
    for (int i = 0; i < m.rows; ++i) {
        for (int j = 0; j < m.cols; ++j) {
            if (!(is >> m.data[i][j])) {
                // Обработка ошибки: сброс состояния потока и очистка ввода
                is.clear();
                is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw std::runtime_error(
                    "Ошибка ввода: элемент матрицы должен быть числом (позиция "
                    + std::to_string(i) + "," + std::to_string(j) + ").");
            }
        }
    }
    return is;
}
