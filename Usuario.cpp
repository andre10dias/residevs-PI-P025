#include "Usuario.h"

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
    vector<Usuario> seguidores = _seguidores;
}

vector<Usuario> Usuario::getSeguindo() {
    return seguindo;
}

void Usuario::setSeguindo(vector<Usuario> _seguindo) {
    seguindo = _seguindo;
}

