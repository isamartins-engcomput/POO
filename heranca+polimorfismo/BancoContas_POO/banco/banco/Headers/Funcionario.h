#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "Pessoa.h"
#include <string>

class Funcionario;

class Funcionario : public Pessoa {

    private:
        int id;
        int matricula;
        std::string cargo;
        double salario;

    public:
        // Construtor
        Funcionario(const std::string& nome, const std::string& cpf, const std::string& endereco, const std::string& telefone,
                    int id, int matricula, const std::string& cargo, double salario)
            : Pessoa(nome, cpf, endereco, telefone), id(id), matricula(matricula), cargo(cargo), salario(salario) {}        

        // Getters
        int getId() const { return id; }
        int getMatricula() const { return matricula; }
        std::string getCargo() const { return cargo; }
        double getSalario() const { return salario; }

        // Setters
        void setId(int id) { this->id = id; }
        void setMatricula(int matricula) { this->matricula = matricula; }
        void setCargo(const std::string& cargo) { this->cargo = cargo; }
        void setSalario(double salario) { this->salario = salario; }    

        void exibirDadosBasicos() override;

};


#endif

