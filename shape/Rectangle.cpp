//
// Created by biond on 08.10.2022.
//

#include "Rectangle.h"

Rectangle::Rectangle(double x, double y, double width, double height) : m_p(x, y), m_w(width), m_h(height) {
    if (width <= 0 || height <= 0) {
        throw std::invalid_argument("Width and height must be positive");
    }
}

void Rectangle::Translate(Position p) {
    m_p += p;
}

// TODO: Rotace rectanglu nefunguje spravne, rotuje se pouze hlavni bod, zbytek se neotoci
void Rectangle::Rotate(Position p, double angle) {
    m_p.Rotate(p, angle);
}

void Rectangle::Scale(Position p, double f) {
    m_w *= f;
    m_h *= f;
}

std::string Rectangle::Vectorize(const std::string &color, int width) const {
    std::string result = "<rect x=\"" + std::to_string(m_p.GetX()) + "\" y=\"" + std::to_string(m_p.GetY()) +
                         "\" width=\"" + std::to_string(m_w) + "\" height=\"" + std::to_string(m_h) +
                         "\" stroke=\"" + color + "\" stroke-width=\"" + std::to_string(width) + R"(" fill="none" />)";
    return result;
}

std::vector<Position> Rectangle::Rasterize(int width) const {
    std::vector<Position> result;
    for (int i = 0; i < m_w; i++) {
        for (int j = 0; j < m_h; j++) {
            result.emplace_back(m_p.GetX() + i, m_p.GetY() + j);
        }
    }
    return result;
}



