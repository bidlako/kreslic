//
// Created by biond on 08.10.2022.
//

#ifndef CPP_SP_01_SHAPE_H
#define CPP_SP_01_SHAPE_H


#include "position.h"
#include <vector>
#include <string>


class Shape {
public:

    virtual ~Shape() = default;

    virtual void Translate(Position p) = 0;

    virtual void Rotate(Position p, double angle) = 0;

    virtual void Scale(Position p, double f) = 0;

    // tohle by melo bat color a thickness
    virtual std::string Vectorize(std::string const &color, int width) const = 0;

    // tohle by melo bat color a thickness
    virtual std::vector<Position> Rasterize(int width) const = 0;

};


#endif //CPP_SP_01_SHAPE_H
