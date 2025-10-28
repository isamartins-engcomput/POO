#include "Capacitor.hpp"
#include <iostream>

Capacitor::Capacitor(double capacitancia_farads)
{ std::cout << "Capacitor criado!" << std::endl; }

Capacitor::~Capacitor() { std::cout << "Capacitor destruído!" << std::endl; }

// POLIMORFISMO
void Capacitor::ligar()
{ std::cout << "Capacitor conduzindo!" << std::endl; }