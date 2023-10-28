#ifndef DATAHORA_H
#define DATAHORA_H

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class DataHora
{
    private:
        /* data */
    public:
        DataHora(/* args */);
        ~DataHora();

        static string dataHoraAtual();
};

#endif