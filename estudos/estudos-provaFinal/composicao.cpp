#include <iostream>
#include <string>

using namespace std;

class Motor
{
  protected:
    int potencia;
  
  public:
    Motor(int p) : potencia(p) { cout << "  -> Motor V" << potencia << " fabricado." << endl; }
    ~Motor() { cout << "  -> Motor destruido (virou sucata)." << endl; }
};

class Carro
{
  private:
    Motor* motor; // O Carro TEM UM Motor

  public:
    Carro(int potencia)
    {
        // COMPOSIÇÃO: O Motor é criado DENTRO do Carro.
        // O Carro é o "dono" exclusivo desse motor.
        motor = new Motor(potencia);
        cout << "Carro montado na fabrica." << endl;
    }

    ~Carro()
    {
        cout << "Carro indo para o ferro-velho..." << endl;
        // AQUI ESTÁ A MÁGICA DA COMPOSIÇÃO:
        delete motor; // O Carro mata o Motor antes de morrer.
    }
};

int main()
{
    cout << "--- CENÁRIO COMPOSIÇÃO ---" << endl;
    {
        Carro meuCarro(8); // Cria o Carro (e o Motor nasce junto)
    } // <-- O Carro sai de escopo e morre aqui. 
      // Observe no console que o Motor morre automaticamente.
    
    cout << "--- FIM DO BLOCO ---" << endl;
    
return 0;
}
