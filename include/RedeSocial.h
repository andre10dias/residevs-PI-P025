#ifndef REDESOCIAL_H
#define REDESOCIAL_H

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
        static Usuario usuarioLogado;
        vector<Usuario> usuarios;
        vector<Tweet> tweets;

        static vector<Usuario> retorna_usuarios(string nomeArquivo);

    public:
        RedeSocial(/* args */);
        ~RedeSocial();

        static bool logar(string nomeUsuario);
        static Usuario retorna_usuario_logado();
        static void atualiza_usuario_logado(Usuario _usuarioLogado);
        static vector<Usuario> retorna_seguindo();

        static void registrar_usuario(string nome_usuario, string nome);
        static void registrar_tweet(Tweet tweet);
        static void registrar_seguindo(Usuario usuario);
        static Usuario buscar_usuario(string nome_usuario);
        static vector<Usuario> listar_usuarios();
        static vector<Tweet> listar_tweets();
};

#endif