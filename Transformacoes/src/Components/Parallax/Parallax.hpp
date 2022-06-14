#ifndef __PARALLAX_H__
#define __PARALLAX_H__
#include <iostream>
#include <queue>
#include <vector>
#include "../../Modules/gl_canvas2d.h"
#include "../../Utils/Position.hpp"

class Parallax
{
    private:
        bool Debug;
        int ScreenWidth;
        int ScreenHeight;
        Curves * curves;
        int Timer;
        vector<Position*> mountain1;
        vector<Position*> mountain2;
        vector<Vector2*> clouds;
        vector<float> rgb;

    public:
        Parallax(int screenWidth, int screenHeight, int timer);
        void DrawSky(int posX, int speed);
        void DrawMountains(int posX, int speed, vector<Position*> &mountain, vector<float> rgb,int maxH, int minH);
        int Random(int min, int max);
        void Render(int timer, int speed, bool debug);
        ~Parallax();
};

#endif
