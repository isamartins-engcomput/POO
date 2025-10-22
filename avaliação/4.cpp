// EXERCÍCIO 4 - Implementação em C++ de um Sistema de E-Commerce
// Estudante: Isadora Martins - Eng.Comput3

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Produto
{
    private:
        string nome;
        float valor;

    public:
        Produto(string n, float v) : nome(n), valor(v) { cout << "\nProduto criado!"; };
        ~Produto() { cout << "\nProduto destruído!"; };

        const string& getName() { return nome; };
        const float& getValue() { return valor; };
};


class Item
{
    private:
        vector<Produto*> produto; // AGREGAÇÃO
        int qtd;

    public:
        Item(int q) : qtd(q) { cout << "\nItem criado!"; };
        ~Item() { cout << "\nItem destruído!"; };
};

class Carrinho
{
    private:
        vector<Produto*> produto; // AGREGAÇÃO

    public:
        Carrinho() : { cout << "\nCarrinho criado!"; };
        ~Carrinho() { cout << "\nCarrinho destruído!"; };

        void adicionarItem()
        {
            produto.push_back(item);
        }
};

class Pedido
{
    private:
        vector<Carrinho*> carrinho; // COMPOSIÇÃO
        string total;

    public:
        Pedido(string t) : total(t) { cout << "\nPedido criado!"; };
        ~Pedido() { cout << "\nPedido destruído!"; };

        void const listarItens(item)
        {
            for(const auto& item)
            { item->Carrinho*}
        }
};

class Pagamento
{
    private:
        string modo;
        string status;

    public:
        Pagamento(string m, string s) : modo(m), status(s) { cout << "\nPagamento criado!"; };
        ~Pagamento() { cout << "\nPagamento destruído!"; };
};

int main()
{
    cout << "\n===== SISTEMA DE GERENCIAMENTO PARA E-COMMERCE =====\n";

    Item item1("Banana","1.00","2");
    Item item2("Snickers","5.00","1");
    Item item3("Água","5.00","1");

return 0;
}