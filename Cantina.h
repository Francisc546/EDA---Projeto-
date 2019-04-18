#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct refeiçao {

	string entrada;
	string principal;
	float custo;
};
struct pessoa {
	string primeironome;
	string ultimonome;
	int numero;
	int numerogrupo;
	string curso;
	float plafond;

};

void InsereRefeição(refeiçao * novaref);
void ImprimeRefeição(refeiçao * novaref);