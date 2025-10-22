#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Livro
{
  private:
    string titulo, autor;
    string ano_pub;

  public:
    Livro(string t, string a, string p) : titulo(t), autor(a), ano_pub(p) {};
    ~Livro() {};

    void listarLivro() const
    { 
      cout << "\nTitulo: " << titulo;
      cout << "\nAutor: " << autor;
      cout << "\nAno de publicação: " << ano_pub;
    }

    const string& getTitle() const { return titulo; }
};

class Biblioteca
{
  private:
    string nome;
    vector<Livro*> acervo;

  public:
    Biblioteca(string n) : nome(n) {};
    ~Biblioteca() {};

    void adicionarLivro(Livro* livro)
    { acervo.push_back(livro); }

    void listarAcervo() const
    {
      cout << "Acervo da Biblioteca - " << nome;
      for(const auto& livro : acervo)
      { livro->listarLivro(); }
    }
};

int main()
{
  Livro livro1("1984","George Orwell","1949");

  Biblioteca myBiblio("MyBiblioteca");

  myBiblio.adicionarLivro(&livro1);
  myBiblio.listarAcervo();

return 0;
}