#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int contaLinhas(string filename);
void Insere(string* Nome, string filename, int tamanho);
void escreve(string* Nome, int tamanho);
void rec(refeicao* novaref, identidade* filadeespera, Mesa* mesas, int tdc);
void loading(refeicao* novaref, identidade* filadeespera);
void loading_m(Mesa* mesas);