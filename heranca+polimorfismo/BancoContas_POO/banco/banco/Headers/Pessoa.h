#ifndef PESSOA_H
#define PESSOA_H

#include <string>

class Pessoa {
    protected:
        std::string nome;
        std::string cpf;
        std::string endereco;  //
        std::string telefone;

    public:
        // Construtor
        Pessoa(const std::string& nome, const std::string& cpf, const std::string& endereco, const std::string& telefone)
            : nome(nome), cpf(cpf), endereco(endereco), telefone(telefone) {}

        // Getters
        std::string getNome() const { return nome; }
        std::string getCpf() const { return cpf; }
        std::string getEndereco() const { return endereco; }
        std::string getTelefone() const { return telefone; }

        // Setters
        void setNome(const std::string& nome) { this->nome = nome; }
        void setCpf(const std::string& cpf) { this->cpf = cpf; }
        void setEndereco(const std::string& endereco) { this->endereco = endereco; }
        void setTelefone(const std::string& telefone) { this->telefone = telefone; }


        virtual void exibirDadosBasicos() = 0; 

};
#endif