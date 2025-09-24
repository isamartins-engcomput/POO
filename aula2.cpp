#include <iostream>

using namespace std;

/* int main()
{
  int i = 02;
  cout << "AULA n POO " << i;

  return 0;
} */

class Mouse
{
  private:
    // Atributos -> Características
    int sn;
    bool sem_fio;
    string marca;
    string modelo;
    int dpi;

  public:
    // Construtor -> Quase como uma função, mas diferente por conta do escopo
    Mouse(int sn, bool sem_fio, string marca, string modelo, int dpi)
    {
      // this->atributo = variável;
      this->sn = sn;
      this->sem_fio = sem_fio;
      this-> marca = marca;
      this-> modelo = modelo;
      this-> dpi = dpi;
    }
};