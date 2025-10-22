#include "FiguraGeometrica.h"
#include "Reta.h"

int main()
{
  FiguraGeometrica fig, *rfig, *cfig;
  Reta reta;

  rfig = &reta;

  fig.draw();
  rfig->draw();

return 0;
}