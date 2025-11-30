#ifndef CONTA_CORRENTE_HPP
#define CONTA_CORRENTE_HPP

#include "Conta.hpp"

class ContaCorrente : public Conta
{
    private:
        double taxaOperacao;

    public:
        ContaCorrente(const std::string& numero, double saldoInicial, double taxa);
        ~ContaCorrente();

        bool sacar(double valor) override;
};

#endif