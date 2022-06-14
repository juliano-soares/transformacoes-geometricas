#ifndef WHEEL_H
#define WHEEL_H

#include "../../Utils/Position.hpp"
#include <vector>

#pragma once

class Wheel
{
    private:
        Position * wheelCenter;
        std::vector<Position *> bicycleSpokes;
    public:
        Wheel(Position * center);
        void render(int speed);
        ~Wheel();
};

#endif
