#include "Conta.hpp"

Conta::Conta(const std::string& numero, double saldoInicial) : numeroConta(numero), saldo(saldoInicial)
{ std::cout << "Conta base " << this->numeroConta << " criada com R$" << this->saldo << std::endl; }

Conta::~Conta()
{ std::cout << "Conta base " << this->numeroConta << " destruída." << std::endl; }

void Conta::depositar(double valor)
{
    if (valor > 0)
    {
        this->saldo += valor;
        std::cout << "Depósito de R$" << valor << " em " << this->numeroConta << ". Saldo novo: R$" << this->saldo << std::endl;
    }
    else 
    { std::cout << "Valor de depósito inválido." << std::endl; }
}

double Conta::getSaldo() const
{ return this->saldo; }

std::string Conta::getNumConta() const
{ return this->numeroConta; }