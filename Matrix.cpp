#include "Matrix.h"
#include <iomanip>  // ��� �������������� ������ � setprecision

// ����������� ��� �������� ������� ��������� �������
Matrix::Matrix(int r, int c) : rows(r), cols(c), data(r, std::vector<double>(c, 0.0)) {}

// ����������� ��� �������� ������� �� ������
Matrix::Matrix(const std::vector<std::vector<double>>& values)
    : rows(values.size()), cols(values[0].size()), data(values) {
}

// �������� �������� ������
Matrix Matrix::operator+(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols)  // �������� �� ���������� ��������
        throw std::invalid_argument("Matrix sizes must match for addition.");

    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = data[i][j] + other.data[i][j];  // �������� ��������� ������
    return result;
}

// �������� ��������� ������
Matrix Matrix::operator-(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols)  // �������� �� ���������� ��������
        throw std::invalid_argument("Matrix sizes must match for subtraction.");

    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = data[i][j] - other.data[i][j];  // ��������� ��������� ������
    return result;
}

// �������� ��������� ������
Matrix Matrix::operator*(const Matrix& other) const {
    if (cols != other.rows)  // �������� �� ����������� ���������
        throw std::invalid_argument("Matrix multiplication dimension mismatch.");

    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < other.cols; ++j)
            for (int k = 0; k < cols; ++k)
                result.data[i][j] += data[i][k] * other.data[k][j];  // ��������� ������
    return result;
}

// �������� ��������� ������� �� ������
Matrix Matrix::operator*(double scalar) const {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = data[i][j] * scalar;  // ��������� ������� �������� �� ������
    return result;
}

// �������� ������� ������� �� ������
Matrix Matrix::operator/(double scalar) const {
    if (scalar == 0)  // �������� �� ������� �� ����
        throw std::invalid_argument("Zero division.");
    return *this * (1.0 / scalar);  // ������� ����� ��������� �� �������� ��������
}

// �������� �������� � ������������
Matrix& Matrix::operator+=(const Matrix& other) {
    return *this = *this + other;  // �������� � ������������
}

// �������� ��������� � ������������
Matrix& Matrix::operator-=(const Matrix& other) {
    return *this = *this - other;  // ��������� � ������������
}

// �������� ��������� � ������������
Matrix& Matrix::operator*=(double scalar) {
    return *this = *this * scalar;  // ��������� � ������������
}

// �������� ��������� �� ���������
bool Matrix::operator==(const Matrix& other) const {
    return data == other.data;  // ��������� ������ ������
}

// �������� ��������� �� �����������
bool Matrix::operator!=(const Matrix& other) const {
    return !(*this == other);  // ��������� ��������� ���������
}

// �������� �� ������������ �������
bool Matrix::isSquare() const {
    return rows == cols;  // ���������� ������� ����� ���������� ���������� ����� � ��������
}

// �������� �� ��������������
bool Matrix::isDiagonal() const {
    if (!isSquare()) return false;  // ������������ ������� ������ ���� ����������
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if (i != j && std::abs(data[i][j]) > 1e-9)  // ���� �� �� ������������ �������� ���� ��������, �������� �� 0
                return false;
    return true;
}

// �������� �� �����������
bool Matrix::isIdentity() const {
    if (!isSquare()) return false;  // ��������� ������� ������ ���� ����������
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j) {
            if (i == j && std::abs(data[i][j] - 1) > 1e-9)  // ��������� ������� ����� 1 �� ������� ���������
                return false;
            if (i != j && std::abs(data[i][j]) > 1e-9)  // ��� ��������� �������� ������ ���� 0
                return false;
        }
    return true;
}

// �������� �� ������� �������
bool Matrix::isZero() const {
    for (auto& row : data)
        for (auto& val : row)
            if (std::abs(val) > 1e-9)  // ���� ������ �������, �������� �� 0
                return false;
    return true;
}

// �������� �� ��������������
bool Matrix::isSymmetric() const {
    if (!isSquare()) return false;  // ������������ ������� ������ ���� ����������
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < i; ++j)
            if (std::abs(data[i][j] - data[j][i]) > 1e-9)  // ���� �������� �� ������������ �������� �� �����
                return false;
    return true;
}

// �������� �� ������� ����������� �������
bool Matrix::isUpperTriangular() const {
    if (!isSquare()) return false;  // ������� ����������� ������� ������ ���� ����������
    for (int i = 1; i < rows; ++i)
        for (int j = 0; j < i; ++j)
            if (std::abs(data[i][j]) > 1e-9)  // ���� �������� ���� ������� ��������� �� ����� 0
                return false;
    return true;
}

// �������� �� ������ ����������� �������
bool Matrix::isLowerTriangular() const {
    if (!isSquare()) return false;  // ������ ����������� ������� ������ ���� ����������
    for (int i = 0; i < rows - 1; ++i)
        for (int j = i + 1; j < cols; ++j)
            if (std::abs(data[i][j]) > 1e-9)  // ���� �������� ���� ������� ��������� �� ����� 0
                return false;
    return true;
}

// ���������� ������������ ������� (����������)
double Matrix::determinantRecursive(const std::vector<std::vector<double>>& mat) const {
    int n = mat.size();
    if (n == 1) return mat[0][0];  // ������������ 1x1 - ������ �������
    if (n == 2) return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];  // ������������ 2x2

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
        det += (i % 2 == 0 ? 1 : -1) * mat[0][i] * determinantRecursive(submat);  // ����������� ����������
    }
    return det;
}

// ���������� ������������ �������
double Matrix::determinant() const {
    if (!isSquare())  // ������������ ����� ��������� ������ ��� ���������� ������
        throw std::invalid_argument("Matrix must be square to compute determinant.");
    return determinantRecursive(data);  // ����������� �����
}

// ���������������� �������
Matrix Matrix::transpose() const {
    Matrix result(cols, rows);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[j][i] = data[i][j];  // ����������� ��������� �� ���������
    return result;
}

// �������������� ���������� (������� �������)
Matrix Matrix::adjugate() const {
    if (!isSquare())  // �������������� ���������� ������ ��� ���������� ������
        throw std::invalid_argument("Matrix must be square for adjugate.");
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = std::pow(-1, i + j) * determinantRecursive(getMinor(i, j));  // �������������� ����������
    return result;
}

// ��������� ������ (������� ��� i-� ������ � j-�� �������)
std::vector<std::vector<double>> Matrix::getMinor(int row, int col) const {
    std::vector<std::vector<double>> minor(rows - 1, std::vector<double>(cols - 1));

    int minorRow = 0, minorCol = 0;
    for (int i = 0; i < rows; ++i) {
        if (i == row) continue;  // ���������� ������, �� ������� ������� �������
        minorCol = 0;
        for (int j = 0; j < cols; ++j) {
            if (j == col) continue;  // ���������� �������, �� �������� ������� �������
            minor[minorRow][minorCol++] = data[i][j];
        }
        ++minorRow;
    }

    return minor;
}


// �������� �������
Matrix Matrix::inverse() const {
    double det = determinant();
    if (std::abs(det) < 1e-9)  // ���� ������������ ����� 0, �������� ������� �� ����������
        throw std::invalid_argument("Matrix is singular and cannot be inverted.");
    return adjugate() / det;  // �������� ������� = (�������������� ����������) / ������������
}

// �������� ������ �������
std::ostream& operator<<(std::ostream& os, const Matrix& m) {
    for (const auto& row : m.data) {
        for (const auto& val : row)
            os << std::setw(10) << std::fixed << std::setprecision(2) << val << " ";  // ��������������� �����
        os << std::endl;
    }
    return os;
}

// �������� ����� �������
std::istream& operator>>(std::istream& is, Matrix& m) {
    for (int i = 0; i < m.rows; ++i)
        for (int j = 0; j < m.cols; ++j)
            is >> m.data[i][j];  // ���� ��������� �������
    return is;
}