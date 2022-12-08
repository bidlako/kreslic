//
// Created by biond on 08.10.2022.
//

#include <stdexcept>
#include "../include/circle.h"
#include "../include/position.h"

Circle::Circle(double x, double y, double r) : m_p(x, y), m_r(r) {
    if (r <= 0) {
        throw std::invalid_argument("Radius must be positive");
    }
}

void Circle::Translate(Position p) {
    m_p += p;
}

void Circle::Rotate(Position p, double angle) {
    m_p.Rotate(p, angle);
}


void Circle::Scale(Position p, double f) {
    m_p *= f;
    m_r *= f;
}

std::string Circle::Vectorize(const std::string &color, int width) const {
    std::string result = "<circle cx=\"" + std::to_string(m_p.GetX()) + "\" cy=\"" + std::to_string(m_p.GetY()) +
                         "\" r=\"" + std::to_string(m_r) + "\" stroke=\"" + color + "\" stroke-width=\"" +
                         std::to_string(width) + R"(" fill="none" />)";
    return result;
}

std::vector<Position> Circle::Rasterize(int width) const {
    std::vector<Position> result;
    for (int i = 0; i < m_r; i++) {
        for (int j = 0; j < m_r; j++) {
            if (i * i + j * j <= m_r * m_r && (i + 1) * (i + 1) + j * j > m_r * m_r) {
                result.emplace_back(m_p.GetX() + i, m_p.GetY() + j);
                result.emplace_back(m_p.GetX() - i, m_p.GetY() + j);
                result.emplace_back(m_p.GetX() + i, m_p.GetY() - j);
                result.emplace_back(m_p.GetX() - i, m_p.GetY() - j);
            }
        }
    }
    return result;
}


