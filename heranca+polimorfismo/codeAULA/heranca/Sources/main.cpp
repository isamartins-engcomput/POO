#include <FiguraGeometrica.h>
#include <Reta.h>
#include <Circulo.h>
int main()
{
    FiguraGeometrica  fig, *rfig, *cfig;
    Reta reta;
    Circulo circulo;

    rfig = &reta;
    cfig = &circulo;

    fig.draw();
    rfig->draw();
    cfig->draw();


}