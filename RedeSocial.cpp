#include "RedeSocial.h"

RedeSocial::RedeSocial(/* args */)
{
}

RedeSocial::~RedeSocial()
{
}

vector<Usuario> RedeSocial::getUsuarios() {
    return listar_usuarios();
}

vector<Tweet> RedeSocial::getTweets() {
    return listar_tweets();
}

void RedeSocial::registrar_usuario(string nome_usuario, string nome)
{
    string nomeArquivo = Usuario::NOME_ARQUIVO;
    vector<string> dados = BancoDeDados::recuperarDados(nomeArquivo);
    string dado = "";

    dado += nome_usuario + "," + nome;
    dados.push_back(dado);

    BancoDeDados::salvarDados(dados, nomeArquivo);
}

Usuario RedeSocial::buscar_usuario(string nome_usuario)
{
    vector<Usuario> usuarios = listar_usuarios();
    Usuario usuario;

    for (Usuario usuario : usuarios)
    {
        if (usuario.getNome_usuario().compare(nome_usuario) == 0)
        {
            return usuario;
        }
    }

    return usuario;
}

vector<Usuario> RedeSocial::listar_usuarios() {
    vector<string> dados = BancoDeDados::recuperarDados(Usuario::NOME_ARQUIVO);
    vector<string> linhas;
    vector<string> campos;
    vector<Usuario> usuarios;

    const int NOME_USUARIO = 0;
    const int NOME = 1;

    linhas = BancoDeDados::retornarLinha(dados);
    for (string linha : linhas)
    {
        campos = BancoDeDados::retornarCampos(linha);

        Usuario usuario(campos[NOME_USUARIO], campos[NOME]);
        usuarios.push_back(usuario);
    }

    return usuarios;
}

vector<Tweet> RedeSocial::listar_tweets() {
    vector<string> dados = BancoDeDados::recuperarDados(Usuario::NOME_ARQUIVO);
    vector<string> linhas;
    vector<string> campos;
    vector<Tweet> tweets;

    const int AUTOR_NOME_USUARIO = 0;
    const int AUTOR_NOME = 1;
    const int CONTEUDO = 2;
    const int DATA_CRIACAO = 3;

    linhas = BancoDeDados::retornarLinha(dados);
    for (string linha : linhas)
    {
        campos = BancoDeDados::retornarCampos(linha);

        Usuario usuario(campos[AUTOR_NOME_USUARIO], campos[AUTOR_NOME]);
        Tweet tweet(usuario, campos[CONTEUDO], campos[DATA_CRIACAO]);

        tweets.push_back(tweet);
    }

    return tweets;
}
