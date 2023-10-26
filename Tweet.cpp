#include "Tweet.h"

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

