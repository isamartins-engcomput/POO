#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Item
{
  private:
    string nome;
  
  public:
    Item(string n) : nome(n) {}
    ~Item() {}
    
    void listar() const
    { cout << "- Item: " << nome << endl; }
};

class Arma
{
  private:
    string nome;
    int dano;
  
  public:
    Arma(string n, int d) : nome(n), dano(d) {}
    ~Arma() {}
    
    void listar() const
    { cout << "- Arma: " << nome << " (Dano: " << dano << ")" << endl; }

    int getDano() const { return dano; }
};

class Inventario
{
  private:
    vector<Item*> itens_gerais;
    vector<Arma*> armas;

  public:
    ~Inventario() 
    {
      for (Item* item : itens_gerais)
      { delete item; }
      for (Arma* arma : armas)
      { delete arma; }
    }
    
    void adicionarItem(Item* item)
    { itens_gerais.push_back(item); }
    
    void adicionarArma(Arma* arma)
    { armas.push_back(arma); }
    
    void listar() const
    {
      cout << "\n--- Inventário ---\n";
      if (itens_gerais.empty() && armas.empty())
      { cout << "(Vazio)\n"; }
      
      for (const auto& item : itens_gerais)
      { item->listar(); }
      
      for (const auto& arma : armas)
      { arma->listar(); }
    }
};

class Jogador
{
  private:
    string nome;
    Inventario inventario;

  public:
    Jogador(string n) : nome(n), inventario() {}
    ~Jogador() {}
    
    Inventario& getInventario() { return inventario; }
    const string& getNome() const { return nome; }
};

class Inimigo
{
  private:
    string nome;
    Arma* arma;

  public:
    Inimigo(string n, Arma* a = nullptr) : nome(n), arma(a) {}
    ~Inimigo() {}
    
    void listar() const
    {
      cout << "\n--- " << nome << " ---\n";
      cout << "Equipado com: ";
      if (arma)
      { arma->listar(); }
      else
      { cout << "(Nenhuma arma)\n"; }
    }
};

int main()
{
  cout << "\nESTRUTURA DE CLASSES PARA UM JOGO DE AVENTURA\n";

  cout << "\n########## INÍCIO DO JOGO ##########\n";
  
  Item* pocao = new Item("Poção de Vida");
  Arma* espada = new Arma("Espada de Fogo", 25);
  Arma* arco = new Arma("Arco e Flecha", 10);
  
  Jogador jogador("Isadora Aventureira");
  
  jogador.getInventario().adicionarItem(pocao);
  jogador.getInventario().adicionarArma(espada);
  
  Inimigo inimigo1("Goblin", arco);
  Inimigo inimigo2("Dragão");

  cout << "\nEstado atual:\n\n";
  cout << ">>>>> Jogador(a): " << jogador.getNome() << endl;
  jogador.getInventario().listar();
  
  inimigo1.listar();
  inimigo2.listar();
  
  cout << "\n########### FIM DO JOGO! ###########\n\n";

  delete arco;

return 0;
}