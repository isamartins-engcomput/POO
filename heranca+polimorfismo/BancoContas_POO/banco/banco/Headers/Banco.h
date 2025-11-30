#ifndef BANCO_H
#define BANCO_H

#include "Agencia.h"
#include <string>
#include <vector>

class Banco {
private:
    std::string nome;
    std::string cnpj;
    std::string endereco;

    std::vector<Agencia*> agencias;

public:
    Banco();
    Banco(const std::string& nome, const std::string& cnpj,
          const std::string& endereco);
    ~Banco();
    
    // Getters
    std::string getNome() const;
    std::string getCnpj() const;
    std::string getEndereco() const;
    std::vector<Agencia*> getAgencias() const;
    
    // Métodos para gerenciar agências
    void adicionarAgencia(Agencia* agencia);
    void removerAgencia(Agencia* agencia);
    Agencia* buscarAgencia(int numero) const;
    
    // Método para exibir informações do banco
    void exibirInformacoes() const;
    
    // Método para gerar relatório geral
    void gerarRelatorioGeral() const;
};

#endif

