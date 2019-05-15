#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int contaLinhas(string filename);
void Insere(string * Nome, string filename, int tamanho);
void InsereFicheiros(string * nome, string filename);
void escreveFicheiros(string *nome, int tamanho);