#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Jogador
{
  private:
    string nome;
    
  public:
    Jogador(string n) : nome(n) { cout << "Jogador " << nome << " nasceu (está pronto pra jogar)." << endl; }
    ~Jogador() { cout << "Jogador " << nome << " se aposentou (foi destruído)." << endl; }
    
    string getNome() { return nome; }
};

class Time
{
  private:
    vector<Jogador*> elenco; // O Time TEM Jogadores (ponteiros)
  
  public:
    Time() { cout << "Time fundado." << endl; }
    
    // AGREGAÇÃO: O Time recebe um jogador que JÁ EXISTE lá fora.
    void contratar(Jogador* j)
    {
        elenco.push_back(j);
        cout << "Contratado: " << j->getNome() << endl;
    }

    ~Time() {
        cout << "O Time faliu e fechou as portas!" << endl;
        // AQUI ESTÁ A MÁGICA DA AGREGAÇÃO:
        // Nós limpamos a lista, mas NÃO damos 'delete' nos jogadores.
        // Eles continuam vivos na memória para irem para outro time.
        elenco.clear(); 
    }
};

int main() {
    cout << "--- CENARIO AGREGACAO ---" << endl;
    
    // 1. O Jogador nasce FORA do time (vida independente)
    Jogador* neymar = new Jogador("Neymar");
    
    {
        Time psg;
        psg.contratar(neymar);
        
    } // <-- O time 'psg' morre aqui.
      // Observe no console: O Time fecha, mas o Neymar NÃO morre!
    
    cout << "--- FORA DO TIME ---" << endl;
    cout << "O " << neymar->getNome() << " ainda esta vivo e livre no mercado!" << endl;
    
    // Precisamos deletar o Neymar manualmente depois, já que o Time não fez isso.
    delete neymar; 
    
    return 0;
}
