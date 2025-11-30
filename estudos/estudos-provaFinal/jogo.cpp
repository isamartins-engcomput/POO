#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Item
{
  protected:
    string habilidade;
    
  public:
    Item(string h) : habilidade(h) { cout << "Item criado!" << endl; }
    virtual ~Item() { cout << "Item destruído!" << endl; }
    
    virtual void listarItem() = 0;
};

class Pocao : public Item
{
  private:
    string rec_vida;
  
  public:
    Pocao(string h, string v) : Item(h), rec_vida(v) { cout << "Poção criada!" << endl; }
    
    void beber() { cout << ">>> Glup glup! Vida recuperada: " << rec_vida << endl; };
    
    void listarItem() override
    { cout << "[POCAO] " << habilidade << " | Vida: " << rec_vida << endl; }
};

class Arma : public Item
{
  private:
    string dano;
  
  public:
    Arma(string h, string d) : Item(h), dano(d) { cout << "Arma criada!" << endl; }
    
    void atacar() { cout << ">>> POW! Dano causado: " << dano << endl; };
    
    void listarItem() override
    { cout << "[ARMA] " << habilidade << " | Dano: " << dano << endl; }
};

int main()
{
  vector<Item*> listaItens;
  
  listaItens.push_back(new Pocao("Cura Leve","50HP"));
  listaItens.push_back(new Arma("Espada","100 Atk"));
  
  cout << "--- INICIO DO JOGO ---" << endl;
  
  for (Item* i : listaItens)
  { 
    i->listarItem();
    
    Pocao* p = dynamic_cast<Pocao*>(i);
    Arma* a = dynamic_cast<Arma*>(i);
    
    if(p != nullptr)
    { p->beber(); }
    else if (a != nullptr)
    { a->atacar(); }
  }
  
  cout << "--- FIM DO JOGO ---" << endl;
  
  for (Item* i : listaItens)
  { delete i; }
  listaItens.clear();
  
return 0;
}
