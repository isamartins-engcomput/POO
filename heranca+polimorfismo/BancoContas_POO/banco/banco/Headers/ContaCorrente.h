#ifndef CONTA_CORRENTE_H
#define CONTA_CORRENTE_H

#include "Conta.h"

class ContaCorrente : public Conta {
private:
    double limiteChequeEspecial;
    double taxaManutencao;

public:
    ContaCorrente();
    ContaCorrente(const std::string& numeroConta, Cliente* cliente,
                  double saldoInicial = 0.0, double limiteChequeEspecial = 0.0,
                  double taxaManutencao = 0.0);
    virtual ~ContaCorrente();
    
    // Getters
    double getLimiteChequeEspecial() const;
    double getTaxaManutencao() const;
    
    // Setters
    void setLimiteChequeEspecial(double limite);
    void setTaxaManutencao(double taxa);
    
    // Sobrescrita de métodos
    bool sacar(double valor) override;
    bool depositar(double valor) override;
    double calcularTaxa() const override;
    
    // Método específico para usar cheque especial
    bool usarChequeEspecial(double valor);
    
    // Sobrescrita do método de exibição
    void exibirInformacoes() const override;
};

#endif

