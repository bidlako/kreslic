//
// Created by biond on 08.10.2022.
//

#ifndef CPP_SP_01_POSITION_H
#define CPP_SP_01_POSITION_H


class Position {
public:
    Position(double x, double y);

    double GetX() const;

    double GetY() const;

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
    static double deg2rad(double deg) ;
};


#endif //CPP_SP_01_POSITION_H
