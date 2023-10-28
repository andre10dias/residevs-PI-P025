#include "include/DataHora.h"

DataHora::DataHora(/* args */)
{
}

DataHora::~DataHora()
{
}

string DataHora::dataHoraAtual() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);

    char buffer[128];
    strftime(buffer, sizeof(buffer), "%d/%m/%Y %X", now);

    return buffer;
}
