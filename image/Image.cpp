//
// Created by biond on 06.10.2022.
//

#include "Image.h"

Image::Image(int width, int height) : mWidth(width), mHeight(height), mMatrix(width, height) {}

Image::Image(const std::vector<std::vector<int>> &matrix) : mWidth((int) matrix[0].size()),
                                                            mHeight((int) matrix.size()), mMatrix(matrix) {}

void Image::draw_line(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int d = 2 * dy - dx;
    int dE = 2 * dy;
    int dNE = 2 * (dy - dx);
    int x = x1;
    int y = y1;
    mMatrix.Get_Matrix()[x][y] = 1;
    while (x < x2) {
        if (d <= 0) {
            d += dE;
            x++;
        } else {
            d += dNE;
            x++;
            y++;
        }
        mMatrix.Get_Matrix()[x][y] = 1;
    }
}



