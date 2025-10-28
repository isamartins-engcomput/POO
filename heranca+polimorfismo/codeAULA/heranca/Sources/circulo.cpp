#include <Circulo.h>

Circulo::Circulo(){
    std::cout << "Circulo criado" << std::endl;
}

//POLIMORFISMO
void Circulo::draw(){
    std::cout << "Circulo desenhado!" << std::endl;
}
