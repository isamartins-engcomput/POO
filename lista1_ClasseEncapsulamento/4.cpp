/* Exercício 4: Em uma clínica médica, cada paciente tem um prontuário contendo diversas
anotações médicas feitas por um médico responsável. O prontuário deve estar vinculado a
um paciente e a um médico. Identifique e implemente as classes envolvidas. */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Paciente
{
  private:
    string nome;
    string id;

  public:
    Paciente(string n, string i) : nome(n), id(i)
    { cout << "Paciente '" << nome << "' criado!\n"; }
    ~Paciente() {}

    const string& getName() const { return nome; }
    const string& getID() const { return id; }
};

class Medico
{
  private:
    string nome;
    string crm;

  public:
    Medico(string n, string c) : nome(n), crm(c)
    { cout << "Médico '" << nome << "' criado!\n"; }

    ~Medico() { cout << "Médico '" << nome << "' destruído!\n"; }

    const string& getName() const { return nome; }
    const string& getCRM() const { return crm; }
};

class AnotacaoMedica
{
  private:
    string data;
    string descricao;

  public:
    AnotacaoMedica(string d, string desc) : data(d), descricao(desc)
    { cout << "Anotação médica da data '" << data << "' criada!\n"; }

    ~AnotacaoMedica() { cout << "Anotação médica da data '" << data << "' destruída!\n"; }
    
    void listarAnotacao() const
    {
      cout << "\nData: " << data;
      cout << "\nDescrição: " << descricao << "\n";
    }
};

class Prontuario
{
  private:
    Paciente* paciente; // Agregação: ponteiro para o Paciente
    Medico* medico;     // Agregação: ponteiro para o Médico
    vector<AnotacaoMedica> anotacoes; // Composição: armazena objetos diretamente

  public:
    Prontuario(Paciente* p, Medico* m) : paciente(p), medico(m)
    { cout << "Prontuário criado para o paciente '" << paciente->getName() << "'\n"; }
    
    ~Prontuario() { cout << "Prontuário do paciente '" << paciente->getName() << "' destruído!\n"; }

    void adicionarAnotacao(string data, string descricao)
    { anotacoes.emplace_back(data, descricao); }
    
    void listarProntuario() const
    {
      cout << "\n=============== PRONTUÁRIO MÉDICO '" << paciente->getName() << "' ===============\n\n";
      cout << "Paciente: " << paciente->getName() << "\n";
      cout << "Médico Responsável: " << medico->getName() << "\n";
      cout << "\nAnotações:\n";
      for (const auto& anotacao : anotacoes)
      { anotacao.listarAnotacao(); }
      cout << "\n========================================================\n\n";
    }
};

int main()
{
  cout << "\nSISTEMA DE PRONTUÁRIOS MÉDICOS\n\n";

  Paciente p1("Maria", "ID123");
  Medico m1("Dr. João", "CRM456");

  Prontuario prontuario1(&p1, &m1);

  prontuario1.adicionarAnotacao("22/09/2025", "Paciente apresenta sintomas de gripe, febre alta e tosse seca.");
  prontuario1.adicionarAnotacao("23/09/2025", "Sintomas melhorando, tosse menos frequente.");
  
  prontuario1.listarProntuario();

return 0;
}