#include "RedeSocial.h"

RedeSocial::RedeSocial(/* args */)
{
}

RedeSocial::~RedeSocial()
{
}

Usuario RedeSocial::retorna_usuario_logado() 
{
    return usuarioLogado;
}

void RedeSocial::atualiza_usuario_logado(Usuario _usuarioLogado) 
{
    usuarioLogado = _usuarioLogado;
}

vector<Usuario> RedeSocial::retorna_seguindo() 
{
    string nomeUsuarioLogado = usuarioLogado.getNome_usuario();
    string nomeArquivo = nomeUsuarioLogado + "_" + Usuario::NOME_ARQUIVO;
    return retorna_usuarios(nomeArquivo);
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

void RedeSocial::registrar_tweet(Tweet t)
{
    string nomeArquivo = Tweet::NOME_ARQUIVO;
    vector<string> dados = BancoDeDados::recuperarDados(nomeArquivo);
    string dado = "";

    dado += t.getAutor().getNome_usuario() + "," + t.getAutor().getNome() + "," 
        + t.getConteudo() + "," + t.getData_criacao();

    dados.push_back(dado);
    
    BancoDeDados::salvarDados(dados, nomeArquivo);
}

void RedeSocial::registrar_seguindo(Usuario u)
{
    string nomeUsuarioLogado = usuarioLogado.getNome_usuario();
    string nomeArquivo = nomeUsuarioLogado + "_" + Usuario::NOME_ARQUIVO;
    vector<string> dados = BancoDeDados::recuperarDados(nomeArquivo);
    string dado = "";

    dado += u.getNome() + "," + u.getNome_usuario();
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
    return retorna_usuarios(Usuario::NOME_ARQUIVO);
}

vector<Tweet> RedeSocial::listar_tweets() {
    vector<string> dados = BancoDeDados::recuperarDados(Tweet::NOME_ARQUIVO);
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

vector<Usuario> RedeSocial::retorna_usuarios(string nomeArquivo)
{
    vector<string> dados = BancoDeDados::recuperarDados(nomeArquivo);
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
