#include "Tweet.h"

static string NOME_ARQUIVO = "tweet.txt";

Tweet::Tweet(/* args */)
{
}

Tweet::Tweet(Usuario _autor, string _conteudo)
{
    autor = _autor;
    conteudo = _conteudo;
    data_criacao = DataHora::dataHoraAtual();
}

Tweet::Tweet(Usuario _autor, string _conteudo, string _data_criacao)
{
    autor = _autor;
    conteudo = _conteudo;
    data_criacao = _data_criacao;
}

Tweet::~Tweet()
{
}

Usuario Tweet::getAutor() {
    return autor;
}

void Tweet::setAutor(Usuario _autor) {
    autor = _autor;
}

string Tweet::getConteudo() {
    return conteudo;
}

void Tweet::setConteudo(string _conteudo) {
    conteudo = _conteudo;
}

string Tweet::getData_criacao() {
    return data_criacao;
}

vector<Tweet> Tweet::retornaTweetsPorAutor(Usuario autor) {
    vector<Tweet> tweets = RedeSocial::listar_tweets();
    vector<Tweet> tweetsDoAutor;

    for (Tweet tweet : tweets)
    {
        if (tweet.getAutor().getNome_usuario().compare(autor.getNome_usuario()) == 0)
        {
            tweetsDoAutor.push_back(tweet);
        }
    }

    return tweetsDoAutor;
}