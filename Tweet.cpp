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
};

Tweet::Tweet(/* args */)
{
}

Tweet::Tweet(Usuario _autor, string _conteudo)
{
    autor = _autor;
    conteudo = _conteudo;
    data_criacao = DataHora::dataHoraAtual();
}

Tweet::~Tweet()
{
}
