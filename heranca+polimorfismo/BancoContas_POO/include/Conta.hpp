#ifndef CONTA_HPP
#define CONTA_HPP

#include <iostream>
#include <string>

class Conta
{
    protected:
        std::string numeroConta;
        double saldo;

    public:
        Conta(const std::string& numero, double saldoInicial);
        virtual ~Conta();

        void depositar(double valor);
        virtual bool sacar(double valor) = 0;
        double getSaldo() const;
        std::string getNumConta() const;
};

#endif