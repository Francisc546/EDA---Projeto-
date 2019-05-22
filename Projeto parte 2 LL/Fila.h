#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Cantina.h"
using namespace std;

int comprimento(identidade * filadeespera);
identidade * removerPos(identidade * filadeespera, int pos);
int retornapos(identidade * filadeespera, int custo);
identidade * removerInicio(identidade * filadeespera);
void removerFim(identidade * filadeespera);
identidade * removeGrupo(identidade * filadeespera);