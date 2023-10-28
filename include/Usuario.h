#ifndef USUARIO_H
#define USUARIO_H

#include "RedeSocial.h"
#include "Tweet.h"

using namespace std;

class Usuario
{
    private:
        string nome_usuario;
        string nome;
        vector<Usuario> seguidores;
        vector<Usuario> seguindo;

    public:
        static string NOME_ARQUIVO;
        
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

        void postar_tweet(Tweet t);
        void seguir(Usuario u);
        vector<Tweet> receber_feed();
};

#endif