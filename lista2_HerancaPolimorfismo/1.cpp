// Exercício 1: Sistema de Pagamentos de Funcionários

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Funcionario
{
  protected:
    string id;
    string nome;
    string cpf;

  public:
    Funcionario(string i, string n, string c) : id(i), nome(n), cpf(c) {}
    virtual ~Funcionario() { cout << "Funcionário(a) " << nome << " removido" << endl; }

    virtual double calcularPagamento() = 0;
    virtual void gerarDemonstrativo() = 0;
};

class Assalariado : public Funcionario
{
  private:
    double salarioMensal;

  public:
    Assalariado(string i, string n, string c, double s) : Funcionario(i,n,c), salarioMensal(s) {}

    double calcularPagamento() override { return salarioMensal; }

    void gerarDemonstrativo() override
    {
      cout << "-----------------------------------" << endl;
      cout << ">>> ASSALARIADO" << endl;
      cout << "ID: " << id << endl;
      cout << "Nome: " << nome << endl;
      cout << "Salário Base R$: " << salarioMensal << endl;
      cout << "Total à Receber R$: " << calcularPagamento() << endl;
      cout << "-----------------------------------" << endl;
    }
};

class Horista : public Funcionario
{
  private:
    double valorHora;
    double horasTrabalhadas;

  public:
    Horista(string i, string n, string c, double v, double h) : Funcionario(i,n,c), valorHora(v), horasTrabalhadas(h) {}

    double calcularPagamento() override
    {
      if (horasTrabalhadas <= 44)
      { return horasTrabalhadas * valorHora; }
      else
      {
        double horasNormais = 44 * valorHora;
        double horasExtras = horasTrabalhadas - 44;
        return horasNormais + (horasExtras * (valorHora * 1.5));
      }
    }

    void gerarDemonstrativo() override
    {
      cout << "-----------------------------------" << endl;
      cout << ">>> HORISTA" << endl;
      cout << "ID: " << id << endl;
      cout << "Nome: " << nome << endl;
      cout << "Horas Trabalhadas: " << horasTrabalhadas << "h" << endl;
      cout << "Total à Receber R$: " << calcularPagamento() << endl;
      cout << "-----------------------------------" << endl;
    }
};

class Comissionado : public Funcionario
{
  private:
    double salarioBase;
    double totalVendas;
    double percentualComissao;
    const double tetoComissao = 3000.00;

  public:
    Comissionado(string i, string n, string c, double b, double v, double p) : Funcionario(i,n,c), salarioBase(b), totalVendas(v), percentualComissao(p) {}

    double calcularPagamento() override
    { 
        double valorComissao = totalVendas * percentualComissao;
        
        if (valorComissao > tetoComissao)
        { valorComissao = tetoComissao; }

        return salarioBase + valorComissao; 
    }

    void gerarDemonstrativo() override
    {
      cout << "-----------------------------------" << endl;
      cout << ">>> COMISSIONADO" << endl;
      cout << "ID: " << id << endl;
      cout << "Nome: " << nome << endl;
      cout << "Salário Base R$: " << salarioBase << endl;
      cout << "Vendas R$: " << totalVendas << " (Comissão: " << percentualComissao * 100 << "%)" << endl;
      cout << "Total à Receber R$: " << calcularPagamento() << endl;
      cout << "-----------------------------------" << endl;
    }
};

int main()
{
  vector<Funcionario*> folha;

  folha.push_back(new Assalariado("101","Isadora Martins","012.345.678-99",5000.00));
  folha.push_back(new Horista("102","Marcos Souza","987.654.321-00",50.00,50));
  folha.push_back(new Comissionado("103","Marta Mariana","101.112.131-41",1500.00,20000.00,0.05));

  cout << "-----------------------------------" << endl;
  cout << "==== FOLHA DE PAGAMENTO MENSAL ====" << endl;

  for (Funcionario* f : folha)
  { f->gerarDemonstrativo(); }

  for (Funcionario* f : folha)
  { delete f;}
  folha.clear();

return 0;
}