// Exercício 3: Frota de Veículos Autônomos

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class VeiculoAutonomo
{
  protected:
    string id;
    string modelo;
    string posicao;
    double bateria;

  public:
    VeiculoAutonomo(string i, string m, string p, double b) : id(i), modelo(m), posicao(p), bateria(b) {}
    virtual ~VeiculoAutonomo() { cout << "Veículo " << modelo << " removido" << endl; }

    virtual void mover() = 0;
    virtual void planejarRota(string destino) = 0;
    virtual void estrategiaRecarga() = 0;
    virtual void detectarObstaculos() = 0;
    virtual double consumoPorKm() = 0;
    virtual void relatorioStatus() = 0;
};

class CarroAutonomo : public VeiculoAutonomo
{
  private:
    int passageiros;
    double autonomia;

  public:
    CarroAutonomo(string i, string m, string p, double b, int pass, double a) : VeiculoAutonomo(i,m,p,b), passageiros(pass), autonomia(a) {}

    void detectarObstaculos() override
    { cout << "Sensor: Escaneando perímetro 360°" << endl; }

    void mover() override
    { 
      detectarObstaculos();
      cout << "Movimento: Acelerando suavemente" << endl; 
    }

    void planejarRota(string destino) override
    { cout << "Rota: Caminho mais rápido via GPS para " << destino << endl; }

    void estrategiaRecarga() override
    { cout << "Recarga: Estação Supercharger mais próxima" << endl; }

    double consumoPorKm() override { return 0.15; }

    void relatorioStatus() override
    {
      cout << "-----------------------------------" << endl;
      cout << ">>> CARRO AUTÔNOMO" << endl;
      cout << "ID: " << id << endl;
      cout << "Modelo: " << modelo << endl;
      cout << "Posição: " << posicao << endl;
      cout << "Bateria: " << bateria << "%" << endl;
      cout << "Passageiros: " << passageiros << endl;
      cout << "Consumo Estimado: " << consumoPorKm() << " kWh/km" << endl;
      estrategiaRecarga();
      mover();
      cout << "-----------------------------------" << endl;
    }
};

class CaminhaoAutonomo : public VeiculoAutonomo
{
  private:
    double capacidadeCarga;
    int eixos;

  public:
    CaminhaoAutonomo(string i, string m, string p, double b, double c, int e) : VeiculoAutonomo(i,m,p,b), capacidadeCarga(c), eixos(e) {}

    void detectarObstaculos() override
    { cout << "Sensor: Verificando altura de pontes e tráfego" << endl; }

    void mover() override
    { 
      detectarObstaculos();
      cout << "Movimento: Mantendo velocidade constante na direita" << endl; 
    }

    void planejarRota(string destino) override
    { cout << "Rota: Evitando vias com restrição de peso para " << destino << endl; }

    void estrategiaRecarga() override
    { cout << "Recarga: Doca de alta potência para caminhões" << endl; }

    double consumoPorKm() override { return 2.5; }

    void relatorioStatus() override
    {
      cout << "-----------------------------------" << endl;
      cout << ">>> CAMINHÃO AUTÔNOMO" << endl;
      cout << "ID: " << id << endl;
      cout << "Modelo: " << modelo << endl;
      cout << "Posição: " << posicao << endl;
      cout << "Bateria: " << bateria << "%" << endl;
      cout << "Carga: " << capacidadeCarga << " Ton" << endl;
      cout << "Eixos: " << eixos << endl;
      cout << "Consumo Estimado: " << consumoPorKm() << " kWh/km" << endl;
      estrategiaRecarga();
      mover();
      cout << "-----------------------------------" << endl;
    }
};

class OnibusAutonomo : public VeiculoAutonomo
{
  private:
    int lotacao;
    bool acessibilidade;

  public:
    OnibusAutonomo(string i, string m, string p, double b, int l, bool a) : VeiculoAutonomo(i,m,p,b), lotacao(l), acessibilidade(a) {}

    void detectarObstaculos() override
    { cout << "Sensor: Monitorando pedestres e pontos de parada" << endl; }

    void mover() override
    { 
      detectarObstaculos();
      cout << "Movimento: Seguindo faixa exclusiva" << endl; 
    }

    void planejarRota(string destino) override
    { cout << "Rota: Priorizando paradas pré-definidas até " << destino << endl; }

    void estrategiaRecarga() override
    { cout << "Recarga: Indução rápida no terminal" << endl; }

    double consumoPorKm() override { return 1.2; }

    void relatorioStatus() override
    {
      cout << "-----------------------------------" << endl;
      cout << ">>> ÔNIBUS AUTÔNOMO" << endl;
      cout << "ID: " << id << endl;
      cout << "Modelo: " << modelo << endl;
      cout << "Posição: " << posicao << endl;
      cout << "Bateria: " << bateria << "%" << endl;
      cout << "Lotação: " << lotacao << endl;
      cout << "Acessibilidade: " << (acessibilidade ? "Sim" : "Não") << endl;
      cout << "Consumo Estimado: " << consumoPorKm() << " kWh/km" << endl;
      estrategiaRecarga();
      mover();
      cout << "-----------------------------------" << endl;
    }
};

class Despachante
{
  private:
    vector<VeiculoAutonomo*> frota;

  public:
    void adicionarVeiculo(VeiculoAutonomo* v)
    { frota.push_back(v); }

    void atribuirRotaGlobal(string destino)
    {
      cout << "-----------------------------------" << endl;
      cout << "========= ATRIBUINDO ROTA ========" << endl;
      cout << "-----------------------------------" << endl;
      for (VeiculoAutonomo* v : frota)
      { 
        v->planejarRota(destino);
      }
      cout << "-----------------------------------" << endl;
    }

    void gerarRelatorioUnificado()
    {
      cout << "-----------------------------------" << endl;
      cout << "======== RELATÓRIO DA FROTA =======" << endl;
      for (VeiculoAutonomo* v : frota)
      { v->relatorioStatus(); }
    }

    ~Despachante()
    {
      for (VeiculoAutonomo* v : frota)
      { delete v;}
      frota.clear();
    }
};

int main()
{
  Despachante central;

  central.adicionarVeiculo(new CarroAutonomo("V-01", "Tesla Model Y 2025", "Garagem", 85.5, 4, 500.0));
  central.adicionarVeiculo(new CaminhaoAutonomo("V-02", "Volvo VNL Autonomus", "Logística", 60.0, 20.5, 6));
  central.adicionarVeiculo(new OnibusAutonomo("V-03", "Mercedes Future", "Terminal", 75.0, 45, true));

  central.atribuirRotaGlobal("Centro da Cidade");
  central.gerarRelatorioUnificado();

return 0;
}