#ifndef FIGURA_GEOMETRICA_H
#define FIGURA_GEOMETRICA_H

// CLASSE ABSTRATA: ao menos um método virtual (método apenas como um cabeçalho)

// 100% INTERFACE: uma classe com todos os métodos virtuais puros
class FiguraGeometrica
{
  // private: NADA DAQUI DE DENTRO É HERDADO!

  public:
    FiguraGeometrica();
    virtual ~FiguraGeometrica();
    virtual void draw(); // método puro (=0)
};

#endif