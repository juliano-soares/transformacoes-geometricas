#include "Wheel.hpp"
#include "../../Modules/gl_canvas2d.h"

/* Wheel constructor
   @param centerPosition: center position to draw the pedal.
*/
Wheel::Wheel(Position * center){
    this->wheelCenter = center;
    double ang = 0.0;
    for(int i = 0; i < 10; i++, ang+=0.628318531){
        Position * p = new Position(0, 50);
        p->translate(wheelCenter->x, wheelCenter->y);
        p->rotate(ang);
        p->apply();
        this->bicycleSpokes.push_back(p);
    }
}

/* Renders the Wheels
   @param speed: speed to increase or decrease transformations for animations.
*/
void Wheel::render(int speed)
{
    CV::color(0,0,0);
    wheelCenter->circleInPosition(51, false);
    wheelCenter->circleInPosition(52, false);
    CV::color(1,1,1);
    wheelCenter->circleInPosition(53, false);
    CV::color(0,0,0);
    wheelCenter->circleInPosition(54, false);
    wheelCenter->circleInPosition(55, false);
    wheelCenter->circleInPosition(56, false);
    wheelCenter->circleInPosition(57, false);
    wheelCenter->circleInPosition(50, false);
    CV::color(0,0,0);
    wheelCenter->circleInPosition(4, false);
    for(Position * p : bicycleSpokes){
        p->translate(wheelCenter->x,wheelCenter->y);
        p->rotate(0.05 + ((float)speed/100));
        p->translate(-wheelCenter->x,-wheelCenter->y);
        p->apply();
        wheelCenter->pLine(*p);
    }
}

/* Deconstructor
*/
Wheel::~Wheel(){
    for (auto p : bicycleSpokes)
        delete p;
    bicycleSpokes.clear();
}
