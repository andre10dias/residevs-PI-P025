#ifndef BD_H
#define BD_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class BancoDeDados
{
    private:
        /* data */
    public:
        BancoDeDados(/* args */);
        ~BancoDeDados();

        static void salvarDados(vector<string> listaDados, string nomeArquivo);
        static vector<string> recuperarDados(string nomeArquivo);
        static vector<string> tratarDados(vector<string> listaDados);
        static vector<string> retornarLinha(vector<string> listaDados);
        static vector<string> retornarCampos(string linha);
};

#endif