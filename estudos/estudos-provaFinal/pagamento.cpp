#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pagamento
{
  protected:
    float valor;
    
  public:
    Pagamento(float v) : valor(v) {}
    virtual ~Pagamento() {}
    
    virtual void processar() = 0;
};

class Pix : public Pagamento
{
  protected:
    string chave;
    
  public:
    Pix(float v, string c) : Pagamento(v), chave(c) {}
    
    void processar() override
    {
      cout << ">>> Gerando QR Code..." << endl;
    }
};

class Cartao : public Pagamento
{
  protected:
    string num;
    
  public:
    Cartao(float v, string n) : Pagamento(v), num(n) {}
    
    void processar() override
    {
      cout << ">>> Verificando limite..." << endl;
    }
};

int main()
{
  vector<Pagamento*> pagamentos;
  
  pagamentos.push_back(new Pix(100.55,"0XABCISA06"));
  pagamentos.push_back(new Cartao(99.5,"123456789"));
  
  for(Pagamento* p : pagamentos)
  { p->processar(); }
  
  for(Pagamento* p : pagamentos)
  { delete p; }
  pagamentos.clear();

return 0;
}
