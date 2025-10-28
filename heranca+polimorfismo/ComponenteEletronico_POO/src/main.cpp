#include "ComponenteEletronico.hpp"
#include "Resistor.hpp"
#include "Capacitor.hpp"
#include <iostream>
#include <vector>
#include <memory>

int main()
{
    std::cout << ">>> Criando Componentes..." << std::endl;
    Capacitor capacitor(10); 
    Resistor resistor(220);

    std::cout << "\n>>> POLIMORFISMO <<<" << std::endl;
    std::vector<ComponenteEletronico*> circuito_poo;
    
    circuito_poo.push_back(&resistor);
    circuito_poo.push_back(&capacitor);

    for (ComponenteEletronico* componente : circuito_poo)
    { componente->ligar(); }
    
    std::cout << "\n>>> Fim do Programa!" << std::endl;
    
return 0;
}