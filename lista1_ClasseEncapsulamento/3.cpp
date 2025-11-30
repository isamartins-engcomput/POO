/* Exercício 3: Uma loja virtual registra pedidos de clientes. Cada pedido possui itens
(com produto, quantidade e preço unitário) e está vinculado a um cliente. O sistema deve
calcular o valor total do pedido. Descubra as classes e implemente. */

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
    Produto(string n, double p) : nome(n), preco(p)
    { cout << "Produto '" << nome << "' criado!\n"; }
    
    ~Produto() { cout << "Produto '" << nome << "' destruído!\n"; }
    
    const string& getName() const { return nome; }
    const double& getPreco() const { return preco; }
};

class ItemPedido
{
  private:
    Produto* produto;
    int qtd;
    double preco;

  public:
    ItemPedido(Produto* pd, int q, double p) : produto(pd), qtd(q), preco(p)
    { cout << "Item pedido '" << produto->getName() << "' criado!\n"; }
    
    ~ItemPedido() { cout << "Item pedido '" << produto->getName() << "' destruído!\n"; }
    
    double getValorSubtotal() const { return qtd * preco; }

    void listarItem() const
    {
      cout << "\nProduto: " << produto->getName();
      cout << "\nQuantidade: " << qtd;
      cout << "\nPreço unitário: R$" << preco;
      cout << "\nSubtotal: R$" << getValorSubtotal() << "\n";
    }
};

class Cliente
{
  private:
    string nome;

  public:
    Cliente(string n) : nome(n)
    { cout << "Cliente '" << nome << "' criado!\n"; }
    
    ~Cliente() { cout << "Cliente '" << nome << "' destruído!\n"; }

    const string& getName() const { return nome; }
};

class Pedido
{
  private:
    string data;
    Cliente* cliente;
    vector<ItemPedido> itens;

  public:
    Pedido(string d, Cliente* c) : data(d), cliente(c)
    { cout << "Pedido da data'" << data << "' criado!\n"; }
    
    ~Pedido() { cout << "Pedido da data '" << data << "' destruído!\n"; }

    void adicionarItem(Produto* produto, int qtd, double preco)
    {
      // 'emplace_back' para construir o objeto ItemPedido diretamente no vetor,
      itens.emplace_back(produto, qtd, preco); 
    }

    double calcularValorTotal() const
    {
      double total = 0.0;
      for (const auto& item : itens)
      { total += item.getValorSubtotal(); }
      return total;
    }

    void listarPedido() const
    {
      cout << "\n===== PEDIDO DE '" << cliente->getName() << "' =====\n\n";
      cout << "Data: " << data << "\n";
      cout << "\nItens do pedido:\n";
      for (const auto& item : itens)
      { item.listarItem(); }
      cout << "\nVALOR TOTAL: R$" << calcularValorTotal() << "\n\n";
      cout << "======================================\n\n";
    }
};

int main()
{
  cout << "\nSISTEMA DE GERENCIAMENTO DE PEDIDOS\n\n";

  Produto produto1("Banana", 1.50);
  Produto produto2("Snickers", 5.00);
  Produto produto3("Trident", 2.00);

  Cliente cliente("Isadora Martins");

  Pedido pedido("22/09/2025",&cliente);

  pedido.adicionarItem(&produto1, 2, produto1.getPreco());
  pedido.adicionarItem(&produto2, 1, produto2.getPreco());
  pedido.adicionarItem(&produto3, 1,produto3.getPreco());

  pedido.listarPedido();

return 0;
}