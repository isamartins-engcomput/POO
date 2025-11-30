// Exercício 4: Editor de Formas Vetoriais

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

struct Ponto
{ double x, y; };

class Forma
{
  protected:
    string id;
    string tipo;
    Ponto ancora;

  public:
    Forma(string i, string t, double x, double y) : id(i), tipo(t), ancora{x, y} {}
    virtual ~Forma() { cout << "Forma " << tipo << " (" << id << ") removida" << endl; }

    virtual void desenhar() = 0;
    virtual double area() = 0;
    virtual double perimetro() = 0;
    virtual void mover(double dx, double dy) = 0;
    virtual Forma* clonar() = 0;
    virtual void redimensionar(double fator) = 0;

    virtual void relatorioForma() = 0;
};

class Circulo : public Forma
{
  private:
    double raio;

  public:
    Circulo(string i, double x, double y, double r) : Forma(i,"Círculo",x,y), raio(r) {}

    void desenhar() override
    { cout << "Renderizando... \nCírculo em (" << ancora.x << "," << ancora.y << ") com raio " << raio << endl; }

    double area() override { return 3.14159 * (raio * raio); }

    double perimetro() override { return 2 * 3.14159 * raio; }

    void mover(double dx, double dy) override
    { 
      ancora.x += dx; 
      ancora.y += dy;
      cout << "Movimento: Círculo movido para (" << ancora.x << "," << ancora.y << ")" << endl;
    }

    Forma* clonar() override
    { return new Circulo(*this); }

    void redimensionar(double fator) override
    { 
      if (fator > 0) raio *= fator; 
      cout << "Edição: Raio alterado para " << raio << endl;
    }

    void relatorioForma() override
    {
      cout << "-----------------------------------" << endl;
      cout << ">>> " << tipo << " <<<" << endl;
      cout << "ID: " << id << endl;
      cout << "Posição: (" << ancora.x << "," << ancora.y << ")" << endl;
      cout << "Raio: " << raio << endl;
      cout << "Área: " << area() << endl;
      cout << "Perímetro: " << perimetro() << endl;
      desenhar();
      cout << "-----------------------------------" << endl;
    }
};

class Retangulo : public Forma
{
  private:
    double largura;
    double altura;

  public:
    Retangulo(string i, double x, double y, double l, double a) : Forma(i,"Retângulo",x,y), largura(l), altura(a) {}

    void desenhar() override
    { cout << "Renderizando... \nRetângulo em (" << ancora.x << "," << ancora.y << ") de " << largura << "x" << altura << endl; }

    double area() override { return largura * altura; }

    double perimetro() override { return 2 * (largura + altura); }

    void mover(double dx, double dy) override
    {
      ancora.x += dx;
      ancora.y += dy;
      cout << "Movimento: Retângulo movido para (" << ancora.x << "," << ancora.y << ")" << endl;
    }

    Forma* clonar() override
    { return new Retangulo(*this); }

    void redimensionar(double fator) override
    {
      if (fator > 0) { largura *= fator; altura *= fator; }
      cout << "Edição: Dimensões alteradas para " << largura << "x" << altura << endl;
    }

    void relatorioForma() override
    {
      cout << "-----------------------------------" << endl;
      cout << ">>> " << tipo << " <<<" << endl;
      cout << "ID: " << id << endl;
      cout << "Posição: (" << ancora.x << "," << ancora.y << ")" << endl;
      cout << "Dimensões: " << largura << "x" << altura << endl;
      cout << "Área: " << area() << endl;
      cout << "Perímetro: " << perimetro() << endl;
      desenhar();
      cout << "-----------------------------------" << endl;
    }
};

class Poligono : public Forma
{
  private:
    int numLados;
    double tamLado;

  public:
    Poligono(string i, double x, double y, int n, double t) : Forma(i,"Polígono",x,y), numLados(n), tamLado(t) {}

    void desenhar() override
    { cout << "Renderizando... \nPolígono de " << numLados << " lados em (" << ancora.x << "," << ancora.y << ")" << endl; }

    double area() override 
    { return (numLados * tamLado * tamLado) / (4 * tan(3.14159 / numLados)); }

    double perimetro() override { return numLados * tamLado; }

    void mover(double dx, double dy) override
    {
      ancora.x += dx;
      ancora.y += dy;
      cout << "Movimento: Polígono movido para (" << ancora.x << "," << ancora.y << ")" << endl;
    }

    Forma* clonar() override
    { return new Poligono(*this); }

    void redimensionar(double fator) override
    {
      if (fator > 0) tamLado *= fator;
      cout << "Edição: Lado alterado para " << tamLado << endl;
    }

    void relatorioForma() override
    {
      cout << "-----------------------------------" << endl;
      cout << ">>> " << tipo << " <<<" << endl;
      cout << "ID: " << id << endl;
      cout << "Posição: (" << ancora.x << "," << ancora.y << ")" << endl;
      cout << "Lados: " << numLados << " (Tamanho: " << tamLado << ")" << endl;
      cout << "Área: " << area() << endl;
      cout << "Perímetro: " << perimetro() << endl;
      desenhar();
      cout << "-----------------------------------" << endl;
    }
};

class Ferramenta
{
  public:
    virtual void aplicar(Forma* f) = 0;
    virtual ~Ferramenta() {}
};

class FerramentaRedimensionar : public Ferramenta
{
  private:
    double fator;
  public:
    FerramentaRedimensionar(double f) : fator(f) {}
    void aplicar(Forma* f) override
    {
      cout << ">> Ferramenta: Aplicando Zoom " << fator << "x" << endl;
      f->redimensionar(fator);
    }
};

class FerramentaMover : public Ferramenta
{
  private:
    double dx, dy;
  public:
    FerramentaMover(double x, double y) : dx(x), dy(y) {}
    void aplicar(Forma* f) override
    {
      cout << ">> Ferramenta: Movendo objeto..." << endl;
      f->mover(dx, dy);
    }
};

class Renderer
{
  private:
    vector<Forma*> canvas;

  public:
    void adicionarForma(Forma* f)
    { canvas.push_back(f); }

    void renderizarTudo()
    {
      cout << "-----------------------------------" << endl;
      cout << "===== RENDERIZAÇÃO DO CANVAS =====" << endl;
      for (Forma* f : canvas)
      { f->relatorioForma(); }
    }

    void duplicarForma(int indice)
    {
      if (indice >= 0 && indice < canvas.size())
      {
        cout << "-----------------------------------" << endl;
        cout << ">> Renderer: Clonando objeto " << indice << "..." << endl;
        canvas.push_back(canvas[indice]->clonar());
      }
    }

    void aplicarFerramenta(Ferramenta& tool)
    {
      cout << "-----------------------------------" << endl;
      cout << "== APLICANDO FERRAMENTA EM LOTE ==" << endl;
      cout << "-----------------------------------" << endl;
      for (Forma* f : canvas)
      { tool.aplicar(f); }
      cout << endl;
    }

    ~Renderer()
    {
      for (Forma* f : canvas)
      { delete f;}
      canvas.clear();
    }
};

int main()
{
  Renderer editor;

  editor.adicionarForma(new Circulo("F-01", 0, 0, 5.0));
  editor.adicionarForma(new Retangulo("F-02", 10, 10, 8.0, 4.0));
  editor.adicionarForma(new Poligono("F-03", -5, 5, 6, 3.0));

  editor.renderizarTudo();

  FerramentaRedimensionar zoom(2.0);
  editor.aplicarFerramenta(zoom);

  editor.duplicarForma(0);

  editor.renderizarTudo();

return 0;
}