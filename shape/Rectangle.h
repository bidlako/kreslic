//
// Created by biond on 08.10.2022.
//

#ifndef CPP_SP_01_RECTANGLE_H
#define CPP_SP_01_RECTANGLE_H

#include "Shape.h"
#include "Line.h"
#include <iostream>
#include "../position/Position.h"

class Rectangle : public Shape {
public:
    Rectangle(double x, double y, double width, double height);

    void Translate(Position p) override;

    void Rotate(Position p, double angle) override;

    void Scale(Position p, double f) override;

    std::string Vectorize(std::string const &color, int width) const override;

    std::vector<Position> Rasterize(int width) const override;

private:
    Line m_a;
    Line m_b;
    Line m_c;
    Line m_d;
//    Position m_p;
    double m_w;
    double m_h;
};


#endif //CPP_SP_01_RECTANGLE_H
