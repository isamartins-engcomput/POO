#include "Resistor.hpp"
#include <iostream>

Resistor::Resistor(double resistencia_ohms)
{ std::cout << "Resistor criado!" << std::endl; }

Resistor::~Resistor() { std::cout << "Resistor destruído!" << std::endl; }

// POLIMORFISMO
void Resistor::ligar()
{ std::cout << "Resistor limitando!" << std::endl; }