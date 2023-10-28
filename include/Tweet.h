#ifndef TWEET_H
#define TWEET_H

#include <vector>

#include "RedeSocial.h"
#include "DataHora.h"
#include "Usuario.h"

using namespace std;

class Tweet
{
    private:
        Usuario autor;
        string conteudo;
        string data_criacao;

    public:
        static string NOME_ARQUIVO;
        
        Tweet(/* args */);
        Tweet(Usuario _autor, string _conteudo);
        Tweet(Usuario _autor, string _conteudo, string _data_criacao);
        ~Tweet();

        Usuario getAutor();
        void setAutor(Usuario _autor);
        string getConteudo();
        void setConteudo(string _conteudo);
        string getData_criacao();

        static vector<Tweet> retornaTweetsPorAutor(Usuario autor);
};

#endif