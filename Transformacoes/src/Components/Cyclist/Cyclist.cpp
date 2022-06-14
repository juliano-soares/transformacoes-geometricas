/**
    Cyclist functions
    @file Cyclist.cpp
    @author Juliano Leonardo Soares
    @version 1.1 13/06/22
*/
#include "../../Modules/gl_canvas2d.h"
#include "Cyclist.hpp"
#include "../Curves/Curves.hpp"
#include <cmath>

/* Builder setting start points to draw cyclist
   @param screenWidth: screen width.
   @param screenHeight: screen height.
*/
Cyclist::Cyclist(int screenWidth, int screenHeight)
{
    ptLeftWheel = new Position(screenWidth/2-80, 200);
    leftWheel = new Wheel(ptLeftWheel);
    ptRightWheel = new Position(screenWidth/2 + 100, 200);
    rightWheel = new Wheel(ptRightWheel);
    pFrame1 = new Position(screenWidth/2 - 25, 260);
    pFrame2 = new Position(screenWidth/2 + 78, 265);
    pFrame3 = new Position(screenWidth/2 + 75, 270);
    pFrame4 = new Position(screenWidth/2 + 65, 300);
    pBezier1 = new Position(screenWidth/2 - 60, 330);
    pBezier2 = new Position(screenWidth/2, 370);
    pBezier3 = new Position(screenWidth/2-20, 320);
    pBezier4 = new Position(screenWidth/2+90, 320);
    pBezier5 = new Position(screenWidth/2+110, 300);
    pBench = new Position(screenWidth/2 - 40, 290);
    pBench1 = new Position(screenWidth/2 - 45, 288);
    pBench2 = new Position(screenWidth/2 - 35, 288);
    pCatraca = new Position(screenWidth/2, 200);
    pedal  = new Pedal(pCatraca);
    pGuidon = new Position(screenWidth/2 + 100, 290);
    pKnee1 = new Position(screenWidth/2 - 70, 300);
    pKnee2 = new Position(screenWidth/2 - 70, 300);
    pHead = new Position(screenWidth/2 + 70, 350);
    pNeck = new Position(screenWidth/2 + 40, 350);
    pArm = new Position(screenWidth/2 + 30, 360);
    curves = new Curves();
}

/* Method to render the cyclist in the correct
   positions according to speed, rotations and translations
   @param speed: speed to speed up transformations.
   @param debug: bolean for debug mode.
*/
void Cyclist::Render(int speed, bool debug){
    rightWheel->render(speed);
    leftWheel->render(speed);
    ptLeftWheel->pLine(*pFrame1);
    ptRightWheel->pLine(*pFrame4);
    pCatraca->pLine(*ptLeftWheel);
    pCatraca->pLine(*pBench);
    pCatraca->pLine(*pFrame2);
    pFrame2->pLine(*pFrame3);
    pFrame1->pLine(*pFrame3);
    pedal->getP1()->cIntersect(*pBench, 60, 80, *pKnee1);
    pedal->getP2()->cIntersect(*pBench, 60, 80, *pKnee2);
    pBench->pLine(*pKnee1);
    pedal->getP1()->pLine(*pKnee1);
    pedal->render(speed);
    pBench1->pLineBold(*pBench2);
    pBench->pLine(*pKnee2);
    pedal->getP2()->pLine(*pKnee2);
    pHead->circleInPosition(20, true);
    pNeck->pLine(*pHead);
    curves->SetDebug(debug);
    vector<float> rgb = Utils::RGBtoFloat(144, 191, 173);
    curves->RenderBezierCurve(pBench,pBezier1,pBezier2,pNeck, false, rgb);
    curves->RenderBezierCurve(pNeck,pBezier3,pFrame3,pGuidon, false, rgb);
    curves->RenderBezierCurve(pFrame4,pBezier4,pBezier5,pGuidon, false, rgb);

    if(debug){
        CV::color(0,0,1);
        pBench->circleInPosition(80, false);
        pKnee1->circleInPosition(4, true);
        pKnee2->circleInPosition(4, true);
    }
}

/* Deconstructor
*/
Cyclist::~Cyclist(){
    delete ptLeftWheel;
    delete ptRightWheel;
    delete leftWheel;
    delete rightWheel;
    delete curves;
    delete pCatraca;
    delete pBench;
    delete pBench1;
    delete pBench2;
    delete pedal;
    delete pGuidon;
    delete pKnee1;
    delete pKnee2;
    delete pHead;
    delete pArm;
    delete pNeck;
    delete pBezier1;
    delete pBezier2;
    delete pBezier3;
    delete pBezier4;
    delete pBezier5;
    delete pFrame1;
    delete pFrame2;
    delete pFrame3;
    delete pFrame4;
}
