#ifndef PEDAL_H
#define PEDAL_H

#include "../../Utils/Position.hpp"

#pragma once

class Pedal
{
    private:
        Position * centerPosition;
        Position * p1;
        Position * p2;
    public:
        Pedal(Position * pc);
        void render(int speed);
        Position * getP1();
        Position * getP2();
        ~Pedal();
};

#endif
