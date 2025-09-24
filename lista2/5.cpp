/* Exercício 5: Uma instituição de ensino organiza cursos, que possuem várias turmas.
Cada turma é conduzida por um professor e contém vários alunos matriculados. Represente
esse cenário com classes em C++. */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Professor
{
  private:
    string nome;
    string disciplina;

  public:
    Professor(string n, string d) : nome(n), disciplina(d) {}
    ~Professor() {}

    const string& getName() const { return nome; }
    const string& getDisciplina() const { return disciplina; }
};

class Aluno
{
  private:
    string nome;
    string matricula;

  public:
    Aluno(string n, string m) : nome(n), matricula(m) {}
    ~Aluno() {}

    const string& getName() const { return nome; }
    const string& getMatricula() const { return matricula; }
};

// Classe Turma: contém Professor (Agregação) e Alunos (Agregação)
class Turma
{
  private:
    string codigo;
    Professor* professor;
    vector<Aluno*> alunos;

  public:
    Turma(string c, Professor* p) : codigo(c), professor(p) {}
    ~Turma() {}
    
    void matricularAluno(Aluno* a)
    { alunos.push_back(a); }
    
    void listarTurma() const
    {
      cout << "\nTURMA: '" << codigo << "'\n";
      cout << "\nProfessor: " << professor->getName() << " (" << professor->getDisciplina() << ")\n";
      cout << "\nAlunos Matriculados:\n\n";
      for (const auto& aluno : alunos)
      { cout << "- " << aluno->getName() << " (" << aluno->getMatricula() << ")\n"; }
    }
};

class Curso
{
  private:
    string nome;
    vector<Turma> turmas;

  public:
    Curso(string n) : nome(n) {}
    ~Curso() {}

    void adicionarTurma(string codigo, Professor* professor)
    { turmas.emplace_back(codigo, professor); }
    
    void listarCurso() const
    {
      cout << "\n>>>>> CURSO: '" << nome << "' <<<<<\n";
      for (const auto& turma : turmas)
      { turma.listarTurma(); }
    }

    Turma& getTurma(int indice) { return turmas.at(indice); }
    
};

class Instituicao
{
  private:
    string nome;
    vector<Curso> cursos;

  public:
    Instituicao(string n) : nome(n) {}
    ~Instituicao() {}

    void adicionarCurso(string nome)
    { cursos.emplace_back(nome); }

    void listarInstituicao() const
    {
      cout << "\n=============== INSTITUIÇÃO: '" << nome << "' ===============\n";
      for (const auto& curso : cursos)
      { curso.listarCurso(); }
    }

    Curso& getCurso(int indice) { return cursos.at(indice); }
};

int main()
{
  cout << "\nSISTEMA DE GERENCIAMENTO DE CURSOS E TURMAS\n";

  Professor prof_poo("Beto", "POO");
  Professor prof_algoritmos("Rogério", "Algoritmos");

  Aluno aluno1("Bruno Felix", "202303");
  Aluno aluno2("Pedro Sperandio", "202302");
  Aluno aluno3("Isadora Martins", "202301");

  Instituicao faculdade("IFMS");
  
  faculdade.adicionarCurso("Ciência da Computação");
  faculdade.adicionarCurso("Engenharia de Software");
  
  faculdade.getCurso(0).adicionarTurma("T1-CC", &prof_algoritmos);
  faculdade.getCurso(0).getTurma(0).matricularAluno(&aluno1);
  faculdade.getCurso(0).getTurma(0).matricularAluno(&aluno2);

  faculdade.getCurso(0).adicionarTurma("T2-CC", &prof_poo);
  faculdade.getCurso(0).getTurma(1).matricularAluno(&aluno3);

  faculdade.getCurso(1).adicionarTurma("T1-ES", &prof_algoritmos);
  faculdade.getCurso(1).getTurma(0).matricularAluno(&aluno3);

  faculdade.listarInstituicao();
  
  cout << "\n===================================================\n\n";

return 0;
}