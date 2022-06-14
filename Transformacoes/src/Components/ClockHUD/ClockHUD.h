#ifndef __CLOCKHUD_H__
#define __CLOCKHUD_H__

#include "../../Modules/gl_canvas2d.h"
#include "../../Utils/Position.hpp"

class ClockHUD
{
    int posX;
    int posY;
    int ScreenWidth;
    int ScreenHeight;
    Position * p0;
    Position * pH;
    Position * pM;
    Position * pS;

    double OldfHour = 0;
    double OldfMinute = 0;
    double OldfSecond = 0;

public:
    ClockHUD(int screenWidth, int screenHeight, int posX, int posY);
    void AnalogicClock(int posX, int posY, int seconds);
    void Render(int seconds);
    void DayNight(int posX, int posY, int seconds);
    void RotatePositions(double ang, Position &o, Position &p);
    ~ClockHUD();
};

#endif
