#ifndef CONTA_POUPANCA_HPP
#define CONTA_POUPANCA_HPP

#include "Conta.hpp"

class ContaPoupanca : public Conta
{
    public:
        ContaPoupanca(const std::string& numero, double saldoInicial);
        ~ContaPoupanca();

        bool sacar(double valor) override;
};

#endif