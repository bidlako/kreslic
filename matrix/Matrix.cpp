//
// Created by biond on 06.10.2022.
//

#include <stdexcept>
#include <memory>
#include "Matrix.h"

Matrix::Matrix(int rows, int cols) : mColumns(cols), mRows(rows) {
    mMatrix = std::vector<std::vector<int>>(rows, std::vector<int>(cols, 0));
}

Matrix::Matrix(const std::vector<std::vector<int>> &matrix) : mColumns((int) matrix[0].size()),
                                                              mRows((int) matrix.size()), mMatrix(matrix) {}

Matrix Matrix::operator*(const Matrix &other) const {
    if (mColumns != other.mRows) {
        throw std::invalid_argument("Matrix dimensions do not match");
    }
    std::vector<std::vector<int>> result(mRows, std::vector<int>(other.mColumns, 0));
    for (int i = 0; i < mRows; i++) {
        for (int j = 0; j < other.mColumns; j++) {
            for (int k = 0; k < mColumns; k++) {
                result[i][j] += mMatrix[i][k] * other.mMatrix[k][j];
            }
        }
    }
    return {result};
}

Matrix::operator std::string() const {
    std::string result;
    for (int i = 0; i < mRows; i++) {
        for (int j = 0; j < mColumns; j++) {
            result += std::to_string(mMatrix[i][j]) + " ";
        }
        result += "\n";
    }
    return result;
}

