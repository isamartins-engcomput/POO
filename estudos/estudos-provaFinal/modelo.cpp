// 1. Classe Base (Abstrata)
class Base
{
protected: 
    int dado; // Filhos podem ver
public:
    Base(int d) : dado(d) {}
    
    // OBRIGATÓRIO: Destrutor virtual
    virtual ~Base() { cout << "Base tchau"; } 

    // OBRIGATÓRIO: Método virtual puro (torna a classe abstrata)
    virtual void mostrar() = 0; 
};

// 2. Herança Pública
class Derivada : public Base
{
public:
    // Construtor repassa dados para o pai
    Derivada(int d) : Base(d) {}

    // Sobrescrita segura
    void mostrar() override { cout << "Sou Derivada"; }
    
    // Método Exclusivo
    void especial() { cout << "Só eu tenho isso"; }
};

// 3. Main "Hardcore"
int main()
{
    vector<Base*> lista; // Vetor de ponteiros!
    
    // Alocação Dinâmica
    lista.push_back( new Derivada(10) );

    for(Base* b : lista) {
        b->mostrar(); // Polimorfismo funciona sozinho

        // Cast para acessar método especial
        Derivada* d = dynamic_cast<Derivada*>(b);
        if (d != nullptr) {
            d->especial();
        }
    }

    // Limpeza de Memória (Essencial!)
    for(Base* b : lista) { delete b; }
    lista.clear();
}
