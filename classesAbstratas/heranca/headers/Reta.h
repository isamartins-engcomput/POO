#ifndef FIGURA_RETA_H
#define FIGURA_RETA_H

#include "FiguraGeometrica.h"

class Reta : public FiguraGeometrica
// HERANÇA: a subclass filha Reta herda tudo da superclass FiguraGeometrica, menos o que está em private
{
  public:
    Reta();
    void draw();
};

#endif