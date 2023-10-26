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

        static string dataHoraAtual() {
            time_t t = time(nullptr);
            tm* now = localtime(&t);
        
            char buffer[128];
            strftime(buffer, sizeof(buffer), "%d/%m/%Y %X", now);

            return buffer;
        }
};

DataHora::DataHora(/* args */)
{
}

DataHora::~DataHora()
{
}
