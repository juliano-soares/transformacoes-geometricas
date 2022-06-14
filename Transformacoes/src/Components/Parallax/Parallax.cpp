#include <cmath>
#include <random>
#include <time.h>
#include <vector>
#include <algorithm>

#include "../../Utils/Utils.h"
#include "../../Utils/Vector2.h"
#include "../Curves/Curves.hpp"
#include "../../Modules/gl_canvas2d.h"
#include "Parallax.hpp"

/* Wheel constructor
   @param screenWidth: screen width.
   @param screenHeight: screen height.
   @param timer: time os seconsds to draw a nem position.
*/
Parallax::Parallax(int screenWidth, int screenHeight, int timer)
{
    ScreenWidth = screenWidth;
    ScreenHeight = screenHeight;
    Timer = timer;
    curves = new Curves();

    mountain1.push_back(new Position(0, Random(300,600)));
    for(int i = 0; i <= 32; i++)
    {
       mountain1.push_back(new Position(i * 50, Random(200,300)));
    }

    mountain2.push_back(new Position(0, Random(300,600)));
    for(int i = 0; i <= 32; i++)
    {
       mountain2.push_back(new Position(i * 50, Random(240,500)));
    }

    for(int i = 0; i <= 10; i++)
    {
        clouds.push_back(new Vector2(Random(ScreenWidth + i * 400,ScreenWidth + i * 800), Random(500,ScreenHeight)));
    }
}

/*  method to randomize a point between two heights
*/
int Parallax::Random(int min, int max)
{
   static bool first = true;
   if (first)
   {
      srand( time(NULL) );
      first = false;
   }
   return min + rand() % (( max + 1 ) - min);
}


/* Renders the Parallax
   @param timer: time os seconsds to draw a nem position.
   @param speed: speed to increase or decrease transformations for animations.
   @param debug: bolean to enable or disable debug mode.
*/
void Parallax::Render(int timer, int speed, bool debug)
{
    if(Timer > timer)
        return;
    Timer = timer;
    Debug = debug;

    DrawSky(timer, speed+3);
    rgb = Utils::RGBtoFloat(82, 133, 124);
    DrawMountains(timer, speed, mountain2, rgb, 240, 500);
    rgb = Utils::RGBtoFloat(21, 100, 95);
    DrawMountains(timer, speed+2, mountain1, rgb,200, 300);
    curves->SetDebug(Debug);
}

/* Draw the Sky
   @param timer: time os seconsds to draw a nem position.
   @param speed: speed to increase or decrease transformations for animations.
*/
void Parallax::DrawSky(int timer, int speed)
{
    CV::color(1, 1, 0);
    CV::circleFill(400, 600, 75, 100);
    for(size_t i = 0; i < clouds.size(); i++)
    {
        CV::color(1, 1, 1);
        CV::circleFill(clouds[i]->x, clouds[i]->y, 30, 20);
        CV::circleFill(clouds[i]->x + 30, clouds[i]->y, 30, 20);
        CV::circleFill(clouds[i]->x - 30, clouds[i]->y, 30, 20);
        CV::circleFill(clouds[i]->x, clouds[i]->y + 30, 30, 20);
        clouds[i]->x = clouds[i]->x - speed;
    }
    if(clouds[0]->x < -100){
        clouds.erase(clouds.begin());
        clouds.push_back(new Vector2(Random(clouds[9]->x + 400,clouds[9]->x  + 800), Random(500,ScreenHeight)));
    }

}

/* Draw the mountains
   @param timer: time os seconsds to draw a nem position.
   @param speed: speed to increase or decrease transformations for animations.
   @param mountain: array for positions mountain.
   @param rgb: color to fill.
   @param minH: minimum height to generate new points
   @param maxH: maximum height to generate new points.
*/
void Parallax::DrawMountains(int timer, int speed, vector<Position*> &mountain, vector<float> rgb, int minH, int maxH)
{
    for(size_t i = 0; i < mountain.size() - 4; i +=3)
    {
        curves->RenderBezierCurve(mountain[i],mountain[i+1],mountain[i+2],mountain[i+3], true, rgb);
    }

    for(size_t i = 0; i < mountain.size(); i++)
    {
        mountain[i]->x = mountain[i]-> x - speed;
    }

    if(mountain[1]->x < -400)
    {
        mountain.erase(mountain.begin());
        mountain.erase(mountain.begin() + 1);
        mountain.erase(mountain.begin() + 2);
        mountain.push_back(new Position(mountain[mountain.size()]->x + 50, Random(minH,maxH)));
        mountain.push_back(new Position(mountain[mountain.size()]->x + 150, Random(minH,maxH)));
        mountain.push_back(new Position(mountain[mountain.size()]->x + 200, Random(minH,maxH)));
    }
}

/* Deconstructor
*/
Parallax::~Parallax()
{
    for (auto p : mountain1)
        delete p;
    for (auto p : mountain2)
        delete p;
    for (auto p : clouds)
        delete p;
    mountain1.clear();
    mountain2.clear();
    clouds.clear();
    delete curves;
}

