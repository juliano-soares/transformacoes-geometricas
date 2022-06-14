#ifndef CYCLIST_H
#define CYCLIST_H

#include "Wheel.hpp"
#include "Pedal.hpp"
#include "../../Utils/Position.hpp"
#include "../Curves/Curves.hpp"

#pragma once

class Cyclist
{
    private:
        Position * ptLeftWheel;
        Position * ptRightWheel;
        Wheel * leftWheel;
        Wheel * rightWheel;
        Position * pFrame1;
        Position * pFrame2;
        Position * pFrame3;
        Position * pFrame4;
        Position * pBezier1;
        Position * pBezier2;
        Position * pBezier3;
        Position * pBezier4;
        Position * pBezier5;
        Position * pCatraca;
        Position * pKnee1;
        Position * pKnee2;
        Position * pGuidon;
        Position * pNeck;
        Position * pHead;
        Position * pArm;
        Pedal * pedal;
        Position * pBench;
        Position * pBench1;
        Position * pBench2;
        Curves * curves;
    public:
        Cyclist(int screenWidth, int screenHeight);
        void Render(int speed, bool debug);
        ~Cyclist();
};
#endif
