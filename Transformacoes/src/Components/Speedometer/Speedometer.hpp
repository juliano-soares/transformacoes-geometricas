#ifndef __SPEEDOMETER_H__
#define __SPEEDOMETER_H__

#include "../../Modules/gl_canvas2d.h"

class Speedometer
{
    private:
        float velocity;
        float time;
        float distance;

    public:
        Speedometer();
        void Render(int screenWidth, int screenHeight, int speed,int seconds);
};

#endif
