/* Exercício 6: Uma empresa de transporte possui uma frota de ônibus, cada um com sua rota.
As rotas possuem várias paradas. A empresa também mantém motoristas associados à frota.
Elabore as classes e implemente. */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Parada
{
  private:
    string nome;
  
  public:
    Parada(string n) : nome(n) {}
    ~Parada() {}
    
    void listarParada() const
    { cout << "- " << nome << endl; }
};

class Rota
{
  private:
    string codigo;
    vector<Parada> paradas;
  
  public:
    Rota(string c) : codigo(c) {}
    ~Rota() {}

    void adicionarParada(string nome_parada)
    { paradas.emplace_back(nome_parada); }
    
    void listarRota() const
    {
      cout << "\nRota: " << codigo << "\n\n";
      cout << "Paradas:\n";
      for (const auto& parada : paradas)
      { parada.listarParada(); }
    }
};

class Motorista
{
  private:
    string nome;
    string cnh;
  
  public:
    Motorista(string n, string c) : nome(n), cnh(c) {}
    ~Motorista() {}
    
    const string& getNome() const { return nome; }
};

class Onibus
{
  private:
    string placa;
    Motorista* motorista;
    Rota rota;

  public:
    Onibus(string p, Motorista* m, string codigo_rota) : placa(p), motorista(m), rota(codigo_rota) {}
    ~Onibus() {}

    Rota& getRota() { return rota; }

    void listarOnibus() const
    {
      cout << "\n>>>>> ÔNIBUS: " << placa << "\n";
      cout << "Motorista: " << motorista->getNome() << endl;
      rota.listarRota();
    }
};

class Empresa
{
  private:
    string nome;
    vector<Onibus> frota;
    vector<Motorista*> equipe;

  public:
    Empresa(string n) : nome(n) {}
    ~Empresa() {}
    
    void contratarMotorista(Motorista* m)
    { equipe.push_back(m); }
    
    void adicionarOnibus(string placa, Motorista* motorista, string codigo_rota)
    { frota.emplace_back(placa, motorista, codigo_rota); }
    
    void listarFrota() const
    {
      cout << "\n========== FROTA DA EMPRESA '" << nome << "' ==========\n";
      for (const auto& onibus : frota)
      { onibus.listarOnibus(); }
      cout << "\n======================================================\n\n";
    }

    Onibus& getOnibus(int indice) { return frota.at(indice); }
};

int main()
{
  cout << "\nSISTEMA DE GERENCIAMENTO DE TRANSPORTES\n";

  Motorista mot1("João", "1234");
  Motorista mot2("Maria", "5678");

  Empresa empresa("Lucas Tur");

  empresa.contratarMotorista(&mot1);
  empresa.contratarMotorista(&mot2);

  empresa.adicionarOnibus("ABC-1234", &mot1, "Rota Centro-Bairro");
  empresa.adicionarOnibus("XYZ-5678", &mot2, "Rota Leste-Oeste");

  empresa.getOnibus(0).getRota().adicionarParada("Parada 1");
  empresa.getOnibus(0).getRota().adicionarParada("Parada 2");
  empresa.getOnibus(0).getRota().adicionarParada("Parada 3");
  
  empresa.getOnibus(1).getRota().adicionarParada("Parada A");
  empresa.getOnibus(1).getRota().adicionarParada("Parada B");

  empresa.listarFrota();

return 0;
}