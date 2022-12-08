//
// Created by biond on 08.10.2022.
//

#ifndef CPP_SP_01_CIRCLE_H
#define CPP_SP_01_CIRCLE_H

#include "shape.h"


class Circle : public Shape {
public:
    Circle(double x, double y, double r);

    void Translate(Position p) override;

    void Rotate(Position p, double angle) override;

    void Scale(Position p, double f) override;

    [[nodiscard]] std::string Vectorize(std::string const &color, int width) const override;

    [[nodiscard]] std::vector<Position> Rasterize(int width) const override;

private:
    Position m_p;
    double m_r;
};


#endif //CPP_SP_01_CIRCLE_H
