/* Exercício 2: Um usuário de música online pode criar playlists, onde cada playlist
contém várias músicas. Um mesmo usuário pode ter diversas playlists associadas ao seu
perfil. Modele as classes necessárias e implemente. */

// Classes: Usuário, Playlist e Música -> AGREGAÇÃO

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Musica
{
  private:
    string titulo, artista;

  public:
    Musica(string t, string a) : titulo(t), artista(a)
    { cout << "Música '" << titulo << "' criada!\n"; }
    
    ~Musica() { cout << "Música '" << titulo << "' destruída!\n"; }

    void listarMusica() const
    {
      cout << "\nTítulo: " << titulo;
      cout << "\nArtista: " << artista;
      cout << "\n";
    }

    const string& getTitle() const { return titulo; }
};

class Playlist
{
  private:
    string nome;
    vector<Musica*> playlist;

  public:
    Playlist(string n) : nome(n)
    { cout << "Playlist '" << nome << "' criada!\n"; }
    
    ~Playlist() { cout << "Playlist '" << nome << "' destruída!\n"; }

    void adicionarMusica(Musica* musica)
    { playlist.push_back(musica); }

    void listarPlaylist() const
    {
      cout << "\n==== PLAYLIST '" << nome << "' - MÚSICAS ====\n";
      for (const auto& musica : playlist)
      { musica->listarMusica(); }
      cout << "\n============================================\n\n";
    }
    
    const string& getName() const { return nome; }
};

class Usuario
{
  private:
    string user;
    vector<Playlist*> playlists_user;

  public:
    Usuario(string u) : user(u)
    { cout << "Usuário '" << user << "' criado!\n"; }
    
    ~Usuario() { cout << "Usuário '" << user << "' destruído!\n"; }

    void adicionarPlaylist(Playlist* playlist)
    { playlists_user.push_back(playlist); }

    void listarPlaylists() const
    {
      cout << "\nPlaylists do usuário '" << user << "'...\n";
      for (const auto& playlist : playlists_user)
      { playlist->listarPlaylist(); }
    }
};

int main()
{
  cout << "\nSISTEMA DE GERENCIAMENTO DE PLAYLISTS MUSICAIS\n\n";

  Musica musica1("Se eu cair", "Eli Soares");
  Musica musica2("Sublime", "Fhop Music");
  Musica musica3("É Ele", "Drops INA");

  Playlist minha_playlist("Favourites <3");

  minha_playlist.adicionarMusica(&musica1);
  minha_playlist.adicionarMusica(&musica2);
  minha_playlist.adicionarMusica(&musica3);
  
  Usuario user_isa("isa1906");
  user_isa.adicionarPlaylist(&minha_playlist);

  user_isa.listarPlaylists();

return 0;
}