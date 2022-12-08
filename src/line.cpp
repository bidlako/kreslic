//
// Created by biond on 08.10.2022.
//

#include "../include/line.h"

#include "../include/position.h"
#include <cmath>
#include <iostream>

Line::Line(double x1, double y1, double x2, double y2) : m_x(x1, y1), m_y(x2, y2) {
    if (x1 == x2 && y1 == y2) {
        throw std::invalid_argument("Line must have two different points");
    }
}

void Line::Translate(Position p) {
    m_x += p;
    m_y += p;
}

void Line::Rotate(Position p, double angle) {
    m_x.Rotate(p, angle);
    m_y.Rotate(p, angle);
}

void Line::Scale(Position p, double f) {
    m_x -= p;
    m_y -= p;
    m_x *= f;
    m_y *= f;
    m_x += p;
    m_y += p;
}

std::string Line::Vectorize(std::string const &color, int width) const {
    std::string result = "<line x1=\"" + std::to_string(m_x.GetX()) + "\" y1=\"" + std::to_string(m_x.GetY()) +
                         "\" x2=\"" + std::to_string(m_y.GetX()) + "\" y2=\"" + std::to_string(m_y.GetY()) +
                         "\" stroke=\"" + color + "\" stroke-width=\"" + std::to_string(width) + "\" />";
    return result;
}

std::vector<Position> Line::Rasterize(int width) const {
    std::vector<Position> result;
// TODO predelat aby to pouzivalo point operatory
    double x1 = m_x.GetX();
    double y1 = m_x.GetY();
    double x2 = m_y.GetX();
    double y2 = m_y.GetY();

    double dx = x2 - x1;
    double dy = y2 - y1;

    double length = sqrt(dx * dx + dy * dy);

    double x = x1;
    double y = y1;

    double stepX = dx / length;
    double stepY = dy / length;

    for (int i = 0; i < length; i++) {
        result.emplace_back(x, y);
        x += stepX;
        y += stepY;
    }
    return result;
}
