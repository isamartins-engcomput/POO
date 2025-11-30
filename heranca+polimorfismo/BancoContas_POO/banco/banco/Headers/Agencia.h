#ifndef AGENCIA_H
#define AGENCIA_H

#include "Conta.h"
#include "Cliente.h"
#include "Funcionario.h"
#include <string>
#include <vector>

class Agencia {
private:
    int numero;
    std::string nome;
    std::string endereco;
    std::string telefone;
   
    std::vector<Conta*> contas;
    std::vector<Cliente*> clientes;
    std::vector<Funcionario*> funcionarios;

public:
    Agencia();
    Agencia(int numero, const std::string& nome, const std::string& endereco,
            const std::string& telefone);
    ~Agencia();
    
    // Getters
    int getNumero() const;
    std::string getNome() const;
    std::string getEndereco() const;
    std::string getTelefone() const;
    std::vector<Conta*> getContas() const;
    std::vector<Cliente*> getClientes() const;
    std::vector<Funcionario*> getFuncionarios() const;
    
    // Métodos para gerenciar contas
    void adicionarConta(Conta* conta);
    void removerConta(Conta* conta);
    Conta* buscarConta(const std::string& numeroConta) const;
    
    // Métodos para gerenciar clientes
    void adicionarCliente(Cliente* cliente);
    void removerCliente(Cliente* cliente);
    Cliente* buscarCliente(int numeroCliente) const;
    Cliente* buscarClientePorCpf(const std::string& cpf) const;
    
    // Métodos para gerenciar funcionários
    void adicionarFuncionario(Funcionario* funcionario);
    void removerFuncionario(Funcionario* funcionario);
    Funcionario* buscarFuncionario(int matricula) const;
    
    // Método para exibir informações da agência
    void exibirInformacoes() const;
    
    // Método para gerar relatório
    void gerarRelatorio() const;
};

#endif

