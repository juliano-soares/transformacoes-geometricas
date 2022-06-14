#ifndef CURVES_H
#define CURVES_H

#include "../../Utils/Position.hpp"
#include "../../Utils/Utils.h"

#pragma once

class Curves{
    private:
        bool Debug;
    public:
        Curves();
        void RenderBezierCurve(Position * p1, Position * p2, Position * p3, Position * p4, bool filled, vector<float> rgb);
        void RenderBSplineCurve(Position * p1, Position * p2, Position * p3, Position * p4);
        void SetDebug(bool debug);
        void ShowDebug(Position * p1, Position * p2, Position * p3, Position * p4);
};
#endif
