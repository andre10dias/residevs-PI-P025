#include "include/BancoDeDados.h"

void BancoDeDados::salvarDados(vector<string> listaDados, string nomeArquivo) {
    ofstream saida;

    saida.open(nomeArquivo, ios_base::out);

    if (saida.is_open())
    {
        for (string dado : listaDados)
        {
            saida << dado;
        }
        
        saida << ";";
        saida.close();
    }
    else
    {
        cout << "Falha ao abrir o arquivo.";
    }
}

vector<string> BancoDeDados::recuperarDados(string nomeArquivo) {
    vector<string> listaDados;
    ifstream entrada;

    entrada.open(nomeArquivo, ios_base::in);

    if (entrada.is_open())
    {
        string linha;
        while (entrada.eof() == false)
        {
            getline(entrada, linha);
            listaDados.push_back(linha);
        }

        entrada.close();
    }
    else
    {
        cout << "Falha ao abrir o arquivo.";
    }

    return listaDados;
}

vector<string> BancoDeDados::tratarDados(vector<string> listaDados) {
    vector<string> listaCampos;
    vector<string> listaLinhas;
    string linha;
    string campo;

    for (string str : listaDados)
    {
        istringstream ss(str);

        while (getline(ss, linha, ';')) {
            listaLinhas.push_back(linha);
        }
    }
    

    for (string str : listaLinhas)
    {
        istringstream ss(str);

        while (getline(ss, campo, ',')) {
            listaCampos.push_back(campo);
        }
    }

    return listaCampos;
}

vector<string> BancoDeDados::retornarLinha(vector<string> listaDados) {
    vector<string> listaLinhas;
    string linha;

    for (string str : listaDados)
    {
        istringstream ss(str);

        while (getline(ss, linha, ';')) {
            listaLinhas.push_back(linha);
        }
    }

    return listaLinhas;
}

vector<string> BancoDeDados::retornarCampos(string linha) {
    vector<string> listaCampos;
    string campo;

    istringstream ss(linha);

    while (getline(ss, campo, ',')) {
        listaCampos.push_back(campo);
    }

    return listaCampos;
}