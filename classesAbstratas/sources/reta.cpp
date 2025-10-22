#include "Reta.h"
#include <iostream>

Reta::Reta()
{
  std::cout << "\nReta criada!" << std::endl;
}

// POLIMORFISMO
void Reta::draw()
{
  std::cout << "\nReta desenhada!" << std::endl;
}