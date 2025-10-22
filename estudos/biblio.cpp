#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Livro
{
  private:
    string titulo, autor;
    int ano_pub;
  
  public:
    Livro (string t, string a, int p) : titulo(t), autor(a), ano_pub(p) {};
    ~Livro();

    void listarLivro() const {}

    const string& getTitle() { return titulo; }
};

class Biblioteca
{
  private:
    string nome;
    vector<Livro*> acervo;

  public:
      Biblioteca(string n) : nome(n) {};
      ~Biblioteca();

      void adicionarLivro(Livro* livro)
      { acervo.push_back(livro); }

      void listarAcervo()
      {

      }
};  