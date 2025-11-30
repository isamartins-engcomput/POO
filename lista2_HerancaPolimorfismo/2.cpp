// Exercício 2: Catálogo Multimídia

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Midia
{
  protected:
    string titulo;
    int ano;
    string duracao;

  public:
    Midia(string t, int a, string d) : titulo(t), ano(a), duracao(d) {}
    virtual ~Midia() { cout << "Mídia " << titulo << " removida" << endl; }

    virtual void reproduzir() = 0;
    virtual void infoDetalhada() = 0;
    virtual bool combina(string filtro) = 0;
};

class Musica : public Midia
{
  private:
    string artista;
    int bitrate;

  public:
    Musica(string t, int a, string d, string art, int b) : Midia(t,a,d), artista(art), bitrate(b) {}

    void reproduzir() override
    { cout << "Reproduzindo: Tocando " << titulo << " de " << artista << "..." << endl; }

    void infoDetalhada() override
    {
      cout << "-----------------------------------" << endl;
      cout << ">>> MÚSICA" << endl;
      cout << "Título: " << titulo << endl;
      cout << "Ano: " << ano << endl;
      cout << "Duração: " << duracao << endl;
      cout << "Artista/Banda: " << artista << endl;
      cout << "Qualidade: " << bitrate << " kbps" << endl;
      cout << "-----------------------------------" << endl;
    }

    bool combina(string filtro) override
    {
      bool noTitulo = titulo.find(filtro) != string::npos;
      bool noArtista = artista.find(filtro) != string::npos;
      return noTitulo || noArtista;
    }
};

class Video : public Midia
{
  private:
    string canal;
    string resolucao;
    string codec;

  public:
    Video(string t, int a, string d, string ch, string res, string c) : Midia(t,a,d), canal(ch), resolucao(res), codec(c) {}

    void reproduzir() override
    { cout << "Reproduzindo: Exibindo vídeo em " << resolucao << "..." << endl; }

    void infoDetalhada() override
    {
      cout << "-----------------------------------" << endl;
      cout << ">>> VÍDEO" << endl;
      cout << "Título: " << titulo << endl;
      cout << "Canal: " << canal << endl;
      cout << "Ano: " << ano << endl;
      cout << "Duração: " << duracao << endl;
      cout << "Resolução: " << resolucao << endl;
      cout << "Codec: " << codec << endl;
      cout << "-----------------------------------" << endl;
    }

    bool combina(string filtro) override
    {
      bool noTitulo = titulo.find(filtro) != string::npos;
      bool naResolucao = resolucao.find(filtro) != string::npos;
      return noTitulo || naResolucao;
    }
};

class Podcast : public Midia
{
  private:
    string host;
    string convidados;

  public:
    Podcast(string t, int a, string d, string h, string c) : Midia(t,a,d), host(h), convidados(c) {}

    void reproduzir() override
    { cout << "Reproduzindo: Podcast com host " << host << "..." << endl; }

    void infoDetalhada() override
    {
      cout << "-----------------------------------" << endl;
      cout << ">>> PODCAST" << endl;
      cout << "Título: " << titulo << endl;
      cout << "Ano: " << ano << endl;
      cout << "Duração: " << duracao << endl;
      cout << "Host: " << host << endl;
      cout << "Convidado(s): " << convidados << endl;
      cout << "-----------------------------------" << endl;
    }

    bool combina(string filtro) override
    {
      bool noTitulo = titulo.find(filtro) != string::npos;
      bool noHost = host.find(filtro) != string::npos;
      return noTitulo || noHost;
    }
};

class Audiolivro : public Midia
{
  private:
    string autor;
    string narrador;

  public:
    Audiolivro(string t, int a, string d, string aut, string n) : Midia(t,a,d), autor(aut), narrador(n) {}

    void reproduzir() override
    { cout << "Reproduzindo: Lendo livro de " << autor << " na voz de " << narrador << "..." << endl; }

    void infoDetalhada() override
    {
      cout << "-----------------------------------" << endl;
      cout << ">>> AUDIOLIVRO" << endl;
      cout << "Título: " << titulo << endl;
      cout << "Ano: " << ano << endl;
      cout << "Duração: " << duracao << endl;
      cout << "Autor(a): " << autor << endl;
      cout << "Narrador(a): " << narrador << endl;
      cout << "-----------------------------------" << endl;
    }

    bool combina(string filtro) override
    {
      bool noTitulo = titulo.find(filtro) != string::npos;
      bool noAutor = autor.find(filtro) != string::npos;
      return noTitulo || noAutor;
    }
};

int main()
{
  vector<Midia*> catalogo;

  catalogo.push_back(new Musica("Cinco Pães e Dois Peixinhos", 2003, "8:12", "4/1", 320));
  catalogo.push_back(new Video("Linguagem C++ | Aula 37 - POO: Relacionamento de Agregação", 2025, "4:46", "Programação Descomplicada | Linguagem C - André Backes", "1080p", "H.264"));
  catalogo.push_back(new Podcast("Retrópolis", 2025, "57min", "isadaora1906", "Piter Punk"));
  catalogo.push_back(new Audiolivro("1984", 1949, "12h", "George Orwell", "Raphalê"));

  cout << "-----------------------------------" << endl;
  cout << "======= CATÁLOGO MULTIMÍDIA =======" << endl;

  for (Midia* m : catalogo)
  { m->infoDetalhada(); }

  string busca = "4/1";
  cout << "-----------------------------------" << endl;
  cout << "=> RESULTADO BUSCA: '" << busca << "'" << endl;
  
  for (Midia* m : catalogo)
  {
    if (m->combina(busca))
    { m->reproduzir(); }
  }

  cout << "-----------------------------------" << endl;

  for (Midia* m : catalogo)
  { delete m;}
  catalogo.clear();

return 0;
}