#include "include/Interface.h"

int sair() {
    cout << "\nFinalizando programa...";
    systemPauseAndClear();
    return 0;
}

void systemClear() {
    #if __linux__
        system("clear");
    #else
        system("cls");
    #endif
}

void systemPause() {
    cout << "\nPressione ENTER para continuar...\n";
    #if __linux__
        cin.ignore();
    #else
        cin.sync();
    #endif
    cin.get();
}

void systemPauseAndClear() {
    systemPause();
    systemClear();
}

void monta_menu(vector<string> itens, string titulo)
{
    cout << titulo << endl;
    for (auto item : itens)
    {
        cout << item << endl;
    }
};

int obter_opcao(int qtde_opcoes)
{
    int opcao = -1;
    while (opcao < 1 || opcao > qtde_opcoes)
    {
        cout << "Selecione uma opção: ";
        cin >> opcao;
        if (opcao < 1 || opcao > qtde_opcoes)
        {
            cout << "Opção invalida! Digite um número entre 1 e " << qtde_opcoes << endl;
            systemPause();
        }
    }

    return opcao;
}