#ifndef COMPONENTE_ELETRONICO_CAPACITOR_H
#define COMPONENTE_ELETRONICO_CAPACITOR_H

#include "ComponenteEletronico.hpp"

class Capacitor : public ComponenteEletronico // HERANÇA
{
    public:
        Capacitor(double capacitancia_farads);
        ~Capacitor();
        void ligar() override;
};

#endif