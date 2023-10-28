#include "include/Usuario.h"

static string NOME_ARQUIVO = "usuario.txt";

Usuario::Usuario(/* args */)
{
}

Usuario::Usuario(string _nome, string _nome_usuario) {
    nome = _nome;
    nome_usuario = _nome_usuario;
}

Usuario::~Usuario()
{
}

string Usuario::getNome_usuario() {
    return nome_usuario;
}

void Usuario::setNome_usuario(string _nome_usuario) {
    nome_usuario = _nome_usuario;
}

string Usuario::getNome() {
    return nome;
}

void Usuario::setNome(string _nome) {
    nome = _nome;
}

vector<Usuario> Usuario::getSeguidores() {
    return seguidores;
}

void Usuario::setSeguidores(vector<Usuario> _seguidores) {
    seguidores = _seguidores;
}

vector<Usuario> Usuario::getSeguindo() {
    return RedeSocial::retorna_seguindo();
}

void Usuario::setSeguindo(vector<Usuario> _seguindo) {
    seguindo = _seguindo;
}

void Usuario::postar_tweet(Tweet t) {
    RedeSocial::registrar_tweet(t);
}

void Usuario::seguir(Usuario u) {
    RedeSocial::registrar_seguindo(u);
}

vector<Tweet> Usuario::receber_feed() {
    vector<Usuario> seguindo = RedeSocial::retorna_usuario_logado().getSeguindo();
    vector<Tweet> tweetsSeguindo;
    vector<Tweet> tweetsTodosSeguindo;

    for (Usuario usuario : seguindo)
    {
        tweetsSeguindo = Tweet::retornaTweetsPorAutor(usuario);

        for (Tweet tweet : tweetsSeguindo)
        {
            tweetsTodosSeguindo.push_back(tweet);
        }
    }
    
    return tweetsTodosSeguindo;
}
