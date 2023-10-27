#ifndef REDE_H
#define REDE_H

#include <iostream>
#include <string>
#include <vector>

#include "BancoDeDados.h"
#include "Usuario.h"
#include "Tweet.h"

using namespace std;

class RedeSocial
{
    private:
        vector<Usuario> usuarios;
        vector<Tweet> tweets;

        vector<Usuario> listar_usuarios();
        vector<Tweet> listar_tweets();

    public:
        RedeSocial(/* args */);
        ~RedeSocial();

        vector<Usuario> getUsuarios();
        vector<Tweet> getTweets();

        void registrar_usuario(string nome_usuario, string nome);
        Usuario buscar_usuario(string nome_usuario);
};

#endif