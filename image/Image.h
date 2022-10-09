//
// Created by biond on 06.10.2022.
//

#ifndef CPP_SP_01_IMAGE_H
#define CPP_SP_01_IMAGE_H


#include <vector>
#include "../matrix/Matrix.h"

class Image {
public:
    Image(int rows, int cols);

    Image(const std::vector<std::vector<int>> &matrix);

    virtual void dump(std::string &filename) = 0;

    void Translate(double x, double y);

    void Scale(double x, double y, double f);

    void Rotate(double x, double y, double angle);

    void draw_line(int x1, int y1, int x2, int y2);

    explicit operator std::string() const;

private:
    unsigned int mWidth;
    unsigned int mHeight;
    Matrix mMatrix;

};


#endif //CPP_SP_01_IMAGE_H
