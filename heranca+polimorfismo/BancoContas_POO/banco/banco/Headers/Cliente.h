#ifndef CLIENTE_H
#define CLIENTE_H

#include "Pessoa.h"
#include <vector>

class Conta; // Declaração antecipada da classe Conta 'forward declaration'

class Cliente : public Pessoa {

    private:
        int numeroCliente;
    
        std::vector<Conta> contasAssociadas; // IDs das contas associadas ao cliente
    public:
        // Construtor
        Cliente(const std::string& nome, const std::string& cpf, const std::string& endereco, const std::string& telefone, int numeroCliente)
            : Pessoa(nome, cpf, endereco, telefone), numeroCliente(numeroCliente) {}

        void adicionarConta(Conta* conta);
        void removerConta(Conta* conta);

        std::vector<Conta*> getContasAssociadas() const;

        
        void exibirDadosBasicos() override;
};


#endif