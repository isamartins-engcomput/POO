#ifndef TRANSACAO_H
#define TRANSACAO_H

#include <string>
#include <ctime>

enum class TipoTransacao {
    DEPOSITO,
    SAQUE,
    TRANSFERENCIA,
    SALDO_INICIAL
};

class Transacao {
private:
    int id;
    std::string numeroConta;
    TipoTransacao tipo;
    double valor;
    std::string descricao;
    std::time_t dataHora;
    std::string contaDestino; // Para transferências

public:
    Transacao();
    Transacao(int id, const std::string& numeroConta, TipoTransacao tipo,
              double valor, const std::string& descricao = "");
    Transacao(int id, const std::string& numeroConta, TipoTransacao tipo,
              double valor, const std::string& contaDestino,
              const std::string& descricao);
    ~Transacao();
    
    // Getters
    int getId() const;
    std::string getNumeroConta() const;
    TipoTransacao getTipo() const;
    double getValor() const;
    std::string getDescricao() const;
    std::time_t getDataHora() const;
    std::string getContaDestino() const;
    
    // Método para obter string do tipo
    std::string getTipoString() const;
    
    // Método para exibir transação
    void exibir() const;
};

#endif

