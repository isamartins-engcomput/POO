/* Exercício 2: Um usuário de música online pode criar playlists, onde cada playlist
contém várias músicas. Um mesmo usuário pode ter diversas playlists associadas ao seu
perfil. Modele as classes necessárias e implemente. */

// Classes: Usuário, Playlist e Música -> AGREGAÇÃO

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Musica
{
  private:
    string titulo, artista;

  public:
    Musica(string t, string a) : titulo(t), artista(a) {};
    ~Musica() {};

    void listarMusica()
    {
      cout << "\nTítulo: " << titulo;
      cout << "\nArtista: " << artista;
      cout << "\n";
    }

    const string& getTitle() { return titulo; };
};

class Playlist
{
  private:
    string nome;
    vector<Musica*> playlist;
  
  public:
    Playlist(string n) : nome(n) {};
    ~Playlist() {};

  void adicionarMusica(Musica* musica)
  { playlist.push_back(musica); }

  void listarPlaylist()
  {
    cout << "\nNome: " << nome;
    for (const auto& musica : playlist)
      musica->listarMusica();
  }
};