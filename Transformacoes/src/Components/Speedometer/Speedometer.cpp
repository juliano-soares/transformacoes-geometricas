#include "Speedometer.hpp"
#include "../../Modules/gl_canvas2d.h"
#include "../../Utils/Utils.h"
#include <iostream>
#include <string>
#include <math.h>

Speedometer::Speedometer()
{
}

void Speedometer::Render(int screenWidth, int screenHeight, int speed,int seconds)
{
    char* char_arr;
    string prv;
    vector<float> rgb = Utils::RGBtoFloat(61, 61, 61);
    CV::color(rgb[0], rgb[1], rgb[2]);
    CV::rectFill(screenWidth - 200, 0, screenWidth, 160);
    CV::color(1, 1, 1);
    CV::rectFill(screenWidth - 180, 90, screenWidth - 20, 120);
    CV::rectFill(screenWidth - 180, 30, screenWidth - 20, 60);
    CV::color(0, 1, 0);
    CV::text(screenWidth - 160, 125, "Speed");
    prv = to_string(speed) + " m/s";
    char_arr = &prv[0];
    CV::text(screenWidth - 160, 100, char_arr);
    CV::text(screenWidth - 160, 70, "Time");
    int resto=seconds;
    string hour, minut, sec;
    hour = to_string(seconds/3600);
    if((seconds/3600) < 10)
        hour = "0" + hour;
    minut = to_string(resto/60);
    resto = seconds%3600;
    if((resto/60) < 10)
        minut = "0" + minut;
    sec = to_string(resto%60);
    if((resto%60) < 10)
        sec = "0" + sec;
    prv = hour + " : " + minut + " : " +  sec;
    char_arr = &prv[0];
    CV::text(screenWidth - 160, 40, char_arr);
}
