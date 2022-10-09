//
// Created by biond on 08.10.2022.
//

#include "Rectangle.h"
#include "Line.h"


Rectangle::Rectangle(double x, double y, double width, double height) :
        m_a(x, y, x
                  + width, y),
        m_b(x
            + width, y, x + width, y + height),
        m_c(x
            + width, y + height, x, y + height),
        m_d(x, y
               + height, x, y),

        m_w(width), m_h(height) {}

void Rectangle::Translate(Position p) {
    m_a.Translate(p);
    m_b.Translate(p);
    m_c.Translate(p);
    m_d.Translate(p);
}

// TODO: Rotace rectanglu nefunguje spravne, rotuje se pouze hlavni bod, zbytek se neotoci
void Rectangle::Rotate(Position p, double angle) {
    m_a.Rotate(p, angle);
    m_b.Rotate(p, angle);
    m_c.Rotate(p, angle);
    m_d.Rotate(p, angle);
}

void Rectangle::Scale(Position p, double f) {
    m_a.Scale(p, f);
    m_b.Scale(p, f);
    m_c.Scale(p, f);
    m_d.Scale(p, f);
    m_w *= f;
    m_h *= f;
}

std::string Rectangle::Vectorize(const std::string &color, int width) const {
    return m_a.Vectorize(color, width) + m_b.Vectorize(color, width) + m_c.Vectorize(color, width) +
           m_d.Vectorize(color, width);
}

std::vector<Position> Rectangle::Rasterize(int width) const {
    std::vector<Position> result;
    std::vector<Position> a = m_a.Rasterize(width);
    std::vector<Position> b = m_b.Rasterize(width);
    std::vector<Position> c = m_c.Rasterize(width);
    std::vector<Position> d = m_d.Rasterize(width);
    result.insert(result.end(), a.begin(), a.end());
    result.insert(result.end(), b.begin(), b.end());
    result.insert(result.end(), c.begin(), c.end());
    result.insert(result.end(), d.begin(), d.end());
    return result;
}




