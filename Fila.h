#pragma once
#include "Cantina.h"
#include <iostream>
#include <fstream>
#include <string>


int adicionafila(identidade * filadeespera, int posicaovazia, string * pNome, string * uNome, string * cursos);
void imprimeFila(identidade * filadeespera, int tamanho);
void apagaFilaEspera(identidade * f, int n_elem);
int apagaElementoFilaespera(identidade * filadeespera, int custo);
