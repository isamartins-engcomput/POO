#ifndef COMPONENTE_ELETRONICO_H
#define COMPONENTE_ELETRONICO_H

#include <iostream>

class ComponenteEletronico
{
    public:
        ComponenteEletronico();
        virtual ~ComponenteEletronico();
        virtual void ligar() = 0;
};

#endif