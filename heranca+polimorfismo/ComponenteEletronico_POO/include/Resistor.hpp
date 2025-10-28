#ifndef COMPONENTE_ELETRONICO_RESISTOR_H
#define COMPONENTE_ELETRONICO_RESISTOR_H

#include "ComponenteEletronico.hpp"

class Resistor : public ComponenteEletronico // HERANÇA
{
    public:
        Resistor(double resistencia_ohms);
        ~Resistor();
        void ligar() override;
};

#endif