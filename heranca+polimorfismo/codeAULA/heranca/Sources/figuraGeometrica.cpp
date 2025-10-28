#include <FiguraGeometrica.h>
#include <iostream>

FiguraGeometrica::FiguraGeometrica()
{
    std::cout << "FiguraGeometrica " << std::string(40, '.') << " criada \n";
}

void FiguraGeometrica::draw() 
{
    std::cout << "Desenhando uma figura genérica..." << std::endl;
}

FiguraGeometrica::~FiguraGeometrica() 
{
    std::cout << "Uma figura geométrica foi destruída!" << std::endl;
}

