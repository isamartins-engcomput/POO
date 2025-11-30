#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Funcionario
{
  protected:
    float salario;
    
  public:
    Funcionario(float s) : salario(s) {}
    virtual ~Funcionario() {}
    
    virtual void relatorio() = 0;
};

class Gerente : public Funcionario
{
  private:
    float bonus;
    
  public:
    Gerente(float s, float b) : Funcionario(s), bonus(b) {}
    
    float aumentarSalario(float bonus)
    {
      salario = salario + bonus;
      return salario;
    }
    
    void relatorio() override
    {
      cout << "GERENTE" << endl;
      cout << "Salário turbinado para: " << salario << endl;
    }
};

int main()
{
  vector<Funcionario*> cargo;
  
  cargo.push_back(new Gerente(1000.00,250.00));
  
  for(Funcionario* f : cargo)
  {
    f->relatorio();
    
    Gerente* g = dynamic_cast<Gerente*>(f);
    
    if(g != nullptr)
    { 
      g->aumentarSalario(500.0);
      g->relatorio();
    }
  }
  
  for(Funcionario* f : cargo)
  { delete f; }
  cargo.clear();
  
return 0;
}
