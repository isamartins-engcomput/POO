#include <iostream>
#include <vector> // Add vector, que é tipo uma lista dinâmica de objetos
#include <string>

using namespace std;

class Livro
{
  private:
    string titulo, autor;
    int ano_pub;

  public:
    Livro(string t, string a, int p) : titulo(t), autor(a), ano_pub(p)
    { cout << "Livro '" << titulo << "' criado!\n"; }

    // Destrutor: método de limpeza da memória chamado para destruir um objeto
    ~Livro() { cout << "Livro '" << titulo << "' destruído!\n"; }

    /* Método para exibir os dados do livro.
    'const' serve para dizer ao compilador que esse método não vai
    alterar em nada os atributos do objeto. */
    void listarLivro() const
    {
      cout << "\nTítulo: " << titulo;
      cout << "\nAutor: " << autor;
      cout << "\nAno de publicação: " << ano_pub;
      cout << "\n";
    }
    
    /* Método 'getter' (método de acesso): retorna algo, nesse caso o título do livro.
    O '&' faz com que a string seja retornada por referência,
    evitando cópias e otimizando o código. */
    const string& getTitle() const { return titulo; }
};

/* Classe Biblioteca: vai gerenciar uma coleção de Livros.
Relação entre Biblioteca e Livro -> AGREGAÇÃO
A Biblioteca tem livros, mas os livros existem independentemente dela.
Por isso, usamos um ponteiro para o Livro. */
class Biblioteca
{
  private:
    string nome;
    // Agregação: usamos um vector de PONTEIROS para Livros.
    // Biblioteca não 'possui' os livros, ela apenas 'aponta' para eles.
    vector<Livro*> acervo; 

  public:
    Biblioteca(string n) : nome(n)
    { cout << "Biblioteca '" << nome << "' criada.\n"; }

    /* Destrutor da Biblioteca não deleta os Livros, pois o ciclo de vida do
    Livro não depende da Biblioteca (agregação) */
    ~Biblioteca() { cout << "\nBiblioteca '" << nome << "' destruída.\n"; }

    // Método para registrar/adicionar um Livro ao acervo. Recebe um PONTEIRO para um Livro.
    // O push_back() serve para adicionar um novo elemento ao final do vector.
    void registrarLivro(Livro* livro)
    { acervo.push_back(livro); }

    // Método para listar o acervo da biblioteca.
    void listarAcervo() const
    {
      cout << "\n===== ACERVO DA BIBLIOTECA '" << nome << "' =====\n";
      // Loop 'for' para percorrer o vector acervo.
      // 'const auto&' garante que não faremos cópias e nem modificaremos os ponteiros.
      for (const auto& livro : acervo)
      { livro->listarLivro(); } // '->' desreferencia o ponteiro e acessa o elemento
      cout << "\n==========================================\n";
    }
};

int main()
{
  cout << "\nSISTEMA DE GERENCIAMENTO DE LIVROS PARA BIBLIOTECA\n\n";

  Livro livro1("1984", "George Orwell", 1949);
  Livro livro2("Todo esse tempo", "Mikki Daughtry", 2020);
  Livro livro3("Perdido em Marte", "Andy Weir", 2011);

  // Criação da Biblioteca
  Biblioteca minha_biblioteca("Central");

  // Adicionando os livros à biblioteca...
  // A Biblioteca não recebe o objeto em si, mas o "endereço" dele.
  minha_biblioteca.registrarLivro(&livro1);
  minha_biblioteca.registrarLivro(&livro2);
  minha_biblioteca.registrarLivro(&livro3);
  
  // Chama o método para listar o acervo, que vai percorrer os ponteiros.
  minha_biblioteca.listarAcervo();

  // A ordem de destruição será a inversa da criação:
  // 1. minha_biblioteca
  // 2. livro3
  // 3. livro2
  // 4. livro1

return 0;
}