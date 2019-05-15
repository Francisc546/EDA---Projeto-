#pragma once
#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct refeicao {

	string entrada;
	string principal;
	float custo;
};
struct identidade {
	//int special;
	string primeironome, ultimonome;
	int numeroid, numerogrupo, duracao;
	string curso;
	int plafond;
	bool tipo;
	int n_elementos;
	identidade * seguinte;

};


struct Mesa {
	int numMesa;
	int tamanho;
	int vagas;
	identidade * pessoas;
	Mesa* seguinte;

};
identidade * criagrupo(identidade*filadeespera, string * pNome, string * uNome, string * cursos);
void escreveFiladeEspera(identidade * filadeespera);
identidade * adiciona_filadeespera(identidade*filadeespera, identidade*novo);
void imprimeCantina(Mesa * mesas);
Mesa * criamesas(Mesa*mesas, int tamanhodacantina);
Mesa * adiciona_mesas(Mesa*mesas, Mesa*novo);
void InsereRefeição(refeicao * novaref);
void ImprimeRefeição(refeicao * novaref);
identidade * criaespecial(identidade*filadeespera, string * pNome, string * uNome, string * cursos);
