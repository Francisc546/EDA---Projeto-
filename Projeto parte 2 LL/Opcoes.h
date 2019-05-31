#pragma once
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Cantina.h"
using namespace std;


void imprimeMesa(Mesa * mesas, int nMesa);
identidade * alteraduracaofila(identidade * filadeespera, int numgrupo, int duracao);
Mesa * alteraduracaomesas(Mesa * mesas, int numgrupo, int duracao);
identidade * alterarnome(identidade * filadeespera, int id, string pnome, string unome);
Mesa * alterarnome2(Mesa* mesas, int id, string pnome, string unome);
void imprime(identidade * filadeespera, int departamento);
void imprimemesa(Mesa * mesas, int departamento);
void imprime2(identidade * filadeespera, string curso);
void imprimemesa2(Mesa * mesas, string curso);
void imprimemesa3(Mesa * mesas, int id);
void imprime3(identidade * filadeespera, int id);
void ordena(Mesa*mesas);
void imprimeMesa2(Mesa * mesas, int nMesa);
void BubbleSort(int m[], int a[], int n);
void ordenaFmaisM(identidade * filadeespera, Mesa * mesas);
void imprimePRIMOS(Mesa*mesas, identidade * filadeespera, int id);
