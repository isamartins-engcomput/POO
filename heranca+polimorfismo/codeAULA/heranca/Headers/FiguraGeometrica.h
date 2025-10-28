#ifndef FIGURA_GEOMETRICA_H
#define FIGURA_GEOMETRICA_H

#include <iostream>

//100% INTERFACE
class FiguraGeometrica
{
//protected:
    //int x, y;

public:
    FiguraGeometrica();
    virtual ~FiguraGeometrica();

    virtual void draw();
};

#endif