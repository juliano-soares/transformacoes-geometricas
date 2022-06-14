#include "Position.hpp"
#include "../Modules/gl_canvas2d.h"
#include <cmath>

Position::Position() : mtx()
{
    x = y = 0;
}

Position::Position(double x, double y) : mtx()
{
    this->x = x;
    this->y = y;
}

void Position::apply()
{
    mtx.forPosition(x, y);
    mtx.identity();
}

void Position::rotate(double ang)
{
    MyMatrix R;
    R(0, 0) = cos(ang);
    R(0, 1) = sin(ang);
    R(1, 0) = -sin(ang);
    R(1, 1) = cos(ang);
    mtx = mtx * R;
}

void Position::translate(double dx, double dy)
{
    MyMatrix T;
    T(0, 2) = dx;
    T(1, 2) = dy;
    mtx = mtx * T;
}

void Position::scale(double sx, double sy)
{
    MyMatrix S;
    S(0, 0) = sx;
    S(1, 1) = sy;
    mtx = mtx * S;
}

void Position::pLine(Position &p2)
{
    CV::line(x, y, p2.x, p2.y);
}

void Position::pLineBold(Position &p2)
{
    CV::line(x, y, p2.x, p2.y);
    CV::line(x-1, y-1, p2.x-1, p2.y-1);
    CV::line(x+1, y+1, p2.x+1, p2.y+1);
}

void Position::circleInPosition(double r, bool f)
{
    if (f)
        CV::circleFill(x, y, r, 30);
    else
        CV::circle(x, y, r, 30);
}

void Position::cIntersect(Position &p2, double r0, double r1, Position &res)
{
    double dx, dy, d, a, h, x2, y2;
    dx = p2.x - x;
    dy = p2.y - y;
    d = hypot(dx, dy);
    if (d > (r0 + r1))
        return;
    if (d < fabs(r0 - r1))
        return;
    a = (pow(r0, 2) - pow(r1, 2) + pow(d, 2)) / (2 * d);
    h = sqrt(pow(r0, 2) - pow(a, 2));
    x2 = x + (dx * a / d);
    y2 = y + (dy * a / d);
    res.x = x2 + h * (dy) / d;
    res.y = y2 - h * (dx) / d;
}

Position::~Position()
{
    delete &mtx;
}
