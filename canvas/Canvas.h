//
// Created by biond on 08.10.2022.
//

#ifndef CPP_SP_01_CANVAS_H
#define CPP_SP_01_CANVAS_H

#include "../shape/Shape.h"
#include <vector>
#include <memory>

constexpr uint8_t BLACK = 0;
constexpr uint8_t WHITE = 255;

class Canvas {
public:
    Canvas() = default;

    Canvas(int width, int height);

    void Draw(std::unique_ptr<Shape> shape);

    void Translate(double x, double y) const;

    void Scale(double x, double y, double f) const;

    void Rotate(double x, double y, double angle) const;

    void Export_to_svg(std::string const &filename) const;

    void Export_to_pgm(std::string const &filename) const;

private:
    int m_width;
    int m_height;
    std::vector<std::unique_ptr<Shape>> m_shapes;
};


#endif //CPP_SP_01_CANVAS_H
