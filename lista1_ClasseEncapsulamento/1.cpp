/* Exercício 1: Uma pequena biblioteca deseja informatizar seu acervo. Ela guarda vários
livros, cada um com informações básicas como título, autor e ano de publicação. O sistema
deve permitir registrar os livros e listá-los. */

// Classe: Livro
// Atributos: título, autor e ano de publicação
// Métodos: registrarLivro e listarLivro

#include <iostream>

using namespace std ;

class Livro
{
  private:
    string titulo, autor;
    int ano_pub;

  public:
    
    // Construtor vazio (permite eu criar o objeto sem dados por enquanto)
    Livro() : titulo(""), autor(""), ano_pub(0) {}
    
    // Método para registrar os dados do Livro
    void registrarLivro(string t, string a, int p)
    { 
      titulo = t;
      autor = a;
      ano_pub = p;
    }

    // Método para listar os dados do Livro
    void listarLivro()
    {
      cout << "\nTítulo: " << titulo;
      cout << "\nAutor: " << autor;
      cout << "\nAno de publicação: " << ano_pub;
      cout << "\n";
    }
};

int main()
{
  Livro livro1, livro2, livro3;

  cout << "\n|====|~ LIVROS REGISTRADOS ~|====|\n";

  livro1.registrarLivro("1984","George Orwell",1949);
  livro1.listarLivro();
  
  livro2.registrarLivro("Todo esse tempo","Mikki Daughtry",2020);
  livro2.listarLivro();

  livro3.registrarLivro("Perdido em Marte","Andy Weir",2011);
  livro3.listarLivro();

  cout << "\n==================================\n\n";

return 0;
}