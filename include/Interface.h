#ifndef INTERFACE_H
#define INTERFACE_H

#define TRACO "-------------------------------------------------------------------------------------------------------"

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

#include "RedeSocial.h"

int sair();
void systemClear();
void systemPause();
void systemPauseAndClear();
void monta_menu(std::vector<std::string> itens, std::string titulo);
int obter_opcao(int qtde_opcoes);

#endif