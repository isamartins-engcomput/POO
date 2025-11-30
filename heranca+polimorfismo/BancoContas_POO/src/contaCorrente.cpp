#include "ContaCorrente.hpp"

ContaCorrente::ContaCorrente(const std::string& numero, double saldoInicial, double taxa) : Conta(numero, saldoInicial), taxaOperacao(taxa)
{ std::cout << "  -> É uma Conta Corrente com taxa de R$" << this->taxaOperacao << std::endl; }

ContaCorrente::~ContaCorrente()
{ std::cout << "Conta Corrente " << this->numeroConta << " destruída." << std::endl; }

bool ContaCorrente::sacar(double valor)
{
    double valorTotal = valor + this->taxaOperacao;
    
    if (valorTotal <= this->saldo)
    {
        this->saldo -= valorTotal;
        std::cout << "Saque (C/C) de R$" << valor << " (taxa R$" << this->taxaOperacao << "). Saldo novo: R$" << this->saldo << std::endl;
        return true;
    }
    else
    {
        std::cout << "Saque (C/C) negado. Saldo insuficiente (R$" << this->saldo << ") para sacar R$" << valorTotal << std::endl;
        return false;
    }
}