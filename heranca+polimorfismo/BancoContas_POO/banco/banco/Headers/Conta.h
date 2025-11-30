#ifndef CONTA_H
#define CONTA_H

#include "Transacao.h"
#include "Cliente.h"
#include <string>
#include <vector>


class Conta {
protected:
    std::string numeroConta;
  
    Cliente* cliente;
    double saldo;
  
    std::vector<Transacao*> transacoes;
    static int proximoIdTransacao;

public:
    Conta();
    Conta(const std::string& numeroConta, Cliente* cliente, double saldoInicial = 0.0);
    virtual ~Conta();
    
    // Getters
    std::string getNumeroConta() const;
    Cliente* getCliente() const;
    double getSaldo() const;
    std::vector<Transacao*> getTransacoes() const;
    
    // Métodos principais
    virtual bool sacar(double valor);
    virtual bool depositar(double valor);
    virtual bool transferir(Conta* contaDestino, double valor);
    
    // Método virtual para calcular taxa (será sobrescrito nas classes filhas)
    virtual double calcularTaxa() const = 0;
    
    // Métodos de extrato
    void exibirExtrato() const;
    void exibirExtratoPorPeriodo(const std::time_t& dataInicio, 
                                  const std::time_t& dataFim) const;
    
    // Método virtual para exibir informações
    virtual void exibirInformacoes() const;
    
    // Método para adicionar transação (protegido para uso interno)
protected:
    void adicionarTransacao(TipoTransacao tipo, double valor, 
                           const std::string& descricao = "");
    void adicionarTransacaoTransferencia(TipoTransacao tipo, double valor,
                                        const std::string& contaDestino,
                                        const std::string& descricao = "");
};

#endif

