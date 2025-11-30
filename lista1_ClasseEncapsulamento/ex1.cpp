#include <iostream>

using namespace std; // reúne todas as bibliotecas mais usadas no C++ em um único espaço

class Livro
{
  // Modificadores de acesso -> Nível de visibilidade dos atributos e métodos

  private:
    // private -> Visibilidade privada somente à classe
    // Quando os atr estão privados, damos o nome de encapsulamento

    string isbn, titulo, autor;
    bool disponivel{true};

  public:
    // public -> Todo mundo vai ter acesso

    Livro(string i, string t, string a) : isbn(move(i)), titulo(move(t)), autor(move(a)) {} // rvalue -> move um valor pra outra variável
    
    bool estaDisponivel() const { return disponivel; }
    
    void marcarIndisponivel() { disponivel = false; }
    void marcarDisponivel() { disponivel = true; } // poderia ser um if e else dentro da função estaDisponivel

    string getTitle() { return titulo; }
};

class Aluno
{
  private:
    string ra, nome;

  public:
    Aluno(string r, string n) : ra(move(r)), nome(move(n)) {}

    string getName() { return nome; }
};

class Emprestimo
{
  private:
    Livro* livro;
    Aluno* aluno;
    string dataEmprestada, dataDevolutiva;
    bool devolvido{false};

  public:
    Emprestimo(Livro* l, Aluno* a, string saida, string prevista) : livro(l), aluno(a), dataEmprestada(move(saida)), dataDevolutiva(move(prevista)) {}
    
    bool confirmar()
    {
      if(livro && livro->estaDisponivel())
      {
        livro->marcarIndisponivel();
        return true;
      }
      return false;
    }

    void devolver(string dataDevolutiva)
    {
      if(livro)
      {
        livro->estaDisponivel();
        cout << "Livro " << livro->getTitle() << " devolvido em: " << dataDevolutiva << "\n";
      }
    }
};

void testeBiblioteca()
{
  cout << "|=====> BIBLIOTECA <=====|\n";

  Livro l("192-3819","POO","IFMS");
  Aluno a("4562","Isadora");

  Emprestimo e(&l,&a,"2025-09-09","2025-10-09");
  e.confirmar();
  e.devolver("2025-10-09");
}

int main()
{
  testeBiblioteca();
  return 0;
}