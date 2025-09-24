/* Exercício 8: Em um sistema de e-commerce, o cliente adiciona produtos em um carrinho de
compras. Esse carrinho é usado para gerar um pedido, que inclui informações de pagamento.
Monte as classes necessárias e implemente. */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Produto
{
  private:
    string nome;
    double preco;

  public:
    Produto(string n, double p) : nome(n), preco(p) {}
    ~Produto() {}
    
    const string& getNome() const { return nome; }
    const double& getPreco() const { return preco; }
};

class Cliente
{
  private:
    string nome;
  
  public:
    Cliente(string n) : nome(n) {}
    ~Cliente() {}
    
    const string& getNome() const { return nome; }
};

class Pagamento
{
  private:
    string metodo;
    double valor;

  public:
    Pagamento(string m, double v) : metodo(m), valor(v) {}
    ~Pagamento() {}
    
    void listar() const
    { cout << "Método: " << metodo << "\nValor: R$" << valor << "\n"; }
};

class ItemCarrinho
{
  private:
    Produto* produto;
    int quantidade;
    double preco_unitario;

  public:
    ItemCarrinho(Produto* pd, int q) : produto(pd), quantidade(q), preco_unitario(pd->getPreco()) {}
    ~ItemCarrinho() {}

    double getValorTotal() const
    { return quantidade * preco_unitario; }
    
    void listar() const
    {
      cout << "- " << produto->getNome() << " x" << quantidade << " | Subtotal: R$" << getValorTotal() << "\n";
    }
};

class Pedido
{
  private:
    Cliente* cliente;
    vector<ItemCarrinho> itens;
    Pagamento pagamento;
    
  public:
    Pedido(Cliente* c, const vector<ItemCarrinho>& items, const Pagamento& p)
      : cliente(c), itens(items), pagamento(p) {}
    ~Pedido() {}
    
    void listar() const
    {
      cout << "\n========== PEDIDO FINAL ==========\n\n";
      cout << "Cliente: " << cliente->getNome() << "\n";
      cout << "\nItens do Pedido:\n";
      for (const auto& item : itens)
      { item.listar(); }
      cout << "\nInformações de Pagamento:\n";
      pagamento.listar();
      cout << "\n==================================\n";
    }
};

class Carrinho
{
  private:
    vector<ItemCarrinho> itens;
    
  public:
    ~Carrinho() {}

    void adicionarItem(Produto* produto, int quantidade)
    { itens.emplace_back(produto, quantidade); }
    
    double getValorTotal() const
    {
      double total = 0.0;
      for (const auto& item : itens)
      { total += item.getValorTotal(); }
      return total;
    }
    
    const vector<ItemCarrinho>& getItens() const
    { return itens; }
    
    void listar() const
    {
      cout << "\n------ CARRINHO DE COMPRAS ------\n\n";
      if (itens.empty())
      { cout << "(Vazio)\n"; }
      for (const auto& item : itens)
      { item.listar(); }
      cout << "\n>>>>> Total do Carrinho: R$" << getValorTotal() << "\n";
    }
};

int main()
{
  cout << "\nSISTEMA DE E-COMMERCE\n";

  Produto p1("Notebook", 3500.00);
  Produto p2("Mouse", 40.00);
  Produto p3("Fone Gamer", 100.00);
  Cliente cliente1("Isadora Martins");
  
  Carrinho carrinho1;

  carrinho1.adicionarItem(&p1, 1);
  carrinho1.adicionarItem(&p2, 1);
  carrinho1.adicionarItem(&p3, 1);
  carrinho1.listar();
  
  Pagamento pagamento1("Cartão de Crédito", carrinho1.getValorTotal());
  Pedido pedido1(&cliente1, carrinho1.getItens(), pagamento1);

  pedido1.listar();
    
  cout << "\nFim da execução.\n";

return 0;
}