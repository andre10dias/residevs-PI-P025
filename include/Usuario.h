#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Usuario
{
    private:
        string nome_usuario;
        string nome;
        vector<Usuario> seguidores;
        vector<Usuario> seguindo;

    public:
        Usuario(/* args */);
        Usuario(string _nome, string _nome_usuario);
        ~Usuario();

        string getNome_usuario();
        void setNome_usuario(string _nome_usuario);
        string getNome();
        void setNome(string _nome);
        vector<Usuario> getSeguidores();
        void setSeguidores(vector<Usuario> _seguidores);
        vector<Usuario> getSeguindo();
        void setSeguindo(vector<Usuario> _seguindo);
};