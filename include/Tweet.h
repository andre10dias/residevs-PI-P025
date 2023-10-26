#include <iostream>
#include <string>
#include <vector>

#include "Usuario.h"
#include "DataHora.h"

using namespace std;

class Tweet
{
    private:
        Usuario autor;
        string conteudo;
        string data_criacao;

    public:
        Tweet(/* args */);
        Tweet(Usuario _autor, string _conteudo);
        ~Tweet();

        Usuario getAutor();
        void setAutor(Usuario _autor);
        string getConteudo();
        void setConteudo(string _conteudo);
        string getData_criacao();
};