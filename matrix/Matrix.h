//
// Created by biond on 06.10.2022.
//

#ifndef CPP_SP_01_MATRIX_H
#define CPP_SP_01_MATRIX_H


#include <vector>
#include <iostream>

class Matrix {
public:
    Matrix(int rows, int cols);

    Matrix(const std::vector<std::vector<int>> &matrix);

    auto Get_Matrix() const { return mMatrix; }

    Matrix operator*(const Matrix &other) const;

    explicit operator std::string() const;


private:
    unsigned int mColumns;
    unsigned int mRows;
    std::vector<std::vector<int>> mMatrix;

};


#endif //CPP_SP_01_MATRIX_H
