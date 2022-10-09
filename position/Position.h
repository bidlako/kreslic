//
// Created by biond on 08.10.2022.
//

#ifndef CPP_SP_01_POSITION_H
#define CPP_SP_01_POSITION_H


class Position {
public:
    Position() = default;

    Position(double x, double y);

    double GetX() const;

    double GetY() const;

    void SetX(double x);

    void SetY(double y);

    void Rotate(double angle);

    void Rotate(Position p, double angle);

    Position operator+(const Position &other) const;

    Position operator-(const Position &other) const;

    Position operator*(double f) const;

    void operator*=(double f);

    void operator+=(const Position &other);

    void operator-=(const Position &other);

    bool operator==(const Position &other) const;

private:
    double m_x;
    double m_y;
    double deg2rad(double deg) const;
};


#endif //CPP_SP_01_POSITION_H
