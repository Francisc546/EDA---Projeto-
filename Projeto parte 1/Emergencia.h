#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Cantina.h"

void removeElemento(Mesa * cantina, int id, int numeromesas, int custoref);
void apagaElmentoMesa(identidade * ocupantes, int indiceRemover, int tamanho);
void removeGrupo(Mesa * cantina, int numerogrupo, int numeromesas, int custoref);
