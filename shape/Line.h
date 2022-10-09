//
// Created by biond on 08.10.2022.
//

#ifndef CPP_SP_01_LINE_H
#define CPP_SP_01_LINE_H

#include "Shape.h"
#include "../canvas/Canvas.h"
#include "../position/Position.h"

class Line : public Shape {
public:

    Line() = default;

    Line(double x1, double y1, double x2, double y2);

    void Translate(Position p) override;

    void Rotate(Position p, double angle) override;

    void Scale(Position p, double f) override;

    std::string Vectorize(std::string const &color, int width) const override;

    std::vector<Position> Rasterize(int width) const override;

private:
    Position m_x;
    Position m_y;
};


#endif //CPP_SP_01_LINE_H
