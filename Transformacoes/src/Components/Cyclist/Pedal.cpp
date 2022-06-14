/**
    Pedal functions
    @file Pedal.cpp
    @author Juliano Leonardo Soares
    @version 1.1 13/06/22
*/
#include "Pedal.hpp"
#include "../../Modules/gl_canvas2d.h"

/* Bicycle pedal constructor
   @param centerPosition: center position to draw the pedal.
*/
Pedal::Pedal(Position * centerPosition)
{
    this->centerPosition = centerPosition;
    p1 = new Position(centerPosition->x, centerPosition->y + 25);
    p2 = new Position(centerPosition->x, centerPosition->y - 25);
}
/* Renders the pedal
   @param speed: speed to increase or decrease transformations for animations.
*/
void Pedal::render(int speed)
{
    p1->translate(centerPosition->x, centerPosition->y);
    p1->rotate(0.05 + ((float)speed/100));
    p1->translate(-centerPosition->x, -centerPosition->y);
    p1->apply();
    p2->translate(centerPosition->x, centerPosition->y);
    p2->rotate(0.05 + ((float)speed/100));
    p2->translate(-centerPosition->x, -centerPosition->y);
    p2->apply();
    CV::color(0,0,0);
    centerPosition->pLine(*p1);
    CV::color(0,0,0);
    centerPosition->circleInPosition(15, true);
    CV::color(0,0,0);
    centerPosition->pLine(*p2);
    p1->circleInPosition(4, true);
    p2->circleInPosition(4, true);
}

Position * Pedal::getP1(){
    return this->p1;
}

Position * Pedal::getP2(){
    return this->p2;
}

/* Deconstructor
*/
Pedal::~Pedal(){
    delete p1;
    delete p2;
}
