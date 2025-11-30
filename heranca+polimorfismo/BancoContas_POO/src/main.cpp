#include <iostream>
#include <vector>

#include "ContaCorrente.hpp"
#include "ContaPoupanca.hpp"

int main()
{
    std::cout << "--- BANCO INICIANDO OPERAÇÕES ---" << std::endl;

    ContaCorrente cc1("CC-101", 500.0, 2.50);
    ContaPoupanca cp1("CP-202", 1000.0);

    std::cout << "\n--- GERENCIANDO CONTAS (POLIMORFISMO) ---" << std::endl;

    std::vector<Conta*> banco;
    
    banco.push_back(&cc1);
    banco.push_back(&cp1);

    std::cout << "\n--- TESTE DE DEPÓSITOS ---" << std::endl;
    for (Conta* conta : banco)
    { conta->depositar(100.0); }

    std::cout << "\n--- TESTE DE SAQUES (POLIMÓRFICOS) ---" << std::endl;
    for (Conta* conta : banco)
    {
        std::cout << "--- Tentando sacar R$500 de " << conta->getNumConta() << " ---" << std::endl;
        conta->sacar(500.0);
    }

    std::cout << "\n--- FIM DAS OPERAÇÕES ---" << std::endl;

return 0;
}