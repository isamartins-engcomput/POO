#include "ContaPoupanca.hpp"

ContaPoupanca::ContaPoupanca(const std::string& numero, double saldoInicial) : Conta(numero, saldoInicial)
{ std::cout << "  -> É uma Conta Poupança." << std::endl; }

ContaPoupanca::~ContaPoupanca()
{ std::cout << "Conta Poupança " << this->numeroConta << " destruída." << std::endl; }

bool ContaPoupanca::sacar(double valor)
{
    if (valor <= this->saldo)
    {
        this->saldo -= valor;
        std::cout << "Saque (C/P) de R$" << valor << ". Saldo novo: R$" << this->saldo << std::endl;
        return true;
    }
    else
    {
        std::cout << "Saque (C/P) negado. Saldo insuficiente (R$" << this->saldo << ") para sacar R$" << valor << std::endl;
        return false;
    }
}