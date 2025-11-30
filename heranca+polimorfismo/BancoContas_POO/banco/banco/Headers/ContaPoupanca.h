#ifndef CONTA_POUPANCA_H
#define CONTA_POUPANCA_H

#include "Conta.h"

class ContaPoupanca : public Conta {
private:
    double taxaRendimento;
    int diaAniversario; // Dia do mês para aplicar rendimento

public:
    ContaPoupanca();
    ContaPoupanca(const std::string& numeroConta, Cliente* cliente,
                  double saldoInicial = 0.0, double taxaRendimento = 0.5,
                  int diaAniversario = 1);
    virtual ~ContaPoupanca();
    
    // Getters
    double getTaxaRendimento() const;
    int getDiaAniversario() const;
    
    // Setters
    void setTaxaRendimento(double taxa);
    void setDiaAniversario(int dia);
    
    // Sobrescrita de métodos
    bool sacar(double valor) override;
    double calcularTaxa() const override;
    
    // Método específico para aplicar rendimento
    void aplicarRendimento();
    
    // Sobrescrita do método de exibição
    void exibirInformacoes() const override;
};

#endif

