/**
    Clock HUD functions
    @file ClockHUD.cpp
    @author Juliano Leonardo Soares
    @version 1.1 13/06/22
*/
#include "ClockHUD.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../../Utils/Utils.h"
#include "../../Utils/Vector2.h"
#include "../../Utils/Position.hpp"

/* Create new ClockHUD.
   @param screenWidth: screen width.
   @param screenHeight: screen height.
   @param posX: ClockHUD start x position.
   @param posY ClockHUD start y position.
*/
ClockHUD::ClockHUD(int screenWidth, int screenHeight, int posX, int posY)
{
    ScreenWidth = screenWidth;
    ScreenHeight = screenHeight;

    p0 = new Position(70,ScreenHeight - 90);
    pH = new Position(70,ScreenHeight - 40);
    pM = new Position(70,ScreenHeight - 40);
    pS = new Position(70,ScreenHeight - 40);
}

/* Create new Analogic Clock.
   @param posX: Analogic clock starts x position to be drawn.
   @param posY Analogic clock starts y position to be drawn.
   @param seconds: time in seconds.
*/
void ClockHUD::AnalogicClock(int posX, int posY, int seconds)
{
    CV::translate(0, 0);
    int resto, hour, minut, sec;
    hour = seconds/3600;
    resto = seconds%3600;
    minut = resto/60;
    sec = resto%60;

    CV::color(255, 255, 255);
    CV::circleFill(posX, posY, 60, 360);
    CV::color(0, 0, 0);
    CV::circle(posX, posY, 60, 360);

    if(hour != OldfHour)
    {
        OldfHour = hour;
        RotatePositions(0.5, *p0, *pH);
    } if(minut != OldfMinute)
    {
        OldfMinute = minut;
        RotatePositions(0.0175, *p0, *pM);
    }if(sec != OldfSecond)
    {
        OldfSecond = sec;
        RotatePositions(0.0175, *p0, *pS);
    }
    CV::color(1, 0, 0);
    p0->pLine(*pS);
    CV::color(0, 1, 0);
    p0->pLine(*pM);
    CV::color(0, 0, 1);
    p0->pLine(*pH);
}

/* Rotate pointer positions.
   @param o: pointer start position.
   @param p: pointer end position.
   @param ang: angle to be rotated.
*/
void ClockHUD::RotatePositions(double ang, Position &o, Position &p)
{
    p.translate(o.x, o.y);
    p.rotate(0.5);
    p.translate(-o.x,-o.y);
    p.apply();
}

/* Drawing a color palette, which was supposed to be a watch
   to change the game between day and night was not finished
   in time due to lack of experience.
   @param posX: DayNight starts x position to be drawn.
   @param posY DayNight starts y position to be drawn.
   @param seconds: time in seconds.
*/
void ClockHUD::DayNight(int posX, int posY, int seconds)
{
    vector<float> rgb;
    float vx[] = {135, 135, 172};
    float vy[] = {(float)(ScreenHeight - 90), (float)(ScreenHeight - 15), (float)(ScreenHeight - 25)};
    rgb = Utils::RGBtoFloat(92, 81, 133);
    CV::color(rgb[0], rgb[1], rgb[2]);
    CV::polygonFill(vx, vy, 3);

    float vx1[] = {135, 172, 200};
    float vy1[] = {(float)(ScreenHeight - 90), (float)(ScreenHeight - 25), (float)(ScreenHeight - 52)};
    rgb = Utils::RGBtoFloat(108, 123, 161);
    CV::color(rgb[0], rgb[1], rgb[2]);
    CV::polygonFill(vx1, vy1, 3);

    float vx2[] = {135, 200, 210};
    float vy2[] = {(float)(ScreenHeight - 90), (float)(ScreenHeight - 52), (float)(ScreenHeight - 90)};
    rgb = Utils::RGBtoFloat(142, 180, 189);
    CV::color(rgb[0], rgb[1], rgb[2]);
    CV::polygonFill(vx2, vy2, 3);

    float vx3[] = {135, 210, 200};
    float vy3[] = {(float)(ScreenHeight - 90), (float)(ScreenHeight - 90), (float)(ScreenHeight - 128)};
    rgb = Utils::RGBtoFloat(178, 212, 201);
    CV::color(rgb[0], rgb[1], rgb[2]);
    CV::polygonFill(vx3, vy3, 3);

    float vx4[] = {135, 200, 172};
    float vy4[] = {(float)(ScreenHeight - 90), (float)(ScreenHeight - 128), (float)(ScreenHeight - 155)};
    rgb = Utils::RGBtoFloat(199, 237, 201);
    CV::color(rgb[0], rgb[1], rgb[2]);
    CV::polygonFill(vx4, vy4, 3);

    float vx5[] = {135, 172, 135};
    float vy5[] = {(float)(ScreenHeight - 90), (float)(ScreenHeight - 155), (float)(ScreenHeight - 165)};
    rgb = Utils::RGBtoFloat(229, 255, 230);
    CV::color(rgb[0], rgb[1], rgb[2]);
    CV::polygonFill(vx5, vy5, 3);
}

/*  Render the clocks
    @param seconds: time in seconds.
*/
void ClockHUD::Render(int seconds)
{
    vector<float> rgb = Utils::RGBtoFloat(61, 61, 61);
    CV::color(rgb[0], rgb[1], rgb[2]);
    CV::rectFill(5, ScreenHeight - 5, 135, ScreenHeight - 175);

    CV::color(0, 0, 0);
    DayNight(70, ScreenHeight - 70, seconds);
    AnalogicClock(70,ScreenHeight - 90, seconds);

    CV::translate(0, 0);
    rgb = Utils::RGBtoFloat(253, 252, 231);
    CV::color(rgb[0], rgb[1], rgb[2]);
    CV::circleFill(170, ScreenHeight - 55, 10, 30);
    rgb = Utils::RGBtoFloat(255, 234, 139);
    CV::color(rgb[0], rgb[1], rgb[2]);
    CV::circleFill(170, ScreenHeight - 125, 10, 30);
}

/* Deconstructor
*/
ClockHUD::~ClockHUD(){
    delete p0;
    delete pH;
    delete pM;
    delete pS;
}
