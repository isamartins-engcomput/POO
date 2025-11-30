#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Cliente
{
  protected:
    string nome;
    string cpf;
    int idade;
  
  public:
    Cliente(string n, string c, int i) : nome(n), cpf(c), idade(i) { cout << "Cliente criado!" << endl; }
    virtual ~Cliente() { cout << "Cliente deletado!" << endl; }
    
    virtual void imprimirDados() = 0;
};

class ClienteVIP : public Cliente
{
  private:
    int pontosFidelidade;
    
  public:
    ClienteVIP(string n, string c, int i, int p) : Cliente(n, c, i), pontosFidelidade(p)
    { cout << "ClienteVIP criado!" << endl; }
    
    void imprimirDados() override
    {
      cout << "===== Dados do ClienteVIP =====" << endl;
      cout << "Nome: " << this->nome << endl;
      cout << "CPF: " << this->cpf << endl;
      cout << "Idade: " << this->idade << endl;
      cout << "Pontos Fidelidade: " << pontosFidelidade << endl;
    }
    
    int ganharPontos(int pontos)
    { 
      pontosFidelidade = pontosFidelidade + pontos;
      return pontosFidelidade;
    }
};

/* int main() // + SIMPLES
 * {
 *    ClienteVIP vip("Isadora Martins","012.345.678-99",19,20);
 *    vip.imprimirDados();
 *
 *    return 0;
 * }
*/

int main()
{
  vector<Cliente*> listaClientes;
  
  listaClientes.push_back(new ClienteVIP("Isadora Martins","012.345.678-99",19,20));
  
  for (Cliente* cliente : listaClientes)
  { 
    ClienteVIP* vip = dynamic_cast<ClienteVIP*>(cliente);
    if(vip != nullptr)
    {
      vip->imprimirDados();
    cout << "Pontos Fidelidade do ClienteVIP: " << vip->ganharPontos(50) << endl;
    }
  }
  
  for (Cliente* cliente : listaClientes)
  { 
    delete cliente;
    listaClientes.clear();
  }
  
return 0;
}
