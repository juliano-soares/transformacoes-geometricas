/**
    Header MyMatrix
    @file Buttom.cpp
    @author Juliano Leonardo Soares
    @version 1.1 13/06/22
*/
#ifndef POSITION_H
#define POSITION_H

#include "MyMatrix.hpp"

#pragma once
class Position
{
private:
    MyMatrix mtx;

public:
    double x, y;
    Position();
    Position(double x, double y);
    void rotate(double ang);              // apply the rotation
    void translate(double dx, double dy); // apply the translation
    void apply();                         // apply the transformations
    void scale(double sx, double sy);     // apply the scale

    void circleInPosition(double r, bool f); // desenha circulo
    void pLineBold(Position &p2);
    void cIntersect(Position &p2, double r0, double r1, Position &res); // calcula intersecção de círculo
    void pLine(Position &p2);                                           // desenha linha

    ~Position();
};
#endif
