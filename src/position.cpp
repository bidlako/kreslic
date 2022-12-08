//
// Created by biond on 08.10.2022.
//
#include <numbers>
#include <cmath>
#include "position.h"

Position::Position(double x, double y) : m_x(x), m_y(y) {}

double Position::GetX() const {
    return m_x;
}

double Position::GetY() const {
    return m_y;
}

Position Position::operator+(const Position &other) const {
    return {m_x + other.m_x, m_y + other.m_y};
}

void Position::operator+=(const Position &other) {
    m_x += other.m_x;
    m_y += other.m_y;
}

Position Position::operator-(const Position &other) const {
    return {m_x - other.m_x, m_y - other.m_y};
}

void Position::operator-=(const Position &other) {
    m_x -= other.m_x;
    m_y -= other.m_y;
}

bool Position::operator==(const Position &other) const {
    return m_x == other.m_x && m_y == other.m_y;
}

void Position::Rotate(double angle) {
    double x = m_x;
    double y = m_y;
    double theta = deg2rad(angle);
    m_x = x * cos(theta) - y * sin(theta);
    m_y = x * sin(theta) + y * cos(theta);
}

void Position::Rotate(Position p, double angle) {
    *this -= p;
    Rotate(angle);
    *this += p;
}

Position Position::operator*(double f) const {
    return {m_x * f, m_y * f};
}

void Position::operator*=(double f) {
    m_x *= f;
    m_y *= f;
}

double Position::deg2rad(double deg) {
    return deg * std::numbers::pi / 180;
}



